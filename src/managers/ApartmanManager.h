//
// Created by Private on 5/29/2023.
//

#ifndef OBJ_PROJEKAT_APARTMANMANAGER_H
#define OBJ_PROJEKAT_APARTMANMANAGER_H


#include "Apartman.h"
#include "AbstractManager.h"

class ApartmanManager : public AbstractManager<Apartman> {
protected:
    [[nodiscard]] string GetFileName() const override;

public:
    static int lastId;

    void Save() override;

    ApartmanManager();

    vector<Apartman>::iterator FindByName(const string &);

    void AddApartman(const Smestaj &, bool, bool, int);

    void PrintResult(vector<Apartman> &) override;
};


#endif //OBJ_PROJEKAT_APARTMANMANAGER_H
