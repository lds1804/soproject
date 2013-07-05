#include "job.h"
#include <iostream>
#include <stdio.h>


using namespace std;

job::job(int tempproc,int quantmemoria,int nentsaidisc1,int nentsaiimp1,int nentsaiimp2,int nentsaileit1,int nentsaileit2,int ident,int tinicial)
{
    tempodeprocessamento=tempproc;
    quantidadememoria=quantmemoria;
    numerodeentradassaidastotal=nentsaidisc1+nentsaiimp1+nentsaiimp2+nentsaileit1+nentsaileit2;
    numerodeentradassaidasdisco1=nentsaidisc1;
    numerodeentradasaidaimpressora1=nentsaiimp1;
    numerodeentradassaidaimpressora2=nentsaiimp2;
    numerodeentradassaidaleitora1=nentsaileit1;
    numerodeentradassaidaleitora2=nentsaileit2;
    intervaloes=tempproc/(numerodeentradassaidastotal+1);
    id=ident;
    tempoentradasistema=tinicial;
    cout <<"Cria job com memoria:"<<quantmemoria<<" tempoCPU:"<<tempodeprocessamento<<" nES"<<numerodeentradassaidastotal<<" ID "<<id<<" Tini:"<<tempoentradasistema<<"Intervalo es:"<<intervaloes<<endl;



    saidoprocessador=-1;
    entraprocessador=-1;
    nafilacpu=false;
    nafiladisco=false;
    entradasesaidasrealizadas=0;
    tempoproc=0;
    saifilamemoria=0;
    nfilamemoriaj=0;
    tfilamemoriaj=0;
    nfilacpuj=0;
    tfilacpuj=0;
    tfiladiscoj=0;
    nfiladiscoj=0;
    nfilaimp1j=0;
    tfilaimp1j=0;
    nfilaimp2j=0;
    tfilaimp2j=0;
    nfilaleit1j=0;
    tfilaleit1j=0;
    tfilaleit2j=0;
    nfilaleit2j=0;



}

int job::gettempodeprocessamento()
{
    return tempodeprocessamento;
}

int job::getquantmemoria()
{
    return quantidadememoria;

}
int job::getnumeroestotal()
{
    return numerodeentradassaidastotal;
}

int job::getintervaloes()
{

    return intervaloes;
}
int job::getid()
{
    return id;

}

int job::gettempodeinicio()
{
    return tempoentradasistema;
}



int job::getinicio()
{
    return iniciom;

}
int job::getfim()
{
    return fimm;
}

void job::setinicio(int inicio)
{
    iniciom=inicio;

}
void job::setfim(int fim2)
{
    fimm=fim2;
}

void job::setsaidoprocessador(int tempo)
{
    saidoprocessador=tempo+intervaloes;
}

int job::getentraprocessador()
{
    return entraprocessador;

}


bool job::getnafiladisco()
{
    return nafiladisco;
}
bool job::getnafilacpu()
{
    return nafilacpu;
}


int job::getsaidoprocessador()
{
    return saidoprocessador;

}
void job::setentraprocessador(int tempo)
{
    entraprocessador=tempo;
}







void job::setentradisco(int entdisc)
{
    entradisco=entdisc;


}


void job::setsaidisco(int saidisc)
{
    saidisco=saidisc;


}
int  job::getentradisco()
{
    return entradisco;


}
int  job::getsaidisco()
{
    return saidisco;

}






void  job::incrementaentsairealizas()
{
    entradasesaidasrealizadas++;
}
int   job::getesrealizadas()
{
    return entradasesaidasrealizadas;
}


int  job::gettempoproc()
{
    return tempoproc;
}
void job::settempoproc(int tempo)
{
    tempoproc=tempoproc+tempo;

}
