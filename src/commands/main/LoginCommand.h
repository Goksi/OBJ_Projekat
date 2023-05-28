//
// Created by Private on 5/26/2023.
//

#ifndef OBJ_PROJEKAT_LOGINCOMMAND_H
#define OBJ_PROJEKAT_LOGINCOMMAND_H


#include "AbstractCommand.h"
#include "KorisnikManager.h"
#include "Korisnik.h"
#include "AuthException.h"
#include "CommandHandler.h"
#include "HotelManager.h"

class LoginCommand : public AbstractCommand {
private:
    KorisnikManager *korisnikManager;
    HotelManager *hotelManager;
public:
    explicit LoginCommand(vector<Manager *> &managers) : AbstractCommand("login",
                                                                         "Komanda koja sluzi za logovanje (login <username>)") {
        this->korisnikManager = dynamic_cast<KorisnikManager *>(managers[0]);
        this->hotelManager = dynamic_cast<HotelManager *>(managers[1]);
    }

    void Execute(queue<string> *args) override;

    void PrintHelpCommand() override;
};


#endif //OBJ_PROJEKAT_LOGINCOMMAND_H
