//
// Created by liupai on 18-7-3.
//

#ifndef TYPE_NAME_H
#define TYPE_NAME_H

#include <stdio.h>

#include <typeinfo>
#include <cxxabi.h>
//#include <utility> //std::move
//
// class type_name
//{
// public:
//    template <typename T>
//    type_name(const T t): realname(abi::__cxa_demangle(typeid(T).name(), 0, 0,
//    &status))
//    {
//        printf("%s \n", realname);
//    }
//    ~type_name()
//    {
//        delete realname;
//    }
//
// private:
//    int status;
//    char* realname;
//
//};
#define TYPE_NAME(T)                                             \
    int   status##T = 0;                                         \
    char* realname##T =                                          \
        abi::__cxa_demangle(typeid(T).name(), 0, 0, &status##T); \
    printf("%s \n", realname##T);                                \
    delete realname##T;
// #define TYPE_NAME(i) type_name(std::move(i));
#endif  // TYPE_NAME_H
