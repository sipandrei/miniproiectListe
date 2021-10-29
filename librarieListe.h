#include <iostream>

using namespace std;

struct nod{
    int val;
    nod* urm, ant;
};

nod* CreareNodNou(int x){
    nod* p = new nod;
    p -> val = x;
    p -> urm = NULL;
    p -> ant = NULL;
}

void AdaugareNodInceput(nod* &prim, int x){
    nod* q;
    q = CreareNodNou(x);

    if(prim == NULL)
        prim = q;
    else
    {
        q -> urm = prim;
        prim = q;
    }
}

void AdaugareNodFinal(nod* &prim, int x){
    nod* q;
    q = CreareNodNou(x);

    if(prim == NULL)
        prim = q;
    else
    {
        nod* t;
        t = prim;
        while(t->urm != NULL)
            t = t->urm;
        t->urm = q;
        q->ant = t;
    }
}

void StergerePrimulNod(nod* &prim){
    if(prim != NULL & prim->urm != NULL)
    {
        nod* a = prim;
        prim = prim->urm;
        prim->ant = NULL;
        delete a;
    }
    else if(prim != NULL);
    {
        nod* a = prim;
        prim = NULL;
        delete a;
    }
}

void StergereUltimNod(nod* &prim){
    if(prim->urm == NULL && prim != NULL)
        StergerePrimulNod(prim);
    else if(prim != NULL)
    {
        nod* t = prim;
        while(t->urm->urm != NULL)
            t = t->urm;
        delete t->urm;
        t->urm = NULL;
    }
}

void ListareStgDr(nod* prim){
    while(prim != NULL)
    {
        cout << prim->val;
        prim = prim->urm;
    }
}

void ListareDrStg(nod* prim){
    nod* t = prim;
    while(t->urm != NULL)
        t = t->urm;
    while(t!=NULL)
    {
        cout << t->val;
        t = t->ant;
    }
}

void InserareDupaPozitie(nod* prim, int k, int val){
    nod* x = prim;
    for(int i = 1; i<=k, x->urm!=NULL; i++)
        x = x->urm;
    nod* y = x -> urm;
    nod* nou = CreareNodNou(val);
    x->urm = nou;
    y->ant = nou;
    nou->ant = x;
    nou->urm = y;
}

void InserareInaintePozitie(nod* prim, int k, int val){
    nod* x = prim;
    for(int i = 1; i<=k, x->urm!=NULL; i++)
        x = x->urm;
    nod* y = x -> ant;
    nod* nou = CreareNodNou(val);
    x->ant = nou;
    y->urm = nou;
    nou->urm = x;
    nou->ant = y;
}

void InserareInainteValoare(nod* prim, int k, int val){
    nod* x = prim;
    while(x->val!=k, x->urm!=NULL)
        x = x->urm;
    nod* y = x -> ant;
    nod* nou = CreareNodNou(val);
    x->ant = nou;
    y->urm = nou;
    nou->urm = x;
    nou->ant = y;
}

void InserareDupaValoare(nod* prim, int k, int val){
    nod* x = prim;
    while(x->val!=k, x->urm!=NULL)
        x = x->urm;
    nod* y = x -> urm;
    nod* nou = CreareNodNou(val);
    x->urm = nou;
    y->ant = nou;
    nou->ant = x;
    nou->urm = y;
}

void StergerePozitie(nod* prim, int k){
    nod* x = prim;
    for(int i = 1; i<=k, x->urm!=NULL; i++)
        x = x->urm;
    x->ant->urm = x->urm;
    x->urm->ant = x->ant;
    delete x;
}

void StergereValoare(nod* prim, int k){
    nod* x = prim;
    while(x->val!=k, x->urm!=NULL)
        x = x->urm;
    x->ant->urm = x->urm;
    x->urm->ant = x->ant;
    delete x;
}
