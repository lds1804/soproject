#include "fila.h"
#include <iostream>
#include <stdio.h>

using namespace std;
void    fila::inserejobnafila(job* jobfila)
{
    if(numerojobsfila==0 && numerojobsfila<1000)
    {
        inicio=0;
        fim=0;
        numerojobsfila++;
        filadejobs[0]=jobfila;
    }

    else if(numerojobsfila>0 && numerojobsfila<1000)
    {
        fim=(fim+1)%1000;
        filadejobs[fim]=jobfila;
        numerojobsfila++;
    }

    else
        cout<< "Fila cheia"<<endl;

    imprimefila();
    getchar();

}


job* fila::removejobfila()
{
    int prov=inicio;
    if(numerojobsfila==0)
    {
        cout << "Underflow"<<endl;
        return NULL;
    }

    else
    {
        inicio=(inicio+1)%1000;

    }

    numerojobsfila--;

    imprimefila();
    getchar();


    return filadejobs[prov];
}



fila::fila()
{
    numerojobsfila=0;
    inicio=-1;
    fim=-1;



}

bool fila::filavazia()
{


    if(numerojobsfila==0)
        return true;
    else
        return false;


}


void fila::imprimefila()
{
    cout<<"Tamanho fila:"<<numerojobsfila<<endl;
    for(int i=inicio; i<numerojobsfila+inicio; i++)
    {
        cout << "Job" << filadejobs[i%1000]->getid()<<endl;


    }



}
