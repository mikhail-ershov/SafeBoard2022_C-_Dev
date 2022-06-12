#ifndef WEBSITEGENERATOR_GEMTEXTLISTITEMREADER_H
#define WEBSITEGENERATOR_GEMTEXTLISTITEMREADER_H

#include "GemtextElementReader.h"

//Класс для считывания элементов списка
class GemtextListItemReader: public GemtextElementReader {
public:
    GemtextElement * read(const std::string &line, const GemtextType &type) override;
};


#endif //WEBSITEGENERATOR_GEMTEXTLISTITEMREADER_H
