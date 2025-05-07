#include <bits/stdc++.h>
using namespace std;
const int R=10;
const int C=30;
void stampamenu() {
    cout << "*************************************************\n";
    cout << "* I - Carica i dati                             *\n";
    cout << "* P - Stampa dati                               *\n";
    cout << "* M - Indice giorno piu' piovoso                *\n";
    cout << "* Z - Stampa indici delle citta' senza pioggia  *\n";
    cout << "* A - Media di pioggia per citta'               *\n";
    cout << "* H - Citta' con il totale di pioggia pia' alta *\n";
    cout << "*                                               *\n";
    cout << "* X - Esci                                      *\n";
    cout << "*************************************************\n";
}


int main() {

    bool finito = false;
    char ch;

    while (!finito) {
        stampamenu();
        cin >> ch;

        switch (ch) {

            case 'I':

                break;

            case 'P':

                break;

            case 'M':

                break;

            case 'Z':

                break;

            case 'A':

                break;

            case 'H':
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
