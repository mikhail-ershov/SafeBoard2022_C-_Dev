#ifndef WEBSITEGENERATOR_INVALIDGEMTEXTFILEEXCEPTION_H
#define WEBSITEGENERATOR_INVALIDGEMTEXTFILEEXCEPTION_H

#include <exception>
#include <string>

//Класс исключений, которые происходят при некорректных данных в файлах .gmi
class InvalidGemtextFileException: public std::exception {
private:
    const std::string message;
public:
    InvalidGemtextFileException(): std::exception() {}
    explicit InvalidGemtextFileException(const std::string& message);
    const char * what() const noexcept override;
};


#endif //WEBSITEGENERATOR_INVALIDGEMTEXTFILEEXCEPTION_H
