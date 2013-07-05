#ifndef DISCO_H_INCLUDED
#define DISCO_H_INCLUDED
#include "job.h"
#include "fila.h"

class disco
{
private:
    fila*   filadedisco;
    bool    ocupado;
    job*    jobusandodisco;
    int     velocidade;
    int     tamanhoarquivos;

public:
    disco();
    job* jobatualdisco();
    bool getocupado();
    void inserefiladisco(job* jobdisco);
    fila* getfiladisco();
    void setocupado(bool ocupado);
    void setjobusandodisco(job* joba);
    job* removejobfiladisco();
    int  gettamanhoporvelocidade();



};


#endif // DISCO_H_INCLUDED
