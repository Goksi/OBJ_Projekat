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
    this->username = MiscUtils::ReadString(stream);
    this->ime = MiscUtils::ReadString(stream);
    this->prezime = MiscUtils::ReadString(stream);
    this->hashedPassword = MiscUtils::ReadString(stream);
    TipKorisnika temp;
    stream.read(reinterpret_cast<char *>(&temp), sizeof(temp));
    this->tipKorisnika = temp;
}

Korisnik::Korisnik(int id, string username, string ime, string prezime, const string &password,
                   TipKorisnika tipKorisnika) : Serializable(id) {
    this->username = std::move(username);
    this->ime = std::move(ime);
    this->prezime = std::move(prezime);
    this->hashedPassword = bcrypt::generateHash(password);
    this->tipKorisnika = tipKorisnika;
}

string Korisnik::GetUsername() const {
    return username;
}

bool Korisnik::operator==(const Korisnik &other) {
    return username == other.username && Serializable::id == other.GetId();
}