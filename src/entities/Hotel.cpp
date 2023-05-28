//
// Created by Private on 5/27/2023.
//

#include "Hotel.h"

#include <utility>

Hotel::Hotel() {
    this->tipHotela = TipHotela::UNKNOWN;
    this->teretana = false;
    this->restoran = false;
}

Hotel::Hotel(Smestaj smestaj, TipHotela tipHotela, bool teretana, bool restoran) : Smestaj(std::move(smestaj)) {
    this->tipHotela = tipHotela;
    this->teretana = teretana;
    this->restoran = restoran;
}

void Hotel::Serialize(ostream &stream) const {
    Smestaj::Serialize(stream);

    stream.write(reinterpret_cast<const char *>(&tipHotela), sizeof(tipHotela));

    stream.write(reinterpret_cast<const char *>(&teretana), sizeof(teretana));

    stream.write(reinterpret_cast<const char *>(&restoran), sizeof(restoran));
}

void Hotel::Deserialize(istream &stream) {
    Smestaj::Deserialize(stream);

    stream.read(reinterpret_cast<char *>(&tipHotela), sizeof(tipHotela));

    stream.read(reinterpret_cast<char *>(&teretana), sizeof(teretana));

    stream.read(reinterpret_cast<char *>(&restoran), sizeof(restoran));
}

string Hotel::GetTeretanaText() const {
    return teretana ? "DA" : "NE";
}

string Hotel::GetRestoranText() const {
    return restoran ? "DA" : "NE";
}

TipHotela Hotel::GetType() const {
    return tipHotela;
}
