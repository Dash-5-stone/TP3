#include <iostream>
#include <fstream>
#include <vector>
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

void Magasin::sauvegarderDonnees(std::string fichierProduits){
    std::ofstream fichier(fichierProduits);
    if(fichier.is_open()){
        for (size_t i = 0; i < produits_.size(); i++)
        {
            fichier << produits_[i].getTitre() <<";"
            << produits_[i].getDescription() << ";"
            << produits_[i].getQuantite() << ";"
            << produits_[i].getQuantite()<<";"
            << produits_[i].getPrix() << ";" ;
        }
        
    }
}


void Magasin::sauvegarderDonnees(std::string nomFichierProduits) {
    std::ofstream fichier(nomFichierProduits);

    if (fichier.is_open()) {
           for (size_t i = 0; i < produits_.size(); i++) {
            fichier << produits_[i].getTitre() << ";"
                    << produits_[i].getDescription() << ";"
                    << produits_[i].getQuantite() << ";"
                    << produits_[i].getPrix() << "\n";
        }
        fichier.close();
        std::cout << "Sauvegarde reussie !" << std::endl;
    } else {
        std::cerr << "Erreur d'ouverture du fichier." << std::endl;
    }
}








void Magasin::chargerProduits(std::string nomFichier) {
    std::ifstream fichier(nomFichier); // "in file stream" pour lire
    std::string ligne;

    if (fichier.is_open()) {
        produits_.clear(); // On vide le magasin avant de charger

        while (std::getline(fichier, ligne)) {
            // On utilise un flux de chaîne pour découper la ligne
            std::stringstream ss(ligne);
            std::string titre, desc, tempQte, tempPrix;

            // On extrait chaque morceau entre les point-virgules
            std::getline(ss, titre, ';');
            std::getline(ss, desc, ';');
            std::getline(ss, tempQte, ';');
            std::getline(ss, tempPrix, ';');

            // On convertit les chaînes en nombres (std::stoi et std::stod)
            int qte = std::stoi(tempQte);
            double prix = std::stod(tempPrix);

            // On recrée l'objet et on l'ajoute au magasin
            Produit p(titre, desc, qte, prix);
            produits_.push_back(p);

        }
        fichier.close();
    }
}