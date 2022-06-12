#ifndef WEBSITEGENERATOR_GMIFILEREADERPREFORMATTEDSTATE_H
#define WEBSITEGENERATOR_GMIFILEREADERPREFORMATTEDSTATE_H

#include "GMIFileReaderAbstractState.h"
#include "../Parsing/GMIFileReader.h"
//Класс состояния PreformattedText: в этом состоянии GMIFileReader находится в режиме обработки преформатированного текста
class GMIFileReaderPreformattedState: public GMIFileReaderAbstractState {
private:
    GemtextPreformattedText* text;
    //из-за особенности разметки преформатированного текста, нельзя одновременно добавить преформатированный текст в файл
    //и сменить состояние, для этого нужен флаг, который сообщит классу, что надо сменить состояние
    bool changeState;
public:
    GMIFileReaderPreformattedState();
    GMIFileReaderAbstractState* updateFile(GemtextFile &file, std::string line) override;
};


#endif //WEBSITEGENERATOR_GMIFILEREADERPREFORMATTEDSTATE_H
