#include "GemtextQuote.h"

GemtextQuote::GemtextQuote(std::string text): text(text) {}

std::string GemtextQuote::toHTML() {
    return "<q>" + text + "</q>";
}