#ifndef MAGASIN_H
#define MAGASIN_H
#include "Produit.h"
#include "Client.h"
#include "Commande.h"
#include <vector>
#include <string>
#include <iostream>
class Magasin
{
private:
   std::vector<Produit> produits_;
std::vector<Client> clients_;
std::vector<Commande> commandes_;
public:
  
    Magasin();
    void ajouterProduit(Produit produit);
std::vector<Commande> getCommande();
std::vector<Client> getClient();
std::vector<Produit> getProduit();
void setProduit(std::vector<Produit> produits);
void setCommande(std::vector<Commande> Commande);
void setClient(std::vector<Client> client);
void afficherProduits();
void afficherProduitParNom(std::string nom);
void mettreJourQuantite(std::string nom,int quantite);
void ajouterClient(Client client);
void afficherClientMagasin();

void afficherClientMagasin(std::string nom);
void ajouterProduitPanier(Produit& produit);
void ajouterProduitPanier(Produit& produit, Client& client);
void supprimerProduitPanier(Produit& produit, Client& client);
void modifierQuantitePanier(int& quantite, Produit& produit, Client& client);
void validerCommande(Client& client);

void mettreJourStatut(Commande& commande, bool statut);

void afficherCommandePasser(Commande& commande);
void afficherCommande(Commande& commande, Client& client);

void sauvegarderDonnees(std::string nomFichierProduits);
void chargerProduits(std::string nomFichier);
};















#endif