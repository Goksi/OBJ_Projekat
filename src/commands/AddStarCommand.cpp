//
// Created by Private on 6/10/2023.
//

#include "AddStarCommand.h"

AddStarCommand::AddStarCommand(ApartmanManager *apartmanManager, HotelManager *hotelManager)
        : AbstractCommand("addstar", "Komanda za dodavanje zvezdica hotelu/apartmanu") {
    this->apartmanManager = apartmanManager;
    this->hotelManager = hotelManager;
}

void AddStarCommand::PrintHelpCommand() {
    cout << "addstar <tip> <zvezdice> <naziv> " << " - " << this->GetDescription();
}

void AddStarCommand::Execute(queue<string> *args) {
    if (args->size() < 3) {
        PrintHelpCommand();
        return;
    }
    string tip = args->front();
    args->pop();
    int zvezdice;
    try {
        zvezdice = stoi(args->front());
        args->pop();
    } catch (invalid_argument &) {
        cout << "Unet je nevazeci broj zvezdica, pokusajte ponovo !" << endl;
        return;
    }
    string naziv;
    while (!args->empty()) {
        naziv += args->front();
        args->pop();
        if (!args->empty()) {
            naziv += " ";
        }
    }

    if (tip == "apartman") {
        auto iter = apartmanManager->FindByName(naziv);
        if (!apartmanManager->IsValidIter(iter)) {
            cout << "Nije pronadjen apartman za to ime, pokusajte ponovo !" << endl;
            return;
        }
        Apartman &apartman = *iter;
        apartman.DodajZvezdicu(zvezdice);
        cout << "Uspesno ste dodali ocenu " << zvezdice << " za apartman " << naziv << " !" << endl;
    } else if (tip == "hotel") {
        auto iter = hotelManager->FindByName(naziv);
        if (!hotelManager->IsValidIter(iter)) {
            cout << "Nije pronadjen hotel za to ime, pokusajte ponovo !" << endl;
            return;
        }
        Hotel &hotel = *iter;
        hotel.DodajZvezdicu(zvezdice);
        cout << "Uspesno ste dodali ocenu " << zvezdice << " za hotel " << naziv << " !" << endl;
    } else {
        cout << "Nevazeci tip smestaja, pokusajte ponovo !" << endl;
    }
}
