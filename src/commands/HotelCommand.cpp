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
        manager->PrintResult();
    }});
    if (!admin) return;
    subcommands.insert({"add", [this](queue<string> *args) {
        Smestaj smestaj = MiscUtils::ReadSmestaj(HotelManager::lastId);
    }});
}

void HotelCommand::PrintHelpCommand() {
    cout << "hotel list" << " - " << "Prikazuje listu svih dostupnih hotela" << endl;
}
