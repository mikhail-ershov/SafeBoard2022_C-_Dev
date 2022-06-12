#include "GemtextFile.h"
#include "GMIFileReader.h"
#include "../Gemtext/GemtextElement.h"
#include <iostream>

void GemtextFile::add(GemtextElement* element) {
    elements.push_back(element);
}

void GemtextFile::writeHTML(const fs::path& target) {
    std::ofstream writer;
    writer.open(target);
    //Проверка, открылся ли файл
    if (writer.fail()) {
        throw std::ios_base::failure("Failed to open file: " + target.string());
    }
    //Стандартная запись в начале html файла
    writer << "<!DOCTYPE>\n<html>\n<head>\n<meta charset=\"utf-8\">\n<title>WebsiteGenerator</title>\n</head>\n<body>\n";

    for (GemtextElement* element: elements) {
        writer << element->toHTML() << std::endl;
    }
    //Стандартная запись в конце html файла
    writer << "</body>\n</html>";
}

GemtextFile::~GemtextFile() {
    for (GemtextElement* element: elements) {
        delete element;
    }
}
