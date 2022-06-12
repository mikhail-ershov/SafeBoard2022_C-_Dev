#ifndef WEBSITEGENERATOR_GEMTEXTPARAGRAPHREADER_H
#define WEBSITEGENERATOR_GEMTEXTPARAGRAPHREADER_H

#include "GemtextElementReader.h"
#include <fstream>

//Класс для считывания абзацев
class GemtextParagraphReader: public GemtextElementReader {
public:
    GemtextElement* read(const std::string& line, const GemtextType& type) override;
};


#endif //WEBSITEGENERATOR_GEMTEXTPARAGRAPHREADER_H
