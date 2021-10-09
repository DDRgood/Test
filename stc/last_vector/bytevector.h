#include <stdexcept>
#include <iostream>

// byte realization
template<class T>
class ByteVector
{
    private:
        size_t _size;
        size_t _capacity;
        char* storage = nullptr;
        void myrealloc();
    public:
        ByteVector(size_t n);
        ByteVector(ByteVector& vec);
        size_t size();
        size_t capacity();
        T& operator[](size_t index);
        T& pop_back();
        void push_back(const T& elem);
        void resize(size_t newSize);
        ~ByteVector();
};

template<class T>
ByteVector<T>::ByteVector(size_t n)
    : _size(0), _capacity(n), storage(new char[n*sizeof(T)])
    {}

template<class T>
ByteVector<T>::~ByteVector()
{
    for (int i = 0; i < _size; i++)
    {
        static_cast<T*> elem = storage+(i*sizeof(T));
        elem->~T();
    }
    delete[] storage;
}

template<class T>
size_t ByteVector<T>::size()
{
    return _size;
}

template<class T>
size_t ByteVector<T>::capacity()
{
    return _capacity;
}

template<class T>
T& ByteVector<T>::operator[](size_t index)
{
    return storage[index*sizeof(T)];
}

template<class T>
void ByteVector<T>::resize()
{
    if(newSize > _capacity)
    {
        _capacity = newSize;
        myrealloc();
    }
    else
    {
        for (size_t i = newSize; i < _size; i++)
        {
            storage[i].~T();
        }
    }
    _size = newSize;  
}