//
// Created by Private on 5/26/2023.
//

#ifndef OBJ_PROJEKAT_LOGINCOMMAND_H
#define OBJ_PROJEKAT_LOGINCOMMAND_H


#include "AbstractCommand.h"
#include "KorisnikManager.h"
#include "Korisnik.h"
#include "AuthException.h"

class LoginCommand : public AbstractCommand {
private:
    KorisnikManager *manager;
public:
    explicit LoginCommand(KorisnikManager *manager) : AbstractCommand("login",
                                                                      "Komanda koja sluzi za logovanje (login <username>)") { this->manager = manager; }

    void Execute(queue<string> *args) override;

    void PrintHelpCommand() override;
};


#endif //OBJ_PROJEKAT_LOGINCOMMAND_H
