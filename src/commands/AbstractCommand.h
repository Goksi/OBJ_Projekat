//
// Created by Private on 5/25/2023.
//

#ifndef OBJ_PROJEKAT_ABSTRACTCOMMAND_H
#define OBJ_PROJEKAT_ABSTRACTCOMMAND_H

#include <string>
#include <queue>
#include <map>
#include <functional>

using namespace std;

class AbstractCommand {
private:
    string name;
    string description;
protected:
    map<string, function<void(queue<string>)>> subcommands;
public:
    AbstractCommand(string, string);

    virtual ~AbstractCommand() = default;

    virtual void Execute(queue<string> *args) = 0;

    virtual void PrintHelpCommand() = 0;

    [[nodiscard]] string GetName() const;

    [[nodiscard]] string GetDescription() const;
};


#endif //OBJ_PROJEKAT_ABSTRACTCOMMAND_H
