#include    "agendador.h"
#include    <iostream>
#include    <stdio.h>
#include    "disco.h"
#include <stdlib.h>

using namespace std;

void agendador::criajobs()
{   for(int i=0;i<400;i++)
    {

    }

    job* novojob = new job(200, 400, 3, 4, 1, 3, 2, 0, 20);
    listadejobs[0] = novojob;
    njobs++;
    job* novojob2 = new job(300, 100, 5, 1, 4, 2, 3, 1, 100);
    listadejobs[1] = novojob2;
    njobs++;
    job* novojob3 = new job(200, 200, 4, 2, 3, 1, 2, 2, 50);
    listadejobs[2] = novojob3;
    njobs++;


}

agendador::agendador(int temptotal)
{
    processador = new cpu();
    mem = new memoria();
    disco1 = new disco();
    disco2 = new disco();
    imp1 = new impressora();
    imp2 = new impressora();
    leit1 = new leitora();
    leit2 = new leitora();
    tempototal = temptotal;
    tempoatual = 0;
    njobsativos = 0;
    njobs = 0;
    ListaDeEventos = new listacircular();
    nfilamemoria = 0;
    tfilamemoria = 0;
    nfilacpu = 0;
    tfilacpu = 0;
    tfiladisco = 0;
    nfiladisco = 0;
    nfilaimp1 = 0;
    tfilaimp1 = 0;
    nfilaimp2 = 0;
    tfilaimp2 = 0;
    nfilaleit1 = 0;
    tfilaleit1 = 0;
    tfilaleit2 = 0;

  nfilaleit2 = 0;

}

void agendador::iniciasimulacao()
{   bool primeiravez = false;
    bool firstenter = false;
    while ((ListaDeEventos->listavazia() == false)
            || firstenter == false)
    {
        firstenter = true;

        for (int i = 0; (i < njobs && primeiravez == false); i++) // insere eventos zero na lista de eventos
        {
            int tempoinicio = listadejobs[i]->gettempodeinicio();
            evento* event = new evento();
            event->setidevento(1);
            event->setjob(listadejobs[i]);
            event->settempo(tempoinicio);
            ListaDeEventos->insereeventolista(event);

        }
        primeiravez = true;

        int numerodeeventos = ListaDeEventos->GetNumeroEventosLista();

        for (int i = 0; i < numerodeeventos; i++)
        {
            evento* EventoAtual;
            EventoAtual = ListaDeEventos->removeeventolista(0);
            int idevento = EventoAtual->getidevento();
            tempoatual = EventoAtual->gettempo();

            if (idevento == 1)
            {
                Evento1(EventoAtual);


            }

            if (idevento == 2)
            {
                Evento2(EventoAtual);

            }

            if (idevento == 3)
            {
                Evento3(EventoAtual);

            }

            if (idevento == 4)
            {

                Evento4(EventoAtual);

            }

            if (idevento == 5)
            {
                Evento5(EventoAtual);
            }

            if (idevento == 6)
            {
                Evento6(EventoAtual);
            }

            if (idevento == 7)
            {
                Evento7(EventoAtual);
            }

        }


//     mem->getfiladememoria()->imprimefila();
//     imp1->getfilaimpressora()->imprimefila();
//     imp2->getfilaimpressora()->imprimefila();

//     leit2->getfilaleitora()->imprimefila();
//     disco1->getfiladisco()->imprimefila();
//     getchar();

    }
    if (nfilacpu>0)
    {float avgcpu=float (tfilacpu)/float (nfilacpu);
     cout << "Tempo medio fila processador:"<<avgcpu<<endl;

    }
    if (nfilamemoria>0)
    { float avgmem=float(tfilamemoria)/float(nfilamemoria);
      cout<<"Tempo medio fila memoria:"<<avgmem<<endl;
    }
    if (nfiladisco>0)
    {float avgdisco=float (tfiladisco)/float(nfiladisco);
     cout<<"Tempo medio fila disco:"<<avgdisco<<endl;


    }
    if (nfilaimp1>0)
    {float avgimp1=float (tfilaimp1)/float(nfilaimp1);
     cout<<"Tempo medio fila impressora 1:"<<avgimp1<<endl;
    }
    if(nfilaimp2>0 )
    {float avgimp2=float (tfilaimp2)/ float(nfilaimp2);
     cout<<"Tempo medio fila impressora 2:"<<avgimp2<<endl;

    }
    if(nfilaleit1>0)
    {float avgleit1=float (tfilaleit1)/float (nfilaleit1);
     cout<<"Tempo medio fila leitora 1:"<<avgleit1<<endl;

    }
    if(nfilaleit2>0)
    {float avgleit2=float(tfilaleit2)/float (nfilaleit2);
     cout<<"Tempo medio fila leitora 2:"<<avgleit2<<endl;
    }



}

void agendador::imprimeagendador()
{
    // cout<<"Memoria "<<mem->

}

int agendador::gettempototal()
{
    return tempototal;

}

int agendador::gettempoatual()
{
    return tempoatual;

}

void agendador::Evento1(evento* eventatual)
{
    job* jobatual = eventatual->getjob();

    int tempoat = eventatual->gettempo();
    tempoatual = tempoat;

    cout << "Evento 1 " << " Job " << jobatual->getid() << "Tempo Atual"
         << tempoat << endl;
    evento* novoevento = new evento();
    novoevento->setidevento(2);
    novoevento->setjob(jobatual);
    novoevento->settempo(tempoat + 5);

    ListaDeEventos->insereeventolista(novoevento);

}

void agendador::Evento2(evento* eventatual)
{
    job* jobatual = eventatual->getjob();
    int tempat = eventatual->gettempo();
    cout << "Evento 2 Job:" << jobatual->getid() << " Tempo atual:" << tempat
         << endl;

    tempoatual = tempat;

    bool alocacao = mem->aloca(jobatual);
    evento* event1;
    event1 = new evento();
    event1->setidevento(3);
    event1->setjob(jobatual);
    event1->settempo(tempat + 5);

    if (alocacao == true)
        ListaDeEventos->insereeventolista(event1);
    else
        {jobatual->setentrafilamemoria(tempat);
         jobatual->incnfilamemoriaj();
        }
}

void agendador::Evento3(evento* eventatual)
{
    job* jobatual = eventatual->getjob();
    int tempat = eventatual->gettempo();
    tempoatual = tempat;
    cout << "Evento 3 Job:" << jobatual->getid() << " Tempo atual:" << tempat
         << endl;

    int tempsaida = tempat + jobatual->getintervaloes();
    evento* event = new evento();
    event->settempo(tempsaida);
    event->setjob(jobatual);
    event->setidevento(4);
    bool aloc = processador->alocajobcpu(jobatual);

    int nesimp1 = jobatual->getnumerodeentradassaidasimpressora1();
    int nesimp2 = jobatual->getnumerodeentradasaidasimpressora2();
    int nesdisc = jobatual->getnumerodeentradassaidasdisco1();
    int nesleit1 = jobatual->getnumerodeentradassaidaleitora1();
    int nesleit2 = jobatual->getnumerodeentradassaidaleitora2();
    if (aloc == true)
    {
        if ((nesimp1 == 0) & (nesimp2 == 0) & (nesdisc == 0) & (nesleit1 == 0)
                & (nesleit2 == 0))
        {
            int temporestante = tempat + jobatual->gettempodeprocessamento()
                                - jobatual->gettempoproc();
            cout << "Tempo atual " << tempat << "Tempo proc"
                 << jobatual->gettempodeprocessamento() << "Tempo processado"
                 << jobatual->gettempoproc() << endl;
            cout << "tempo processamento" << jobatual->gettempoproc() << endl;
            event->settempo(temporestante);

            event->setidevento(6);
            jobatual->settempoproc(temporestante - tempat);

            ListaDeEventos->insereeventolista(event);

        }
        else
        {
            ListaDeEventos->insereeventolista(event);
            jobatual->settempoproc(jobatual->getintervaloes());




        }

    }

    else
        { jobatual->setentrafilacpu(tempat);
          jobatual->incnfilacpuj();
          cout<<"Entra fila cpu"<<jobatual->getentrafilacpu()<<"Job"<<jobatual->getid()<<endl;
          getchar();

        }

}

void agendador::Evento4(evento* eventatual)
{
    job* jobatual = eventatual->getjob();
    int tempat = eventatual->gettempo();
    tempoatual = tempat;
    cout << "Evento 4 Job:" << jobatual->getid() << " Tempo atual:" << tempat<< endl;


    if (processador->getfilacpu()->filavazia() == false)
    {
        evento* event = new evento();
        processador->setjobatual(NULL);
        event->setidevento(3);
        job* jobtemp = processador->removejobfilacpu();
        jobtemp->setsaifilacpu(tempat);

        cout<<"Tempo trancorrido:"<<jobtemp->getentrafilacpu()<<"tempo atual"<<tempat<<"Job:"<<jobtemp->getid()<<endl;
        cout<<"Entra cpu:"<<jobtemp->getentrafilacpu()<<endl;
        cout<<"Tempo na fila:"<<tempat-jobtemp->getentrafilacpu()<<endl;
        jobtemp->addtfilacpuj(tempat-jobtemp->getentrafilacpu());
        cout<< "tempo total na cpu:" << jobtemp->gettfilacpuj()<<endl;


        event->setjob(jobtemp);
        event->settempo(tempoatual + 5);
        ListaDeEventos->insereeventolista(event);

    }

    else
    {
        processador->setjobatual(NULL);
    }

    int neslet1 = jobatual->getnumerodeentradassaidaleitora1();
    int neslet2 = jobatual->getnumerodeentradassaidaleitora2();
    int nesdisc1 = jobatual->getnumerodeentradassaidasdisco1();
    int nesimp1 = jobatual->getnumerodeentradassaidasimpressora1();
    int nesimp2 = jobatual->getnumerodeentradasaidasimpressora2();
    if (jobatual->getnumerodeentradassaidaleitora1() > 0)
    {
        cout << "Entrada e saida leitora 1 Nes:" << neslet1 << " Job:"
             << jobatual->getid() << endl;

        evento* event;
        event = new evento();
        event->setidevento(5);
        event->setjob(jobatual);
        event->settempo(tempat + leit1->gettamanhoporvelocidade());

        if (leit1->getfilaleitora()->filavazia() == true
                && leit1->jobatualleitora() == NULL)
        {
            ListaDeEventos->insereeventolista(event);
            leit1->setjobusandoleitora(jobatual);
            jobatual->decrementanesleit1();

        }

        else if (leit1->getfilaleitora()->filavazia() == false
                 && leit1->jobatualleitora() == NULL)
        {
            job* jobprov = leit1->removejobfilaleitora();
            jobprov->setsaifilaleitora1(tempat);
//          jobprov->addtfilaleit1j(tempat-jobprov->getentrafilaleitora1());
            event->setidevento(5);
            event->setjob(jobprov); // falta configurar o tempo do job nao configurei
            event->settempo(tempat + leit1->gettamanhoporvelocidade());
            ListaDeEventos->insereeventolista(event);

            leit1->inserefilaleitora(jobatual);
            jobatual->setentrafilaleitora1(tempat);
            jobatual->incnfilaleit1j();

            jobprov->decrementanesleit1();


        }

        else
        {
            leit1->inserefilaleitora(jobatual);
            jobatual->setentrafilaleitora1(tempat);
            jobatual->incnfilaleit1j();
        }

        job* proximojobcpu = NULL;

        if (processador->getfilacpu()->filavazia() == false)
        {
            proximojobcpu = processador->removejobfilacpu();
            proximojobcpu->setsaifilacpu(tempat);
            proximojobcpu->addtfilacpuj(tempat-proximojobcpu->getentrafilacpu());
        }

        evento* Event2;
        Event2 = new evento();

        Event2->setidevento(3);

        if (proximojobcpu != NULL)
            Event2->setjob(proximojobcpu);

        Event2->settempo(tempoatual + 5);

        if (proximojobcpu != NULL)
            ListaDeEventos->insereeventolista(Event2);




    }

    else if (jobatual->getnumerodeentradassaidaleitora2() > 0)
    {
        cout << "Entrada e saida leitora 2 Nes:" << neslet2 << " Job:"
             << jobatual->getid() << endl;

        evento* event;
        event = new evento();
        event->setidevento(5);
        event->setjob(jobatual);
        event->settempo(tempat + leit2->gettamanhoporvelocidade());

        if (leit2->getfilaleitora()->filavazia() == true
                && leit2->jobatualleitora() == NULL)
        {
            ListaDeEventos->insereeventolista(event);
            leit2->setjobusandoleitora(jobatual);
            jobatual->decrementanesleit2();

        }
        else if (leit2->getfilaleitora()->filavazia() == false&& leit2->jobatualleitora() == NULL)
        {   job* jobprov = leit2->removejobfilaleitora();
            jobprov->setsaifilaleitora2(tempat);
//          jobprov->addtfilaleit1j(tempat-jobprov->getentrafilaleitora1());
            event->setidevento(5);
            event->setjob(jobprov); // falta configurar o tempo do job nao configurei
            event->settempo(tempat + leit2->gettamanhoporvelocidade());
            ListaDeEventos->insereeventolista(event);

            leit2->inserefilaleitora(jobatual);
            jobatual->setentrafilaleitora1(tempat);
            jobatual->incnfilaleit2j();

            jobprov->decrementanesleit2();

        }

        else
        {
            leit2->inserefilaleitora(jobatual);
            jobatual->setentrafilaleitora2(tempat);
            jobatual->incnfilaleit2j();
        }

        job* proximojobcpu = NULL;

        if (processador->getfilacpu()->filavazia() == false)
            proximojobcpu = processador->removejobfilacpu();

        evento* Event2;
        Event2 = new evento();

        Event2->setidevento(3);

        if (proximojobcpu != NULL)
            Event2->setjob(proximojobcpu);

        Event2->settempo(tempoatual + 5);

        if (proximojobcpu != NULL)
            ListaDeEventos->insereeventolista(Event2);

    }

    else if (jobatual->getnumerodeentradassaidasdisco1() > 0)
    {
        cout << "Entrada e saida disco 1 Nes:" << nesdisc1 << " Job:"
             << jobatual->getid() << endl;

        evento* event;
        event = new evento();
        event->setidevento(5);
        event->setjob(jobatual);
        event->settempo(tempat + disco1->gettamanhoporvelocidade());

        if (disco1->getfiladisco()->filavazia() == true
                && disco1->jobatualdisco() == NULL)
        {
            ListaDeEventos->insereeventolista(event);
            disco1->setjobusandodisco(jobatual);
            jobatual->decrementanesdisc1();

        }

        else if (disco1->getfiladisco()->filavazia() == false
                 && disco1->jobatualdisco() == NULL)
        {
            job* jobprov = disco1->removejobfiladisco();
            jobprov->setsaifiladisco(tempat);
//          jobprov->addtfilaleit1j(tempat-jobprov->getentrafilaleitora1());
            event->setidevento(5);
            event->setjob(jobprov); // falta configurar o tempo do job nao configurei
            event->settempo(tempat + disco1->gettamanhoporvelocidade());
            ListaDeEventos->insereeventolista(event);

            disco1->inserefiladisco(jobatual);
            jobatual->setentrafiladisco(tempat);
            jobatual->incnfiladiscoj();

            jobprov->decrementanesdisc1();

        }

        else
        {
            disco1->inserefiladisco(jobatual);
            jobatual->setentrafiladisco(tempat);
            jobatual->incnfiladiscoj();
        }

        job* proximojobcpu = NULL;

        if (processador->getfilacpu()->filavazia() == false)
            proximojobcpu = processador->removejobfilacpu();

        evento* Event2;
        Event2 = new evento();

        Event2->setidevento(3);

        if (proximojobcpu != NULL)
            Event2->setjob(proximojobcpu);

        Event2->settempo(tempoatual + 5);

        if (proximojobcpu != NULL)
            ListaDeEventos->insereeventolista(Event2);

    }

    else if (jobatual->getnumerodeentradassaidasimpressora1() > 0)
    {
        cout << "Entrada e saida impressora 1 Nes:" << nesimp1 << " Job:"
             << jobatual->getid() << endl;

        evento* event;
        event = new evento();
        event->setidevento(5);
        event->setjob(jobatual);
        event->settempo(tempat + imp1->gettamanhoporvelocidade());

        if (imp1->getfilaimpressora()->filavazia() == true
                && imp1->jobatualimpressora() == NULL)
        {
            ListaDeEventos->insereeventolista(event);
            imp1->setjobusandoimpressora(jobatual);
            jobatual->decrementanesimp1();

        }

        else if (imp1->getfilaimpressora()->filavazia() == false
                 && imp1->jobatualimpressora() == NULL)
        {
            job* jobprov = imp1->removejobfilaimpressora();
            jobprov->setsaifilaimpressora1(tempat);
//          jobprov->addtfilaleit1j(tempat-jobprov->getentrafilaleitora1());
            event->setidevento(5);
            event->setjob(jobprov); // falta configurar o tempo do job nao configurei
            event->settempo(tempat + imp1->gettamanhoporvelocidade());
            ListaDeEventos->insereeventolista(event);

            imp1->inserefilaimpressora(jobatual);
            jobatual->setentrafilaimpressora1(tempat);
            jobatual->incnfilaimp1j();

            jobprov->decrementanesimp1();

        }

        else
        {
            imp1->inserefilaimpressora(jobatual);
            jobatual->setentrafilaimpressora1(tempat);
            jobatual->incnfilaimp1j();
        }

        job* proximojobcpu = NULL;

        if (processador->getfilacpu()->filavazia() == false)
            proximojobcpu = processador->removejobfilacpu();

        evento* Event2;
        Event2 = new evento();

        Event2->setidevento(3);

        if (proximojobcpu != NULL)
            Event2->setjob(proximojobcpu);

        Event2->settempo(tempoatual + 5);

        if (proximojobcpu != NULL)
            ListaDeEventos->insereeventolista(Event2);

    }

    else if (jobatual->getnumerodeentradasaidasimpressora2() > 0)
    {
        cout << "Entrada e saida impressora 2 Nes:" << nesimp2 << " Job:"
             << jobatual->getid() << endl;

        evento* event;
        event = new evento();
        event->setidevento(5);
        event->setjob(jobatual);
        event->settempo(tempat + imp2->gettamanhoporvelocidade());

        if (imp2->getfilaimpressora()->filavazia() == true
                && imp2->jobatualimpressora() == NULL)
        {
            cout << "Fila vazia e impressora desocupada" << endl;
            ListaDeEventos->insereeventolista(event);
            imp2->setjobusandoimpressora(jobatual);
            jobatual->decrementanesimp2();

        }

        else if (imp2->getfilaimpressora()->filavazia() == false
                 && imp2->jobatualimpressora() == NULL)
        {
            cout << "Fila cheia e impressora desocupada" << endl;
            job* jobprov = imp2->removejobfilaimpressora();
            jobprov->setsaifilaimpressora2(tempat);
//          jobprov->addtfilaleit1j(tempat-jobprov->getentrafilaleitora1());
            event->setidevento(5);
            event->setjob(jobprov); // falta configurar o tempo do job nao configurei
            event->settempo(tempat + imp2->gettamanhoporvelocidade());
            ListaDeEventos->insereeventolista(event);

            imp2->inserefilaimpressora(jobatual);
            jobatual->setentrafilaimpressora2(tempat);
            jobatual->incnfilaimp2j();
            jobprov->decrementanesimp2();
        }

        else
        {
            cout << "Fila cheia e impressora ocupada ou impressora ocupada"
                 << endl;
            imp2->inserefilaimpressora(jobatual);
            jobatual->setentrafilaimpressora2(tempat);
            jobatual->incnfilaimp2j();
        }

        job* proximojobcpu = NULL;

        if (processador->getfilacpu()->filavazia() == false)
            proximojobcpu = processador->removejobfilacpu();

        evento* Event2;
        Event2 = new evento();

        Event2->setidevento(3);

        if (proximojobcpu != NULL)
            Event2->setjob(proximojobcpu);

        Event2->settempo(tempoatual + 5);

        if (proximojobcpu != NULL)
            ListaDeEventos->insereeventolista(Event2);
    }

}

void agendador::Evento5(evento* eventoatual)
{
    job* jobatual = eventoatual->getjob();


    int tempoat = eventoatual->gettempo();
    tempoatual = tempoat;

    cout << "Evento 5 " << " Job " << jobatual->getid() << "Tempo Atual"
         << tempoat << endl;

    if (disco1->jobatualdisco() == jobatual)
    {
        if (disco1->getfiladisco()->filavazia() == false)
        {
            job* proximojob = disco1->removejobfiladisco();
            disco1->setjobusandodisco(proximojob);
            proximojob->setsaifiladisco(tempoat);
            proximojob->addtfiladiscoj(tempoat-proximojob->getentrafiladisco());
            evento* event = new evento();
            event->setjob(proximojob);
            event->settempo(tempoat + disco1->gettamanhoporvelocidade());
            event->setidevento(5);
            ListaDeEventos->insereeventolista(event);
            proximojob->decrementanesdisc1();
        }
    }
    if (imp1->jobatualimpressora() == jobatual)
    {
        if (imp1->getfilaimpressora()->filavazia() == false)
        {
            job* proximojob = imp1->removejobfilaimpressora();
            imp1->setjobusandoimpressora(proximojob);
            proximojob->setsaifilaimpressora1(tempoat);
            proximojob->addtfilaimp1j(tempoat-proximojob->getentrafilaimpressora1());
            evento* event = new evento();
            event->setjob(proximojob);
            event->settempo(tempoat + imp1->gettamanhoporvelocidade());
            event->setidevento(5);
            ListaDeEventos->insereeventolista(event);
            proximojob->decrementanesimp1();
        }
    }
    if (imp2->jobatualimpressora() == jobatual)
    {
        if (imp2->getfilaimpressora()->filavazia() == false)
        {
            job* proximojob = imp2->removejobfilaimpressora();
            imp2->setjobusandoimpressora(proximojob);
            proximojob->setsaifilaimpressora2(tempoat);
            proximojob->addtfilaimp2j(tempoat-proximojob->getentrafilaimpressora2());
            evento* event = new evento();
            event->setjob(proximojob);
            event->settempo(tempoat + imp2->gettamanhoporvelocidade());
            event->setidevento(5);
            ListaDeEventos->insereeventolista(event);
            proximojob->decrementanesimp2();
        }
    }
    if (leit1->jobatualleitora() == jobatual)
    {
        if (leit1->getfilaleitora()->filavazia() == false)
        {
            job* proximojob = leit1->removejobfilaleitora();
            leit1->setjobusandoleitora(proximojob);
            proximojob->setsaifilaleitora1(tempoat);
            proximojob->addtfilaleit1j(tempoat-proximojob->getentrafilaleitora1());
            evento* event = new evento();
            event->setjob(proximojob);
            event->settempo(tempoat + leit1->gettamanhoporvelocidade());
            event->setidevento(5);
            ListaDeEventos->insereeventolista(event);
            proximojob->decrementanesleit1();
        }
    }
    if (leit2->jobatualleitora() == jobatual)
    {
        if (leit2->getfilaleitora()->filavazia() == false)
        {
            job* proximojob = leit2->removejobfilaleitora();
            leit2->setjobusandoleitora(proximojob);
            proximojob->setsaifilaleitora2(tempoat);
            proximojob->addtfilaleit2j(tempoat-proximojob->getentrafilaleitora2());
            evento* event = new evento();
            event->setjob(proximojob);
            event->settempo(tempoat + leit2->gettamanhoporvelocidade());
            event->setidevento(5);
            ListaDeEventos->insereeventolista(event);
            proximojob->decrementanesleit2()
            ;
        }
    }

    if (disco1->jobatualdisco() == jobatual)
        {disco1->setjobusandodisco(NULL);

        }

    if (imp1->jobatualimpressora() == jobatual)
        {imp1->setjobusandoimpressora(NULL);

        }
    if (imp2->jobatualimpressora() == jobatual)
        {imp2->setjobusandoimpressora(NULL);

        }
    if (leit1->jobatualleitora() == jobatual)
        {leit1->setjobusandoleitora(NULL);

        }
    if (leit2->jobatualleitora() == jobatual)
        {leit2->setjobusandoleitora(NULL);

        }
    evento* event2;
    event2 = new evento();
    event2->settempo(tempoat + 5);
    event2->setidevento(3);

    event2->setjob(jobatual);

    ListaDeEventos->insereeventolista(event2);

}

void agendador::Evento6(evento* eventoatual)
{
    int temp = eventoatual->gettempo();
    job* jobatual = eventoatual->getjob();
    cout << "Evento 6 " << " Job " << jobatual->getid() << " Tempo Atual"
         << temp << endl;
    mem->desaloca(jobatual->getid());
    jobatual->addtfilamemoriaj(temp-jobatual->getentrafilamemoria());
    if (processador->getfilacpu()->filavazia() == false)
    {
        evento* event = new evento();
        event->setidevento(3);
        job* jobprov = processador->removejobfilacpu();
        jobprov->addtfilacpuj(temp-jobprov->getentrafilacpu());
        event->setjob(jobprov);
        event->settempo(temp + 5);
        processador->setjobatual(NULL);
        processador->alocajobcpu(jobprov);
        ListaDeEventos->insereeventolista(event);
    }
    else
        processador->setjobatual(NULL);

    evento* event2 = new evento();
    event2->setidevento(7);
    event2->settempo(temp + 5);
    event2->setjob(jobatual);

    ListaDeEventos->insereeventolista(event2);

}

void agendador::Evento7(evento* eventoatual)
{   job* jobatual=eventoatual->getjob();
    cout << "Evento 7 " << " Job " << eventoatual->getjob()->getid()
         << "Tempo Atual:" << eventoatual->gettempo() << endl;

    nfilacpu=nfilacpu+jobatual->getnfilacpuj();
    tfilacpu=tfilacpu+jobatual->gettfilacpuj();



    nfilamemoria=nfilamemoria+jobatual->getnfilamemoriaj();
    tfilamemoria=tfilamemoria+jobatual->gettfilamemoriaj();



    nfilaimp1=nfilaimp1+jobatual->getnfilaimp1j();
    tfilaimp1=tfilaimp1+jobatual->gettfilaimp1j();

    nfilaimp2=nfilaimp2+jobatual->getnfilaimp2j();
    tfilaimp2=tfilaimp2+jobatual->gettfilaimp2j();

    nfilaleit1=nfilaleit1+jobatual->getnfilaleit1j();
    tfilaleit1=tfilaleit1+jobatual->gettfilaleit1j();

    nfilaleit2=nfilaleit2+jobatual->getnfilaleit2j();
    tfilaleit2=tfilaleit2+jobatual->gettfilaleit2j();

    nfiladisco=nfiladisco+jobatual->getnfiladiscoj();
    tfiladisco=tfiladisco+jobatual->gettfiladiscoj();



}

