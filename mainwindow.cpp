#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>

typedef struct
{
  int   id;
  char  nom[40];
  char  email[40];
} ELEMENT;

ELEMENT Elm[] = 
{ 
  {0,"",""},
  {1,"aaa","aaa@gmail.com"},
  {2,"bbb","bbb@gmail.com"},
  {3,"ccc","ccc@gmail.com"},
  {4,"ddd","ddd@gmail.com"},
  {5,"eee","eee@gmail.com"},
  {0,"",""}
};

int cpt=1; //ajouter une variable globale qui serait un int (compteur)


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  //***** A modifier ***********************
  setNom(Elm[cpt].nom); //remplacer le 1 par compteur //Affiche le nom et mail de l'utilisateur
  setEmail(Elm[cpt].email);
  //****************************************
}

MainWindow::~MainWindow()
{
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles : ne pas modifier /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::setNom(const char* Text)
{
  fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditNom->clear();
    return;
  }
  ui->lineEditNom->setText(Text);
}

void MainWindow::setEmail(const char* Text)
{
  fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditEmail->clear();
    return;
  }
  ui->lineEditEmail->setText(Text);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les boutons ////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_pushButtonSuivant_clicked()
{
  fprintf(stderr,"Clic sur le bouton >>>\n"); //Incrementer le cpt et regarder si l'identififiant de la case cpt incrementee est different de 0, si oui setnom et setmail pour cette case là, sinon, si il vaut 0, on est arrivé au dernier membre qui n'existe pas, on fait -- pour revenir en arrière 
  // TO DO
  cpt++;

  if(Elm[cpt].id!=0){
    setNom(Elm[cpt].nom);
    setEmail(Elm[cpt].email);
  }
  else{
    cpt--;
  }


}

void MainWindow::on_pushButtonPrecedent_clicked()
{
  fprintf(stderr,"Clic sur le bouton <<<\n");
  cpt--;

  if(Elm[cpt].id!=0){
    setNom(Elm[cpt].nom);
    setEmail(Elm[cpt].email);
  }
  else{
    cpt++;
  }


}

void MainWindow::on_pushButtonQuitter_clicked()
{
  fprintf(stderr,"Clic sur le bouton Quitter\n");
  // TO DO
  exit(0);
}
