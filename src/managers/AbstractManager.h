
#ifndef OBJ_PROJEKAT_ABSTRACTMANAGER_H
#define OBJ_PROJEKAT_ABSTRACTMANAGER_H

#include <vector>
#include "SerializationUtils.h"
#include "Manager.h"
#include <algorithm>

using namespace std;

template<class T>
class AbstractManager : public Manager {
protected:
    vector<T> list;

    explicit AbstractManager(T);

    virtual string GetFileName() const = 0;

    static int lastId;
public:
    vector<T> GetList() const;

    typename vector<T>::iterator GetById(int) const;

    void Save() override;

    void Delete(int) override;

    bool IsValidIter(typename vector<T>::iterator);
};

#endif //OBJ_PROJEKAT_ABSTRACTMANAGER_H
