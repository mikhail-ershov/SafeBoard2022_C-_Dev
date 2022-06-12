#include "GemtextParagraphReader.h"
#include "../Gemtext/GemtextParagraph.h"

GemtextElement *GemtextParagraphReader::read(const std::string& line, const GemtextType& type) {
    if (type == PARAGRAPH) {
        return new GemtextParagraph(line);
    }
    throw std::invalid_argument("Type is not PARAGRAPH");
}
