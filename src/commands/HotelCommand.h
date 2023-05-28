//
// Created by Private on 5/28/2023.
//

#ifndef OBJ_PROJEKAT_HOTELCOMMAND_H
#define OBJ_PROJEKAT_HOTELCOMMAND_H

#include "HotelManager.h"
#include "AbstractCommand.h"

class HotelManager;

class HotelCommand : public AbstractCommand {
private:
    HotelManager *manager;
    bool admin;
public:
    HotelCommand(const string &, HotelManager *);


    void PrintHelpCommand() override;

    void SetupSubcommands();
};


#endif //OBJ_PROJEKAT_HOTELCOMMAND_H
