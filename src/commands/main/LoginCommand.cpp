//
// Created by Private on 5/26/2023.
//

#include "LoginCommand.h"

void LoginCommand::PrintHelpCommand() {
    cout << "login <username> - Logovanje na korisnicki/admin panel" << endl;
}

void LoginCommand::Execute(queue<string> *args) {
    if (args->empty()) {
        PrintHelpCommand();
        return;
    }
    string username = args->front();
    args->pop();
    cout << "Unesite password za nalog " << username << ":" << endl;
    string password;
    cin >> password;
    try {
        Korisnik &korisnik = manager->TryLogin(username, password);
        cout << "Uspesno ste ulogovani kao " << korisnik.GetFullIme() << ", prebacujemo vas na "
             << (korisnik.IsAdmin() ? "admin" : "korisnicki") << " panel !";
    } catch (AuthException &err) {
        cout << "Pogresno korisnicko ime ili lozinka, pokusajte ponovo !" << endl;
    }
}
