//
// Created by Private on 5/26/2023.
//

#ifndef OBJ_PROJEKAT_SMESTAJ_H
#define OBJ_PROJEKAT_SMESTAJ_H

#include <string>
#include "Serializable.h"
#include "MiscUtils.h"

using namespace std;

class Smestaj : public Serializable {
private:
    string name;
    string lokacija;
    int cenaZaNoc;
    int kapacitet;
    float starRating;
    int recenzije;
public:
    Smestaj();

    Smestaj(int, const string &, const string &, int, int, int = 0, float = 0);

    float DodajZvezdicu(int);

    void Serialize(std::ostream &stream) const override;

    void Deserialize(std::istream &stream) override;

    [[nodiscard]] string GetName() const;

    [[nodiscard]] string GetLokacija() const;

    [[nodiscard]] int GetKapacitet() const;

    [[nodiscard]] float GetStars() const;

    bool operator==(const Smestaj &other);
};


#endif //OBJ_PROJEKAT_SMESTAJ_H
