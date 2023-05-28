//
// Created by Private on 5/23/2023.
//

#include "Korisnik.h"
#include <iostream>

bool Korisnik::IsAdmin() const {
    return this->tipKorisnika == TipKorisnika::ADMIN;
}

bool Korisnik::TryLogin(const string &password) {
    return bcrypt::validatePassword(password, hashedPassword);
}

void Korisnik::Serialize(ostream &stream) const {
    Serializable::Serialize(stream);
    size_t usernameSize = username.size();
    size_t imeSize = ime.size();
    size_t prezimeSize = prezime.size();
    size_t passSize = hashedPassword.size();

    stream.write(reinterpret_cast<const char *>(&usernameSize), sizeof(usernameSize));
    stream.write(username.data(), (long long) usernameSize);

    stream.write(reinterpret_cast<const char *>(&imeSize), sizeof(imeSize));
    stream.write(ime.data(), (long long) imeSize);

    stream.write(reinterpret_cast<const char *>(&prezimeSize), sizeof(prezimeSize));
    stream.write(prezime.data(), (long long) prezimeSize);

    stream.write(reinterpret_cast<const char *>(&passSize), sizeof(passSize));
    stream.write(hashedPassword.data(), (long long) passSize);

    stream.write(reinterpret_cast<const char *>(&tipKorisnika), sizeof(TipKorisnika));
}

void Korisnik::Deserialize(istream &stream) {
    Serializable::Deserialize(stream);
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

Korisnik::Korisnik() : Serializable(-1) {
    this->tipKorisnika = TipKorisnika::UNDEFINED;
}

string Korisnik::GetUsername() const {
    return username;
}

string Korisnik::GetIme() const {
    return ime;
}

string Korisnik::GetPrezime() const {
    return prezime;
}

bool Korisnik::operator==(const Korisnik &other) {
    return username == other.username && Serializable::id == other.GetId();
}

string Korisnik::GetFullIme() const {
    return ime + " " + prezime;
}

void Korisnik::setIme(const string &i) {
    this->ime = i;
}

void Korisnik::setPrezime(const string &p) {
    this->prezime = p;
}

void Korisnik::setPassword(const string &password) {
    this->hashedPassword = bcrypt::generateHash(password);
}

void Korisnik::setTipKorisnika(TipKorisnika tip) {
    this->tipKorisnika = tip;
}
