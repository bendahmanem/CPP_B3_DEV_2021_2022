#include <iostream>
#include "constantes.h"

using namespace std;
/************************************************************************************************************************************************/

// il faut passer une référence
enum class ChoixMenu
{
    JOUER = 'a',
    JOUER_FACILE = 'b',
    JOUER_TROIS_PARTIES = 'c',
    QUITTER = 'q',
    INCORRECT
};


ChoixMenu demanderChoixMenu()
{
    char saisieChoix;
    cin >> saisieChoix;
    // on met a jour la condition demander choix menu
    if (saisieChoix == static_cast<char>(ChoixMenu::JOUER) || saisieChoix == static_cast<char>(ChoixMenu::JOUER_FACILE) || saisieChoix == static_cast<char>(ChoixMenu::JOUER_TROIS_PARTIES) || saisieChoix == static_cast<char>(ChoixMenu::QUITTER))
    {
        return static_cast<ChoixMenu>(saisieChoix);
    }
    else
    {
        return ChoixMenu::INCORRECT;
    }
}

void demanderProposition(int &proposition)
{
    cin >> proposition;
    // ici on passe la référence
}

void jouerPartie(int leJustePrix, int max)
// type pour le paramètre, pas auto, on remplace les occurrences de aDeviner par leJustePrix
{
    auto proposition{0};
    auto nombreTentatives{0};
    do
    {
        // comme dans tous les langages l'intérêt des fonctions est de pouvoir réutiliser le code
        cout << "Proposition? ";
        demanderProposition(proposition);

        cout << proposition;

        if (proposition >= BORNE_MIN && proposition < max)
        {
            nombreTentatives++;
            if (proposition == leJustePrix)
            {
                cout << "Bravo! " << endl;
            }
            else if (proposition > leJustePrix)
            {
                cout << "C'est moins ! " << endl;
            }
            else
            {
                cout << "C'est plus ! " << endl;
            }
        }
    } while (proposition != leJustePrix && proposition >= BORNE_MIN);

    if (proposition == leJustePrix)
    {
        cout << "partie terminée! "
             << "en " << nombreTentatives << " tentatives" << endl;
    }
    else
    {
        cout << "partie abandonnée ";
    }
}

// ici on ne souhaite pas retourner de valeur on utilise void
void jouerTroisParties()
{
    cout << "C'est parti ! " << endl;
    for (auto aDeviner : {208, 42, 1984})
    {
        // on veut la paramétrer avec le nombre a deviner
        jouerPartie(aDeviner, BORNE_MAX);
    }
}

void afficherMenu()
{
    cout << static_cast<char>(ChoixMenu::JOUER) << ": jouer" << endl;
    // on ajoute les choix possible à l'affichage
    cout << static_cast<char>(ChoixMenu::JOUER_FACILE) << ": jouer" << endl;
    cout << static_cast<char>(ChoixMenu::JOUER_TROIS_PARTIES) << ": jouer" << endl;
    cout << static_cast<char>(ChoixMenu::QUITTER) << ": quitter" << endl;
}

int main()
{
    const auto BORNE_MIN{0};
    const auto BORNE_MAX{10'000};
    cout << "Bienvenue au juste prix" << endl;

    // on créé un booléen continuer
    bool continuer(true);
    // ici on insert la boucle while
    while (continuer)
    {
        afficherMenu();
        // ici lorsqu'on initialise une var avec le result d'un func on utilise =
        auto choix = demanderChoixMenu();
        switch (choix)
        {
            // on met à jour le switch aussi
        case ChoixMenu::JOUER:
            jouerPartie(3000, BORNE_MAX);
            break;
        case ChoixMenu::JOUER_FACILE:
            jouerPartie(250, BORNE_MAX_FACILE);
            break;
        case ChoixMenu::JOUER_TROIS_PARTIES:
            jouerTroisParties();
            break;
        case ChoixMenu::QUITTER:
            cout << "Au revoir " << endl;
            // on met variable continuer a false afin de pouvoir sortir de la boucle
            continuer = false;
            break;
        case ChoixMenu::INCORRECT:
        default:
            return EXIT_FAILURE;
        }
    }
    // rigoureusement on devrait ajouter ceci
    return EXIT_SUCCESS;
}

/******/

// créer un fichier constantes.h et cocher debug et release
// et enregistrer le projet !!! très important pour la compilation
// création de trois lignes par défaut directives préprocesseur, ici on évite de déclare plusieurs fois le contenu de notre fichier

// à cet endroit le nom de la constante que nous allons utiliser doit être unique dans l'ensemble de tout notre programme

// #pragma once on verra plus tard

// on passe au dossier !!!
