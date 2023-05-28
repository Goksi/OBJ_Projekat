//
// Created by Private on 5/27/2023.
//

#ifndef OBJ_PROJEKAT_BUNGALOV_H
#define OBJ_PROJEKAT_BUNGALOV_H

#include "Smestaj.h"

class Bungalov : public Smestaj {
private:
    bool bazen;
    bool dvoriste;
    int povrsina;
public:
    Bungalov() = default;

    Bungalov(Smestaj, bool, bool, int);

    void Serialize(std::ostream &stream) const override;

    void Deserialize(std::istream &stream) override;
};


#endif //OBJ_PROJEKAT_BUNGALOV_H
