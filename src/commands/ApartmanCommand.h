//
// Created by Private on 5/29/2023.
//

#ifndef OBJ_PROJEKAT_APARTMANCOMMAND_H
#define OBJ_PROJEKAT_APARTMANCOMMAND_H


#include "AbstractCommand.h"
#include "ApartmanManager.h"

class ApartmanCommand : public AbstractCommand {
private:
    ApartmanManager *manager;
    bool admin;
public:
    ApartmanCommand(const string &, ApartmanManager *);

    void PrintHelpCommand() override;

    void SetupSubcommands();
};


#endif //OBJ_PROJEKAT_APARTMANCOMMAND_H
