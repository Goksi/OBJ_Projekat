
#ifndef OBJ_PROJEKAT_ABSTRACTMANAGER_H
#define OBJ_PROJEKAT_ABSTRACTMANAGER_H

#include <vector>
#include "SerializationUtils.h"
#include "Manager.h"
#include <algorithm>
#include <optional>
#include <functional>

using namespace std;

template<class T>
class AbstractManager : public Manager {
protected:
    vector<T> list;

    [[nodiscard]] virtual string GetFileName() const = 0;

    void init(int &, std::optional<T> = nullopt);

public:

    vector<T> GetList() const;

    typename vector<T>::const_iterator GetById(int) const;

    void Save() override = 0;

    void Delete(int) override;

    bool IsValidIter(typename vector<T>::const_iterator);

    virtual void PrintResult(vector<T> &list) = 0;

    void PrintResult() { PrintResult(list); }
};

#endif //OBJ_PROJEKAT_ABSTRACTMANAGER_H
