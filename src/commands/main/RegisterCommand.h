//
// Created by Private on 5/26/2023.
//

#ifndef OBJ_PROJEKAT_REGISTERCOMMAND_H
#define OBJ_PROJEKAT_REGISTERCOMMAND_H


#include "KorisnikManager.h"
#include "AbstractCommand.h"

class RegisterCommand : public AbstractCommand {
private:
    KorisnikManager *manager;
public:
    explicit RegisterCommand(KorisnikManager *manager) : AbstractCommand("register",
                                                                         "Komanda sluzi za registrovanje novih naloga !") { this->manager = manager; }

    void Execute(queue<string> *args) override;

    void PrintHelpCommand() override;
};


#endif //OBJ_PROJEKAT_REGISTERCOMMAND_H
