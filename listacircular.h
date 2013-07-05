#ifndef LISTACIRCULAR_H_INCLUDED
#define LISTACIRCULAR_H_INCLUDED
#include "evento.h"

class listacircular
{
private:
    evento* eventos[10000];
    int numeroeventoslista;


public:
    void            insereeventolista(evento* event);
    evento*         removeeventolista(int posicao);
    listacircular();
    bool listavazia();
    void imprimelista();
    int  GetNumeroEventosLista()
    {
        return numeroeventoslista;
    }

};


#endif // LISTACIRCULAR_H_INCLUDED
