//
// Created by Margo on 14.04.2019.
//

#ifndef LAB_2_ERRORS_H
#define LAB_2_ERRORS_H

#include <iostream>
#include <exception>

class baseError : public std::exception
{
public:
    baseError(std::string filename, std::string classname, int line, const char *time,
              std::string info = "Ошибка")
    {
        err_info = "\nИмя файла: " + filename + "\nКласс: " + classname + "\n№ линии: " + std::to_string(line) +
                   "\nДата, время: " + time + "Информация: " + info;
    }
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
protected:
    std::string err_info;
};

class memError : public baseError
{
public:
    memError(std::string filename, std::string classname, int line, const char *time,
             std::string info = "Ошибка памяти") :
            baseError(filename, classname, line, time, info) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
};

class emptyError : public baseError
{
public:
    emptyError(std::string filename, std::string classname, int line, const char *time,
               std::string info = "Попытка работы с пустым вектором") :
            baseError(filename, classname, line, time, info) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
};

class rangeError : public baseError
{
public:
    rangeError(std::string filename, std::string classname, int line, const char *time,
               std::string info = "Ошибка выхода за границы!") :
            baseError(filename, classname, line, time, info) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
};

class deletedObj : public baseError
{
public:
    deletedObj(std::string filename, std::string classname, int line, const char *time,
               std::string info = "Работа с удаленным объектом (дикий указатель)") :
            baseError(filename, classname, line, time, info) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
};
#endif //LAB_2_ERRORS_H
