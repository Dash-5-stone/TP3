#ifndef PRODUIT_H
#define PRODUIT_H
#include <iostream>
#include <string>

class Produit
{
private:
    std::string titre_;
    std::string description_;
    int quantite_;
    double prixUnitaire_;
    bool disponible_;
public:
    Produit(std::string titre, std::string description, int quantite, double prixUnitaire,bool disponible);
    std::string getTitre() const;
    void setTitre(std::string titre);
    std::string getDescription() const;
    void setDescription(std::string description);
    int getQuantite() const;
    void setQuantite(int quantite) const;
    bool getDisponible() const;
    bool setDisponible(bool disponible);

friend std::ostream& operator<<(std::ostream& os , Produit& produit);


};








#endif