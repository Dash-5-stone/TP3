#ifndef COMMANDE_H
#define COMMANDE_H
#include "Client.h"
#include "Produit.h"
#include <vector>
#include <string>
#include <iostream>

class Commande{
private:
   Client client_;
   std::vector<Produit> produitCommander_;
   bool statutCommande_;
public:
    Commande(Client client, std::vector<Produit> produitCommander, bool statutCommande);
    Client getClient();
    std::vector<Produit> getProduitCommander();
    bool getStatutCommande();
    void setClient(Client client);
    void setStatutCommande(bool statutCommande);
    void setProduitCommander(std::vector<Produit> poduitCommander);
};






#endif