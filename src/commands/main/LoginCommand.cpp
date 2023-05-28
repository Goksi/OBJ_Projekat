//
// Created by Private on 5/26/2023.
//

#include "LoginCommand.h"
#include "KorisnikCommand.h"
#include "HotelCommand.h"

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
        Korisnik &korisnik = korisnikManager->TryLogin(username, password);
        cout << "Uspesno ste ulogovani kao " << korisnik.GetFullIme() << ", dobrodosli na "
             << (korisnik.IsAdmin() ? "admin" : "korisnicki") << " panel !" << endl;
        if (korisnik.IsAdmin()) {
            CommandHandler handler("admin");
            handler.AddCommand("korisnik", new KorisnikCommand(korisnikManager));
            handler.AddCommand("hotel", new HotelCommand(handler.getIme(), hotelManager));
            handler.ListenStdin();
        } else {
            CommandHandler handler("klijent");
            handler.AddCommand("hotel", new HotelCommand(handler.getIme(), hotelManager));
            handler.ListenStdin();
        }
    } catch (AuthException &err) {
        cout << "Pogresno korisnicko ime ili lozinka, pokusajte ponovo !" << endl;
    }
}
