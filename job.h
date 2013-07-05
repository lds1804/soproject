#ifndef JOB_H_INCLUDED
#define JOB_H_INCLUDED
#include <stdio.h>
#include <iostream>

using namespace std;


class job
{


private:
    int tempodeprocessamento;
    int quantidadememoria;
    int numerodeentradassaidasdisco1;
    int numerodeentradassaidaleitora1;
    int numerodeentradassaidaleitora2;
    int numerodeentradasaidaimpressora1;
    int numerodeentradassaidaimpressora2;
    int entradasesaidasrealizadas;
    int numerodeentradassaidastotal;
    int intervaloes;
    int tempoentradasistema;
    int id;
    int iniciom;
    int fimm;
    int saidoprocessador;
    bool usaprocessador;
    bool usadisco;
    int entraprocessador;
    bool nafiladisco;
    bool nafilacpu;
    int  entradisco;
    int  saidisco;
    int  tempoproc;
    int  saifilamemoria;
    int  entrafilamemoria;
    int  entrafilacpu;
    int  saifilacpu;
    int  saifiladisco;
    int  entrafiladisco;
    int  entrafilaimpressora1;
    int  saifilaimpressora1;
    int  entrafilaimpressora2;
    int  saifilaimpressora2;
    int  entrafilaleitora1;
    int  saifilaleitora1;
    int  entrafilaleitora2;
    int  saifilaleitora2;
    int nfilamemoriaj;
    int tfilamemoriaj;
    int nfilacpuj;
    int tfilacpuj;
    int tfiladiscoj;
    int nfiladiscoj;
    int nfilaimp1j;
    int tfilaimp1j;
    int nfilaimp2j;
    int tfilaimp2j;
    int nfilaleit1j;
    int tfilaleit1j;
    int tfilaleit2j;
    int nfilaleit2j;








public:
    job(int tempproc,int quantmemoria,int nentsaidisc1,int nentsaiimp1,int nentsaiimp2,int nentsaileit1,int nentsaileit2,int ident,int tinicial);
    int gettempodeprocessamento();
    void setsaidoprocessador(int tempo);
    int getsaidoprocessador();
    void setentraprocessador(int tempo);
    int getquantmemoria();
    int getnumeroestotal();
    int getintervaloes();
    int getid();
    int gettempodeinicio();
    int getinicio();
    int getfim();
    void setinicio(int inicio);
    void setfim(int fim2);
    int getentraprocessador();
    bool getnafiladisco();
    bool getnafilacpu();
    void setentradisco(int entdisc);
    void setsaidisco(int saidisc);
    int  getentradisco();
    int  getsaidisco();
    void setentracpu(int entcpu);
    int  getentracpu();
    void incrementaentsairealizas();
    int  getesrealizadas();
    int  gettempoproc();
    void settempoproc(int tempo);
    int getnumerodeentradassaidasdisco1()
    {
        return numerodeentradassaidasdisco1;
    }
    int getnumerodeentradassaidaleitora1()
    {
        return numerodeentradassaidaleitora1;
    }
    int getnumerodeentradassaidaleitora2()
    {
        return numerodeentradassaidaleitora2;
    }
    int getnumerodeentradassaidasimpressora1()
    {
        return numerodeentradasaidaimpressora1;
    }
    int getnumerodeentradasaidasimpressora2()
    {
        return numerodeentradassaidaimpressora2;
    }
    void decrementanesdisc1()
    {
        numerodeentradassaidasdisco1--;
    }
    void decrementanesimp1()
    {
        numerodeentradasaidaimpressora1--;
    }
    void decrementanesimp2()
    {
        numerodeentradassaidaimpressora2--;
    }
    void decrementanesleit1()
    {
        numerodeentradassaidaleitora1--;
    }
    void decrementanesleit2()
    {
        numerodeentradassaidaleitora2--;
    }
    int  getsaifilamemoria()
    {
        return saifilamemoria;
    }
    void setsaifilamemoria(int sfm)
    {
        saifilamemoria=sfm;
    }
    int  getentrafilamemoria()
    {
        return entrafilamemoria;
    }
    void setentrafilamemoria(int efm)
    {
        entrafilamemoria=efm;
    }
    int  getentrafilacpu()
    {
        return entrafilacpu;
    }
    void setentrafilacpu(int efc)
    {
        cout<<"entra fila cpu "<<"Job"<< id<<endl;
        entrafilacpu=efc;
    }
    int  getsaifilacpu()
    {
        return saifilacpu;
    }
    void setsaifilacpu(int sfc)
    {
        saifilacpu=sfc;
    }
    int  getsaifiladisco()
    {
        return saifiladisco;
    }
    int  setsaifiladisco()
    {
        return saifiladisco;
    }

    void setentrafiladisco(int efd)
    {
        entrafiladisco=efd;
    }
    int  getentrafiladisco()
    {
        return entrafiladisco;
    }

    int  getentrafilaimpressora1()
    {
        return entrafilaimpressora1;
    }
    void setentrafilaimpressora1(int efi1)
    {
        entrafilaimpressora1=efi1;

    }


    int  getsaifilaimpressora1()
    {
        return saifilaimpressora1;
    }
    void setsaifilaimpressora1(int sfimp1)
    {
        saifilaimpressora1=sfimp1;
    }

    int  getentrafilaimpressora2()
    {
        return entrafilaimpressora2;
    }
    void setentrafilaimpressora2(int efim2)
    {
        entrafilaimpressora2=efim2;
    }

    void  setsaifilaimpressora2(int sfimp2)
    {
        saifilaimpressora2=sfimp2;
    }
    int  getsaifilaimpressora2()
    {
        return saifilaimpressora2;
    }

    void setentrafilaleitora1(int efl1)
    {
        entrafilaleitora1=efl1;
        cout<<"entra fila leitora1 "<<"Job:"<< id<<" Tempo:"<<entrafilaleitora1<<endl;
    }
    int  getentrafilaleitora1()
    {
        return entrafilaleitora1;
    }

    void  setsaifilaleitora1(int sfl1)
    {
        saifilaleitora1=sfl1;
    }
    int   getsaifilaleitora1()
    {
        return saifilaleitora1;
    }

    void setentrafilaleitora2(int efl2)
    {
        entrafilaleitora2=efl2;
        cout<<"Tempo leitora2 de entrada"<<entrafilaleitora2<<endl;
    }
    int  getentrafilaleitora2()
    {
        return entrafilaleitora2;
    }

    void   setsaifilaleitora2(int sfl2)
    {
        saifilaleitora2=sfl2;
    }
    int   getsaifilaleitora2()
    {
        return saifilaleitora2;
    }

    int getnfilamemoriaj(){return nfilamemoriaj;}
    void incnfilamemoriaj(){nfilamemoriaj++;}

    int gettfilamemoriaj(){return tfilamemoriaj;}
    void addtfilamemoriaj(int time){tfilamemoriaj=tfilamemoriaj+time;}

    int getnfilacpuj() {return nfilacpuj;}
    void incnfilacpuj(){nfilacpuj=nfilacpuj+1;}

    int gettfilacpuj(){return tfilacpuj;}
    void addtfilacpuj(int time){tfilacpuj=tfilacpuj+time;}

    int gettfiladiscoj(){return tfiladiscoj;}
    void addtfiladiscoj(int time){tfiladiscoj=tfiladiscoj+time;}

    int getnfiladiscoj(){return nfiladiscoj;}
    void incnfiladiscoj(){nfiladiscoj=nfiladiscoj+1;}

    int getnfilaimp1j(){return nfilaimp1j;}
    void incnfilaimp1j(){nfilaimp1j++;}

    int gettfilaimp1j(){return tfilaimp1j;}
    void addtfilaimp1j(int time){tfilaimp1j=tfilaimp1j+time;}

    int getnfilaimp2j(){return nfilaimp2j; }
    void incnfilaimp2j(){nfilaimp2j++;}

    int gettfilaimp2j(){return tfilaimp2j;}
    void addtfilaimp2j(int time){tfilaimp2j=tfilaimp2j+time;}

    int getnfilaleit1j(){return nfilaleit1j;}
    void incnfilaleit1j(){nfilaleit1j++;}

    int gettfilaleit1j(){return tfilaleit1j;}
    void addtfilaleit1j(int time){
        cout<<"Tempo leitora1:"<<time<<endl;
        tfilaleit1j=tfilaleit1j+time;}

    int gettfilaleit2j(){return tfilaleit2j;}
    void addtfilaleit2j(int time){
        cout<<"Time total:"<< time<<endl;
        tfilaleit2j=tfilaleit2j+time;}

    int getnfilaleit2j(){return nfilaleit2j;}
    void incnfilaleit2j(){nfilaleit2j++;}









};

#endif // JOB_H_INCLUDED
