
#include "AbstractManager.h"
#include "Korisnik.h"
#include "Hotel.h"
#include "Apartman.h"

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
void AbstractManager<T>::Delete(int id) {
    list.erase(remove_if(
            list.begin(), list.end(),
            [&id](const T &current) {
                return current.GetId() == id;
            }
    ));
}

template<class T>
void AbstractManager<T>::init(int &lastId, optional<T> defValue) {
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

template
class AbstractManager<Hotel>;

template
class AbstractManager<Apartman>;