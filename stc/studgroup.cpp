#include <studgroup.h>

StudGroup::StudGroup() : 
    groupName(""), facultyName(""), studentsCount(0), normalStudentsCount(0) 
    { 

    }

StudGroup::StudGroup(std::string group, std::string facult; int stud, int normalStud)
{
    groupName = group;
    facultyName = facult;
    studentsCount = stud;
    normalStudentsCount = normalStud;
}

std::string StudGroup::getGroupName()
{
    return this->groupName;
}

std::string StudGroup::getFacultyName()
{
    return this->facultyName;
}

int StudGroup::getNormalStudentsCount()
{
    return this->normalStudentsCount;
}

int StudGroup::getStudentsCount()
{
    return this->studentsCount;
}

void StudGroup::printInfo()
{
    std::cout << "\t" << "Group Name: " << groupName << std::endl;
    std::cout << "\t" << "Faculty Name: " << facultyName << std::endl;
    std::cout << "\t" << "Students count: " << studentsCount << std::endl;
    std::cout << "\t" << "Normal students count: " << normalStudentsCount << std::endl;
}

void StudGroup::setFacultyName(std::string name)
{
    facultyName = name;
}

void StudGroup::setGroupName(std::string name)
{
    groupName = name;
}

void StudGroup::setStudentsCount(int count)
{
    if (count < 0)
    {
        std::cout << "Bad count (<0)!!" << std::endl; // throw exception later
        return;
    }
    studentsCount = count;
}


StudGroup::~StudGroup()
{

}