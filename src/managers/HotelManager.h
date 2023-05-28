//
// Created by Private on 5/27/2023.
//

#ifndef OBJ_PROJEKAT_HOTELMANAGER_H
#define OBJ_PROJEKAT_HOTELMANAGER_H

#include <string>
#include "AbstractManager.h"
#include "Hotel.h"
#include "Table.h"
#include "SmestajExistException.h"

using namespace std;

class HotelManager : public AbstractManager<Hotel> {
protected:
    [[nodiscard]] string GetFileName() const override;

public:
    static int lastId;

    void Save() override;

    HotelManager();

    vector<Hotel>::iterator FindByName(const string &);

    void AddHotel(const Smestaj &, TipHotela, bool, bool);


    void PrintResult() override;
};


#endif //OBJ_PROJEKAT_HOTELMANAGER_H
