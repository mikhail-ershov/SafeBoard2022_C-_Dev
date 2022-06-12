#ifndef WEBSITEGENERATOR_GEMTEXTQUOTEREADER_H
#define WEBSITEGENERATOR_GEMTEXTQUOTEREADER_H

#include "GemtextElementReader.h"

//Класс для считывания цитат
class GemtextQuoteReader: public GemtextElementReader {
public:
    GemtextElement * read(const std::string &line, const GemtextType &type) override;
};


#endif //WEBSITEGENERATOR_GEMTEXTQUOTEREADER_H
