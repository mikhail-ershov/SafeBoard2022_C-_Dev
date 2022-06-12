#ifndef WEBSITEGENERATOR_GMIFILEREADERSTANDARDSTATE_H
#define WEBSITEGENERATOR_GMIFILEREADERSTANDARDSTATE_H

#include "GMIFileReaderAbstractState.h"

//Класс состояние Standard: В этом состоянии GMIFileReader считывает все элементы gemtext,
// кроме преформатированного текста и списков
class GMIFileReaderStandardState: public GMIFileReaderAbstractState {
public:
    GMIFileReaderAbstractState* updateFile(GemtextFile &file, std::string line) override;
};


#endif //WEBSITEGENERATOR_GMIFILEREADERSTANDARDSTATE_H
