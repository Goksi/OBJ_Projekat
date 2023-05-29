//
// Created by Private on 5/27/2023.
//

#ifndef OBJ_PROJEKAT_APARTMAN_H
#define OBJ_PROJEKAT_APARTMAN_H

#include "Smestaj.h"

class Apartman : public Smestaj {
private:
    bool terasa;
    bool kuhinja;
    int brojSoba;
public:
    Apartman() = default;

    Apartman(Smestaj, bool, bool, int);

    [[nodiscard]] string HaveTerasa() const;

    [[nodiscard]] string HaveKuhinja() const;

    [[nodiscard]] int GetBrojSoba() const;

    void Serialize(std::ostream &stream) const override;

    void Deserialize(std::istream &stream) override;
};


#endif //OBJ_PROJEKAT_APARTMAN_H
