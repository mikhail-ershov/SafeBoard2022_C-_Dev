#include <stdexcept>
#include "GemtextHeaderReader.h"
#include "../Gemtext/GemtextHeader.h"

GemtextElement* GemtextHeaderReader::read(const std::string &line, const GemtextType &type) {
    switch (type) {
        case HEADER_1:
            if (line.size() == 2) {
                throw InvalidGemtextFileException("Empty header");
            }
            return new GemtextHeader(line.substr(2), 1);
        case HEADER_2:
            if (line.size() == 3) {
                throw InvalidGemtextFileException("Empty header");
            }
            return new GemtextHeader(line.substr(3), 2);
        case HEADER_3:
            if (line.size() == 4) {
                throw InvalidGemtextFileException("Empty header");
            }
            return new GemtextHeader(line.substr(4), 3);
        default:
            throw std::invalid_argument("Type is not HEADER");
    }

}
