#include "myvector.h"

template<class Type>
MyVector<Type>::MyVector(size_t n)
{
    storage = new Type[n];
    size = n;
    capacity = n;
}

template<class Type>
size_t MyVector<Type>::getSize()
{
    return size;
}

template<class Type>
size_t MyVector<Type>::getCapacity()
{
    return capacity;
}

template<class Type>
void MyVector<Type>::resize(size_t newSize)
{
    if (newSize > size)
    {
        if (newSize > capacity)
        {
            capacity = newSize;
            myrealloc2();
        }
    }
    else
    {
        for (size_t i = newSize; i < size; i++)
        {
            storage[i].~Type();
        }
    }
    size = newSize;
}

// rude realize
template<class Type>
void MyVector<Type>::myrealloc()
{
    Type* newStorage = new Type[capacity];
    //memcpy(static_cast<void*>(newStorage), static_cast<void*>(storage), sizeof(Type)*size);
    delete [] storage;
    storage = newStorage;
}

template<class Type>
void MyVector<Type>::myrealloc2()
{
    storage = (Type*)realloc(storage, size*sizeof(Type));
    if (!storage) throw std::bad_alloc();
}

template<class Type>
Type& MyVector<Type>::operator[](size_t index)
{
    return storage[index];
}

template<class Type>
void MyVector<Type>::push_back(const Type& element)
{
    if (size+1 < capacity)
    {
        storage[size++] = element;
    }
    else
    {
        capacity = capacity + capacity/2 + 1;
        myrealloc2();
        storage[size++] = element;
    }
}

template<class Type>
Type& MyVector<Type>::pop_back()
{
    return storage[size-1];
}


template<class Type>
MyVector<Type>::~MyVector()
{
    if (storage != nullptr)
        delete[] storage;
}

