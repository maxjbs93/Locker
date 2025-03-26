from flask import Flask, request, jsonify
import pymysql
from flask_cors import CORS

app = Flask(__name__)
CORS(app)  # Autorise les requêtes cross-origin

# Connexion à la base de données
def get_db_connection():
    return pymysql.connect(
        host="localhost",
        user="root",
        password="",
        database="locker",
        cursorclass=pymysql.cursors.DictCursor
    )


# Route pour l'authentification
@app.route('/login', methods=['POST'])
def login():
    data = request.json
    username = data.get("username")
    password = data.get("password")

    try:
        conn = get_db_connection()
        cursor = conn.cursor()

        # Vérifier si c'est un commerçant
        cursor.execute("SELECT id, pseudo AS username, 'commercant' AS role FROM commercants WHERE pseudo=%s AND mdp=%s", (username, password))
        user = cursor.fetchone()

        # Sinon, vérifier si c'est un livreur
        if not user:
            cursor.execute("SELECT id, username, 'livreur' AS role FROM livreurs WHERE username=%s AND password=%s", (username, password))
            user = cursor.fetchone()

        return jsonify({"status": "success", "message": "Connexion réussie", "user": user}) if user else jsonify({"status": "error", "message": "Nom d'utilisateur ou mot de passe incorrect"})

    except Exception as e:
        return jsonify({"status": "error", "message": str(e)}), 500

    finally:
        cursor.close()
        conn.close()


# Route pour ajouter un livreur
@app.route('/ajouter_livreur', methods=['POST'])
def ajouter_livreur():
    data = request.json
    nom = data.get("nom")
    prenom = data.get("prenom")
    adresse = data.get("adresse")
    username = data.get("username")
    password = data.get("password")

    conn = get_db_connection()
    cursor = conn.cursor()

    # Insertion du livreur dans la base de données
    sql = "INSERT INTO livreurs (nom, prenom, adresse, username, password) VALUES (%s, %s, %s, %s, %s)"
    cursor.execute(sql, (nom, prenom, adresse, username, password))
    conn.commit()

    cursor.close()
    conn.close()

    return jsonify({"status": "success", "message": "Livreur ajouté avec succès !"})


# Routes pour accepter ou refuser une commande
@app.route('/commande/accepter', methods=['POST'])
def accepter_commande():
    data = request.json
    id_commande = data.get("id_commande")

    if not id_commande:
        return jsonify({"status": "error", "message": "ID de commande manquant"}), 400

    try:
        conn = get_db_connection()
        cursor = conn.cursor()

        # Vérifier si la commande existe
        cursor.execute("SELECT * FROM commandes WHERE id = %s", (id_commande,))
        commande = cursor.fetchone()
        if not commande:
            return jsonify({"status": "error", "message": "Commande introuvable"}), 404

        # Récupérer l'ID du livreur associé à la commande
        livreur_id = commande.get("livreur_id")
        if not livreur_id:
            return jsonify({"status": "error", "message": "Aucun livreur associé à cette commande"}), 400

        # Mettre à jour le statut de la commande et du livreur
        cursor.execute("UPDATE commandes SET statut = 'en cours' WHERE id = %s", (id_commande,))
        cursor.execute("UPDATE livreurs SET statut = 'en cours de livraison' WHERE id = %s", (livreur_id,))
        conn.commit()

        return jsonify({"status": "success", "message": "Commande acceptée avec succès"})

    except Exception as e:
        return jsonify({"status": "error", "message": str(e)}), 500

    finally:
        cursor.close()
        conn.close()

@app.route('/commande/refuser', methods=['POST'])
def refuser_commande():
    data = request.json
    id_commande = data.get("id_commande")

    if not id_commande:
        return jsonify({"status": "error", "message": "ID de commande manquant"}), 400

    try:
        conn = get_db_connection()
        cursor = conn.cursor()

        # Vérifier si la commande existe
        cursor.execute("SELECT * FROM commandes WHERE id = %s", (id_commande,))
        commande = cursor.fetchone()
        if not commande:
            return jsonify({"status": "error", "message": "Commande introuvable"}), 404

        # Récupérer l'ID du livreur associé à la commande
        livreur_id = commande.get("livreur_id")
        if not livreur_id:
            return jsonify({"status": "error", "message": "Aucun livreur associé à cette commande"}), 400

        # Mettre à jour le statut de la commande (retour à "en attente") et retirer l'association avec le livreur
        cursor.execute("UPDATE commandes SET livreur_id = NULL, statut = 'en attente' WHERE id = %s", (id_commande,))
        cursor.execute("UPDATE livreurs SET statut = 'disponible' WHERE id = %s", (livreur_id,))
        conn.commit()

        return jsonify({"status": "success", "message": "Commande refusée, en attente d'un autre livreur"})

    except Exception as e:
        return jsonify({"status": "error", "message": str(e)}), 500

    finally:
        cursor.close()
        conn.close()

@app.route('/ajouter_commande', methods=['POST'])
def ajouter_commande():
    data = request.json
    print("Données reçues:", data)  # Log des données reçues

    # Vérifier si tous les champs nécessaires sont fournis
    required_fields = ["client_email", "taille_casier", "poids_colis", "commercant_nom", "commercant_adresse"]
    for field in required_fields:
        if field not in data or not data[field]:
            return jsonify({"status": "error", "message": f"Champ manquant : {field}"}), 400

    email_client = data["client_email"]
    taille_casier = data["taille_casier"]
    poids_colis = data["poids_colis"]
    nom_commercant = data["commercant_nom"]
    adresse_commercant = data["commercant_adresse"]

    try:
        conn = get_db_connection()
        cursor = conn.cursor()

        # Insérer la commande dans la BD
        sql = """
        INSERT INTO commandes (client_email, taille_casier, poids_colis, commercant_nom, commercant_adresse)
        VALUES (%s, %s, %s, %s, %s)
        """
        cursor.execute(sql, (email_client, taille_casier, poids_colis, nom_commercant, adresse_commercant))
        conn.commit()

        return jsonify({"status": "success", "message": "Commande ajoutée avec succès !"})

    except Exception as e:
        print(f"Erreur: {e}")  # Log de l'erreur
        return jsonify({"status": "error", "message": str(e)}), 500

    finally:
        cursor.close()
        conn.close()

@app.route('/afficher_commandes', methods=['GET'])
def afficher_commandes():
    try:
        conn = get_db_connection()
        cursor = conn.cursor()

        # Modifier la requête SQL pour inclure "statut"
        cursor.execute("""
            SELECT id, client_email, taille_casier, poids_colis, commercant_nom,
                   commercant_adresse, date_creation, statut
            FROM commandes
        """)

        commandes = cursor.fetchall()

        cursor.close()
        conn.close()

        return jsonify({"status": "success", "commandes": commandes})

    except Exception as e:
        print("Erreur serveur:", str(e))  # Affiche l'erreur dans la console Flask
        return jsonify({"status": "error", "message": str(e)}), 500


@app.route('/supprimer_commande', methods=['DELETE'])
def supprimer_commande():
    data = request.json  # Récupérer les données envoyées (JSON)
    commande_id = data.get("commande_id")  # Récupérer l'ID de la commande

    if not commande_id:
        return jsonify({"status": "error", "message": "ID de commande manquant"}), 400

    try:
        conn = get_db_connection()
        cursor = conn.cursor()

        # Vérifier si la commande existe
        cursor.execute("SELECT * FROM commandes WHERE id = %s", (commande_id,))
        commande = cursor.fetchone()
        if not commande:
            return jsonify({"status": "error", "message": "Commande introuvable"}), 404

        # Supprimer la commande
        cursor.execute("DELETE FROM commandes WHERE id = %s", (commande_id,))
        conn.commit()

        return jsonify({"status": "success", "message": "Commande supprimée avec succès !"})

    except Exception as e:
        return jsonify({"status": "error", "message": str(e)}), 500

    finally:
        cursor.close()
        conn.close()

@app.route('/afficher_etat_casiers', methods=['GET'])
def afficher_etat_casiers():
    try:
        conn = get_db_connection()
        cursor = conn.cursor()

        # Récupérer l'état de chaque casier
        cursor.execute("SELECT id_casier, taille, poids_max, etat, code, id_commande, date_occupation FROM casiers")
        casiers = cursor.fetchall()

        cursor.close()
        conn.close()

        return jsonify({"status": "success", "casiers": casiers})

    except Exception as e:
        return jsonify({"status": "error", "message": str(e)}), 500


@app.route('/afficher_livreurs', methods=['GET'])
def afficher_livreurs():
    try:
        conn = get_db_connection()
        cursor = conn.cursor()

        # Récupérer les informations des livreurs depuis la table 'livreurs'
        cursor.execute("SELECT id, nom, prenom, adresse, username, password, statut FROM livreurs")
        livreurs = cursor.fetchall()

        cursor.close()
        conn.close()

        return jsonify({"status": "success", "livreurs": livreurs})

    except Exception as e:
        return jsonify({"status": "error", "message": str(e)}), 500


@app.route('/supprimer_livreur', methods=['POST'])
def supprimer_livreur():
    data = request.json
    livreur_id = data.get("id")

    if not livreur_id:
        return jsonify({"status": "error", "message": "ID du livreur manquant"}), 400

    try:
        conn = get_db_connection()
        cursor = conn.cursor()

        # Vérifier si le livreur existe
        cursor.execute("SELECT * FROM livreurs WHERE id = %s", (livreur_id,))
        livreur = cursor.fetchone()
        if not livreur:
            return jsonify({"status": "error", "message": "Livreur introuvable"}), 404

        # Supprimer le livreur
        cursor.execute("DELETE FROM livreurs WHERE id = %s", (livreur_id,))
        conn.commit()

        return jsonify({"status": "success", "message": "Livreur supprimé avec succès !"})

    except Exception as e:
        return jsonify({"status": "error", "message": str(e)}), 500

    finally:
        cursor.close()
        conn.close()

@app.route('/attribuer_livreur', methods=['POST'])
def attribuer_livreur():
    data = request.json
    commande_id = data.get("commande_id")
    livreur_id = data.get("livreur_id")

    if not commande_id or not livreur_id:
        return jsonify({"status": "error", "message": "Commande ID ou Livreur ID manquant"}), 400

    try:
        conn = get_db_connection()
        cursor = conn.cursor()

        cursor.execute("SELECT * FROM commandes WHERE id = %s", (commande_id,))
        commande = cursor.fetchone()
        if not commande:
            return jsonify({"status": "error", "message": "Commande introuvable"}), 404

        cursor.execute("SELECT * FROM livreurs WHERE id = %s", (livreur_id,))
        livreur = cursor.fetchone()
        if not livreur:
            return jsonify({"status": "error", "message": "Livreur introuvable"}), 404

        cursor.execute("UPDATE commandes SET livreur_id = %s, statut = 'en attente de confirmation' WHERE id = %s", (livreur_id, commande_id))
        cursor.execute("UPDATE livreurs SET statut = 'en attente de confirmation' WHERE id = %s", (livreur_id,))
        conn.commit()

        cursor.close()
        conn.close()

        return jsonify({"status": "success", "message": "Livreur attribué à la commande, en attente de validation par le livreur."})

    except Exception as e:
        return jsonify({"status": "error", "message": str(e)}), 500



@app.route('/livreur/repondre_commande', methods=['POST'])
def repondre_commande():
    data = request.json
    commande_id = data.get("commande_id")
    livreur_id = data.get("livreur_id")
    reponse = data.get("reponse")  # "accepter" ou "refuser"

    if not commande_id or not livreur_id or not reponse:
        return jsonify({"status": "error", "message": "Données manquantes"}), 400

    try:
        conn = get_db_connection()
        cursor = conn.cursor()

        cursor.execute("SELECT * FROM commandes WHERE id = %s AND livreur_id = %s", (commande_id, livreur_id))
        commande = cursor.fetchone()
        if not commande:
            return jsonify({"status": "error", "message": "Commande non attribuée à ce livreur"}), 404

        if reponse == "accepter":
            cursor.execute("UPDATE commandes SET statut = 'en cours' WHERE id = %s", (commande_id,))
            cursor.execute("UPDATE livreurs SET statut = 'en cours de livraison' WHERE id = %s", (livreur_id,))
            conn.commit()
            message = "Commande acceptée, mise à jour des statuts effectuée."

        elif reponse == "refuser":
            cursor.execute("UPDATE commandes SET livreur_id = NULL, statut = 'en attente' WHERE id = %s", (commande_id,))
            cursor.execute("UPDATE livreurs SET statut = 'disponible' WHERE id = %s", (livreur_id,))
            conn.commit()
            message = "Commande refusée, en attente d'un autre livreur."

        else:
            return jsonify({"status": "error", "message": "Réponse invalide"}), 400

        cursor.close()
        conn.close()

        return jsonify({"status": "success", "message": message})

    except Exception as e:
        return jsonify({"status": "error", "message": str(e)}), 500


# Route pour afficher les commandes attribuées à un livreur
@app.route('/livreur/commandes_attribuees/<int:livreur_id>', methods=['GET'])
def commandes_attribuees(livreur_id):
    print(f"Livreur ID reçu : {livreur_id}")  # Log de l'ID pour vérifier
    try:
        conn = get_db_connection()
        cursor = conn.cursor()  # Retire l'argument 'dictionary' de ici

        cursor.execute("""
            SELECT id, client_email, taille_casier
            FROM commandes
            WHERE livreur_id = %s
        """, (livreur_id,))

        commandes = cursor.fetchall()

        return jsonify({"status": "success", "commandes": commandes})

    except Exception as e:
        return jsonify({"status": "error", "message": str(e)}), 500

    finally:
        cursor.close()
        conn.close()





if __name__ == '__main__':
    app.run(debug=True, port=5000)