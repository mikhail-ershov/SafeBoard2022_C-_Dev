#include "GMIFileReaderStandardState.h"
#include "GMIFileReaderPreformattedState.h"
#include "GMIFileReaderListState.h"


GMIFileReaderAbstractState* GMIFileReaderStandardState::updateFile(GemtextFile &file, std::string line) {
    GemtextType type = getType(line);
    switch (type) {
        case PREFORMATTED:
            //Встречен преформатированный текст, надо сменить состояние
            return new GMIFileReaderPreformattedState();
        case LIST_ITEM:
            //Встречен первый элемент списка, надо сменить состояние
            return new GMIFileReaderListState();
        default:
            //Если пустая строка, то пропустим её(как я понимаю, от <p></p> html файл особо не меняется
            if (!line.empty()) {
                //Встречен другой элемент gemtext, надо добавить его в файл без смены состояния
                file.add(parseLine(line, type));
            }
            return nullptr;
    }
}
