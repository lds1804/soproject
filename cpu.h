#ifndef CPU_H_INCLUDED
#define CPU_H_INCLUDED
#include "job.h"
#include "fila.h"

class cpu

{

private:
    fila* filadecpu;
    bool ocupado;
    job* jobusandocpu;



public:
    cpu();
    job* jobatualcpu();
    bool getocupado();
    void inserefilacpu(job* jobcpu);
    fila* getfilacpu();
    void setocupado(bool ocupado);
    void setjobatual(job* joba);
    job* removejobfilacpu();
    bool alocajobcpu(job* JobAtual);





};





#endif // CPU_H_INCLUDED
