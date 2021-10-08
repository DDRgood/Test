#pragma once
#include <stdexcept>
#include <iostream>

template<class Type>
class MyVector
{
    private:
        size_t size = 0;
        size_t capacity = 0;
        Type* storage = nullptr;
        void resize(size_t newSize);
        void myrealloc();
        void myrealloc2();
        //void move_storage(Type* dest, Type* from, size_t n);

    public:
        MyVector(size_t n);
        size_t getSize();
        size_t getCapacity();
        Type& operator[](size_t index);
        void push_back(const Type& element);
        Type& pop_back();
        ~MyVector();
};