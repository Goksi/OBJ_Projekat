//
// Created by Private on 5/30/2023.
//

#include "Rezervacija.h"

using namespace std;

int Rezervacija::GetIdSmestaja() const {
    return idSmestaja;
}

int Rezervacija::GetIdKorisnika() const {
    return idKorisnika;
}

TipSmestaja Rezervacija::GetTipSmestaja() const {
    return tipSmestaja;
}

void Rezervacija::Serialize(std::ostream &stream) const {
    Serializable::Serialize(stream);
    stream.write(reinterpret_cast<const char *>(&idSmestaja), sizeof(idSmestaja));

    stream.write(reinterpret_cast<const char *>(&idKorisnika), sizeof(idSmestaja));

    stream.write(reinterpret_cast<const char *>(&tipSmestaja), sizeof(idSmestaja));
}

void Rezervacija::Deserialize(std::istream &stream) {
    Serializable::Deserialize(stream);

    stream.read(reinterpret_cast<char *>(&idSmestaja), sizeof(idSmestaja));

    stream.read(reinterpret_cast<char *>(&idKorisnika), sizeof(idSmestaja));

    stream.read(reinterpret_cast<char *>(&tipSmestaja), sizeof(idSmestaja));
}

Rezervacija::Rezervacija() : Serializable(-1) {
    this->idSmestaja = -1;
    this->idKorisnika = -1;
    this->tipSmestaja = TipSmestaja::UNKNOWN;
}

Rezervacija::Rezervacija(int id, int idSmestaja, int idKorisnika, TipSmestaja tipSmestaja) : Serializable(id) {
    this->idSmestaja = idSmestaja;
    this->idKorisnika = idKorisnika;
    this->tipSmestaja = tipSmestaja;
}
