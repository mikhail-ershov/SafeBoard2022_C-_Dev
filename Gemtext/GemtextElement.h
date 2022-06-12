#ifndef WEBSITEGENERATOR_GEMTEXTELEMENT_H
#define WEBSITEGENERATOR_GEMTEXTELEMENT_H

#include <string>

//Абстрактый класс базового элемента gemtext
class GemtextElement {
public:
    //Конвертировать элемент из gemtext в html
    virtual std::string toHTML() = 0;
};

#endif //WEBSITEGENERATOR_GEMTEXTELEMENT_H
