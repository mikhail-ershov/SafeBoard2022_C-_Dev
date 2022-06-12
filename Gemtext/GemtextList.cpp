#include "GemtextList.h"

std::string GemtextList::toHTML() {
    std::string result = "<ul>\n";
    for (GemtextListItem* item: elements) {
        result += "  " + item->toHTML() + "\n";
    }
    result += "</ul>";
    return result;
}

void GemtextList::add(GemtextListItem* element) {
    elements.push_back(element);
}

GemtextList::~GemtextList() {
    for (GemtextListItem* element: elements) {
        delete element;
    }
}
