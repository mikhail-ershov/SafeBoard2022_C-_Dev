#ifndef WEBSITEGENERATOR_GEMTEXTPREFORMATTEDTEXT_H
#define WEBSITEGENERATOR_GEMTEXTPREFORMATTEDTEXT_H

#include "GemtextElement.h"
#include <list>

//Класс преформатированных текстов
class GemtextPreformattedText: public GemtextElement {
private:
    std::list<std::string> elements;
public:
    GemtextPreformattedText() = default;
    void add(std::string element);
    std::string toHTML() override;
};


#endif //WEBSITEGENERATOR_GEMTEXTPREFORMATTEDTEXT_H
