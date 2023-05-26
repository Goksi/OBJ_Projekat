//
// Created by Private on 5/24/2023.
//

#ifndef OBJ_PROJEKAT_KORISNIKMANAGER_H
#define OBJ_PROJEKAT_KORISNIKMANAGER_H

#include "AbstractManager.h"
#include "Korisnik.h"
#include <algorithm>
#include <optional>
#include "AuthException.h"
#include "KorisnikExistException.h"

class KorisnikManager : public AbstractManager<Korisnik> {
protected:
    [[nodiscard]] string GetFileName() const override;

public:
    KorisnikManager();

    vector<Korisnik>::iterator FindByUsername(string);

    Korisnik &TryLogin(const string &, const string &);

    void
    AddKorisnik(const string &, const string &, const string &, const string &,
                const TipKorisnika & = TipKorisnika::KLIJENT);
};


#endif //OBJ_PROJEKAT_KORISNIKMANAGER_H
