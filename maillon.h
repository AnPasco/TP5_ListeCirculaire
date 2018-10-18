//
// Created by Antoine on 15/10/2018.
//

#ifndef TP55_MAILLON_H
#define TP55_MAILLON_H

typedef struct Maillon {
    int numero;
    Maillon *suivant;
} Maillon;

void initMaillon(Maillon *maillon);

void ajouterMaillon(Maillon *np, int numero);

int nbMaillon(Maillon *np);

void afficherMaillon(Maillon *np);

void faireAvancerMaillon(Maillon *np);

void menu();

void desinitMaillon(Maillon *maillon);

#endif //TP55_MAILLON_H
