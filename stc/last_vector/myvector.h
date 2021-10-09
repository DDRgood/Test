#include <stdexcept>
#include <iostream>

// naive realization
template<class T>
class MyVector
{
    private:
        size_t _size;
        size_t _capacity;
        T* storage = nullptr;
        void myrealloc();
    public:
        MyVector(size_t n);
        MyVector(MyVector& vec);
        size_t size();
        size_t capacity();
        T& operator[](size_t index);
        T& pop_back();
        void push_back(const T& elem);
        void resize(size_t newSize);
        ~MyVector();
};

template<class T>
MyVector<T>::MyVector(size_t n)
    : _size(0), _capacity(n), storage(new T[n])
{}

template<class T>
MyVector<T>::MyVector(MyVector& vec)
{
    _size = vec._size;
    _capacity = vec._capacity;
    storage = new T[_capacity];
    for (size_t i = 0; i < _size; i++)
    {
        storage[i] = vec.storage[i];
    }
    //std::copy(vec.storage, vec.storage+vec._size, storage);
}

template<class T>
size_t MyVector<T>::size()
{
    return _size;
}

template<class T>
size_t MyVector<T>::capacity()
{
    return _capacity;
}

template<class T>
T& MyVector<T>::operator[](size_t index)
{
    return storage[index];
}

template<class T>
void MyVector<T>::push_back(const T& elem)
{
    if (_size == _capacity)
    {
        _capacity = _capacity + _capacity / 2 + 1;
        myrealloc();
        storage[_size++] = elem;
    }
    else
    {
        storage[_size++] = elem;
    }
}

template<class T>
T& MyVector<T>::pop_back()
{
    // ~T() ?
    return storage[_size-- - 1];
}


template<class T>
void MyVector<T>::resize(size_t newSize)
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

template<class T>
void MyVector<T>::myrealloc()
{
    T* newStorage = new T[_capacity];
    for (size_t i = 0; i < _size; i++)
    {
        newStorage[i] = storage[i];
    }
    delete[] storage;
    storage = newStorage;
}


template<class T>
MyVector<T>::~MyVector()
{
    delete[] storage;
}