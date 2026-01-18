#include "Produit.h"
#include <iostream>
#include <string>


Produit::Produit(std::string titre,std::string description, int quantite, double prixUnitaire, bool disponible):titre_(titre),description_(description),quantite_(quantite),prixUnitaire_(prixUnitaire),disponible_(disponible){};

std::string Produit::getTitre() const{
    return titre_;
}
void Produit::setTitre(std::string titre){
    titre_=titre;
}
std::string Produit::getDescription() const{
    return description_;
}
void Produit::setDescription(std::string description){
    description_=description;
}
void Produit::setQuantite(int quantite){
    quantite_=quantite;
}
int Produit::getQuantite() const{
    return quantite_;
}
 bool Produit::getDisponible() const{
    return disponible_;
 }
  bool Produit::setDisponible(bool disponible){
     disponible_=disponible;
 }

std::ostream& operator<<(std::ostream& os, Produit& produit){
    os<< " Titre : "<<produit.getTitre() << " Description : "<< produit.getDescription()
    << " Quantite : "<< produit.getQuantite() <<" Disponibilite : ";
    if(produit.getDisponible()){ os << " Disponible ";}else{os << " Non disponible ";}


}

