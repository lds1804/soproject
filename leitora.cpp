#include "leitora.h"


leitora::leitora()
{
    ocupado=false;
    filadeleitora= new fila();
    velocidade=10;
    tamanhoarquivos=400;

}
job* leitora::jobatualleitora()
{
    return jobusandoleitora;

}
bool leitora::getocupado()
{
    return ocupado;


}
void leitora::inserefilaleitora(job* jobleitora)
{
    filadeleitora->inserejobnafila(jobleitora);


}

fila* leitora::getfilaleitora()
{
    return filadeleitora;

}
void leitora::setocupado(bool ocupado)
{
    this->ocupado=ocupado;
}
void leitora::setjobusandoleitora(job* joba)
{
    jobusandoleitora=joba;

}
job* leitora::removejobfilaleitora()
{
    return filadeleitora->removejobfila();
}


int  leitora::gettamanhoporvelocidade()
{
    return tamanhoarquivos/velocidade;
}
