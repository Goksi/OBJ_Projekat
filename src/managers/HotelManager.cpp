//
// Created by Private on 5/27/2023.
//

#include "HotelManager.h"

string HotelManager::GetFileName() const {
    return "hoteli.bin";
}

HotelManager::HotelManager() {
    AbstractManager<Hotel>::init();
}

vector<Hotel>::iterator HotelManager::FindByName(const string &name) {
    auto iter = find_if(list.begin(), list.end(),
                        [&name](const Hotel &current) { return current.GetName() == name; });
    return iter;
}

void HotelManager::PrintResult() {
    VariadicTable<string, string, int, string, string, float, string> table(
            {"Naziv", "Lokacija", "Max osoba", "Teretana", "Restoran", "*", "Tip"},
            12);
    for (const Hotel &hotel: list) {
        table.addRow(hotel.GetName(), hotel.GetLokacija(), hotel.GetKapacitet(), hotel.GetTeretanaText(),
                     hotel.GetRestoranText(), hotel.GetStars(), Hotel::GetByType(hotel.GetType()));
    }
    table.print(cout);
}

void HotelManager::AddHotel(const Smestaj &smestaj, TipHotela tipHotela, bool teretana, bool restoran) {
    auto iter = FindByName(smestaj.GetName());
    if (AbstractManager<Hotel>::IsValidIter(iter)) throw SmestajExistException();
    list.emplace_back(smestaj, tipHotela, teretana, restoran);
}
