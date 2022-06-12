#include "GMIFileReader.h"

GMIFileReader::GMIFileReader(const fs::path& source) {
    reader.open(source);
    if (reader.fail()) {
        throw std::ios_base::failure("Failed to open one of the source .gmi files");
    }
    state = new GMIFileReaderStandardState();
}

void GMIFileReader::close() {
    reader.clear();
    reader.close();
    if (reader.fail()) {
        throw std::ios_base::failure("Failed to close one of the source .gmi files");
    }
}

bool GMIFileReader::eof() {
    return reader.eof();
}

bool GMIFileReader::fail() {
    return reader.fail() && !reader.eof();
}

GemtextFile GMIFileReader::readFile() {
    GemtextFile resultFile;
    string currLine;
    while (!reader.eof()) {
        getline(reader, currLine);
        if (fail()) {
            throw std::ios_base::failure("Failed to read from one of the source .gmi files");
        }
        GMIFileReaderAbstractState* tmp;
        //В цикле GMIFileReader обрабатывает текущую строку и меняет своё состояние, если требуется
        // Когда tmp примет значение nullptr это сигнал программе, что строка обработана и надо идти дальше
        //Так как состояний всего 3, то в цикле будет максимум 2 итерации,
        // но есть возможность для добавления новых состояний
        while ((tmp = state->updateFile(resultFile, currLine)) != nullptr) {
            changeState(tmp);
        }
    }
    return resultFile;
}

void GMIFileReader::changeState(GMIFileReaderAbstractState* state) {
    delete this->state;
    this->state = state;
}
