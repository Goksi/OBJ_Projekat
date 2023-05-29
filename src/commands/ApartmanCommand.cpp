//
// Created by Private on 5/29/2023.
//

#include "ApartmanCommand.h"
#include "SmestajExistException.h"

ApartmanCommand::ApartmanCommand(const string &ime, ApartmanManager *manager) : AbstractCommand("apartman",
                                                                                                "Komanda za baratanje apartmanima") {
    this->manager = manager;
    this->admin = ime == "admin";
    SetupSubcommands();
}

void ApartmanCommand::PrintHelpCommand() {
    cout << "apartman list" << " - " << "Prikazuje listu svih dostupnih apartmana" << endl;
    if (!admin) return;
    cout << "apartman add" << " - " << "Dodavanje novog apartmana !" << endl;
    cout << "apartman delete <id>" << " - " << "Brisanje postojeceg apartmana !" << endl;
}

void ApartmanCommand::SetupSubcommands() {
    subcommands.insert({"list", [this](queue<string> *args) {
        manager->PrintResult();
    }});
    if (!admin) return;
    subcommands.insert({"add", [this](queue<string> *args) {
        Smestaj smestaj = MiscUtils::ReadSmestaj(ApartmanManager::lastId);
        cout << "Da li ovaj apartman ima terasu ? (y/n)" << endl;
        char odg;
        cin >> odg;
        bool terasa = odg == 'y' || odg == 'Y';
        cout << "Da li ima kuhinju ? (y/n)" << endl;
        cin >> odg;
        bool kuhinja = odg == 'y' || odg == 'Y';
        cout << "Koliko soba ima ovaj apartman ?" << endl;
        int brojSoba;
        cin >> brojSoba;
        if (brojSoba < 1) {
            cout << "Broj soba mora biti 1 ili vise !" << endl;
            return;
        }
        try {
            manager->AddApartman(smestaj, terasa, kuhinja, brojSoba);
            cout << "Uspesno ste dodali novi apartman !" << endl;
        } catch (SmestajExistException &) {
            cout << "Apartman sa zadatim imenom vec postoji !" << endl;
        }
    }});
    subcommands.insert({"delete", [this](queue<string> *args) {
        if (args->empty()) {
            PrintHelpCommand();
            return;
        }
        int id;
        try {
            id = stoi(args->front());
        } catch (invalid_argument &) {
            cout << "Dati id nije validan !" << endl;
            return;
        }
        auto iter = manager->GetById(id);
        if (!manager->IsValidIter(iter)) {
            cout << "Ni jedan apartman sa id-om " << id << " nije pronadjen !" << endl;
            return;
        }
        manager->Delete(id);
        cout << "Uspesno ste obrisali apartman " << (*iter).GetName() << " !" << endl;
    }});
}
