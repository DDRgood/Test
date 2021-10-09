#include "myvector.h"

int main()
{
    MyVector<int> vector(4);
    std::cout << vector.size() << std::endl;
    std::cout << vector.capacity() << std::endl;
    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);
    vector.push_back(4);
    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);
    vector.push_back(4);
    std::cout << vector[0] << " " << vector[1] << " " << vector[3] << std::endl;

    std::cout << "Resize: " << std::endl;
    vector.resize(20);
    std::cout << vector.size() << std::endl;
    std::cout << vector.capacity() << std::endl;

    std::cout << "Resize: " << std::endl;
    vector.resize(2);
    std::cout << vector.size() << std::endl;
    std::cout << vector.capacity() << std::endl;  

    vector.push_back(13);
        std::cout << vector.size() << std::endl;
    std::cout << vector.pop_back() << std::endl;
        std::cout << vector.size() << std::endl;
    return 0;
}