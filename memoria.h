#ifndef MEMORIA_H_INCLUDED
#define MEMORIA_H_INCLUDED
#include "job.h"
#include "fila.h"

class memoria
{

private:
    fila*   filadememoria;
    bool    cheio;
    int     tamanhomemoria;
    int     numerodejobsmemoria;
    int     memo[1000];
    int     tamanhoutilizado;
    job*    jobsnamemoria[100];
    int     numerojobsalocados;




public:
    memoria();
    int   gettamanhodememoria();
    bool  aloca(job* jobparaalocar);
    fila* getfiladememoria();
    job*  getjobsnamemoria(int i);
    void  desaloca(int id);
    int   getnumerojobsalocados();
    job*  menortempo(int tempoatual);





};


#endif // MEMORIA_H_INCLUDED
