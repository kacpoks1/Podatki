#include <iostream>
#include <locale.h>
#include "Podatki.h"

using namespace std;

class podatek {

    public:

        virtual double obliczPodatek(double kwota) = 0;

};

class pit : podatek {
    
    public:

        double obliczPodatek(double kwota)

          {
            if (kwota <= 120000) {
                
                
                return (kwota * 0.12) - 3600;


            }
           
            
            else {
                
                double roznica = 0
                
                roznica = (kwota - 120000);
                return (roznica * 0.32) + 10800;
                

            }
          }
};

class cit : podatek {

    public:
        
        double obliczPodatek(double kwota) 
        {
            return kwota * 0.02;

        }
};

class spadek : podatek {

    public:

        double obliczPodatek(double kwota)
        {
            int roznica = 0;
            roznica = kwota - 11128;
            return (roznica * 0.05) + 333.90;

        }
};

class vat : podatek {
    
    public:
        
        double obliczPodatek(double kwota)
        {
            return kwota = 0.23;
        }
};

int main()
{
    setlocale(LC_CTYPE, "Polish");

    double kwota;
    char typ;
    double podatekPit;
    double podatekCit;
    double podatekSpadek;
    double podatekVat;


    cout << "Jaki podatek chcesz obliczyæ? PIT, CIT, Spadkowy (spd) czy VAT. Wpisz: ";
    cin >> typ;
    cout << "Z jakiej kwoty chcesz obliczyæ ten podatek? Wpisz: ";
    cin >> kwota;

    typ* podatekPit = new pit();
    typ* podatekCit = new cit();
    typ* podatekSpadek = new spadek();
    typ* podatekVat = new vat();


    switch (typ)
    {
        case 'cit': {
            
            cout << pit->obliczPodatek(kwota);
            
            if (kwota <= 0) {
                cout << "nic nie p³acisz :)";
            }
            else {

                cout << "Podatek wynosi: " << kwota;
            }
        }
            break;

        case 'cit': {
            cout << cit->obliczPodatek(kwota);
        }
            
            break;

        case 'spd': {
            cout << spadek->obliczSpadek(kwota);
        }
            
            break;

        case 'vat': {
            cout << vat->obliczPodatek(kwota);
        }
            
            break;

        default:
            break;
    }




}


