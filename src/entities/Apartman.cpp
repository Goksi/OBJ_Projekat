//
// Created by Private on 5/27/2023.
//

#include "Apartman.h"

#include <utility>

void Apartman::Serialize(ostream &stream) const {
    Smestaj::Serialize(stream);
    stream.write(reinterpret_cast<const char *>(&terasa), sizeof(terasa));

    stream.write(reinterpret_cast<const char *>(&kuhinja), sizeof(kuhinja));

    stream.write(reinterpret_cast<const char *>(&brojSoba), sizeof(brojSoba));
}

void Apartman::Deserialize(istream &stream) {
    Smestaj::Deserialize(stream);

    stream.read(reinterpret_cast<char *>(&terasa), sizeof(terasa));

    stream.read(reinterpret_cast<char *>(&kuhinja), sizeof(kuhinja));

    stream.read(reinterpret_cast<char *>(&brojSoba), sizeof(brojSoba));
}

Apartman::Apartman(Smestaj smestaj, bool terasa, bool kuhinja, int brojSoba) : Smestaj(std::move(smestaj)) {
    this->terasa = terasa;
    this->kuhinja = kuhinja;
    this->brojSoba = brojSoba;
}
