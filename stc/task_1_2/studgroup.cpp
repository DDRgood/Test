#include "studgroup.h"

StudGroup::StudGroup() : 
    groupName(""), facultyName(""), studentsCount(0), normalStudentsCount(0) 
    { 

    }

StudGroup::StudGroup(std::string group, std::string facult, int stud, int normalStud)
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
        throw StudGroupException("Bad count (<0) !!");
        return;
    }
    studentsCount = count;
}

void StudGroup::setNormalStudentsCount(int count)
{
    if (count < 0)
    {
        throw StudGroupException("Bad count (<0) !!");
        return;
    }
    normalStudentsCount = count;    
}


std::ostream& operator<<(std::ostream& stream, StudGroup& stud)
{
    stream << stud.groupName << " " << stud.facultyName << " " << stud.studentsCount << " " 
           << stud.normalStudentsCount << "\n";
    return stream;
}


StudGroup::~StudGroup()
{

}



StudGroupException::StudGroupException()
{
    *strWhatWrong = 0;
}

StudGroupException::StudGroupException(char* s)
{
    std::strcpy(strWhatWrong, s);
}

/*
StudGroupException::StudGroupException(std::string s)
{
    std::strcpy(strWhatWrong, s.c_str());
}
*/