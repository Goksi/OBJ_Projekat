//
// Created by Private on 5/25/2023.
//

#include "CommandHandler.h"

using namespace std;

CommandHandler::CommandHandler(const string &ime, map<string, AbstractCommand *> cmd) : commands(std::move(cmd)) {
    this->ime = ime;
}

CommandHandler::CommandHandler(const std::string &ime) {
    this->ime = ime;
}

CommandHandler::~CommandHandler() {
    for (const auto &entry: commands) {
        delete entry.second;
    }
}

void CommandHandler::ListenStdin() {
    while (true) {
        string temp;
        getline(cin, temp);
        auto args = MiscUtils::SplitString(temp);
        if (args->empty()) {
            cin.clear();
            continue;
        }
        string cmd = args->front();
        args->pop();
        if (cmd == "exit") {
            delete args;
            break;
        }
        if (cmd == "help") {
            PrintHelp();
            delete args;
            continue;
        }
        auto iter = commands.find(cmd);
        if (iter == commands.cend()) {
            cout << "Nepoznata komanda, pokusajte ponovo !" << endl;
            delete args;
            continue;
        }
        auto command = (*iter).second;
        command->Execute(args);
        delete args;
    }
}

void CommandHandler::AddCommand(const string &cmd, AbstractCommand *command) {
    commands.insert({cmd, command});
}

void CommandHandler::PrintHelp() {
    for (auto pair: commands) {
        pair.second->PrintHelpCommand();
    }
}

string CommandHandler::getIme() const {
    return ime;
}
