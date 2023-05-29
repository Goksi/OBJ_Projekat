//
// Created by Private on 5/27/2023.
//

#include "HotelManager.h"

string HotelManager::GetFileName() const {
    return "hoteli.bin";
}

int HotelManager::lastId = 1;

HotelManager::HotelManager() {
    AbstractManager<Hotel>::init(lastId);
}

vector<Hotel>::iterator HotelManager::FindByName(const string &name) {
    auto iter = find_if(list.begin(), list.end(),
                        [&name](const Hotel &current) { return current.GetName() == name; });
    return iter;
}

void HotelManager::PrintResult() {
    VariadicTable<int, string, string, int, int, string, string, float, string> table(
            {"ID", "Naziv", "Lokacija", "Cena za noc", "Max osoba", "Teretana", "Restoran", "*", "Tip"},
            12);
    for (const Hotel &hotel: list) {
        table.addRow(hotel.GetId(), hotel.GetName(), hotel.GetLokacija(), hotel.GetCena(), hotel.GetKapacitet(), hotel.GetTeretanaText(),
                     hotel.GetRestoranText(), hotel.GetStars(), Hotel::GetByType(hotel.GetType()));
    }
    table.print(cout);
}

void HotelManager::AddHotel(const Smestaj &smestaj, TipHotela tipHotela, bool teretana, bool restoran) {
    auto iter = FindByName(smestaj.GetName());
    if (AbstractManager<Hotel>::IsValidIter(iter)) throw SmestajExistException();
    list.emplace_back(smestaj, tipHotela, teretana, restoran);
    lastId++;
}

void HotelManager::Save() {
    SerializationUtils::Serialize(lastId, list, GetFileName());
}
