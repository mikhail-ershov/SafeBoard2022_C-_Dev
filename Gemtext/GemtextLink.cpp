#include "GemtextLink.h"

GemtextLink::GemtextLink(const std::string& link, const std::string& text): link(link) {
    if (text.empty()) {
        this->text = link;
    } else {
        this->text = text;
    }
}

std::string GemtextLink::toHTML() {
    return "<a href=\"" + link + "\">" + text + "</a>";
}

