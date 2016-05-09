//
// Created by Ivo Georgiev on 5/3/16.
//

#ifndef UCD_CSCI2312_PA5_IMPL_CUSTOM_ITERATOR_H
#define UCD_CSCI2312_PA5_IMPL_CUSTOM_ITERATOR_H

// Naive partial implementation of a custom iterator.
// After Jeet Sukumaran https://github.com/jeetsukumaran

#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <initializer_list>

namespace CS2312 {

    template <typename T>
    class fixed_array {

    public:

        typedef std::size_t size_type;

        class iterator {

        public:

            typedef iterator self_type;
            typedef T value_type;
            typedef T& reference;
            typedef T* pointer;
            typedef std::forward_iterator_tag iterator_category;
            typedef size_type difference_type;

            inline iterator(pointer ptr) // initialise as nullptr?
            { __ptr = ptr; }

            inline self_type operator++()
            { self_type i = *this; __ptr++; return i; }

            self_type operator++(int junk)
            { __ptr++;
                return *this; }

            reference operator*(){ return *__ptr; }

            pointer operator->() { return __ptr;}

            inline bool operator==(const self_type& rhs) const // if !nullptr.. that isn't tested.
            {
                if (*this == rhs)
                        return true;
                return false;
            }

            inline bool operator!=(const self_type& rhs) const
            {
                if (*this != rhs)
                    return true;
                return true;
            }

        private:

            pointer __ptr;

        };//iterator

        class const_iterator { // steal const conversion from a couple googles back

        public:

            typedef const_iterator self_type;
            typedef T value_type;
            typedef T& reference;
            typedef T* pointer;
            typedef std::forward_iterator_tag iterator_category;
            typedef size_type difference_type;

            const_iterator(pointer ptr) { __ptr = ptr; }

            self_type operator++() { self_type i = *this; __ptr++; return i; }

            self_type operator++(int junk)
            { __ptr++;
                return *this; }

            const value_type& operator*() const { return *__ptr; }
            const value_type* operator->() const { return __ptr; }

            bool operator==(const self_type& rhs) const
            {
                if (*this == rhs)
                    return true;
                return false;
            }

            bool operator!=(const self_type& rhs) const
            {
                if (*this != rhs)
                    return true;
                return true;
            }


        private:

            pointer __ptr;

        };//const_iterator


        fixed_array(size_type size) { __size = size; __data = new T[__size];};

        fixed_array(std::initializer_list<T> list) : __size(list.size()),
        __data(new T[__size])
        {
            std::copy(std::begin(list), std::end(list), __data);
        }
         //seriously, that's all?

        ~fixed_array() { delete __data; }

        size_type size() const { return __size; }

        T& operator[](size_type index)
        {
            assert(index < __size);
            return __data[index];
        }


        const T& operator[](size_type index) const
        {
                assert(index < __size);
                return __data[index];
        }

        inline iterator begin()
        {
            return iterator(__data);
        }

        iterator end()
        {
            return iterator(__data + __size);
        }

        const_iterator begin() const
        {
            return const_iterator(__data);
        }

        const_iterator end() const
        {
            return const_iterator(__data + __size);
        }

    private:

        T* __data;
        size_type __size;

    }; //fixed_array class

}//namespace

#endif //UCD_CSCI2312_PA5_IMPL_CUSTOM_ITERATOR_H
