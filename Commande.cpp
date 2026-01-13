#include "Commande.h"
#include <iostream>
#include "Produit.h"
#include <string>


Commande::Commande(Client client, std::vector<Produit> produitCommander,bool statut):client_(client),produitCommander_(produitCommander),statutCommande_(statut){};

Client Commande::getClient(){
    return client_;
}
std::vector<Produit> Commande::getProduitCommander(){
    return produitCommander_;
}
bool Commande::getStatutCommande(){
    return statutCommande_;
}
void Commande::setStatutCommande(bool statutCommande){
    statutCommande_=statutCommande;
}
void Commande::setClient(Client client){
    client_=client;
}
void Commande::setProduitCommander(std::vector<Produit> produitCommander){
    produitCommander_=produitCommander;
}
