#ifndef WEBSITEGENERATOR_GEMTEXTLINK_H
#define WEBSITEGENERATOR_GEMTEXTLINK_H

#include "GemtextElement.h"

//Класс ссылок
class GemtextLink: public GemtextElement {
private:
    std::string link;
    std::string text;
public:
    GemtextLink(const std::string& link, const std::string& text);
    std::string toHTML() override;
};


#endif //WEBSITEGENERATOR_GEMTEXTLINK_H
