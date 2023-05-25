
#include "AbstractManager.h"
#include "Korisnik.h"

using namespace std;

template<class T>
vector<T> AbstractManager<T>::GetList() const {
    return list;
}

template<class T>
[[nodiscard]] typename vector<T>::const_iterator AbstractManager<T>::GetById(int id) const {
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
                return current.GetId() == id;
            }
    ));
}

template<class T>
void AbstractManager<T>::Save() {
    SerializationUtils::Serialize(lastId, list, GetFileName());
}

template<class T>
void AbstractManager<T>::init(optional<T> defValue) {
    try {
        SerializationUtils::Deserialize(lastId, list, GetFileName());
    } catch (FileException &e) {
        if (defValue.has_value()) list.push_back(defValue.value());
    }
}

template<class T>
bool AbstractManager<T>::IsValidIter(typename vector<T>::const_iterator iter) {
    return iter != list.cend();
}

template
class AbstractManager<Korisnik>;