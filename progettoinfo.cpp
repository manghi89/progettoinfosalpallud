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
struct corsi{
    string cod,des,codmat,desmat,matric,cogn,nome;



};



int main() {


    bool finito = false;
    char ch;
    vector<corsi> x;





    while (!finito) {
        stampamenu();
        cin >> ch;

        switch (ch){

            case '1':{
                           string labels;
                           corsi y;
                           ifstream fin("corsi_studenti.csv");
                           if(!fin) cout<<"Bombvardilo crocodilo"<<endl;
                           getline(fin,labels);
                           cout<<labels<<endl;
                           while(!fin.eof()){
                               getline(fin,y.cod,',');
                               if(y.cod=="")break;
                               getline(fin,y.des,',');
                               getline(fin,y.codmat,',');
                               getline(fin,y.desmat,',');
                               getline(fin,y.matric,',');
                               getline(fin,y.cogn,',');
                               getline(fin,y.nome);

                               cout<<y.cod<<"   "<<y.des<<"   "<<y.codmat<<"   "<<y.desmat<<"   "<<y.matric<<"   "<<y.cogn<<"   "<<y.nome<<endl;
                               }

                break;
            }
            case '2':

                break;

            case '3':

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
