//
// Created by Private on 5/26/2023.
//

#include "RegisterCommand.h"

void RegisterCommand::PrintHelpCommand() {
    cout << "register - Cli za registrovanje novih naloga" << endl;
}

void RegisterCommand::Execute(queue<string> *args) {
    cout << "Dobrodosli u CLI za registraciju ! Molim vas unesite zeljeni username: " << endl;
    string username;
    cin >> username;
    cout << "Unesite ime: " << endl;
    string ime;
    cin >> ime;
    cout << "Unesite prezime" << endl;
    string prezime;
    cin >> prezime;
    cout << "Unesite zeljenu sifru: " << endl;
    string password;
    cin >> password;
    try {
        manager->AddKorisnik(username, ime, prezime, password);
        cout << "Novi korisnik uspesno dodat ! Mozete se ulogovati" << endl;
    } catch (KorisnikExistException &) {
        cout << "Zao nam je, korisnik sa tim username-om vec postoji :(" << endl;
    }
}
