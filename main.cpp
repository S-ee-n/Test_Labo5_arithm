#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <cmath> // pour la fonction round()

using namespace std;

double saisie() {
    bool bonne_saisie = false;
    double n = 0.0;
    double min = 0;
    int long long max = 999999999999999.99;
    do {
        bonne_saisie = (cin >> n) && (n >= min) && (n <= max);
        if (!bonne_saisie) {
            cout << "erreur : montant ";
            if (n < min) {
                cout << "negatif" << endl;
            } else if (n > max) {
                cout << "trop grand" << endl;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (!bonne_saisie);
    return n;
}

// chaque paquet de mille :

void exprime_paquet_mille(string nombre, int numero_paquet) {

    // centaines
    switch (nombre[nombre.length() - 3 * numero_paquet]) {
        case '0': cout << "rien ";
            break;
        case '1': cout << "cent ";
            break;
        case '2': cout << "deux cents ";
            break;
        case '3': cout << "trois cents ";
            break;
        case '4': cout << "quatre cents ";
            break;
        case '5': cout << "cinq cents ";
            break;
        case '6': cout << "six cents ";
            break;
        case '7': cout << "sept cents ";
            break;
        case '8': cout << "huit cents ";
            break;
        case '9': cout << "neuf cents ";
            break;
    }

    // dizaines
    switch (nombre[nombre.length() - 3 * numero_paquet + 1]) {
        case '0': cout << "rien ";
            break;
        case '1': cout << "dix-";
            break;
        case '2': cout << "vingt-";
            break;
        case '3': cout << "trente-";
            break;
        case '4': cout << "quarante-";
            break;
        case '5': cout << "cinquante-";
            break;
        case '6': cout << "soixante-";
            break;
        case '7': cout << "septante-";
            break;
        case '8': cout << "huitante-";
            break;
        case '9': cout << "nonante-";
            break;
    }

    // unités
    switch (nombre[nombre.length() - 3 * numero_paquet + 2]) {
        case '0': cout << "rien ";
            break;
        case '1': cout << "un ";
            break;
        case '2': cout << "deux ";
            break;
        case '3': cout << "trois ";
            break;
        case '4': cout << "quatre ";
            break;
        case '5': cout << "cinq ";
            break;
        case '6': cout << "six ";
            break;
        case '7': cout << "sept ";
            break;
        case '8': cout << "huit ";
            break;
        case '9': cout << "neuf ";
            break;
    }
}

void exprime_separation(int numero_paquet) {
    switch (numero_paquet) {
        case 5: cout << "billions ";
            break;
        case 4: cout << "milliards ";
            break;
        case 3: cout << "millions ";
            break;
        case 2: cout << "mille ";
            break;
    }
}

int main() {

    // Conversion en string de la saisie utilisateur
    double n = saisie();
    stringstream flux_pour_pt_entiere;
    stringstream flux_pour_pt_decimale;

    flux_pour_pt_entiere << fixed << setprecision(0) << n;
    flux_pour_pt_decimale << fixed << setprecision(0) << (n-ceil(n-1))*100;

    string pt_entiere = flux_pour_pt_entiere.str();
    string pt_decimale = flux_pour_pt_decimale.str();

    cout << "(string) pt_entiere = " << pt_entiere << endl;
    cout << "(string) pt_decimale = " << pt_decimale << endl;

    int numero_paquet = ceil(pt_entiere.size() / 3.0);

    // exprime la partie entière en CHF
    for (int i = numero_paquet; i >= 1; --i) {
        exprime_paquet_mille(pt_entiere, i);
        exprime_separation(i);
    }

    cout << "francs et ";

    // exprime la partie decimale en ct
    for (int i = numero_paquet; i >= 1; --i) {
        exprime_paquet_mille(pt_decimale, i);
        // pas de "exprime_separation()" car pas besoin ici
    }

    cout << "centimes." << endl;

    return 0;
}


