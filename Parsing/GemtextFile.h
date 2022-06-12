#ifndef WEBSITEGENERATOR_GEMTEXTFILE_H
#define WEBSITEGENERATOR_GEMTEXTFILE_H

#include "../Gemtext/GemtextElement.h"
#include <list>
#include <filesystem>

namespace fs = std::filesystem;

//Класс, представляющий из себя набор элементов gemtext, то есть по сути файл .gmi
class GemtextFile {
private:
    std::list<GemtextElement*> elements;
public:
    GemtextFile() = default;
    ~GemtextFile();
    void add(GemtextElement* element);
    //Конвертировать файл из gemtext в html
    void writeHTML(const fs::path& target);
};


#endif //WEBSITEGENERATOR_GEMTEXTFILE_H
