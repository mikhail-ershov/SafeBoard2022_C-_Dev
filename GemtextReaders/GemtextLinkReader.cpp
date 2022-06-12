#include "GemtextLinkReader.h"
#include "../Gemtext/GemtextLink.h"

GemtextElement *GemtextLinkReader::read(const std::string &line, const GemtextType &type) {
    std::string text, link;
    int i, j, t;
    i = 2;
    while (i < line.size() && isspace(line[i])) {
        i++;
    }
    if (i == line.size()) {
        throw InvalidGemtextFileException("Invalid link");
    }
    j = i;
    while (j < line.size() && !isspace(line[j])) {
        j++;
    }
    link = line.substr(i, j - i);
    t = j;
    while (t < line.size() && isspace(line[t])) {
        t++;
    }
    if (j == t) {
        text = {};
    } else {
        text = line.substr(t);
    }
    return new GemtextLink(link, text);
}
