//
// Created by Private on 5/23/2023.
//

#ifndef OBJ_PROJEKAT_KORISNIK_H
#define OBJ_PROJEKAT_KORISNIK_H

#include <string>
#include "bcrypt.h"
#include "Serializable.h"

using namespace std;
enum TipKorisnika {
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
    bool TryLogin(const string &password);

    bool IsAdmin();

    void Serialize(std::ostream &stream) override;

    void Deserialize(std::istream &stream) override;
};


#endif //OBJ_PROJEKAT_KORISNIK_H
