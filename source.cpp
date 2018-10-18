#include <iostream>
#include "maillon.h"

using namespace std;

//Procédure qui affiche le menu
void menu() {
    cout << endl << "1 - Ajouter un maillon" << endl;
    cout << "2 - Consulter la file" << endl;
    cout << "3 - Faire une rotation d'un cran de la file" << endl;
    cout << "4 - Calculer le nombre de maillon" << endl;
    cout << "5 - Quitter" << endl;
}

//Procédure qui initialise un maillon
//Paramètre d'entrée : maillon
//Paramètre de sortie : maillon
//Post condition : un maillon initialisé
void initMaillon(Maillon *maillon) {
    maillon->numero = 0;
    maillon->suivant = nullptr;
}

//Procédure qui désinitialise un maillon
//Paramètre d'entrée : maillon
//Paramètre de sortie : maillon
//Post condition : un maillon vide
void desinitMaillon(Maillon *maillon) {
    if (maillon->suivant == nullptr) {
        free(maillon);
    } else {
        Maillon *actuelle, *premier, *suppr;
        premier = (Maillon *) malloc(sizeof(Maillon));
        actuelle = (Maillon *) malloc(sizeof(Maillon));
        suppr = (Maillon *) malloc(sizeof(Maillon));
        premier = maillon->suivant;
        actuelle = maillon->suivant->suivant;

        do {
            suppr = actuelle;
            actuelle = actuelle->suivant;
            free(suppr);
        } while (actuelle != premier);

        free(maillon);
    }
}

//Procédure qui ajoute un maillon dans la liste de maillon
//Paramètre d'entrée : maillon, numéro
//Paramètre de sortie : maillon
//Post condition : maillon ajouté dans la file juste avant le premier maillon
void ajouterMaillon(Maillon *np, int numero) {

    Maillon *newMaillon;
    newMaillon = (Maillon *) malloc(sizeof(Maillon));
    initMaillon(newMaillon);

    newMaillon->numero = numero;

    if (np->suivant == nullptr) {
        np->suivant = newMaillon;
        newMaillon->suivant = newMaillon;
        cout << "Ajout de : " << newMaillon->numero << endl;
    } else {

        int i = 0;
        int nb = nbMaillon(np);
        Maillon *maillonDernier;
        maillonDernier = (Maillon *) malloc(sizeof(Maillon));

        maillonDernier = np->suivant;

        while (i != nb - 1) {
            maillonDernier = maillonDernier->suivant;
            i++;
        }
        newMaillon->suivant = maillonDernier->suivant;
        maillonDernier->suivant = newMaillon;
        np->suivant = newMaillon;

        maillonDernier->suivant = newMaillon;
        cout << "Ajout de : " << newMaillon->numero << endl;
    }
}

//Fonction qui retourne le nombre de maillon présent dans la liste
//Paramètre d'entrée : maillon
//Retourne le nombre de maillon dans la file
int nbMaillon(Maillon *np) {

    int compt = 1;

    if (np->suivant == nullptr) {
        compt--;
        return compt;
    } else {
        Maillon *actuelle, *premier;
        premier = (Maillon *) malloc(sizeof(Maillon));
        actuelle = (Maillon *) malloc(sizeof(Maillon));
        premier = np->suivant;
        actuelle = np->suivant->suivant;

        while (actuelle != premier) {
            compt = compt + 1;
            actuelle = actuelle->suivant;
        }
        return compt;
    }
}

//Procédure qui affiche la liste de maillon
//Paramètre d'entrée : maillon
//Paramètre de sortie : maillon
//Post condition : affiche tout les maillons dans la liste
void afficherMaillon(Maillon *np) {
    if (np->suivant == nullptr) {
        cout << "Il n'y a pas de file !" << endl;
    } else {
        int i;
        Maillon *maillon;
        maillon = (Maillon *) malloc(sizeof(Maillon));
        maillon = np->suivant;

        for (i = 0; i < nbMaillon(np); i++) {
            cout << " | " << maillon->numero;
            maillon = maillon->suivant;
        }
        cout << " |" << endl;
    }
}

//Procédure qui fait avancer d'un cran le maillon pointeur
//Paramètre d'entrée : maillon
//Paramètre de sortie : maillon
//Post condition : fait avancer de un le maillon pointeur
void faireAvancerMaillon(Maillon *np) {
    if (np->suivant == nullptr) {
        cout << "La file est vide !" << endl;
    } else {
        Maillon *actuelle, *premier;
        premier = (Maillon *) malloc(sizeof(Maillon));
        actuelle = (Maillon *) malloc(sizeof(Maillon));
        premier = np->suivant;
        actuelle = np->suivant->suivant;

        if (actuelle == premier) {
            cout << "Rotation inutile !" << endl;
        } else {
            np->suivant = np->suivant->suivant;
            cout << " Rotation effectuee !" << endl;
        }
    }
}
