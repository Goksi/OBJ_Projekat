//
// Created by Private on 5/30/2023.
//

#ifndef OBJ_PROJEKAT_REZERVACIJA_H
#define OBJ_PROJEKAT_REZERVACIJA_H

#include "Serializable.h"
#include "Korisnik.h"
#include <chrono>

enum TipSmestaja {
    UNKNOWN = -1,
    HOTEL = 0,
    APARTMAN = 1
};

class Rezervacija : public Serializable {
private:
    int idSmestaja;
    int idKorisnika;
    TipSmestaja tipSmestaja;
public:
    Rezervacija();

    Rezervacija(int, int, int, TipSmestaja);

    [[nodiscard]] int GetIdSmestaja() const;

    [[nodiscard]] int GetIdKorisnika() const;

    [[nodiscard]] TipSmestaja GetTipSmestaja() const;

    void Serialize(std::ostream &stream) const override;

    void Deserialize(std::istream &stream) override;

};


#endif //OBJ_PROJEKAT_REZERVACIJA_H
