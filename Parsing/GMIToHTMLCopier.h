#ifndef WEBSITEGENERATOR_GMITOHTMLCOPIER_H
#define WEBSITEGENERATOR_GMITOHTMLCOPIER_H
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include "GMIFileReader.h"

namespace fs = std::filesystem;
//Класс, осуществляющий копирование директории по адресу source в директорию по адресу target
//Обязательно существование директории source и родительской директории target,
//саму директорию target класс может создать сам.
//Класс полностью перезаписывает директорию target, если она существует, то есть, если в ней находятся какие-то данные,
//то они будут стёрты. Подробнее проблема будет объяснена в описании метода
class GMIToHTMLCopier {
public:
    static void copyDirectory(fs::path source, fs::path target);
    static void copyFile(fs::path source, fs::path target);
};


#endif //WEBSITEGENERATOR_GMITOHTMLCOPIER_H
