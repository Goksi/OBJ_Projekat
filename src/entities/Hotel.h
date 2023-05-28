//
// Created by Private on 5/27/2023.
//

#ifndef OBJ_PROJEKAT_HOTEL_H
#define OBJ_PROJEKAT_HOTEL_H

#include "Smestaj.h"

enum TipHotela {
    UNKNOWN = -1,
    HOTEL = 0,
    MOTEL = 1,
    ODMARALISTE = 2,
    GOSTIONICA = 3
};

class Hotel : public Smestaj {
private:
    TipHotela tipHotela;
    bool teretana;
    bool restoran;
public:
    Hotel();

    Hotel(Smestaj, TipHotela, bool, bool);

    void Serialize(std::ostream &stream) const override;

    void Deserialize(std::istream &stream) override;

    [[nodiscard]] string GetTeretanaText() const;

    [[nodiscard]] string GetRestoranText() const;

    [[nodiscard]] TipHotela GetType() const;

    static string GetByType(TipHotela tip) {
        switch (tip) {
            case HOTEL:
                return "Hotel";
            case MOTEL:
                return "Motel";
            case ODMARALISTE:
                return "Odmaraliste";
            case GOSTIONICA:
                return "Gostionica";
            default:
                return "Nepoznato";
        }
    }
};


#endif //OBJ_PROJEKAT_HOTEL_H
