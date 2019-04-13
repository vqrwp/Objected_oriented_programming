#include "error_messages.h"
#include "QMessageBox"
#include <QObject>

void error_messages(errors err)
{
    switch (err)
    {
        case FILE_NOT_FOUND:
            QMessageBox::critical(nullptr, "Ошибка", "Невозможно открыть файл.");
            break;

        case CONTENT_ERROR:
            QMessageBox::critical(nullptr, "Ошибка", "Ошибка открытия или считывания файла.");
            break;

        case MEMORY_ALLOCATION:
            QMessageBox::critical(nullptr, "Ошибка", "Ошибка при выделении памяти.");
            break;

        case NO_DOTS:
            QMessageBox::critical(nullptr, "Ошибка", "Массив точек пуст.");
            break;

        case UNKNOWN_ERROR:
            QMessageBox::critical(nullptr, "Ошибка", "Неизвестная ошибка.");
            break;
        case NO_ERRORS:
            break;
    }
}
