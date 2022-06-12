#ifndef WEBSITEGENERATOR_GEMTEXTLINKREADER_H
#define WEBSITEGENERATOR_GEMTEXTLINKREADER_H

#include "GemtextElementReader.h"

//Класс для считывания ссылок
class GemtextLinkReader: public GemtextElementReader {
public:
    GemtextElement * read(const std::string &line, const GemtextType &type) override;
};


#endif //WEBSITEGENERATOR_GEMTEXTLINKREADER_H
