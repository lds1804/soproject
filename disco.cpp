#include "disco.h"



disco::disco()
{
    ocupado=false;
    filadedisco= new fila();
    velocidade=20;
    tamanhoarquivos=400;

}
job* disco::jobatualdisco()
{
    return jobusandodisco;

}
bool disco::getocupado()
{
    return ocupado;


}
void disco::inserefiladisco(job* jobdisco)
{
    filadedisco->inserejobnafila(jobdisco);


}
fila* disco::getfiladisco()
{
    return filadedisco;

}
void disco::setocupado(bool ocupado)
{
    this->ocupado=ocupado;
}
void disco::setjobusandodisco(job* joba)
{
    jobusandodisco=joba;

}
job* disco::removejobfiladisco()
{
    return filadedisco->removejobfila();
}


int  disco::gettamanhoporvelocidade()
{
    return tamanhoarquivos/velocidade;
}
