//
// Created by Private on 5/27/2023.
//

#include "KorisnikCommand.h"

void KorisnikCommand::SetupSubcommands() {
    subcommands.insert({"list", [this](queue<string> *args) {
        manager->AbstractManager<Korisnik>::PrintResult();
    }});

    subcommands.insert({"add", [this](queue<string> *args) {
        cout << "Unesite username za novog korisnika: " << endl;
        string username;
        cin >> username;
        cout << "Unesite ime i prezime novog korisnika: " << endl;
        string ime, prezime;
        cin >> ime;
        cin >> prezime;
        cout << "Unesite password novog korisnika: " << endl;
        string pass;
        cin >> pass;
        cout << "Unesite tip novog korisnika (0 - Klijent, 1 - Admin): " << endl;
        int temp;
        cin >> temp;
        if (!(temp == 0 || temp == 1)) {
            cout << "Uneli ste pogresan tip, pokusajte ponovo !" << endl;
            return;
        }
        auto tip = static_cast<TipKorisnika>(temp);
        try {
            manager->AddKorisnik(username, ime, prezime, pass, tip);
        } catch (KorisnikExistException &e) {
            cout << "Korisnik sa tip username-om vec postoji, pokusajte ponovo !" << endl;
            return;
        }
        cout << "Uspesno ste dodali novog korisnika !" << endl;
    }});

    subcommands.insert({"edit", [this](queue<string> *args) {
        if (args->empty()) {
            PrintHelpCommand();
            return;
        }
        string userOrId = args->front();
        args->pop();
        if (args->empty()) {
            PrintHelpCommand();
            return;
        }
        string atribut = args->front();
        args->pop();
        bool username = false;
        int id;
        try {
            id = stoi(userOrId);;
        } catch (invalid_argument &e) {
            username = true;
        }
        auto iter = username ? manager->FindByUsername(userOrId) : manager->GetById(id);
        if (!manager->IsValidIter(iter)) {
            cout << "Korisnik sa tip id-om ili username-om nije pronadjen !" << endl;
            return;
        }
        auto &korisnik = const_cast<Korisnik &>(*iter);
        if (atribut == "ime") {
            cout << "Molim vas unesite novo ime: " << endl;
            string unos;
            cin >> unos;
            korisnik.setIme(unos);
        } else if (atribut == "prezime") {
            cout << "Molim vas unesite novo prezime: " << endl;
            string unos;
            cin >> unos;
            korisnik.setPrezime(unos);
        } else if (atribut == "sifra") {
            cout << "Molim vas unesite novu sifru: " << endl;
            string unos;
            cin >> unos;
            korisnik.setPassword(unos);
        } else if (atribut == "tip") {
            cout << "Molim vas unesite novi tip korisnika (0 - Klijent, 1 - Admin): " << endl;
            int unos;
            cin >> unos;
            korisnik.setTipKorisnika(static_cast<TipKorisnika>(unos));
        } else {
            cout << "Atribut koji ste uneli je nevazeci, pokusajte ponovo !" << endl;
            return;
        }
        cout << "Uspesno ste uredili korisnika !" << endl;
    }});

    subcommands.insert({"delete", [this](queue<string> *args) {
        if (args->empty()) {
            PrintHelpCommand();
            return;
        }
        string username = args->front();
        args->pop();
        auto iter = manager->FindByUsername(username);
        if (!manager->IsValidIter(iter)) {
            cout << "Korisnik sa tim username-om nije pronadjen, pokusajte ponovo !" << endl;
            return;
        }
        Korisnik korisnik = *iter;
        manager->Delete(korisnik.GetId());
        cout << "Uspesno ste obrisali korisnika " << korisnik.GetFullIme() << endl;
    }});
}

void KorisnikCommand::PrintHelpCommand() {
    cout << "korisnik list" << " - " << "Prikazuje listu svih registrovanih korisnika !" << endl;
    cout << "korisnik add" << " - " << "Dodavanje novog korisnika !" << endl;
    cout << "korisnik edit <username/id> <ime/prezime/sifra/tip>" << " - "
         << "Editovanje atributa korisniku sa zadatim username-om/id-em" << endl;
    cout << "korisnik delete <username>" << " - " << "Brisanje korisnika sa zadatim usernameom" << endl;
}
