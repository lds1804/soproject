#include "evento.h"
#include <stdio.h>


evento::evento()
{
    jobevento=NULL;
    tempo=-1;
    idevento=-1;

}


int evento::gettempo()
{
    return tempo;
}

job* evento::getjob()
{
    return jobevento;
}

int evento::getidevento()
{
    return idevento;
}

void evento::settempo(int temp)
{
    tempo=temp;
}

void evento::setjob(job* joba)
{
    jobevento=joba;
}

void evento::setidevento(int id)
{
    idevento=id;
}
