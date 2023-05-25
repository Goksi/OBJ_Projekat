//
// Created by Private on 5/24/2023.
//

#include "KorisnikManager.h"


/*TODO: ne radi zbog templejta, naci kako da hendlujem*/
KorisnikManager::KorisnikManager() {
    AbstractManager<Korisnik>::init(
            {Korisnik(lastId++, "admin", "Vukasin", "Lekic", "maca1234",
                      TipKorisnika::ADMIN)});
}

string KorisnikManager::GetFileName() const {
    return "korisnici.bin";
}

vector<Korisnik>::iterator KorisnikManager::FindByUsername(const string &username) {
    auto iter = find_if(list.begin(), list.end(),
                        [&username](const Korisnik &current) { return current.GetUsername() == username; });
    return iter;
}

/*TODO: check*/
Korisnik &KorisnikManager::TryLogin(const string &username, const string &password) {
    auto iterator = FindByUsername(username);
    if (!AbstractManager<Korisnik>::IsValidIter(iterator)) throw AuthException();
    Korisnik korisnik = *iterator;
    if (!korisnik.TryLogin(password)) throw AuthException();
    return *iterator;
}


