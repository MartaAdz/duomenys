#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <fstream>
#include <algorithm>
#include "studentas.h"
#include "vidurkis.h"
#include "mediana.h"
#include "generavimas.h"

using std::cout; using std::cin; using std::endl; using std::vector; using std::setw;
using std::size_t;

void pasirinkimas(studentas &S){
    cout<<"Skaiciuojame galutini bala\n1-Naudoti vidurki\n2-Naudoti mediana"<<endl;
    int a;
    cin>>a;
    auto kintamieji=S.pazymiai.size()-1;

    while(a!=1||a!=2)
    {

        if(a==1)
        {

            auto nDarSuma=0;
            for(int i=0; i<kintamieji; i++) nDarSuma+=S.pazymiai[i];

            S.galBalasVid=vidurkis(nDarSuma, kintamieji, S.egzaminas);
            cout.precision(3);
            cout<<S.galBalasVid;
            break;
        }

                    else if(a==2)
                    {
                        S.galBalasMed=mediana (S.pazymiai, kintamieji, S.egzaminas);
                        cout.precision (3);
                        cout<<S.galBalasMed;
                        break;
                    }

                    else
                    {
                        cout<<"Neteisingai ivestas pasirinkimas\nIveskite is naujo"<<endl;
                        cin>>a;
                    }

                    break;
            }
        }
void stud_isvedimas(vector<studentas>S){

      for(size_t c=0; c < S.size() ; c++)
        {
            cout<<std::left<<setw(20)<<S[c].vardas
                            <<setw(20)<<S[c].pavarde;
            vidurkis(S[c]);
            mediana(S[c]);
            cout<<"\n";
        }
}