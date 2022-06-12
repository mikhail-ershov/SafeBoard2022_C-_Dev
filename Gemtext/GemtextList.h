//
// Created by mikha on 11.06.2022.
//

#ifndef WEBSITEGENERATOR_GEMTEXTLIST_H
#define WEBSITEGENERATOR_GEMTEXTLIST_H

#include "GemtextElement.h"
#include "GemtextListItem.h"
#include <list>
//Класс списков
class GemtextList: public GemtextElement {
private:
    std::list<GemtextListItem*> elements;
public:
    GemtextList() = default;
    ~GemtextList();
    void add(GemtextListItem* element);
    std::string toHTML() override;
};


#endif //WEBSITEGENERATOR_GEMTEXTLIST_H
