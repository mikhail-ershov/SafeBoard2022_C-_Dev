#ifndef WEBSITEGENERATOR_GMIFILEREADERLISTSTATE_H
#define WEBSITEGENERATOR_GMIFILEREADERLISTSTATE_H

#include "GMIFileReaderAbstractState.h"
#include "../Gemtext/GemtextList.h"
// Класс состояния List: в этом состоянии GMIFileReader занимается построением списка, пока не наткнётся на элемент,
// который не является частью списка, в таком случае он вернётся в состояние Standard
class GMIFileReaderListState: public GMIFileReaderAbstractState {
private:
    GemtextList* list;
public:
    GMIFileReaderAbstractState* updateFile(GemtextFile &file, std::string line) override;
    GMIFileReaderListState();
};


#endif //WEBSITEGENERATOR_GMIFILEREADERLISTSTATE_H
