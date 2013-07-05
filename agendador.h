#ifndef AGENDADOR_H_INCLUDED
#define AGENDADOR_H_INCLUDED
#include "cpu.h"
#include "memoria.h"
#include "disco.h"
#include "job.h"
#include "leitora.h"
#include "impressora.h"
#include "evento.h"
#include "listacircular.h"


class agendador
{
private:
    cpu*                processador;
    listacircular*      ListaDeEventos;
    memoria*            mem;
    disco*              disco1;
    disco*              disco2;
    impressora*         imp1;
    impressora*         imp2;
    leitora*            leit1;
    leitora*            leit2;
    job*                listajobsativos[1000];
    job*                listadejobs[10000];
    int                 tempototal;
    int                 tempoatual;
    int                 njobsativos;
    int                 njobs;




public:
    int nfilamemoria;
    int tfilamemoria;
    int nfilacpu;
    int tfilacpu;
    int tfiladisco;
    int nfiladisco;
    int nfilaimp1;
    int tfilaimp1;
    int nfilaimp2;
    int tfilaimp2;
    int nfilaleit1;
    int tfilaleit1;
    int tfilaleit2;
    int nfilaleit2;
    void criajobs();
    agendador(int temptotal);
    void imprimeagendador();
    void iniciasimulacao();
    int gettempototal();
    int gettempoatual();
    void Evento1(evento* eventatual);
    void Evento2(evento* eventatual);
    void Evento3(evento* eventatual);
    void Evento4(evento* eventatual);
    void Evento5(evento* eventoatual);
    void Evento6(evento* eventoatual);
    void Evento7(evento* eventoatual);





};

#endif // AGENDADOR_H_INCLUDED
