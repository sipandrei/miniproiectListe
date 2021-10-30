#include <iostream>
#include <string.h>

using namespace std;

struct locatie
{
    locatie* urm;
    string denumire;
};

locatie* CreareLocatieNoua(string denumire){
    locatie* nou = new locatie;
    nou->urm = NULL;
    nou->denumire = denumire;
    return nou;
}

int main()
{
    locatie* a = CreareLocatieNoua("Pitesti");
    cout << a->denumire;
    return 0;
}
