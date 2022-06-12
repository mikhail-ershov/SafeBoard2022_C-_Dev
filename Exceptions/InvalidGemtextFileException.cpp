#include "InvalidGemtextFileException.h"

InvalidGemtextFileException::InvalidGemtextFileException(const std::string& message): message(message) {
}

const char *InvalidGemtextFileException::what() const noexcept {
    return message.c_str();
}
