#include "GemtextListItemReader.h"
#include "../Gemtext/GemtextListItem.h"

GemtextElement *GemtextListItemReader::read(const std::string &line, const GemtextType &type) {
    if (line.size() == 2) {
        throw InvalidGemtextFileException("Invalid list");
    }
    if (type == LIST_ITEM) {
        return new GemtextListItem(line.substr(2));
    }
    throw std::invalid_argument("Type is not LIST_ITEM");
}
