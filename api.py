from flask import Flask, request, jsonify
import pymysql
from flask_cors import CORS

app = Flask(__name__)
CORS(app)  # Autorise les requêtes de Qt vers l'API

# Connexion à la base de données
def get_db_connection():
    return pymysql.connect(
        host="localhost",  # Remplace par l'hôte de ta BD si nécessaire
        user="root",       # Remplace par ton utilisateur
        password="",       # Remplace par ton mot de passe
        database="locker", # Nom de ta base de données
        cursorclass=pymysql.cursors.DictCursor
    )

# Route pour l'authentification
@app.route('/login', methods=['POST'])
def login():
    data = request.json  # Récupération des données envoyées par Qt
    username = data.get("pseudo")  # Prendre le pseudo envoyé
    password = data.get("mdp")    # Prendre le mot de passe envoyé

    conn = get_db_connection()
    cursor = conn.cursor()

    # Vérification des identifiants dans la base de données
    sql = "SELECT * FROM commercants WHERE pseudo=%s AND mdp=%s"
    cursor.execute(sql, (username, password))
    user = cursor.fetchone()

    cursor.close()
    conn.close()

    if user:
        return jsonify({"status": "success", "message": "Connexion réussie"})
    else:
        return jsonify({"status": "error", "message": "Nom d'utilisateur ou mot de passe incorrect"})

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
        cursor.execute("SELECT nom, prenom, adresse, username, password, statut FROM livreurs")
        livreurs = cursor.fetchall()

        cursor.close()
        conn.close()

        return jsonify({"status": "success", "livreurs": livreurs})

    except Exception as e:
        return jsonify({"status": "error", "message": str(e)}), 500


if __name__ == '__main__':
    app.run(debug=True, port=5000)
