# 🖥️ Serveur TCP Simple en C

Un serveur TCP basique écrit en C qui écoute sur le port `4444`, reçoit un message d'un client et renvoie une réponse de bienvenue. Ce projet est conçu à des fins **éducatives** pour comprendre les fondamentaux des sockets réseau, la programmation système et les bases des communications client-serveur.

> 💡 **Note** : Le port `4444` est historiquement connu dans le domaine de la cybersécurité (souvent utilisé par défaut par des outils comme Metasploit). Ici, il est utilisé uniquement pour illustrer le fonctionnement d'un bind classique dans un cadre d'apprentissage du hacking éthique.

## 🚀 Fonctionnalités

- Création d'une socket IPv4 avec le protocole TCP.
- Liaison (*bind*) du serveur sur toutes les interfaces locales (`INADDR_ANY`) au port 4444.
- Mise en écoute (*listen*) et acceptation des connexions entrantes.
- Lecture sécurisée des données envoyées par le client (avec gestion du caractère nul `\0`).
- Envoi d'un message de bienvenue au client.
- Gestion propre des erreurs et fermeture des descripteurs de fichiers (*cleanup*).

## 📋 Prérequis

Pour compiler et exécuter ce code, vous avez besoin d'un compilateur C. 
Si vous utilisez **Termux sur Android** (sans accès à un PC), voici comment installer les outils nécessaires :

```bash
# Mettre à jour les paquets
pkg update && pkg upgrade

# Installer le compilateur Clang (équivalent de GCC sur Termux) et netcat pour les tests
pkg install clang netcat-openbsd
