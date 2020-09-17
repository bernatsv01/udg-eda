/*
 *  estructuraDinamica.h
 *  EstructuraDinamica
 *
 *  Created by Santi Espigule & Joan Surrell.
 *  Copyright (c) 2004, 2005 IMA-UdG.
 *
 * Aquest fitxer es comu a tots els programes que usen l'estructura circular
 * simplement encadenada amb sentinella.   
 *
 * JSS - 2008
 *    cal afegir-hi els metodes a implementar
 * JSS [ACS] - 2010
 *    s'ha canviat una diferencia amb el codi de l'enunciat  
 */

#include "estructuraDinamica.h"
#include <iostream>

using namespace std;

estructuraDinamica::estructuraDinamica(){
    inici = new node;
    inici->seguent = inici;
    inici->dada = 0;
}

estructuraDinamica::estructuraDinamica(estructuraDinamica &e){
    inici = new node;
    inici->seguent = inici;
    inici->dada = 0;
    if(e.inici->seguent != e.inici){
        node *ant, *p, *q;
        p = e.inici->seguent;
        q = new node;
        inici->seguent = ant = q;
        q->dada = p->dada;
        p = p->seguent;
        while(p != e.inici){
            q = new node;
            q->dada = p->dada;
            q->seguent = inici;
            ant->seguent = q;
            ant = q;
            p = p->seguent;
        }
        q->seguent = inici;
    }
}

estructuraDinamica::~estructuraDinamica(){
    while(inici->seguent != inici){
        node *aux = inici->seguent;
        inici->seguent = aux->seguent;
        delete aux;
    }

}

void estructuraDinamica::AfegirInici(int i){
    node *p = new node;
    p->dada = i;
    p->seguent = inici->seguent;
    inici->seguent = p;
}

void estructuraDinamica::Llistar() const{
    if(inici != inici->seguent){
        node *p = inici->seguent;
        while(p != inici){
            cout << p->dada << " ";
            p = p->seguent;
        }
    }
    cout << "S:" << inici->dada << endl; // llista el sentinella
}
