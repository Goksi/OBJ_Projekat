//
// Created by Private on 5/29/2023.
//

#include "ApartmanManager.h"
#include "Table.h"
#include "SmestajExistException.h"

void ApartmanManager::PrintResult(vector<Apartman> &lista) {
    VariadicTable<int, string, string, int, int, string, string, int, float> table(
            {"ID", "Naziv", "Lokacija", "Cena za noc", "Max osoba", "Terasa", "Kuhinja", "Broj soba", "*"},
            12);
    table.setColumnPrecision({1, 1, 1, 1, 1, 1, 1, 1, 3});
    for (const Apartman &apartman: lista) {
        table.addRow(apartman.GetId(), apartman.GetName(), apartman.GetLokacija(), apartman.GetCena(), apartman.GetKapacitet(),
                     apartman.HaveTerasa(),
                     apartman.HaveKuhinja(), apartman.GetBrojSoba(), apartman.GetStars());
    }
    table.print(cout);
}

int ApartmanManager::lastId = 1;

void ApartmanManager::Save() {
    SerializationUtils::Serialize(lastId, list, GetFileName());
}

string ApartmanManager::GetFileName() const {
    return "apartmani.bin";
}

ApartmanManager::ApartmanManager() {
    AbstractManager<Apartman>::init(lastId);
}

vector<Apartman>::iterator ApartmanManager::FindByName(const string &name) {
    auto iter = find_if(list.begin(), list.end(),
                        [&name](const Apartman &current) { return current.GetName() == name; });
    return iter;
}

void ApartmanManager::AddApartman(const Smestaj &smestaj, bool terasa, bool kuhinja, int brojSoba) {
    auto iter = FindByName(smestaj.GetName());
    if (AbstractManager<Apartman>::IsValidIter(iter)) throw SmestajExistException();
    list.emplace_back(smestaj, terasa, kuhinja, brojSoba);
    lastId++;
}
