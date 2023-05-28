//
// Created by Private on 5/24/2023.
//

#include "KorisnikManager.h"

int KorisnikManager::lastId = 1;

KorisnikManager::KorisnikManager() {
    AbstractManager<Korisnik>::init(
            lastId, Korisnik(lastId++, "admin", "Vukasin", "Lekic", "maca1234",
                             TipKorisnika::ADMIN));
}

string KorisnikManager::GetFileName() const {
    return "korisnici.bin";
}

vector<Korisnik>::iterator KorisnikManager::FindByUsername(const string username) {
    auto iter = find_if(list.begin(), list.end(),
                        [&username](const Korisnik &current) { return current.GetUsername() == username; });
    return iter;
}

Korisnik &KorisnikManager::TryLogin(const string &username, const string &password) {
    auto iterator = FindByUsername(username);
    if (!AbstractManager<Korisnik>::IsValidIter(iterator)) throw AuthException();
    Korisnik korisnik = *iterator;
    if (!korisnik.TryLogin(password)) throw AuthException();
    return *iterator;
}

void
KorisnikManager::AddKorisnik(const string &username, const string &ime, const string &prezime, const string &password,
                             const TipKorisnika &tipKorisnika) {
    auto iter = FindByUsername(username);
    if (AbstractManager<Korisnik>::IsValidIter(iter)) throw KorisnikExistException();
    list.emplace_back(lastId++, username, ime, prezime, password, tipKorisnika);
}

void KorisnikManager::PrintResult() {
    VariadicTable<string, string, string, string> table({"Username", "Ime", "Prezime", "Tip"}, 10);
    for (const Korisnik &kor: list) {
        string tip = kor.IsAdmin() ? "Admin" : "Klijent";
        table.addRow(kor.GetUsername(), kor.GetIme(), kor.GetPrezime(), tip);
    }
    table.print(cout);
}

void KorisnikManager::Save() {
    SerializationUtils::Serialize(lastId, list, GetFileName());
}


