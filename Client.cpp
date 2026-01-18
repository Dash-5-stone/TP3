#include "Client.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "Produit.h"

Client::Client(std::string identifiant,std::string prenom,std::string nom,std::vector<Produit> panier):identifiant_(identifiant),prenom_(prenom),nom_(nom),panier_(panier){};

std::string Client::getIdentifiant() const{
    return identifiant_;
}
void Client::setIdentifiant(std::string identifiant){
    identifiant_=identifiant;
}
std::string Client::getPrenom() const{
    return prenom_;
}
std::string Client::getNom() const{
    return nom_;
}
// std::vector<Produit>& Client::getPanier() const{
//     return panier_;
// }
std::vector<Produit>& Client::getPanier() {
    return panier_;
}
void Client::setPrenom(std::string prenom){
    prenom_=prenom;
}
void Client::setNom(std::string nom){
    nom_=nom;
}

void Client::setPanier(std::vector<Produit> panier){
    panier_=panier;
}



void Client::supprimerProduit(Client& client, const Produit& produit) {
    client.panier_.erase(
        std::remove_if(client.panier_.begin(), 
                       client.panier_.end(), 
                       [&produit](const Produit& p) {
                           return p.getTitre() == produit.getTitre();
                       }), 
        client.panier_.end()
    );
}

void Client::viderPanier(std::vector<Produit>& panier){
panier.clear();
std::cout << "Panier vider avec succes !" << std::endl;
}
    
void Client::modifierQuantitePanier(std::string titre, int quantite){
for (size_t i = 0; i < panier_.size(); i++)
{
   if(panier_[i].getTitre()==titre){
    panier_[i].setQuantite(quantite);
   }else{
    std::cout << "Aucun panier n'a ce titre" << std::endl;
   }
}

}



std::ostream& operator<<(std::ostream& os, Client& client){
    os<< "Identifiant : " << client.getIdentifiant()<< " Prenom : "<< client.getPrenom()<< " Nom : "<< client.getNom()<< " Panier : " ;
    for(Produit& p:client.panier_){
        std::cout << p << std::endl;
    }
     
}
