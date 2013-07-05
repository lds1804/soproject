#include "impressora.h"
#include <stdio.h>

impressora::impressora()
{
    ocupado=false;
    filadeimpressora= new fila();
    velocidade=5;
    tamanhoarquivos=400;
    jobusandoimpressora=NULL;

}
job* impressora::jobatualimpressora()
{
    return jobusandoimpressora;

}
bool impressora::getocupado()
{
    return ocupado;


}
void impressora::inserefilaimpressora(job* jobimpressora)
{
    filadeimpressora->inserejobnafila(jobimpressora);


}

fila* impressora::getfilaimpressora()
{
    return filadeimpressora;

}
void impressora::setocupado(bool ocupado)
{
    this->ocupado=ocupado;
}
void impressora::setjobusandoimpressora(job* joba)
{
    jobusandoimpressora=joba;

}
job* impressora::removejobfilaimpressora()
{
    return filadeimpressora->removejobfila();
}


int  impressora::gettamanhoporvelocidade()
{
    return tamanhoarquivos/velocidade;
}
