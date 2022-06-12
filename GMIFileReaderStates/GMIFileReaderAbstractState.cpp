#include "GMIFileReaderAbstractState.h"
#include "../GemtextReaders/GemtextElementReader.h"
#include "../GemtextReaders/GemtextHeaderReader.h"
#include "../GemtextReaders/GemtextParagraphReader.h"
#include "../GemtextReaders/GemtextListItemReader.h"
#include "../GemtextReaders/GemtextQuoteReader.h"
#include "../GemtextReaders/GemtextLinkReader.h"

GemtextType GMIFileReaderAbstractState::getType(const std::string& line) {
    if (line.starts_with("### ")) {
        return HEADER_3;
    }
    if (line.starts_with("## ")) {
        return HEADER_2;
    }
    if (line.starts_with("# ")) {
        return HEADER_1;
    }
    if (line.starts_with("* ")) {
        return LIST_ITEM;
    }
    if (line.starts_with("=>")) {
        return LINK;
    }
    if (line.starts_with(">")) {
        return QUOTE;
    }
    if (line.starts_with("```")) {
        return PREFORMATTED;
    }
    return PARAGRAPH;
}

GemtextElement *GMIFileReaderAbstractState::parseLine(const std::string& line, const GemtextType& type) {
    GemtextElementReader* reader;
    switch (type) {
        case HEADER_1:
        case HEADER_2:
        case HEADER_3:
            reader = new GemtextHeaderReader();
            break;
        case PARAGRAPH:
            reader = new GemtextParagraphReader();
            break;
        case LIST_ITEM:
            reader = new GemtextListItemReader();
            break;
        case QUOTE:
            reader = new GemtextQuoteReader();
            break;
        case LINK:
            reader = new GemtextLinkReader();
            break;
        case PREFORMATTED:
            throw std::invalid_argument("PREFORMATTED type is not for parsing");
            break;
    }
    GemtextElement* result = reader->read(line, type);
    delete reader;
    return result;
}

