//
// Created by Private on 5/27/2023.
//

#include "Bungalov.h"

#include <utility>

Bungalov::Bungalov(Smestaj smestaj, bool bazen, bool dvoriste, int povrsina) : Smestaj(std::move(smestaj)) {
    this->bazen = bazen;
    this->dvoriste = dvoriste;
    this->povrsina = povrsina;
}

void Bungalov::Serialize(ostream &stream) const {
    Smestaj::Serialize(stream);

    stream.write(reinterpret_cast<const char *>(&bazen), sizeof(bazen));

    stream.write(reinterpret_cast<const char *>(&dvoriste), sizeof(dvoriste));

    stream.write(reinterpret_cast<const char *>(&povrsina), sizeof(povrsina));
}

void Bungalov::Deserialize(istream &stream) {
    Smestaj::Deserialize(stream);

    stream.read(reinterpret_cast<char *>(&bazen), sizeof(bazen));

    stream.read(reinterpret_cast<char *>(&dvoriste), sizeof(dvoriste));

    stream.read(reinterpret_cast<char *>(&povrsina), sizeof(povrsina));
}
