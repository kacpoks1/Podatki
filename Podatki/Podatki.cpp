#include <iostream>
#include <locale.h>


using namespace std;

class podatek {

public:

    virtual double obliczPodatek(double& kwota) = 0;

};

class pit  {

public:

    double obliczPodatek(double& kwota)

    {
        if (kwota <= 120000) {

            double x;
            x = (kwota * 0.12) - 3600;

            if (x <= 0) {
                cout << "nic nie p³acisz";
                return 0;
            }
            else {
                
                cout << x;
                return 0;
            }

           

        }


        else {

            double roznica = 0;

            roznica = (kwota - 120000);
            cout << (roznica * 0.32) + 10800;

            return 0;
        }
    }
};

class cit : public podatek {

public:

    double obliczPodatek(double& kwota)
    {
        cout <<  (kwota * 0.02);
        return 0;
    }
};

class spadek : public podatek {

public:

    double obliczPodatek(double& kwota)
    {
        double roznica = 0;
        roznica = kwota - 11128;
        cout <<  (roznica * 0.05) + 333.90;
        return 0;
    }
};

class vat : public podatek {

public:
    
    double obliczPodatek(double& kwota)
    {
        cout << (kwota * 0.23);
        return 0;
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
    
    
   cout << "Z jakiej kwoty chcesz obliczyæ podatek? Wpisz: ";
    cin >> kwota;

    cout << "Jaki podatek chcesz obliczyæ? PIT (p), CIT (c), Spadkowy (spd) czy VAT (v). Wpisz: ";
    cin >> typ;
     

    //   typ* podatekPit = new pit();
    //   typ* podatekCit = new cit();
    //   typ* podatekSpadek = new spadek();
   //    typ* podatekVat = new vat();


    switch (typ)
    {
    case 'p': {

        //kwota* podatekPit = new pit();

        pit obiekt;


        obiekt.obliczPodatek(kwota);




        break;
    }

    case 'c': {

        //kwota* podatekCit = new cit();

        cit obiekt;

        obiekt.obliczPodatek(kwota);



        break;
    }
    case 's': {

        //kwota* podatekSpadek = new spadek();

        spadek obiekt;

        obiekt.obliczPodatek(kwota);

        break;
    }
    case 'v': {

        //kwota* podatekVat = new vat();

        vat obiekt;

        obiekt.obliczPodatek(kwota);



        break;
    }
    default:
        break;



    }

}