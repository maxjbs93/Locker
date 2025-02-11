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

if __name__ == '__main__':
    app.run(debug=True, port=5000)
