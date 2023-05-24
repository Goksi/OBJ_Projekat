//
// Created by Private on 5/23/2023.
//

#include "Korisnik.h"

bool Korisnik::IsAdmin() {
    return this->tipKorisnika == TipKorisnika::ADMIN;
}

bool Korisnik::TryLogin(const string &password) {
    return bcrypt::validatePassword(password, hashedPassword);
}

void Korisnik::Serialize(ostream &stream) {
    size_t usernameSize = username.size();
    size_t imeSize = ime.size();
    size_t prezimeSize = prezime.size();
    size_t passSize = hashedPassword.size();

    stream << usernameSize << username;
    stream << imeSize << ime;
    stream << prezimeSize << prezime;
    stream << passSize << hashedPassword;
    stream << tipKorisnika;
}

void Korisnik::Deserialize(istream &stream) {

}


