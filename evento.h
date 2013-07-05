#ifndef EVENTO_H_INCLUDED
#define EVENTO_H_INCLUDED
#include "job.h"


class evento
{
private:
    job* jobevento;
    int  tempo;
    int  idevento;


public:
    evento();
    int     gettempo();
    job*    getjob();
    int     getidevento();
    void    settempo(int temp);
    void    setjob(job* joba);
    void    setidevento(int id);



};


#endif // EVENTO_H_INCLUDED
