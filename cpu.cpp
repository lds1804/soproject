#include "cpu.h"
#include <stdio.h>


cpu::cpu()
{
    filadecpu=new fila();
    ocupado=false;
    jobusandocpu=NULL;

}


job* cpu::jobatualcpu()
{
    return jobusandocpu;




}

bool cpu::getocupado()
{
    return ocupado;


}


void cpu::inserefilacpu(job* jobcpu)
{
    filadecpu->inserejobnafila(jobcpu);




}

fila* cpu::getfilacpu()
{
    return filadecpu;

}

void cpu::setocupado(bool ocupado)
{
    this->ocupado=ocupado;


}
void cpu::setjobatual(job* joba)
{
    jobusandocpu=joba;

}

job* cpu::removejobfilacpu()
{
    return filadecpu->removejobfila();
}

bool cpu::alocajobcpu(job* JobAtual)
{
    if(jobusandocpu==NULL)
    {
        jobusandocpu=JobAtual;
        return true;
    }
    else
    {
        filadecpu->inserejobnafila(JobAtual);
        return false;
    }

}
