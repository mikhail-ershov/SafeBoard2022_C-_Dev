#ifndef WEBSITEGENERATOR_GEMTEXTHEADERREADER_H
#define WEBSITEGENERATOR_GEMTEXTHEADERREADER_H


#include "GemtextElementReader.h"

//Класс для считывания заголовков
class GemtextHeaderReader: public GemtextElementReader {
public:
    GemtextElement* read(const std::string& line, const GemtextType& type) override;
};


#endif //WEBSITEGENERATOR_GEMTEXTHEADERREADER_H
