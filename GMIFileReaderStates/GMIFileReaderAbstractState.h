#ifndef WEBSITEGENERATOR_GMIFILEREADERABSTRACTSTATE_H
#define WEBSITEGENERATOR_GMIFILEREADERABSTRACTSTATE_H

#include "../Parsing/GemtextFile.h"
#include "../Gemtext/GemtextElementTypes.h"

//Класс, обобщающий состояния, в которых может прибывать GMIFileReader. По умолчанию у него есть состояния:Standard, PreformattedText, List
class GMIFileReaderAbstractState {
protected:
    //Метод для определения типа элемента gemtext
    GemtextType getType(const std::string& line);
    //Метод, который конвертирует строку с элементом gemtext указанного типа в класс GemtextElement
    GemtextElement* parseLine(const std::string& line, const GemtextType& type);
public:
    //Метод, который добавляет в указанный GemtextFile элемент gemtext, который содержится в строке
    //Если состояние требуется изменить, тот метод вернёт указатель на новое состояние, в которое надо перейти
    //Если же состояние менять не требуется, то возвращается nullptr
    virtual GMIFileReaderAbstractState* updateFile(GemtextFile& file, std::string line) = 0;
};

#endif //WEBSITEGENERATOR_GMIFILEREADERABSTRACTSTATE_H
