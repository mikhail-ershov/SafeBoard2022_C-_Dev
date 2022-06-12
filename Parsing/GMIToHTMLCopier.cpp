#include "GMIToHTMLCopier.h"

void GMIToHTMLCopier::copyFile(fs::path source, fs::path target) {
    //Для файла .gmi вызовем GMIFileReader, чтобы он записал в target данный файл в виде .html
    //Другие файлы просто скопируем
    if (source.string().ends_with(".gmi")) {
        GMIFileReader gmiFileReader(source);
        gmiFileReader.readFile().writeHTML(target.string());
    } else {
        fs::copy(source, target);
    }
}

void GMIToHTMLCopier::copyDirectory(fs::path source, fs::path target) {
    if (!fs::exists(source)) {
        throw fs::filesystem_error(
                "Source directory not found",
                source,
                std::make_error_code(std::errc::no_such_file_or_directory)
        );
    }
    if (!fs::exists(target.parent_path())) {
        throw fs::filesystem_error(
                "Target parent directory not found",
                target.parent_path(),
                std::make_error_code(std::errc::no_such_file_or_directory)
        );
    }
    //Чтобы избежать проблемы с конфликтующими файлами, я использую метод filesystem::remove_all,
    // который полностью удаляет директорию target, если она существует.
    //Изначально я хотел сделать так, чтобы он перезаписывал только конфликтующие файлы из target и source,
    //и планировал использовать метод std::filesystem::copy с опцией std::filesystem::copy_options::overwrite_existing,
    // которая, судя по документации, должна как раз решать эту проблему, но почему-то я всё равно натыкался на
    // исключение filesystem_error:"File already exists".
    // Я не смог определиться, в чём заключается проблема, поэтому решил удалять всё.
    //В принципе, это не противоречит логике задания, так как вряд ли мы будем создавать сайт в директории,
    // где уже находятся какие-то файлы
    fs::remove_all(target);

    //Копируется директорию source и всё её поддиректории в target, но не копирую файлы
    fs::copy(source, target, fs::copy_options::directories_only | fs::copy_options::recursive);

    //Теперь осуществляется проход по директории source ещё раз, но теперь копируются только файлы
    for (const auto& entry : fs::recursive_directory_iterator(source))
    {
        if (entry.is_directory()) {
            continue;
        }
        //Строим путь до текущего файла относительно директории source,
        //чтобы потом скопировать его по тому же пути в target
        const auto& currSourcePath = entry.path();
        const std::string currSourceFilename = currSourcePath.filename().string();
        const auto relativeSourcePath = fs::relative(currSourcePath, source);
        auto currTargetPath = target / relativeSourcePath.parent_path();

        //Если копируем .gmi файл, то поменяем расширение в target на .html
        if (currSourceFilename.ends_with(".gmi")) {
            std::string currTargetFilename = currSourceFilename.substr(0, currSourceFilename.size() - 4) + ".html";
            currTargetPath /= currTargetFilename;
        } else {
            currTargetPath /= currSourcePath.filename();
        }

        copyFile(currSourcePath, currTargetPath);
    }
}