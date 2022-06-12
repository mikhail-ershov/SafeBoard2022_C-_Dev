#ifndef WEBSITEGENERATOR_GEMTEXTHEADER_H
#define WEBSITEGENERATOR_GEMTEXTHEADER_H

#include "GemtextElement.h"

//Класс заголовков
class GemtextHeader: public GemtextElement {
private:
    std::string text;
    unsigned short level;
public:
    GemtextHeader(std::string text, unsigned short level);
    std::string toHTML() override;
};

#endif //WEBSITEGENERATOR_GEMTEXTHEADER_H
