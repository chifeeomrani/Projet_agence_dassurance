#ifndef CONTRATS_H
#define CONTRATS_H
#include <QDate>
#include <QString>
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include "connection.h"
#include <QDate>
class contrats
{
public:
    contrats();
    contrats(int id, QDate DateSignature, QString Prenom, QString Nom, QString Adresse, QString AdDest, QString Type_Dassurance);
    //getter
    int getID();
    QDate getDateSignature();
    QString getPrenom();
    QString getNom();
    QString getAdresse();
    QString getAdDest();
    QString getType_Dassurance();
    //setter
    void setID(int id);
    void setDateSignature(QDate DateSignature);
    void setPrenom(QString Prenom);
    void setNom(QString Nom);
    void setAdresse(QString Adresse);
    void setAdDest(QString AdDest);
    void setTypeDassurance(QString Type_Dassurance);



    bool AjouterContrats();
    QSqlQueryModel *AfficherContrats();
    bool ModifierContrats();
    bool SupprimerContrats(int val);
private:
    int id;
    QDate DateSignature;
    QString Prenom;
    QString Nom;
    QString Adresse;
    QString AdDest;
    QString Type_Dassurance;
};

#endif // CONTRATS_H
