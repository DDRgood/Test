#include <iostream>
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
        StudGroup(std::string group, std::string facult; int stud, int normalStud);
        ~StudGroup();
        std::string getGroupName();
        std::string getFacultyName();
        int getStudentsCount();
        int getNormalStudentsCount();
        void printInfo();
        void setGroupName(std::string name);
        void setFacultyName(std::string name);
        void setStudentsCount(int count);
        void setNormalStudentsCoutn(int count);
}