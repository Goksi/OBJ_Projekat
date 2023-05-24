
#ifndef OBJ_PROJEKAT_SERIALIZABLE_H
#define OBJ_PROJEKAT_SERIALIZABLE_H

#include <fstream>

class Serializable {
protected:
    int id;
public:
    explicit Serializable(int);

    virtual void Serialize(std::ostream &stream) = 0;

    virtual void Deserialize(std::istream &stream) = 0;

    int GetId() const;
};


#endif //OBJ_PROJEKAT_SERIALIZABLE_H
