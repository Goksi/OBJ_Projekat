//
// Created by Private on 5/25/2023.
//

#ifndef OBJ_PROJEKAT_COMMANDHANDLER_H
#define OBJ_PROJEKAT_COMMANDHANDLER_H

#include <map>
#include <string>
#include "AbstractCommand.h"
#include "MiscUtils.h"
#include <utility>
#include <iostream>

using namespace std;

class CommandHandler {
private:
    string ime;

    map<string, AbstractCommand *> commands;

    void PrintHelp();

public:
    explicit CommandHandler(const string &);

    CommandHandler(const string &, map<string, AbstractCommand *>);

    ~CommandHandler();

    void ListenStdin();

    void AddCommand(const string &, AbstractCommand *);

    [[nodiscard]] string getIme() const;
};


#endif //OBJ_PROJEKAT_COMMANDHANDLER_H
