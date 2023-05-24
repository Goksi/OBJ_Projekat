
#ifndef OBJ_PROJEKAT_ABSTRACTMANAGER_H
#define OBJ_PROJEKAT_ABSTRACTMANAGER_H

#include <vector>
#include "SerializationUtils.h"
#include <algorithm>

using namespace std;

template<class T>
class AbstractManager {
private:
    vector<T> list;
public:
    AbstractManager();

    vector<T> GetList() const;

    typename vector<T>::iterator *GetById(int) const;

    void Save();

    void Delete(int);

    virtual string GetFileName() const = 0;
};

#endif //OBJ_PROJEKAT_ABSTRACTMANAGER_H
