#include "GemtextListItem.h"

GemtextListItem::GemtextListItem(std::string text): text(text) {}

std::string GemtextListItem::toHTML() {
    return "<li>" + text + "</li>";
}