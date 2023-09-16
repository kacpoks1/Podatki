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
     


    switch (typ)
    {
    case 'p': {

        pit obiekt;

        cout << "Podatek wynosi: " << obiekt.obliczPodatek(kwota);

        break;
    }

    case 'c': {

        cit obiekt;

        cout << "Podatek wynosi: " << obiekt.obliczPodatek(kwota);

        break;
    }
    case 's': {

        spadek obiekt;

        cout << "Podatek wynosi: " << obiekt.obliczPodatek(kwota);

        break;
    }
    case 'v': {

        vat obiekt;

        cout << "Podatek wynosi: " << obiekt.obliczPodatek(kwota);

        break;
    }
    default:
        break;

    }

}