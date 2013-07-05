#include "listacircular.h"
#include "evento.h"
#include <iostream>
#include <stdio.h>

using namespace std;


listacircular::listacircular()
{
    numeroeventoslista=0;
}


void listacircular::insereeventolista(evento* event)
{

    int tempo=event->gettempo();
    int posicao=-1;
    evento* prov[1000];
    bool     achou=false;

    if(numeroeventoslista==0)
    {
        eventos[0]=event;
        numeroeventoslista++;

    }

    else
    {


        if(numeroeventoslista==1)//insere no inicio da lista
        {
            if(eventos[0]->gettempo()>=tempo)
            {
                prov[0]=eventos[0];
                eventos[0]=event;
                eventos[1]=prov[0];
                numeroeventoslista++;
            }
            else
            {
                eventos[1]=event;
                numeroeventoslista++;
            }
        }

        else if(numeroeventoslista>1)
        {
            if(eventos[0]->gettempo()>=tempo)  //insere no inicio
            {
                prov[0]=event;
                for(int i=0; i<numeroeventoslista; i++)
                {
                    prov[i+1]=eventos[i];

                }
                numeroeventoslista++;
                for(int i=0; i<numeroeventoslista; i++)
                {
                    eventos[i]=prov[i];

                }

            }

            else if(eventos[numeroeventoslista-1]->gettempo()<=tempo)    //insere no fim
            {
                eventos[numeroeventoslista]=event;
                numeroeventoslista++;
            }

            else
            {
                for(int i=0; i<numeroeventoslista&&achou==false; i++) // insere no meio
                {
                    int tempo1,tempo2;
                    tempo1=eventos[i]->gettempo();
                    tempo2=eventos[i+1]->gettempo();
                    if((tempo1<=tempo) && (tempo2>=tempo))
                    {
                        posicao=i;
                        achou=true;
                    }

                }


                for(int i=0; i<=posicao; i++)
                {
                    prov[i]=eventos[i];

                }
                prov[posicao+1]=event;

                numeroeventoslista++;
                for(int i=posicao+2; i<numeroeventoslista; i++)
                {
                    prov[i]=eventos[i-1];


                }
                for(int i=0; i<numeroeventoslista; i++)
                {
                    eventos[i]=prov[i];

                }
            }
        }




    }


}

bool listacircular::listavazia()
{
    if(numeroeventoslista==0)
        return true;
    else
        return false;

}

void listacircular::imprimelista()
{
    cout<<"Numero de elemetos na lista:"<<numeroeventoslista<<endl;
    for(int i=0; i<numeroeventoslista; i++)
    {
        cout<<"Evento:"<<eventos[i]->getidevento()<<"Tempo entrada:"<< eventos[i]->gettempo()<<endl;


    }

}

evento* listacircular::removeeventolista(int posicao)
{
    evento* prov[10000];

    if(numeroeventoslista==0)
    {
        cout <<"Lista vazia, nao pode remover"<<endl;
        return NULL;
    }

    if(posicao<numeroeventoslista)
    {
        for(int i=0; i<posicao; i++)
        {
            prov[i]=eventos[i];

        }
        evento* temporario=eventos[posicao];

        for(int i=posicao; i<numeroeventoslista; i++)
        {
            prov[i]=eventos[i+1];

        }
        numeroeventoslista--;

        for(int i=0; i<numeroeventoslista; i++)
        {
            eventos[i]=prov[i];

        }
        return  temporario;
    }
    else
    {
        cout<<"Posicao invalida"<<endl;
        return NULL;
    }









}

