#include <iostream>
#include <cstring>
#pragma once

class StudGroup
{
    private:
        std::string groupName;
        std::string facultyName;
        int studentsCount;
        int normalStudentsCount;
    
    public:
        StudGroup();
        StudGroup(std::string group, std::string facult, int stud, int normalStud);
        ~StudGroup();
        friend std::ostream& operator<<(std::ostream& stream, StudGroup& stud);
        std::string getGroupName();
        std::string getFacultyName();
        int getStudentsCount();
        int getNormalStudentsCount();
        void setGroupName(std::string name);
        void setFacultyName(std::string name);
        void setStudentsCount(int count);
        void setNormalStudentsCount(int count);
};

// just for example
class StudGroupException
{
    public:
        char strWhatWrong[80];
        StudGroupException();
        StudGroupException(char* s);
};