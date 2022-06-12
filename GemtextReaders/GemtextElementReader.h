#ifndef WEBSITEGENERATOR_GEMTEXTELEMENTREADER_H
#define WEBSITEGENERATOR_GEMTEXTELEMENTREADER_H

#include "../Exceptions/InvalidGemtextFileException.h"
#include "../Gemtext/GemtextElement.h"
#include "../Gemtext/GemtextElementTypes.h"
#include <stdexcept>
#include <fstream>
#include <string>

//Абстрактный класс, обобщающий чтение элемента gemtext из строки
class GemtextElementReader {
public:
    virtual GemtextElement* read(const std::string& line, const GemtextType& type) = 0;
};


#endif //WEBSITEGENERATOR_GEMTEXTELEMENTREADER_H
