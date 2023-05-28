//
// Created by Private on 5/27/2023.
//

#ifndef OBJ_PROJEKAT_KORISNIKCOMMAND_H
#define OBJ_PROJEKAT_KORISNIKCOMMAND_H

#include "AbstractCommand.h"
#include "KorisnikManager.h"

class KorisnikCommand : public AbstractCommand {
private:
    KorisnikManager *manager;
public:
    explicit KorisnikCommand(KorisnikManager *manager) : AbstractCommand("korisnik",
                                                                         "Komanda za upravljanje korisnicima") {
        this->manager = manager;
        SetupSubcommands();
    }

    void PrintHelpCommand() override;

    void SetupSubcommands();
};


#endif //OBJ_PROJEKAT_KORISNIKCOMMAND_H
