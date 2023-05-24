
#ifndef OBJ_PROJEKAT_SERIALIZABLE_H
#define OBJ_PROJEKAT_SERIALIZABLE_H

#include <fstream>

class Serializable {
public:
    virtual void Serialize(std::ostream &stream) = 0;

    virtual void Deserialize(std::istream &stream) = 0;
};


#endif //OBJ_PROJEKAT_SERIALIZABLE_H
