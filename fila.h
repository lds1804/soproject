#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "job.h"
class fila
{
private:
    job* filadejobs[1000];
    int numerojobsfila;
    int inicio;
    int fim;

public:
    void    inserejobnafila(job* jobfila);
    job*     removejobfila();
    fila();
    bool filavazia();
    void imprimefila();
};


#endif // FILA_H_INCLUDED
