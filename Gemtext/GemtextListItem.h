#ifndef WEBSITEGENERATOR_GEMTEXTLISTITEM_H
#define WEBSITEGENERATOR_GEMTEXTLISTITEM_H

#include "GemtextElement.h"

//Класс элементов списка
class GemtextListItem: public GemtextElement {
private:
    std::string text;
public:
    GemtextListItem(std::string text);
    std::string toHTML() override;

};


#endif //WEBSITEGENERATOR_GEMTEXTLISTITEM_H
