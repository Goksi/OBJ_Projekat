
#include "AbstractManager.h"

using namespace std;

template<class T>
vector<T> AbstractManager<T>::GetList() const {
    return list;
}

template<class T>
typename vector<T>::iterator AbstractManager<T>::GetById(int id) const {
    auto iter = find_if(list.begin(), list.end(), [&id](const T &current) { return current.GetId() == id; });
    return iter;
}

template<class T>
int AbstractManager<T>::lastId = 1;

template<class T>
void AbstractManager<T>::Delete(int id) {
    list.erase(remove_if(
            list.begin(), list.end(),
            [&id](const T &current) {
                current.GetId == id;
            }
    ));
}

template<class T>
void AbstractManager<T>::Save() {
    SerializationUtils::Serialize(lastId, list, GetFileName());
}

template<class T>
AbstractManager<T>::AbstractManager(T defValue) {
    try {
        SerializationUtils::Deserialize(lastId, list, GetFileName());
    } catch (FileException &e) {
        if (defValue != nullptr) list.push_back(defValue);
    }
}

template<class T>
bool AbstractManager<T>::IsValidIter(typename vector<T>::iterator iter) {
    return iter != list.cend();
}