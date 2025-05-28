#include <bits/stdc++.h>
using namespace std;

struct studente
{
    string nome, cogn, matric, cod;
};

struct materia
{
    string codmat, desmat, cod;
};

struct corso
{
    string cod, des;
};

map<string, corso> corsoPerMatricola;
map<string, vector<corso>> corsiPerCognome;
map<string, map<string, studente>> studentiPerCorso;
map<string, map<string, materia>> materiePerCorso;
map<string, int> contaStudentiPerCorso;
map<string, int> contaStudentiPerMateria;
map<string, map<string, materia>> cercaMateriaPerDescrizione;

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

int main()
{
    char ch;
    bool finito = false;

    while (!finito)
    {
        stampamenu();
        cin >> ch;

        switch (ch)
        {
        case '1':
        {
            ifstream fin("corsi_studenti.csv");

            string codCorso, descrCorso, codMat, descrMat, matricola, cognome, nome;

            string labels;
            getline(fin, labels);

            while (!fin.eof())
            {
                getline(fin, codCorso, ',');
                getline(fin, descrCorso, ',');
                getline(fin, codMat, ',');
                getline(fin, descrMat, ',');
                getline(fin, matricola, ',');
                getline(fin, cognome, ',');
                getline(fin, nome);

                corso c{codCorso, descrCorso};
                materia m{codMat, descrMat, codCorso};
                studente s{nome, cognome, matricola, codCorso};

                corsoPerMatricola[matricola] = c;
                corsiPerCognome[cognome].push_back(c);
                studentiPerCorso[codCorso][matricola] = s;
                materiePerCorso[codCorso][descrMat] = m;
                contaStudentiPerCorso[codCorso]++;
                contaStudentiPerMateria[descrMat]++;
                cercaMateriaPerDescrizione[descrMat][codCorso] = m;
            }

            cout << "Dati caricati.\n";
            break;
        }

        case '2':
        {
            for (auto& x : corsoPerMatricola)
                cout << x.first << "       " << x.second.cod << "      " << x.second.des << "\n";
            break;
        }

        case '3':
        {
            for (auto& x : corsiPerCognome)
            {
                cout << x.first << ":\n";
                for (auto& c : x.second)
                    cout << "    " << c.cod << " - " << c.des << "\n";
            }
            break;
        }

        case '4':
        {
            for (auto& x : studentiPerCorso)
            {
                cout << "Corso: " << x.first << "\n";
                for (auto& y : x.second)
                {
                    const studente& s = y.second;
                    cout << "    " << s.cod << "  " << s.nome << "  " << s.cogn << "  " << s.matric << "\n";
                }
            }
            break;
        }

        case '5':
        {
            cout << "Dammi il codice di un corso: ";
            string t;
            cin >> t;
            auto it = materiePerCorso.find(t);
            if (it != materiePerCorso.end())
            {
                cout << "Materie per corso " << t << ":\n";
                for (auto& y : it->second)
                {
                    const materia& m = y.second;
                    cout << "    " << m.cod << "   " << m.codmat << "   " << m.desmat << "\n";
                }
            }
            else
            {
                cout << "Corso non trovato.\n";
            }
            break;
        }

        case '6':
        {
            for (auto& x : contaStudentiPerCorso)
                cout << x.first << "       " << x.second << "\n";
            break;
        }

        case '7':
        {
            for (auto& x : contaStudentiPerMateria)
                cout << x.first << "       " << x.second << "\n";
            break;
        }

        case '8':
        {
            cout<<"dammi descrizione di una materia"<<endl;
            cin.ignore();
            string t;
            getline(cin,t);


            for(auto x :  cercaMateriaPerDescrizione)
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
            ofstream fout("corsi_studenti.csv", ios::app);

            string codice, descrizionec, codicem, descrizionem, matricola, cognome, nnome;

            cout << "Inserisci il codice del corso: ";
            cin >> codice;
            cin.ignore();
            cout << "Inserisci descrizione del corso: ";
            getline(cin, descrizionec);
            cout << "Inserisci il codice materia: ";
            getline(cin, codicem);
            cout << "Inserisci descrizione materia: ";
            getline(cin, descrizionem);
            cout << "Inserisci matricola: ";
            getline(cin, matricola);
            cout << "Inserisci cognome: ";
            getline(cin, cognome);
            cout << "Inserisci il nome: ";
            getline(cin, nnome);

            fout << codice << ',' << descrizionec << ',' << codicem << ',' << descrizionem << ','
                 << matricola << ',' << cognome << ',' << nnome << '\n';

            cout << "Studente aggiunto.\n";
            break;
        }

        case 'X':
        case 'x':
            finito = true;
            break;

        default:
            cout << "Opzione non valida\n";
        }
    }

    return 0;
}
