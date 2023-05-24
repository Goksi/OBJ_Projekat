//
// Created by Private on 5/24/2023.
//

#ifndef OBJ_PROJEKAT_NOTFOUNDEXCEPTION_H
#define OBJ_PROJEKAT_NOTFOUNDEXCEPTION_H

#include <exception>

class NotFoundException : public std::exception {
public:
    const char *what() const noexcept override;
};


#endif //OBJ_PROJEKAT_NOTFOUNDEXCEPTION_H
