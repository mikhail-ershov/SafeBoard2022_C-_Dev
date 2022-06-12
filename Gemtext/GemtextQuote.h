#ifndef WEBSITEGENERATOR_GEMTEXTQUOTE_H
#define WEBSITEGENERATOR_GEMTEXTQUOTE_H

#include "GemtextElement.h"

//Класс цитат
class GemtextQuote: public GemtextElement {
private:
    std::string text;
public:
    GemtextQuote(std::string text);
    std::string toHTML() override;

};


#endif //WEBSITEGENERATOR_GEMTEXTQUOTE_H
