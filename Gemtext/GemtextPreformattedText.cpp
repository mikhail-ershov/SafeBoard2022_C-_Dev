#include "GemtextPreformattedText.h"

std::string GemtextPreformattedText::toHTML() {
    std::string result = "<pre>\n";
    for (auto element: elements) {
        result += element + "\n";
    }
    result += "</pre>";
    return result;
}

void GemtextPreformattedText::add(std::string element) {
    elements.push_back(element);
}