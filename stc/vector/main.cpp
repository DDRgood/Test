#include "myvector.h"

int main()
{
    MyVector<int> vector(2);
    vector.push_back(5);
    std::cout << vector.getCapacity() << std::endl;
    std::cout << vector.getSize() << std::endl;
    vector.push_back(2);
    vector.push_back(11);
    vector.push_back(12);
    std::cout << vector.getCapacity() << std::endl;
    std::cout << vector.getSize() << std::endl;   
    return 0;
}