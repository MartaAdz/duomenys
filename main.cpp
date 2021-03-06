#include <iostream>
#include <iomanip>
#include <fstream>
#include <random>
#include <algorithm>
#include <ctime>
#include <ratio>
#include <chrono>
#include <vector>
#include <list>
#include <deque>
#include "studentas.h"
#include "vidurkis.h"
#include "mediana.h"
#include "generavimas.h"
#include "isvedimas.h"
#include "nuskaitymas.h"
#include "rikiavimas.h"
#include "skirstymas.h"

using std::cout; using std::cin; using std::endl; using std::string; using std::vector; using std::list; using std::deque;
int main()
{
    cout<<"STUDENTU INFORMACIJA APDOROJANTI PROGRAMA"<<endl;
    cout<<"1 - Nuskaityti is failo\n2 - Ivesti ranka \n";

    int p;
    cin>>p;

    if(p==1){

        unsigned int stud_kiekis;
        cout<<"Generuojamu studentu kiekis: ";
        cin>>stud_kiekis;

        const int paz_kiekis = 5;

        studentu_generavimas(stud_kiekis, paz_kiekis);

        std::ifstream duomenys("kursiokai.txt");

        try{
            if(duomenys.fail())
            {
                throw std::exception();
            }
        }
        catch (std::exception &e1)
        {   e1.what();
            cout<<"Tokio failo nera. Baigiu programa.";
            exit(1);
        }

       cout<<"Pasirinkite konteinerio tipa:\n1 - Naudoti deque\n2 - Naudoti list\n3 - Naudoti vector\n";
       int naud;
       cin>>naud;

       using namespace std::chrono;

       if (naud==1){

            high_resolution_clock::time_point t_dek_1 = high_resolution_clock::now();

            deque<studentas> stud_dek;
            nuskaitymas_dek(stud_dek, duomenys, paz_kiekis);
            rikiavimas_dek(stud_dek);

            high_resolution_clock::time_point t_dek_2 = high_resolution_clock::now();
            duration<double> time_dek = duration_cast<duration<double>>(t_dek_2 - t_dek_1);

            cout<<"1 - Skirstyti trinant is bendro konteinerio\n2 - Skirstyti perkeliant i du atskirus konteinerius\n";
            int skirstymas;
            cin>>skirstymas;

            high_resolution_clock::time_point t_dek_3 = high_resolution_clock::now();

            if (skirstymas==1)
            {
                deque<studentas> blogi;
                skirstymas_trinant_dek(stud_dek, blogi);
                stud_toFile_dek(stud_dek);

            }
            if (skirstymas==2)
            {
                deque<studentas> geri;
                deque<studentas> blogi;
                skirstymas_dek(stud_dek, stud_kiekis, geri, blogi);
                stud_toFile_dek(geri);
            }

                high_resolution_clock::time_point t_dek_4 = high_resolution_clock::now();
                duration<double> time_dek_2 = duration_cast<duration<double>>(t_dek_4 - t_dek_3);

            cout<<"Faile issaugoti pazangus studentai.\n";

            cout << "Su deque uztruko " << time_dek.count()+time_dek_2.count()<< " sekundziu.\n";
        }
        else if (naud==2) {

            high_resolution_clock::time_point t_list_1 = high_resolution_clock::now();

            list<studentas> stud_list;
            nuskaitymas_list(stud_list, duomenys, paz_kiekis);
            rikiavimas_list(stud_list);

            high_resolution_clock::time_point t_list_2 = high_resolution_clock::now();
            duration<double> time_list = duration_cast<duration<double>>(t_list_2 - t_list_1);

            cout<<"1 - Skirstyti trinant is bendro konteinerio\n2 - Skirstyti perkeliant i du atskirus konteinerius\n";
            int skirstymas;
            cin>>skirstymas;

            high_resolution_clock::time_point t_list_3 = high_resolution_clock::now();

            if (skirstymas==1)
            {
                list<studentas> blogi;
                skirstymas_trinant_list(stud_list, blogi);
                stud_toFile_list(stud_list);

            }
            if (skirstymas==2)
            {
                list<studentas> geri;
                list<studentas> blogi;
                skirstymas_list(stud_list, geri, blogi);
                stud_toFile_list(geri);
            }

            high_resolution_clock::time_point t_list_4 = high_resolution_clock::now();
            duration<double> time_list_2 = duration_cast<duration<double>>(t_list_4 - t_list_3);

            cout<<"Faile issaugoti pazangus studentai.\n";

            cout << "Su list uztruko " << time_list.count() + time_list_2.count() << " sekundziu.\n";
        }
        else if (naud==3){

            high_resolution_clock::time_point t_vec_1 = high_resolution_clock::now();

            vector<studentas> S;
            nuskaitymas_vec (S, duomenys, paz_kiekis);
            rikiavimas_vec(S);

            high_resolution_clock::time_point t_vec_2 = high_resolution_clock::now();
            duration<double> time_vec = duration_cast<duration<double>>(t_vec_2 - t_vec_1);

            cout<<"1 - Skirstyti trinant is bendro konteinerio\n2 - Skirstyti perkeliant i du atskirus konteinerius\n";
            int skirstymas;
            cin>>skirstymas;

            high_resolution_clock::time_point t_vec_3 = high_resolution_clock::now();

            if (skirstymas==1)
            {
                vector<studentas> blogas;
                skirstymas_trinant_vec(S, blogas);
                stud_toFile_vec(S);

            }
            if (skirstymas==2)
            {
                vector<studentas> geras;
                vector<studentas> blogas;
                skirstymas_vec(S, stud_kiekis, geras, blogas);
                stud_toFile_vec(geras);
            }

            high_resolution_clock::time_point t_vec_4 = high_resolution_clock::now();
            duration<double> time_vec_2 = duration_cast<duration<double>>(t_vec_4 - t_vec_3);

            cout<<"Faile issaugoti pazangus studentai.\n";

            cout << "Su vektoriumi uztruko " << time_vec.count() + time_vec_2.count() << " sekundziu.";
        }
    }
    else if(p==2) {
        auto d=1;
        vector<studentas> S;
        studentas stud;
        while(d!=2){

            cout<<"Iveskite studento varda ir pavarde: ";
            string var, pav;
            cin>>var>>pav;
            stud.vardas=var;
            stud.pavarde=pav;

            cout<<"1 - Generuoti pazymius\n2 - Ivesti pazymius \n";
            int p;
            cin>>p;


            if(p==1){

                cout<<"Generuojamu pazymiu kiekis: ";
                int kiekis;
                cin>>kiekis;

                iverciai (stud, kiekis);

                for(int j=0; j<kiekis; j++) cout<<stud.pazymiai[j]<<" ";

                cout<<"\n";
                pasirinkimas(stud);

            }
            else if (p==2)
            {
                ivesti_pazymiai(stud);
                cout<<"Iveskite egzamino pazymi: ";
                cin>>stud.egzaminas;

                pasirinkimas(stud);
            }

            S.push_back(stud);
            cout<<"\n1 - Testi duomenu ivedima\n2 - Baigti duomenu ivedima\n";
            cin>>d;
        }
    }

 return 0;
}
