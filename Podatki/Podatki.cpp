#include <iostream>
#include <locale.h>


using namespace std;


class podatek {

public:

    virtual double obliczPodatek(double& kwota) = 0;

};

class pit : public podatek {

public:

    double obliczPodatek(double& kwota)

    {
        if (kwota <= 120000) {

            double x;
            x = (kwota * 0.12) - 3600;

            if (x <= 0) {
                
                return 0;
            }
            else {
                return x;
            }

        }


        else {

            return ((kwota - 120000) * 0.32) + 10800;
        }
    }
};

class cit : public podatek {

public:

    double obliczPodatek(double& kwota){
    
        return (kwota * 0.02);
    }
};

class spadek : public podatek {

public:

    double obliczPodatek(double& kwota)
    {
       
        return ((kwota - 11128) * 0.05) + 333.90;
    }
};

class vat : public podatek {

public:
    
    double obliczPodatek(double& kwota)
    {
        
        return (kwota * 0.23);
    }
};

int main()
{
    setlocale(LC_CTYPE, "Polish");

    double kwota;
    char typ;
    
    
    cout << "Z jakiej kwoty chcesz obliczyæ podatek? Wpisz: ";
    cin >> kwota;

    cout << "Jaki podatek chcesz obliczyæ? PIT (p), CIT (c), Spadkowy (s) czy VAT (v). Wpisz: ";
    cin >> typ;
     
    podatek* obiektPodatku = nullptr;


    switch (typ)
    {
    case 'p': {

        obiektPodatku = new pit();

        break;
    }

    case 'c': {

        obiektPodatku = new cit();

        break;
    }
    case 's': {

        obiektPodatku = new spadek();

        break;
    }
    case 'v': {

        obiektPodatku = new vat();

        break;
    }
    default:
        break;

    }

    if (obiektPodatku) {
        cout << "Podatek wynosi: " << obiektPodatku->obliczPodatek(kwota) << endl;
        delete obiektPodatku; 
    }
    else {
        cout << "Nieprawid³owy wybór podatku." << endl;
    }

            return 0;
}