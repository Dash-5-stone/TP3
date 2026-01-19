#include <iostream>
#include "Magasin.h"
#include "Client.h"
#include <string>
#include "Produit.h"
#include "Commande.h"
#include <algorithm>
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
void Magasin::ajouterClient(Client client){
 clients_.push_back(client);
}

void Magasin::afficherClientMagasin(){
for(Client& c:clients_){
    std::cout << c << std::endl;
} 
}

void Magasin::afficherClientMagasin(std::string nom){
    for(Client& c:clients_){
        if(c.getNom()==nom){
            std::cout << c <<std::endl;
        }
    }
}

void Magasin::ajouterProduitPanier(Produit& produit, Client& client){
        client.getPanier().push_back(produit);

}

void Magasin::supprimerProduitPanier(Produit& produit, Client& client){
for(size_t i=0 ; i<client.getPanier().size();i++){
if(client.getPanier()[i].getTitre()==produit.getTitre()){
   client.getPanier().erase(client.getPanier().begin() + i);
   return;
}
}
}

void Magasin::modifierQuantitePanier(int& quantite, Produit& produit, Client& client){
    for (size_t i = 0; i < client.getPanier().size(); i++)
    {
        if(client.getPanier()[i].getTitre()==produit.getTitre()){
            client.getPanier()[i].setQuantite(quantite);
            return;
        }
    }
    
}

void Magasin::validerCommande(Client& client){
for (size_t i = 0; i < client.getPanier().size(); i++)
{
    if (client.getPanier()[i].getDisponible() && client.getPanier()[i].getTitre()== produits_[i].getTitre() && client.getPanier()[i].getQuantite()<=produits_[i].getQuantite())
    {
        std::cout << "Commande valider";
    }else{
        std::cout << "Commande invalide";
    }
    
}

}
void Magasin::mettreJourStatut(Commande& commande, bool statut){
commande.setStatutCommande(statut);
    
}
void Magasin::afficherCommandePasser(Commande& commande){
    for(size_t i=0; i<commande.getProduitCommander().size();i++){
        std::cout << commande.getProduitCommander()[i];
    }
}

void Magasin::afficherCommande(Commande& commande, Client& client){
   for(size_t i=0; i<commande.getProduitCommander().size();i++){
    if (commande.getProduitCommander()[i].getTitre()==client.getPanier()[i].getTitre())
    {
        std::cout << commande.getProduitCommander()[i];
    }
        
    }
}