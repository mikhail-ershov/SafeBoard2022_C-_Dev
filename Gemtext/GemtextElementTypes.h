#ifndef WEBSITEGENERATOR_GEMTEXTELEMENTTYPES_H
#define WEBSITEGENERATOR_GEMTEXTELEMENTTYPES_H

//Все типы элементов gemtext
enum GemtextType {
    HEADER_1, //Заголовок 1 уровня
    HEADER_2, // Заголовок 2 уровня
    HEADER_3, // Заголовок 3 уровня
    PARAGRAPH, // Абзац
    LINK, // Ссылка
    LIST_ITEM, // Элемент списка
    PREFORMATTED, //Преформатированный текст
    QUOTE // Цитата
};

#endif //WEBSITEGENERATOR_GEMTEXTELEMENTTYPES_H
