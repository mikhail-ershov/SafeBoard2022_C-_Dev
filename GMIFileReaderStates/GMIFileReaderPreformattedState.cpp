//
// Created by mikha on 12.06.2022.
//

#include "GMIFileReaderPreformattedState.h"
#include "GMIFileReaderStandardState.h"

GMIFileReaderPreformattedState::GMIFileReaderPreformattedState() {
    text = nullptr;
    changeState = false;
}

GMIFileReaderAbstractState* GMIFileReaderPreformattedState::updateFile(GemtextFile &file, std::string line) {
    //Смена состояния
    if (changeState) {
        return new GMIFileReaderStandardState();
    }
    GemtextType type = getType(line);
    if (type == PREFORMATTED) {
        if (text == nullptr) {
            text = new GemtextPreformattedText(); //GMIFileReader попал на начало текста, то есть на строку "```"
        } else {
            // GMIFileReader попал на последнюю строку, то есть опять же на "```"
            // Так как эту строку не надо рассматривать заново, то вместо смены состояние тут, она будет осуществлена
            // на следующей строке
            file.add(text);
            text = nullptr;
            changeState = true;
        }
    } else {
        text->add(line);
    }
    return nullptr;
}
