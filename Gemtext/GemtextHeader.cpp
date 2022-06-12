#include <stdexcept>
#include "GemtextHeader.h"

GemtextHeader::GemtextHeader(std::string text, unsigned short level): text(text), level(level) {
    if (level == 0 || level > 3) {
        throw std::invalid_argument("Gemtext supports only headers of level 1 to 3");
    }
}

std::string GemtextHeader::toHTML() {
    std::string header = 'h' + std::to_string(level);
    return "<" + header + ">" + text + "</" + header + ">";
}