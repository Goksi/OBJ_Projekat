//
// Created by Private on 5/25/2023.
//

#ifndef OBJ_PROJEKAT_MANAGER_H
#define OBJ_PROJEKAT_MANAGER_H


class Manager {
public:
    virtual void Save() = 0;

    virtual void Delete(int) = 0;

    virtual ~Manager() = default;
};


#endif //OBJ_PROJEKAT_MANAGER_H
