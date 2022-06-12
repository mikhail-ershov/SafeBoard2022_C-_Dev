#ifndef WEBSITEGENERATOR_GMIFILEREADER_H
#define WEBSITEGENERATOR_GMIFILEREADER_H
#include <fstream>
#include <string>
#include "../Gemtext/GemtextElement.h"
#include "../Gemtext/GemtextHeader.h"
#include "../Gemtext/GemtextLink.h"
#include "../Gemtext/GemtextList.h"
#include "../Gemtext/GemtextListItem.h"
#include "../Gemtext/GemtextParagraph.h"
#include "../Gemtext/GemtextPreformattedText.h"
#include "../Gemtext/GemtextQuote.h"
#include "../Gemtext/GemtextElementTypes.h"
#include "../GemtextReaders/GemtextElementReader.h"
#include "../GemtextReaders/GemtextHeaderReader.h"
#include "../GemtextReaders/GemtextParagraphReader.h"
#include "../GemtextReaders/GemtextListItemReader.h"
#include "../GemtextReaders/GemtextQuoteReader.h"
#include "../GemtextReaders/GemtextLinkReader.h"
#include "GemtextFile.h"
#include "../GMIFileReaderStates/GMIFileReaderAbstractState.h"
#include "../GMIFileReaderStates/GMIFileReaderStandardState.h"
#include "../GMIFileReaderStates/GMIFileReaderPreformattedState.h"
#include "../GMIFileReaderStates/GMIFileReaderListState.h"
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

//Класс, позволяющий считать .gmi файл по указанному адресу и конвертировать его в GemtextFile
class GMIFileReader {
private:
    ifstream reader;
    //Текущее состояние GMIFileReader, по умолчанию - Standard
    GMIFileReaderAbstractState* state;
    //Метод, позволяющий изменить состояние
    void changeState(GMIFileReaderAbstractState* state);
public:
    explicit GMIFileReader(const fs::path& source);
    //Метод, позволяющий считать .gmi файл и конвертировать его в GemtextFile
    GemtextFile readFile();
    //Метод для закрытия GMIFileReader
    void close();
    //Метод, сообщающий дошёл ли GMIFileReader до конца файла
    bool eof();
    //Метод, сообщающий произошла ли ошибка при чтении
    bool fail();
};


#endif //WEBSITEGENERATOR_GMIFILEREADER_H
