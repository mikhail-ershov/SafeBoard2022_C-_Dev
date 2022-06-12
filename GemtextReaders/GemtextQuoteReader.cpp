#include "GemtextQuoteReader.h"
#include "../Gemtext/GemtextQuote.h"

GemtextElement* GemtextQuoteReader::read(const std::string &line, const GemtextType &type) {
    if (type != QUOTE) {
        throw std::invalid_argument("Type is not QUOTE");
    }
    if (line.size() == 1) {
        throw InvalidGemtextFileException("Empty quote");
    }
    return new GemtextQuote(line.substr(1));
}
