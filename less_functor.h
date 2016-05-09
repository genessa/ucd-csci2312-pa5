//
// Created by Genessa Moodie on 5/5/16.
//

#ifndef UCD_CSCI2312_PA5_LESS_FUNCTOR_H
#define UCD_CSCI2312_PA5_LESS_FUNCTOR_H

#include <string>
#include <cstring>

namespace CS2312
{

    template<typename T>
    class less
    {
//        T innards;
    public:
        inline bool operator<(const T &t)
        {
            if (*this < t )
                return true;
            return false;
        }//operator<
        inline bool operator()(T less1, T less2)
        {
//            less *l1 = new less;
//            less *l2 = new less;
//            l1->innards = less1;
//            l2->innards = less2;
            if (less1 < less2)  // why isn't this using its own < operator..
            return true;

            else
                return false;
        }
    };//class

    template<>
    class less<std::string>
    {
//        std::string stuff;
    public:
        inline bool operator<(const std::string &s2)
        {
            if (*this < s2)
                return true;
            return false;
        }//operator<

        inline bool operator()(std::string s1, std::string s2)
        {
            //construct two new less objects with s1 and s2, then compare with < ?
//            less *l1 = new less;
//            less *l2 = new less;
//            l1->stuff = s1;
//            l2->stuff = s2;

            if (s1 < s2)
                return true;
            else
                return false;

        }//operator()
    };//less<string>

    template<>
    class less<char *> //hwat
    {
//        std::string stuff;
    public:
        inline bool operator<(const char *thing)
        {
            if (*this < thing)
                return true;
            return false;
        }
        inline bool operator()(const char* less1, const char* less2)
        {
            std::string l1 = less1;
            std::string l2 = less2;

            if (l1 < l2)
                return true;
            else
                return false;
        }
    };

}//namespace
#endif //UCD_CSCI2312_PA5_LESS_FUNCTOR_H
