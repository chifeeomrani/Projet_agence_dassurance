#include "contrats.h"
#include<QtDebug>
#include<QSqlQuery>
#include<QSqlError>
#include<QObject>
#include"connection.h"
contrats::contrats()
{
     Prenom="",Nom="",Adresse="",AdDest="", Type_Dassurance="";
     id=0;
     DateSignature=QDate::currentDate();
}
contrats::contrats(int id, QDate DateSignature, QString Prenom, QString Nom, QString Adresse, QString AdDest, QString Type_Dassurance)
{
    this->id=id; this->DateSignature=DateSignature; this->Prenom=Prenom; this->Nom=Nom; this->Adresse=Adresse; this->AdDest=AdDest; this->Type_Dassurance=Type_Dassurance;
}

//getter

int contrats::getID(){return id;}
QDate contrats::getDateSignature(){return DateSignature;}
QString contrats::getPrenom(){return Prenom ;}
QString contrats::getNom(){return Nom;}
QString contrats::getAdresse(){return Adresse;}
QString contrats::getAdDest(){return AdDest;}
QString contrats::getType_Dassurance(){return Type_Dassurance;}
//setter
void contrats::setID(int id){this->id=id;}
void contrats::setDateSignature(QDate DateSignature){this->DateSignature=DateSignature;}
void contrats::setPrenom(QString Prenom){this->Prenom=Prenom;}
void contrats::setNom(QString Nom){this->Nom=Nom;}
void contrats::setAdresse(QString Adresse){this->Adresse=Adresse;}
void contrats::setAdDest(QString AdDest){this->AdDest=AdDest;}
void contrats::setTypeDassurance(QString Type_Dassurance){this->Type_Dassurance=Type_Dassurance;}


bool contrats::AjouterContrats()
{
    bool test =false;
    QString p1=QString::number(id) ;
    QSqlQuery query;
    query.prepare("INSERT INTO CONTRAT (ID, DATESIGNATURE, PRENOM, NOM, ADRESSE,ADRESSEDUDESTINATAIRE,TYPE_DASSURANCE) VALUES (:ID, :DATESIGNATURE, :PRENOM, :NOM, :ADRESSE,:ADRESSEDUDESTINATAIR,:TYPE_DASSURANCE)");

    query.bindValue(":ID", p1);
    query.bindValue(":DATESIGNATURE", DateSignature);
    query.bindValue(":PRENOM", Prenom);
    query.bindValue(":NOM", Nom);
    query.bindValue(":ADRESSE", Adresse);
    query.bindValue(":ADRESSEDUDESTINATAIRE", AdDest);
    query.bindValue(":TYPE_DASSURANCE", Type_Dassurance);

    if(query.exec()) {
        test=true;
    }
    else{
        qDebug() <<"erreur :"<<query.lastError().text();
    }
    return test;
}
QSqlQueryModel *contrats::AfficherContrats()
{
    QSqlQueryModel *modal = new QSqlQueryModel();

    modal->setQuery("SELECT * FROM CONTRAT");
    modal->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    modal->setHeaderData(1, Qt::Horizontal, QObject::tr("DateSignature"));
    modal->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    modal->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom"));
    modal->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
    modal->setHeaderData(5, Qt::Horizontal, QObject::tr("AdresseDuDestinataire"));
    modal->setHeaderData(6, Qt::Horizontal, QObject::tr("Type_Dassurance"));
    return modal;
}
bool contrats::ModifierContrats()
{
    bool test =false;
    QString p1=QString::number(id) ;
    QSqlQuery query;
    query.prepare("UPDATE CONTRAT"" SET ID=:ID, DATESIGNATURE=:DATESIGNATURE, PRENOM=:PRENOM, NOM=:NOM, ADRESSE=:ADRESSE,ADRESSEDUDESTINATAIRE=:ADRESSEDUDESTINATAIRE,TYPE_DASSURANCE=:TYPE_DASSURANCE  WHERE ID ='"+p1+"' ");
    query.bindValue(":ID", p1);
    query.bindValue(":DATESIGNATURE", DateSignature);
    query.bindValue(":PRENOM", Prenom);
    query.bindValue(":NOM", Nom);
    query.bindValue(":ADRESSE", Adresse);
    query.bindValue(":ADRESSEDUDESTINATAIRE", AdDest);
    query.bindValue(":TYPE_DASSURANCE", Type_Dassurance);

    if(query.exec()) {
        test=true;
    }
    else{
        qDebug() <<"erreur :"<<query.lastError().text();
    }
    return test;
}
bool contrats::SupprimerContrats(int id)
{
    bool test =false;
    QString p1=QString::number(id) ;
    QSqlQuery query;

    query.prepare("DELETE FROM CONTRAT WHERE ID = :ID");
    query.bindValue(":ID", p1);

    if(query.exec()) {
        test=true;
    }
    else{
        qDebug() <<"erreur :"<<query.lastError().text();
    }
    return test;
}
