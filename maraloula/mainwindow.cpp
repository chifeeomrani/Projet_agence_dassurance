#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contrats.h"
#include <QDebug>
#include <QDate>
#include <QAbstractItemModel>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQueryModel>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table_as->setModel(C.AfficherContrats());
    ui->table_as->setColumnWidth(0, 80);
    ui->table_as->setColumnWidth(2, 100);
    ui->table_as->setColumnWidth(3, 100);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_36_clicked()
{
ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_2_clicked()
{
    QModelIndex index=ui->table_as->currentIndex();
    int i=index.row();
    QModelIndex in=index.sibling(i,0);
    int val=ui->table_as->model()->data(in).toInt();
    contrats S2;
    bool test=S2.SupprimerContrats(val);
    ui->table_as->setModel(C.AfficherContrats());
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("suppression effectué:\n"
                                             "Cliquez sur Annuler pour quitter."),
                                 QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("suppression non effectué:\n"
                                          "Cliquez sur Annuler pour quitter."),
                              QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_clicked()
{
    int ID_S =ui->id->text().toInt();
    QDate Dispo_de =ui->date_a->date();
    QString nom =ui->NomC->text();
    QString prenom =ui->Prenom_1->text();
    QString adress =ui->adresse->text();
    QString add =ui->Add_1->text();
    QString type =ui->typeaa->currentText();

    contrats S1(ID_S, Dispo_de, nom, prenom, adress, add,type );
    bool test = S1.ModifierContrats();
       ui->table_as->setModel(C.AfficherContrats());
    if (test)
    {
        // Si l'ajout est réussi, affichez les valeurs dans le message d'information.
        QMessageBox::information(this, tr("OK"),
                                 tr("modification effectué:\n"
                                    "Cliquez sur Annuler pour quitter."));
    }
    else
    {
        // En cas d'échec, affichez également les valeurs.
        QMessageBox::critical(this, tr("Erreur"),
                               tr("modification non effectué:\n"
                                  "Cliquez sur Annuler pour quitter."));
    }

}
void MainWindow::on_Ajouter_clicked()
{
    int ID_S =ui->id->text().toInt();
    QDate Dispo_de =ui->date_a->date();
    QString nom =ui->NomC->text();
    QString prenom =ui->Prenom_1->text();
    QString adress =ui->adresse->text();
    QString add =ui->Add_1->text();
    QString type =ui->typeaa->currentText();

    contrats S(ID_S, Dispo_de, nom, prenom, adress, add,type );
    bool test = S.AjouterContrats();
      ui->table_as->setModel(C.AfficherContrats());
    if (test)
    {
        // Si l'ajout est réussi, affichez les valeurs dans le message d'information.
        QMessageBox::information(this, tr("OK"),
                                 tr("Ajout effectué:\n"
                                    "Cliquez sur Annuler pour quitter."),
                        QMessageBox::Cancel);
    }
    else
    {
        // En cas d'échec, affichez également les valeurs.
        QMessageBox::critical(this, tr("Erreur"),
                               tr("Ajout non effectué:\n"
                                  "Cliquez sur Annuler pour quitter."),
                      QMessageBox::Cancel);
    }
}
void MainWindow::on_table_as_activated(const QModelIndex &index)
{
   int row =index.row();
   QModelIndex col1 =index.sibling(row,0);
   QModelIndex col2 =index.sibling(row,1);
   QModelIndex col3 =index.sibling(row,2);
   QModelIndex col4 =index.sibling(row,3);
   QModelIndex col5 =index.sibling(row,4);
   QModelIndex col6 =index.sibling(row,5);
   QString data1 =  ui->table_as->model()->data(col1).toString();
   QDate data2=  ui->table_as->model()->data(col2).toDate();
   QString data3=  ui->table_as->model()->data(col3).toString();
   QString data4=  ui->table_as->model()->data(col4).toString();
   QString data5=  ui->table_as->model()->data(col5).toString();
   QString data6=  ui->table_as->model()->data(col6).toString();
   ui->id->setText(data1);
   ui->date_a->setDate(data2);
   ui->NomC->setText(data3);
   ui->Prenom_1->setText(data4);
   ui->adresse->setText(data5);
   ui->Add_1->setText(data6);

}
