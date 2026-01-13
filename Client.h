#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <iostream>
#include <vector>
#include "Produit.h"


class Client
{
private:
    std::string identifiant_;
    std::string prenom_;
    std::string nom_;
    std::vector<Produit> panier_;

public:
    Client(std::string identifiant_, std::string prenom,std::string nom,std::vector<Produit> panier);
    std::string getIdentifiant() const;
    void setIdentifiant(std::string identifiant);
    std::string getPrenom()const ;
    std::string getNom() const;
std::vector<Produit> getPanier() const;
void setPrenom(std::string prenom);
void setNom(std::string nom);
void setPanier(std::vector<Produit> panier);
void viderPanier(std::vector<Produit>& panier);
void validerCommande();

void supprimerProduit(Client& client, const Produit& produit);




};








#endif