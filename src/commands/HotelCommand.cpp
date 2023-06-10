//
// Created by Private on 5/28/2023.
//

#include "HotelCommand.h"

HotelCommand::HotelCommand(const string &ime, HotelManager *manager) : AbstractCommand("hotel", "Komanda za baratanje hotelima") {
    this->manager = manager;
    this->admin = ime == "admin";
    SetupSubcommands();
}

void HotelCommand::SetupSubcommands() {
    subcommands.insert({"list", [this](queue<string> *args) {
        if (args->empty()) {
            manager->AbstractManager<Hotel>::PrintResult();
        } else {
            string filter = args->front();
            args->pop();
            if (filter == "cena") {
                vector<Hotel> copy = manager->GetList();
                sort(copy.begin(), copy.end(), [](const Hotel &prvi, const Hotel &drugi) {
                    return prvi.GetCena() < drugi.GetCena();
                });
                manager->PrintResult(copy);
            } else cout << "Nevazeci filter !" << endl;
        }
    }});
    if (!admin) return;
    subcommands.insert({"add", [this](queue<string> *args) {
        Smestaj smestaj = MiscUtils::ReadSmestaj(HotelManager::lastId);
        cout << "Unesite tip hotela (HOTEL - 0, MOTEL - 1, ODMARALISTE - 2, GOSTIONICA - 3): " << endl;
        int tipInt;
        cin >> tipInt;
        auto tip = static_cast<TipHotela>(tipInt);
        cout << "Da li hotel ima teretanu ? (y/n) " << endl;
        char odg;
        cin >> odg;
        bool teretana = odg == 'y' || odg == 'Y';

        cout << "Da li hotel ime restoran ? (y/n) " << endl;
        cin >> odg;
        bool restoran = odg == 'y' || odg == 'Y';

        try {
            manager->AddHotel(smestaj, tip, teretana, restoran);
            cout << "Uspesno ste dodali novi hotel !" << endl;
        } catch (SmestajExistException &) {
            cout << "Greska pri dodavanju hotela, hotel sa istim imenom vec postoji !" << endl;
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
            cout << "Ni jedan hotel sa id-om " << id << " nije pronadjen !" << endl;
            return;
        }
        manager->Delete(id);
        cout << "Uspesno ste obrisali hotel " << (*iter).GetName() << " !" << endl;
    }});
}

void HotelCommand::PrintHelpCommand() {
    cout << "hotel list" << " - " << "Prikazuje listu svih dostupnih hotela" << endl;
    if (!admin) return;
    cout << "hotel add" << " - " << "Dodavanje novog hotela !" << endl;
    cout << "hotel delete <id>" << " - " << "Brisanje postojeceg hotela !" << endl;
}
