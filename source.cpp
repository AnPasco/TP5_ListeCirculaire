#include <iostream>
#include "maillon.h"

using namespace std;

//Procedure qui affiche le menu
void menu() {
    cout << endl << "1 - Ajouter un maillon" << endl;
    cout << "2 - Consulter la file" << endl;
    cout << "3 - Faire une rotation d'un cran de la file" << endl;
    cout << "4 - Calculer le nombre de maillon" << endl;
    cout << "5 - Quitter" << endl;
}

void initMaillon(Maillon *maillon) {
    maillon->numero = 0;
    maillon->suivant = nullptr;
}

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
