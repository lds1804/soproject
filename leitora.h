#ifndef LEITORA_H_INCLUDED
#define LEITORA_H_INCLUDED
#include "job.h"
#include "fila.h"


class leitora
{
private:
    fila*   filadeleitora;
    bool    ocupado;
    job*    jobusandoleitora;
    int     velocidade;
    int     tamanhoarquivos;

public:
    leitora();
    job* jobatualleitora();
    bool getocupado();
    void inserefilaleitora(job* jobleitora);
    fila* getfilaleitora();
    void setocupado(bool ocupado);
    void setjobusandoleitora(job* joba);
    job* removejobfilaleitora();
    int  gettamanhoporvelocidade();





};


#endif // LEITORA_H_INCLUDED
