# Projet-10-Informatique : Analyseur de Texte et Gestionnaire de Mots

## Description du Projet

Ce programme en langage C est un analyseur lexical hautement modulaire et performant, offrant une exploration linguistique précise et dynamique. Il permet de :
- Créer et écrire des fichiers texte
- Analyser des fichiers texte existants
- Calculer des statistiques linguistiques
- Suivre la fréquence des mots
- Rechercher la fréquence d'un mot spécifique

## Caractéristiques Clés
- Allocation mémoire dynamique
- Flexibilité de redimensionnement
- Gestion optimisée de la mémoire

## Fonctionnalités Principales

1. **Création de Fichier Texte**
   - Permet de créer un nouveau fichier texte interactivement et de manière dynamique
   - Possibilité de saisir du contenu ligne par ligne
   - Arrêt de la saisie avec la commande 'FIN'

2. **Analyse de Fichier**
   - Calcul du nombre de lignes
   - Calcul du nombre de mots
   - Calcul du nombre de caractères
   - Conversion automatique des mots en minuscules

3. **Gestion des Mots**
   - Comptage de la fréquence des mots
   - Tri et affichage des mots les plus fréquents
   - Recherche de la fréquence d'un mot spécifique

4. **Sauvegarde des Statistiques**
   - Option de sauvegarde des statistiques dans un fichier

## Gestion Avancée des Erreurs
- Mécanismes de Sécurité
- Vérification systématique des allocations
- Gestion des dépassements de capacité
- Arrêts contrôlés en cas d'erreurs critiques

## Détails d'Implémentation

1. **Analyse de Fichier Sophistiquée**
- Comptage précis des lignes
- Détection dynamique des mots
- Gestion des fichiers sans saut de ligne final

2. **Algorithmes Spécialisés**

- Tri par fréquence descendante
- Conversion uniforme en minuscules
- Détection et agrégation des occurrences

## Prérequis

- Compilateur C (gcc recommandé)
- Système d'exploitation compatible avec les bibliothèques standard C

## Compilation

```bash
gcc -o analyseur_texte Projet_10_version_definitive.c