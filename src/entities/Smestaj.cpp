//
// Created by Private on 5/26/2023.
//

#include "Smestaj.h"

Smestaj::Smestaj(int id, const string &ime, const string &lokacija, int cenaZaNoc, int kapacitet, int recenzije,
                 float starRating) : Serializable(id) {
    this->name = ime;
    this->lokacija = lokacija;
    this->cenaZaNoc = cenaZaNoc;
    this->kapacitet = kapacitet;
    this->starRating = starRating;
    this->recenzije = recenzije;
}

float Smestaj::DodajZvezdicu(int brojZvezdica) {
    this->starRating = (this->starRating * (float) recenzije + (float) brojZvezdica) / (float) recenzije + 1;
    recenzije++;
    return starRating;
}

void Smestaj::Serialize(ostream &stream) const {
    Serializable::Serialize(stream);
    size_t imeSize = name.size();
    size_t lokacijaSize = lokacija.size();

    stream.write(reinterpret_cast<const char *>(&imeSize), sizeof(imeSize));
    stream.write(name.data(), (long long) imeSize);

    stream.write(reinterpret_cast<const char *>(&lokacijaSize), sizeof(lokacijaSize));
    stream.write(lokacija.data(), (long long) lokacijaSize);

    stream.write(reinterpret_cast<const char *>(&cenaZaNoc), sizeof(cenaZaNoc));

    stream.write(reinterpret_cast<const char *>(&kapacitet), sizeof(kapacitet));

    stream.write(reinterpret_cast<const char *>(&starRating), sizeof(starRating));

    stream.write(reinterpret_cast<const char *>(&recenzije), sizeof(recenzije));
}

void Smestaj::Deserialize(istream &stream) {
    Serializable::Deserialize(stream);
    this->name = MiscUtils::ReadString(stream);
    this->lokacija = MiscUtils::ReadString(stream);

    stream.read(reinterpret_cast<char *>(&cenaZaNoc), sizeof(cenaZaNoc));

    stream.read(reinterpret_cast<char *>(&kapacitet), sizeof(kapacitet));

    stream.read(reinterpret_cast<char *>(&starRating), sizeof(starRating));

    stream.read(reinterpret_cast<char *>(&recenzije), sizeof(recenzije));
}

Smestaj::Smestaj() : Serializable(-1) {
    this->cenaZaNoc = -1;
    this->kapacitet = -1;
    this->starRating = -1;
    this->recenzije = -1;
}

bool Smestaj::operator==(const Smestaj &other) {
    return id == other.id && name == other.name && cenaZaNoc == other.cenaZaNoc && kapacitet == other.kapacitet;
}

string Smestaj::GetName() const {
    return name;
}

string Smestaj::GetLokacija() const {
    return lokacija;
}

int Smestaj::GetKapacitet() const {
    return kapacitet;
}

float Smestaj::GetStars() const {
    return starRating;
}
