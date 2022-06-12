#include "GMIFileReaderListState.h"
#include "GMIFileReaderStandardState.h"

GMIFileReaderAbstractState* GMIFileReaderListState::updateFile(GemtextFile &file, std::string line) {
    GemtextType type = getType(line);
    if (type == LIST_ITEM) {
        if (list == nullptr) {
            list = new GemtextList(); // GMIFileReader попал на первый элемент списка и начал построение списка
        }
        // Так как в GemtexList хранятся элементы класса GemtexListItem, а parseLine возвращает элемент класса GemtexElement,
        // то надо привести его к классу потомка
        list->add(dynamic_cast<GemtextListItem *>(parseLine(line, type)));
        // Так как состояние изменять не требуется, возвращается nullptr
        return nullptr;
    } else {
        // Полученный элемент не является частью списка, так что список закончен и его надо добавить в файл
        // Также надо вернуться в состояние Standard и обработать текущий элемент в нём
        file.add(list);
        list = nullptr;
        return new GMIFileReaderStandardState();
    }
}

GMIFileReaderListState::GMIFileReaderListState(){
    list = nullptr;
}
