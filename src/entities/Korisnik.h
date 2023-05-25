//
// Created by Private on 5/23/2023.
//

#ifndef OBJ_PROJEKAT_KORISNIK_H
#define OBJ_PROJEKAT_KORISNIK_H

#include <string>
#include "bcrypt.h"
#include "Serializable.h"
#include "MiscUtils.h"

using namespace std;
enum TipKorisnika {
    UNDEFINED = -1,
    KLIJENT = 0,
    ADMIN = 1,
};

class Korisnik : public Serializable {
private:
    string username;
    string ime;
    string prezime;
    string hashedPassword;
    TipKorisnika tipKorisnika;
public:
    Korisnik();

    Korisnik(int, string, string, string, const string &, TipKorisnika);

    bool TryLogin(const string &password);

    bool IsAdmin();

    [[nodiscard]] string GetUsername() const;

    [[nodiscard]] string GetFullIme() const;

    void Serialize(std::ostream &stream) const override;

    void Deserialize(std::istream &stream) override;

    bool operator==(const Korisnik &other);
};


#endif //OBJ_PROJEKAT_KORISNIK_H
