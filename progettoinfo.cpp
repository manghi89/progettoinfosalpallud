#include <bits/stdc++.h>
using namespace std;
const int R=10;
const int C=30;
void stampamenu()
{
    cout << "*************************************************\n";
    cout << "* 1 - Carica dati da file                       *\n";
    cout << "* 2 - carica corsi di uno studente (matricola)  *\n";
    cout << "* 3 - carica corsi di uno studente (cognome)    *\n";
    cout << "* 4 - elenca studenti iscritti al corso         *\n";
    cout << "* 5 - stampa dati di un esame di un corso       *\n";
    cout << "* 6 - numero di studenti per corso              *\n";
    cout << "* 7 - numero di studenti per materia            *\n";
    cout << "* 8 - cerca materia per descrizione             *\n";
    cout << "* 9 - inserisci nuovo studente                  *\n";
    cout << "* 10 - salva i dati su file                     *\n";
    cout << "* X - Esci                                      *\n";
    cout << "*************************************************\n";
}
struct studente
{
    string nome,cogn,matric,cod;



};
struct materia
{
    string codmat,desmat,cod;



};
struct corso
{
    string cod,des;



};




int main()
{

    char ch;
    bool finito;
    map<string,corso> cmatricola;
    map<string,corso> corsi;

    map<string, map<string,studente>> studenti_per_codice_corso;
    map<string, map<string,materia>> materia_per_corso;
    map<string, int> contastud;
    map<string, int> contamat;
    map<string, map<string,materia>> cercamatperdes;
    vector<corso> x;
    while (!finito)
    {
        stampamenu();
        cin >> ch;

        switch (ch)
        {

        case '1':
        {
            string labels, codice, descrizionec, codicem,descrizionem,matricola,cognome,nnome;
            int i=0;
            corso y;
            ifstream fin("corsi_studenti.csv");
            ofstream fout("corsi_studenti.csv");
            if(!fin) cout<<"file non trovato"<<endl;
            getline(fin,labels);
            cout<<labels<<endl;
            while(!fin.eof())
            {
                getline(fin,codice,',');
                if(codice=="")break;
                getline(fin,descrizionec,',');
                getline(fin,codicem,',');
                getline(fin,descrizionem,',');
                getline(fin,matricola,',');
                getline(fin,cognome,',');
                getline(fin,nnome);

                corso c {codice, descrizionec};

                // corso per studente
                cmatricola[matricola] = c;

                // corso per codice corso
                //corsi[codice] = c;
                corsi[cognome]= c;

                studente m {nnome,cognome,matricola,codice};
                materia g {codicem,descrizionem,codice};
                studenti_per_codice_corso[codice][matricola]=m;
                materia_per_corso[codice][descrizionem]=g;
                contastud[codice]++;
                contamat[descrizionem]++;
                cercamatperdes[descrizionem][codice]=g;



            }




            break;
        }
        case '2':
            for(auto x : cmatricola) cout<<x.first<<"       "<<x.second.cod<<"      " <<x.second.des<<endl;


            break;

        case '3':
            for(auto x : corsi) cout<<x.first<<"       "<<x.second.cod<<"      " <<x.second.des<<endl;
            break;

        case '4':
        {

            for(auto x : studenti_per_codice_corso)
            {

                for(auto y : x.second)
                {
                    cout<<y.second.cod<<"       "<<y.second.nome<<"      " <<y.second.cogn<<"      " <<y.second.matric<<endl;

                }
            }

            break;
        }

        case '5':
        {
            cout<<"dammi il codice di un esame"<<endl;
            string t;
            cin>>t;

            for(auto x : materia_per_corso)
            {
                if(t==x.first)
                {
                    for(auto y : x.second)
                    {
                        cout<<y.second.cod<<"       "<<y.second.codmat<<"      " <<y.second.desmat<<endl;
                    }
                    break;

                }
            }


        }

        case '6':
            cout<<"gli studenti per corso sono"<<endl;
            for(auto x : contastud) cout<<x.first<<"       "<<x.second<<endl;


            break;

        case '7':
            cout<<"gli studenti per materia sono"<<endl;
            for(auto x : contamat) cout<<x.first<<"       "<<x.second<<endl;

            break;

        case '8':
        {
            cout<<"dammi descrizione di una materia"<<endl;
            cin.ignore();
            string t;
            getline(cin,t);


            for(auto x :  cercamatperdes)
            {
                if(t==x.first)
                {
                    for(auto y : x.second)
                    {
                        cout<<y.second.desmat<<"       "<<y.second.codmat<<"      " <<y.second.cod<<endl;
                    }
                    break;

                }
            }
        }


        case '9':
            {


             string  codice, descrizionec, codicem,descrizionem,matricola,cognome,nnome;

            ofstream fout("corsi_studenti.csv",ios::app);
            cout<<"inserisci il codice del corso"<<endl;
            cin>>codice;
            cout<<"inserisci descrizione del corso"<<endl;
            cin>>descrizionec;
            cout<<"inserisci il codice materia"<<endl;
            cin>>codicem;
            cout<<"inserisci descrizione materia"<<endl;
            cin>>descrizionem;
            getline(cin,descrizionem);
            cout<<"inserisci matricola"<<endl;
            cin>>matricola;
            cout<<"inserisci cognome"<<endl;
            cin>>cognome;
            cout<<"inserisci il nome"<<endl;
            cin>>nnome;
            fout<<endl;
            fout<<codice<<',';
            fout<<descrizionec<<',';
            fout<<codicem<<',';
            fout<<descrizionem<<',';
            fout<<matricola<<',';
            fout<<cognome<<',';
            fout<<nnome;
            break;
            }

        case 'X':
            finito = true;
            break;

        default:
            cout << "Opzione non valida\n";

        }

    }

    return 0;
}
