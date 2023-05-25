
#ifndef OBJ_PROJEKAT_ABSTRACTMANAGER_H
#define OBJ_PROJEKAT_ABSTRACTMANAGER_H

#include <vector>
#include "SerializationUtils.h"
#include "Manager.h"
#include <algorithm>
#include <optional>

using namespace std;

template<class T>
class AbstractManager : public Manager {
protected:
    vector<T> list;

    [[nodiscard]] virtual string GetFileName() const = 0;

    static int lastId;

    void init(std::optional<T> = nullopt);

public:
    vector<T> GetList() const;

    typename vector<T>::const_iterator GetById(int) const;

    void Save() override;

    void Delete(int) override;

    bool IsValidIter(typename vector<T>::const_iterator);
};

#endif //OBJ_PROJEKAT_ABSTRACTMANAGER_H
