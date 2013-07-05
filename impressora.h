#ifndef IMPRESSORA_H_INCLUDED
#define IMPRESSORA_H_INCLUDED
#include "job.h"
#include "fila.h"


class impressora
{

private:
    fila*   filadeimpressora;
    bool    ocupado;
    job*    jobusandoimpressora;
    int     velocidade;
    int     tamanhoarquivos;

public:
    impressora();
    job* jobatualimpressora();
    bool getocupado();
    void inserefilaimpressora(job* jobimpressora);
    fila* getfilaimpressora();
    void setocupado(bool ocupado);
    void setjobusandoimpressora(job* joba);
    job* removejobfilaimpressora();
    int  gettamanhoporvelocidade();






};


#endif // IMPRESSORA_H_INCLUDED
