#include "GemtextParagraph.h"

GemtextParagraph::GemtextParagraph(std::string text): text(text) {}

std::string GemtextParagraph::toHTML() {
    return "<p>" + text + "</p>";
}