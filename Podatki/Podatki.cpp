#include <iostream>
#include <locale.h>


using namespace std;

class podatek {

    public:

        virtual double obliczPodatek(double kwota) = 0;

};

class pit : public podatek {
    
    public:

        double obliczPodatek(double kwota)

          {
            if (kwota <= 120000) {
                
                
                return (kwota * 0.12) - 3600;


            }
           
            
            else {
                
                double roznica = 0;
                
                roznica = (kwota - 120000);
                return (roznica * 0.32) + 10800;
                

            }
          }
};

class cit : public podatek {

    public:
        
        double obliczPodatek(double kwota) 
        {
            return kwota * 0.02;

        }
};

class spadek : public podatek {

    public:

        double obliczPodatek(double kwota)
        {
            double roznica = 0;
            roznica = kwota - 11128;
            return (roznica * 0.05) + 333.90;

        }
};

class vat : public podatek {
    
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

 //   typ* podatekPit = new pit();
 //   typ* podatekCit = new cit();
 //   typ* podatekSpadek = new spadek();
//    typ* podatekVat = new vat();


    switch (typ)
    {
        case 'pit': {
            
            kwota* podatekPit = new pit();

          //  cout << pit.obliczPodatek(kwota);
            
        }
            break;

        case 'cit': {
            
            kwota* podatekCit = new cit();

            //cout << cit.obliczPodatek(kwota);
        }
            
            break;

        case 'spd': {
            
            kwota* podatekSpadek = new spadek();
            
            //cout << spadek.obliczSpadek(kwota);
        }
            
            break;

        case 'vat': {

            kwota* podatekVat = new vat();

            //cout << vat.obliczPodatek(kwota);
        }
            
            break;

        default:
            break;
    }




}


