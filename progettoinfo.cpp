#include <bits/stdc++.h>
using namespace std;
const int R=10;
const int C=30;
void stampamenu() {
    cout << "*************************************************\n";
    cout << "* 1 - Carica dati da file                       *\n";
    cout << "* 2 - carica corsi di uno studente (matricola)  *\n";
    cout << "* 3 - carica corsi di uno studente (cognome)    *\n";
    cout << "* 4 - elenca studenti iscritti al corso         *\n";
    cout << "* 5 - numero di studenti per corso              *\n";
    cout << "* 6 - numero di studenti per materia            *\n";
    cout << "* 7 - cerca materia per descrizione             *\n";
    cout << "* 8 - inserisci nuovo studente                  *\n";
    cout << "* 9 - salva i dati su file                      *\n";
    cout << "* X - Esci                                      *\n";
    cout << "*************************************************\n";
}
struct studente{
    string nome,cogn,matric,cod;



};
struct materia{
    string codmat,desmat,cod;



};
struct corso{
    string cod,des;



};




int main() {

    char ch;
    bool finito;
    map<string,corso> cmatricola;
    map<string,corso> corsi;
    map<string, vector<studente>  > studenti_2;
    vector<corso> x;
    while (!finito) {
        stampamenu();
        cin >> ch;

        switch (ch){

            case '1':{
                           string labels, codice, descrizionec, codicem,descrizionem,matricola,cognome,nnome;
                           int i=0;
                           corso y;
                           ifstream fin("corsi_studenti.csv");
                           if(!fin) cout<<"file non trovato"<<endl;
                           getline(fin,labels);
                           cout<<labels<<endl;
                           while(!fin.eof()){
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
                                       corsi[codice] = c;

                                       studente m {nnome,cognome,matricola,codice};

//                                       studenti_2[studente].push_back(m);

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

                break;

            case '5':

                break;

            case '6':
                break;

            case '7':

                break;

            case '8':

                break;

            case '9':

                break;


            case 'X':
                finito = true;
                break;

            default:
                cout << "Opzione non valida\n";

        }

    }

    return 0;
}
