#include <iostream>
#include "maillon.h"

using namespace std;

int main() {

    int choix, num;
    Maillon *np;
    np = (Maillon *) malloc(sizeof(Maillon));

    initMaillon(np);

    cout << "******************** LISTE CIRCULAIRE ********************" << endl;
    menu();
    cout << "Choisissez une option :" << endl;
    cin >> choix;

    while (choix != 5) {

        switch (choix) {
            case 1 :
                cout << "Quel numero voulez vous ajouter ?" << endl;
                cin >> num;
                ajouterMaillon(np, num);
                break;
            case 2:
                afficherMaillon(np);
                break;
            case 3 :
                faireAvancerMaillon(np);
                break;
            case 4:
                cout << "Il y a " << nbMaillon(np) << " maillon(s) dans la file." << endl;
                break;
            default:
                cout << "A plus !";
                return 0;
                break;
        }
        menu();
        cout << "Choisissez une option :" << endl;
        cin >> choix;
    }

    desinitMaillon(np);

}