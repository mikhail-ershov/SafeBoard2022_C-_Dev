#ifndef WEBSITEGENERATOR_GEMTEXTPARAGRAPH_H
#define WEBSITEGENERATOR_GEMTEXTPARAGRAPH_H

#include "GemtextElement.h"

//Класс абзацев
class GemtextParagraph: public GemtextElement {
private:
    std::string text;
public:
    GemtextParagraph(std::string text);
    std::string toHTML() override;

};


#endif //WEBSITEGENERATOR_GEMTEXTPARAGRAPH_H
