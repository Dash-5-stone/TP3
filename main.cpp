#include "Magasin.h"
#include "Client.h"
#include "Produit.h"
#include "Commande.h"

int main(){
    Magasin magasin();
int choix;
do{
std::cout << "Gestion du magasin";
std::cout << "1. Ajouter un produit";
std::cout << "2. Afficher les produits";
std::cout << "3. mettre a jour les quantites";
std::cout << "0. retour au menu principal";
std::cout << "Choix : ";
std::cin >> choix ;

switch (choix) {
            case 1: {
            std::string nom,description;
    double prix;
    int qte;
    std::cout << "Nom du produit : ";
    std::cin.ignore();
    std::getline(std::cin, nom);
    std::cout << "Description : ";
    std::getline(std::cin, description);

    std::cout << "Prix : ";
    std::cin >> prix;
    std::cout << "quantite : ";
    std::cin >> qte;
  std::cout << "disponible : ";
    std::cin >> ;
    Produit p(nom,description,qte,prix,dispo);

        }
    } while (choix != 0);

    return 0;
}
}