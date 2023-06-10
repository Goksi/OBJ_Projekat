//
// Created by Private on 6/10/2023.
//

#ifndef OBJ_PROJEKAT_ADDSTARCOMMAND_H
#define OBJ_PROJEKAT_ADDSTARCOMMAND_H


#include "AbstractCommand.h"
#include "ApartmanManager.h"
#include "HotelManager.h"

class AddStarCommand : public AbstractCommand {
private:
    ApartmanManager *apartmanManager;
    HotelManager *hotelManager;
public:
    AddStarCommand(ApartmanManager *, HotelManager *);

    void Execute(queue<string> *args) override;

    void PrintHelpCommand() override;
};


#endif //OBJ_PROJEKAT_ADDSTARCOMMAND_H
