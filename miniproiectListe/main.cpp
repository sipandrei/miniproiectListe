#include <iostream>
#include <string.h>

using namespace std;

struct locatie
{
    locatie* urm;
    string denumire;
    string tip;
};

locatie* CreareLocatieNoua(string denumire, string tip){
    locatie* nou = new locatie;
    nou->urm = NULL;
    nou->denumire = denumire;
    nou->tip = tip;
    return nou;
}

void InserareLocatieDupaVal(locatie* &prim, string valoareCautata, string denumire, string tip)
{
    locatie* x = prim; 
    while(x -> denumire != valoareCautata && x -> urm != NULL)
        x = x -> urm;
    locatie* y = x -> urm;
    locatie* nou = CreareLocatieNoua(denumire, tip);
    x->urm = nou;
    nou->urm = y;
} 

void InserareLocatieInainteVal(locatie* &prim, string valoareCautata, string denumire, string tip)
{
    locatie* x = prim; 
    while(x -> urm -> denumire != valoareCautata && x -> urm != NULL)
        x = x -> urm;
    locatie* y = x -> urm;
    locatie* nou = CreareLocatieNoua(denumire, tip);
    x->urm = nou;
    nou->urm = y;
} 

void AdaugareLocatieInceput(locatie* &prim, string denumire, string tip)
{
    locatie* q;
    q = CreareLocatieNoua(denumire, tip);

    if(prim == NULL)
        prim = q;
    else
    {
        q -> urm = prim;
        prim = q;
    }
}

void AdaugareLocatieFinal(locatie* &prim, string denumire, string tip)
{
    locatie* q;
    q= CreareLocatieNoua(denumire, tip);
    if(prim == NULL)
        prim=q;
    else
    {
        locatie* t = prim;
        while(t->urm!= NULL)
        {
            t=t->urm;
        }
        t -> urm = q;
    }
}

void Afisare(locatie* prim, locatie* locatieActuala)
{
    locatie* q;
    q = prim;
    while(q != NULL)
    {
        if(q == locatieActuala)
            cout << "[*] ";
        else
            cout << "[ ] ";

        cout<<q->denumire<<" :P "<<q->tip << endl;
        q=q->urm;
    }

}
void AfisareTip(locatie* prim, locatie* locatieActuala, string tipCerut)
{
    locatie* q;
    q = prim;
    while(q != NULL)
    {
        if (tipCerut == q->tip)
        {
            if(q == locatieActuala)
                cout << "[*] ";
            else
                cout << "[ ] ";

            if(tipCerut== q->tip)
                cout<<q->denumire<<" :P "<<q->tip << endl;
        }  
        q=q->urm;            
    }

}

void Miscare(locatie* &locatieActuala, int numarMiscari)
{
    if(locatieActuala->urm == NULL)
        cout << "Ati ajuns la capatul tunelului! :)" << endl;
    else
        while (numarMiscari-1, locatieActuala->urm != NULL)
        {
            locatieActuala = locatieActuala -> urm;
            numarMiscari--;
        }    
}

int Meniu()
{
    cout << "Ce doresti sa faci?"  << endl;
    cout<< "1. Afisare Itinerariu"<<endl;
    cout<< "2. Mutare Urmatoare N Locatii"<<endl;
    cout<< "3. Afisare Locatie De Un Anumit Tip"<<endl;
    cout<< "4. Adaugare Locatie La Final"<<endl;
    cout<< "5. Adaugare Locatie La Inceput"<<endl;
    cout<< "6. Adaugare Locatie Dupa O Denumire"<<endl;
    cout<< "7. Adaugare Locatie Inainte De O Denumire"<<endl;

    int alegere;
    cin>>alegere;
    return alegere;
}

void CitireInfoNod(string &denumire, string &tip)
{
    cout << "Dati denumirea locatiei"<<endl;
    std::getline(std::cin >> std::ws, denumire, '\n'); 
    cout<<"Dati tipul locatiei"<<endl;
    std::getline(std::cin >> std::ws, tip, '\n');
}

int main()
{
    locatie* prim = NULL;
    int nr;
    string denumire, tip;
    string continuare = "y";
    string valoareaCautata;
    while (continuare == "y")
    {        
        CitireInfoNod(denumire, tip);

        AdaugareLocatieFinal(prim, denumire, tip);

        cout << "Doriti sa continuati cu alta locatie? y/n ";
        cin >> continuare;
    }
    locatie* locatieActuala = prim;
    continuare = "y";

    while (continuare == "y")
    {
        cout << endl;
        switch (Meniu())
        {
        case 1:
            Afisare(prim, locatieActuala);
            break;
        
        case 2:
            cout << "Cu cate pozitii doriti sa va miscati?" << endl;
            cin >> nr;
            Miscare(locatieActuala, nr);
            break;
        
        case 3:
            cout << "Ce tip de locatie cautati?" << endl;
            std::getline(std::cin >> std::ws, valoareaCautata, '\n');
            AfisareTip(prim, locatieActuala, valoareaCautata);
            break;

        case 4:
            CitireInfoNod(denumire, tip);
            AdaugareLocatieFinal(prim, denumire, tip);
            break;

        case 5:
            CitireInfoNod(denumire, tip);
            AdaugareLocatieInceput(prim, denumire, tip);
            break;
        
        case 6:
            CitireInfoNod(denumire, tip);
            cout<<"Dupa ce locatie vreti sa inserati?" << endl;
            std::getline(std::cin >> std::ws, valoareaCautata, '\n');
            InserareLocatieDupaVal(prim,valoareaCautata, denumire, tip);
            break;
        
        case 7:
            CitireInfoNod(denumire, tip);
            cout<<"Inainte de ce locatie vreti sa inserati?" << endl;
            std::getline(std::cin >> std::ws, valoareaCautata, '\n');
            InserareLocatieInainteVal(prim, valoareaCautata, denumire, tip);
            break;

        default:
            cout << "Dati o valoare de la 1 la 7" << endl;
            continue; 
            break;
        }

        cout << "Doriti sa continuati? y/n ";
        cin >> continuare;        
    }
    
    cout << "Goodbye! o7";
    
    return 0;
}
