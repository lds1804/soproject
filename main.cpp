#include <iostream>
#include <stdio.h>
#include "agendador.h"
#include  "job.h"
#include "listacircular.h"
#include "evento.h"
#include "memoria.h"



using namespace std;


int main()
{


    agendador agend(1000);
    agend.criajobs();
    agend.iniciasimulacao();

//listacircular* lista1;
//lista1= new listacircular();
//
//evento*  evento1;
//evento1= new evento();
//evento*  evento8;
//evento8= new evento();
//evento1->settempo(20);
//getchar();
//evento*  evento2;
//evento*  evento3;
//evento*  evento4;
//evento*  evento5;
//evento*  evento6;
//evento*  evento7;
//evento2= new evento();
//evento3= new evento();
//evento4= new evento();
//evento5= new evento();
//evento6= new evento();
//evento7= new evento();
//evento2->settempo(30);
//evento3->settempo(100);
//evento7->settempo(120);
//evento4->settempo(30);
//evento5->settempo(25);
//evento6->settempo(150);
//evento1->setidevento(1);
//evento2->setidevento(2);
//evento3->setidevento(3);
//evento4->setidevento(4);
//evento5->setidevento(5);
//evento6->setidevento(6);
//evento7->setidevento(7);
//
//
//lista1->insereeventolista(evento1);
//lista1->imprimelista();
//lista1->removeeventolista(0);
//lista1->imprimelista();
//lista1->insereeventolista(evento7);
//lista1->imprimelista();
//lista1->removeeventolista(0);
//lista1->insereeventolista(evento4);
//lista1->imprimelista();
//lista1->insereeventolista(evento2);
//lista1->imprimelista();
//lista1->removeeventolista(0);
//lista1->imprimelista();

//lista1->imprimelista();
//lista1->insereeventolista(evento4);
//lista1->imprimelista();
//lista1->insereeventolista(evento3);
//lista1->imprimelista();
//lista1->insereeventolista(evento2);
//lista1->imprimelista();
//lista1->insereeventolista(evento5);
//lista1->imprimelista();
//lista1->insereeventolista(evento6);
//lista1->imprimelista();
//
//evento8=lista1->removeeventolista(6);
//lista1->imprimelista();
//lista1->removeeventolista(0);
//lista1->imprimelista();
//lista1->removeeventolista(4);
//lista1->imprimelista();
//lista1->removeeventolista(0);
//lista1->imprimelista();
//lista1->removeeventolista(2);
//lista1->imprimelista();
//lista1->removeeventolista(0);
//lista1->imprimelista();
//lista1->removeeventolista(0);
//lista1->imprimelista();


//job* JobA=new job(200,300,2,1,2,3,0,12);
//job* JobB=new job(300,400,2,1,2,3,1,20);
//job* JobC=new job(300,500,2,1,2,3,2,40);
//job* JobD=new job(300,200,2,1,3,2,3,50);
//job* JobE=new job(300,400,2,1,3,2,4,40);
//
//
//memoria* memo=new memoria();
//bool prov=memo->aloca(JobA);
//prov=memo->aloca(JobB);
//prov=memo->aloca(JobC);
//prov=memo->aloca(JobD);
//prov=memo->aloca(JobE);
//
//memo->desaloca(1);
//memo->desaloca(4);






























    return 0;
}
