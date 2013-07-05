#include "memoria.h"
#include <iostream>
#include <stdio.h>

using namespace std;


memoria::memoria()
{
    tamanhomemoria=1000;
    cheio=false;
    tamanhoutilizado=0;
    filadememoria=new fila();
    numerodejobsmemoria=0;
    numerojobsalocados=0;

    for(int i=0; i<1000; i++)
    {
        memo[i]=-1;


    }





}


bool memoria::aloca(job* jobparaalocar)
{

    int tam=jobparaalocar->getquantmemoria();
    int inicio=0;
    int tamatual;
    int fim=0;
    int achou=false;
    int j;




    for(int i=0; i<tamanhomemoria&&achou==false; i++)
    {

        if (memo[i]==-1) //testa se a posicao i esta vazia
        {
            inicio=i;


            for(j=inicio+1; memo[j]==-1&&j<tamanhomemoria&&achou==false; j++)
            {
                tamatual=j-inicio+1;

                if(tamatual==tam)
                {
                    achou=true;
                    fim=j;
                }

            }
            i=j;
        }




    }


    if(fim!=0)
    {
        for(int h=inicio; h<=fim; h++)
        {
            memo[h]=jobparaalocar->getid();


        }

        jobparaalocar->setinicio(inicio);
        jobparaalocar->setfim(fim);
        jobsnamemoria[numerojobsalocados]=jobparaalocar;
        numerojobsalocados++;


    }

    if(fim==0)
    {
        filadememoria->inserejobnafila(jobparaalocar);


    }



//for(int g=0;g<1000;g++)
//{
//    cout<<"memoria["<<g<<"]="<<memo[g]<<endl;
//    getchar();
//
//
//}

    if (achou==true)
        return true;
    else
        return false;



}


void  memoria::desaloca(int id)
{
    int prov;
    for(int z=0; z<1000; z++)
    {
        if(memo[z]==id)
            memo[z]=-1;
    }

    for(int h=0; h<numerojobsalocados; h++)
    {
        if(jobsnamemoria[h]->getid()==id)
        {
            jobsnamemoria[h]=NULL;
            prov=h;
        }


    }
    numerodejobsmemoria--;
    numerojobsalocados--;

    for(int g=prov; g<numerojobsalocados; g++)
        jobsnamemoria[g]=jobsnamemoria[g+1];

    if(filadememoria->filavazia()==false)
    {
        bool alocacao=aloca(filadememoria->removejobfila());
        if(alocacao==false)
            aloca(filadememoria->removejobfila());
    }



//    for(int g=0;g<1000;g++)
//{
//    cout<<"memoria["<<g<<"]="<<memo[g]<<endl;
//    getchar();
//
//
//}







    //implementar a verificação da fila e inserir o proximo job na memoria se houver fila reordenar jobs na memoria tambem


}



int   memoria::getnumerojobsalocados()
{
    return numerojobsalocados;
}


job*  memoria::getjobsnamemoria(int i)
{
    return jobsnamemoria[i];

}


job* memoria::menortempo(int tempoatual)//nao esquecer de realocar os ponteiros de job na hora de desalocar memoria
{
    int indicemenor=-1,menor=30000;
    for(int i=0; i<numerojobsalocados; i++)
    {
        if((jobsnamemoria[i]->gettempodeinicio()<menor&&jobsnamemoria[i]->gettempodeinicio()==tempoatual))
        {
            menor=jobsnamemoria[i]->gettempodeinicio();
            indicemenor=i;
        }
        if (jobsnamemoria[i]->gettempodeinicio()<menor&&jobsnamemoria[i]->getentraprocessador()==tempoatual)
        {
            menor=jobsnamemoria[i]->getentraprocessador();
            indicemenor=i;
        }


    }
    if(indicemenor!=-1)
    {
//        cout << "Subrotina menor" << jobsnamemoria[indicemenor]->getentraprocessador()<<endl;


        return jobsnamemoria[indicemenor];
    }
    else
        return NULL;
}
