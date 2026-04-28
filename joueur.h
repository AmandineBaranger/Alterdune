#ifndef PROJETA3S6_JOUEUR_H
#define PROJETA3S6_JOUEUR_H

#include "entite.h"
#include "item.h"
#include <vector>
#include <string>

class Monstre; // Déclaration anticipée pour éviter les dépendances circulaires
class ActionAct;

class Joueur : public Entite {
private:
    int monstresTues;
    int monstresEpargnes;
    int victoires;
    std::vector<Item> inventaire; // Composition : le joueur possède un inventaire d'objets

public:
    Joueur(std::string nomEntite, int hp);

    // Méthodes de combat
    void attaquer(Monstre& cible);
    void agirACT(Monstre& cible, ActionAct action);
    void epargnerMercy(Monstre& cible);
    
    // Gestion de l'inventaire (Requis pour la Partie 1)
    void ajouterItem(Item objet);
    void afficherInventaire();
    void utiliserItem(int index); // Utilise l'objet à l'index donné dans le vecteur

    // Accesseurs (Getters) pour les statistiques et les conditions de fin
    int getVictoires();
    int getMonstresTues();
    int getMonstresEpargnes();
    std::vector<Item>& getInventaire(); // Permet au Jeu d'accéder aux items
};

#endif