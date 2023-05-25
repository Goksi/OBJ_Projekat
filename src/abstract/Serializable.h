
#ifndef OBJ_PROJEKAT_SERIALIZABLE_H
#define OBJ_PROJEKAT_SERIALIZABLE_H

#include <fstream>

class Serializable {
protected:
    int id;
public:
    explicit Serializable(int);

    virtual void Serialize(std::ostream &stream) const;

    virtual void Deserialize(std::istream &stream);

    [[nodiscard]] int GetId() const;
};


#endif //OBJ_PROJEKAT_SERIALIZABLE_H
