#include <iostream>
#include "Magasin.h"
#include <string>
#include "Produit.h"

Magasin::Magasin(){

}
std::vector<Commande> Magasin::getCommande(){
return commandes_;
}
std::vector<Client> Magasin::getClient(){
return clients_;
}
std::vector<Produit> Magasin::getProduit(){
return produits_;
}

void Magasin::setProduit(std::vector<Produit> produit){
produits_=produit;
}
void Magasin::setCommande(std::vector<Commande> commande){
commandes_=commande;
}
void Magasin::setClient(std::vector<Client> client){
    clients_=client;
}

void Magasin::ajouterProduit(Produit produit){
produits_.push_back(produit);
}
void Magasin::afficherProduits(){
    for(Produit& p: produits_){
std::cout << p << std::endl;
    }
}
void Magasin::afficherProduitParNom(std::string nom){
for(Produit& p : produits_){
    if (p.getTitre()==nom)
    {
       std::cout<< p <<std::endl;
    }
}
}

void Magasin::mettreJourQuantite(std::string nom,int quantite){
    for(Produit& p: produits_){
        if(p.getTitre()==nom){
            p.setQuantite(quantite);
        }
    }
}

