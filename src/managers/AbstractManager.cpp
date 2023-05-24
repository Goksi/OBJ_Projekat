
#include "AbstractManager.h"

using namespace std;

template<class T>
vector<T> AbstractManager<T>::GetList() const {
    return list;
}

template<class T>
typename vector<T>::iterator *AbstractManager<T>::GetById(int id) const {
    auto iter = find_if(list.begin(), list.end(), [&id](const T &current) { return current.GetId() == id; });
    return iter != list.cend() ? iter : nullptr;
}

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
    SerializationUtils::Serialize(list, GetFileName());
}
