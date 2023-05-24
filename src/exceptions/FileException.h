//
// Created by Private on 5/23/2023.
//

#ifndef OBJ_PROJEKAT_FILEEXCEPTION_H
#define OBJ_PROJEKAT_FILEEXCEPTION_H

#include <exception>
#include <string>

class FileException : std::exception {
private:
    std::string message;
public:
    FileException();

    explicit FileException(std::string);

    const char *what() const noexcept override;
};


#endif //OBJ_PROJEKAT_FILEEXCEPTION_H
