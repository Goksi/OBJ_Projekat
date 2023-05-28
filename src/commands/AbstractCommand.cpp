//
// Created by Private on 5/25/2023.
//

#include "AbstractCommand.h"

AbstractCommand::AbstractCommand(string name, string description) {
    this->name = std::move(name);
    this->description = std::move(description);
}

string AbstractCommand::GetName() const {
    return name;
}

string AbstractCommand::GetDescription() const {
    return description;
}

void AbstractCommand::Execute(queue<string> *args) {
    if (args->empty()) {
        PrintHelpCommand();
        return;
    }
    string subcommand = args->front();
    args->pop();
    auto iter = subcommands.find(subcommand);
    if (iter == subcommands.cend()) {
        PrintHelpCommand();
        return;
    }
    (*iter).second(args);
}
