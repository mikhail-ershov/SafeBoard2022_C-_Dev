#include <iostream>
#include <fstream>
#include <filesystem>
#include "Parsing/GemtextFile.h"
#include "Parsing/GMIToHTMLCopier.h"

namespace fs = std::filesystem;
using path = fs::path;

int main(int argc, char* argv[]) {
    try {
        if (argc < 3) {
            throw std::invalid_argument("Not enough arguments");
        }
        //Откуда
        path source = path(argv[1]);
        //Куда
        path dest = path(argv[2]);
        //Достраиваем абсолютные пути, если указаны относительно текущей директории
        if (source.root_name().empty()) {
            source = fs::current_path() / source;
        }
        if (dest.root_name().empty()) {
            dest = fs::current_path() / dest;
        }
        GMIToHTMLCopier::copyDirectory(source, dest);
    } catch (fs::filesystem_error const& e) {
        std::cerr<< "Filesystem error\nWhat: " << e.what() << std::endl;
        if (!e.path1().empty()) {
            std::cerr << "Path 1: " << e.path1() << std::endl;
        }
        if (!e.path2().empty()) {
            std::cerr << "Path 2: " << e.path2() << std::endl;
        }
        return e.code().value();
    } catch (std::ios_base::failure const& e) {
        std::cerr<< "I/O exception\nWhat: " << e.what() << std::endl;
        return e.code().value();
    } catch (InvalidGemtextFileException const& e) {
        std::cerr<< "Invalide gemtext file exception\nWhat: " << e.what() << std::endl;
    } catch (std::invalid_argument const& e) {
        std::cerr<< "Invalid argument exception\nWhat: " << e.what() << std::endl;
    } catch (std::exception const& e) {
        std:: cerr<< "What: " << e.what() << std::endl;
    }
    return 0;
}
