#include "studgroup.h"
#include <fstream>

int main(int argc, char* argv[])
{
    if (argc < 2){
        std::cout << "Simple example" << std::endl;
        StudGroup ex1;
        StudGroup ex2("8383ab", "FKTI", 25, 5);
        std::cout << "Obj 2: " << ex2;
        std::string nameGroup, nameFacult;
        int count, countNormal;
        std::cout << "Enter like: <group_name> <facult_name> <stud_count> <normal_stud_count>" << std::endl;
        std::cin >> nameGroup >> nameFacult >> count >> countNormal;
        try 
        {
            ex1.setGroupName(nameGroup);
            ex1.setFacultyName(nameFacult);
            ex1.setStudentsCount(count);
            ex1.setNormalStudentsCount(countNormal);
        }
        catch(StudGroupException e)
        {
            std::cout << e.strWhatWrong;
            return 1;
        }
        catch(...)
        {
            std::cout << "Something else error.";
            return 1;
        }
        return 0;
    }

    StudGroup groups[10];
    if (std::strcmp(argv[1], "r")==0 || std::strcmp(argv[1], "read")==0)
    {
        if (argc < 3) return 1;
        std::ifstream in(argv[2]);
        if(!in)
        {
            std::cout << "Cannot open file." << std::endl;
            return 1;
        }
        int index = 0;
        std::string nameGroup, nameFacult;
        int count, countNormal;
        while ((in >> nameGroup >> nameFacult >> count >> countNormal) && index < 10)
        {
            groups[index].setGroupName(nameGroup);
            groups[index].setFacultyName(nameFacult);
            groups[index].setStudentsCount(count);
            groups[index].setNormalStudentsCount(countNormal);
            index++;
        }
        in.close();    
    }


    if (argc > 4 && (std::strcmp(argv[3], "w") || std::strcmp(argv[3], "write")))
    {
        std::ofstream out(argv[4]);
        if(!out)
        {
            std::cout << "Cannot open file (out)." << std::endl;
            return 1;
        }
        for (int i = 0; i < 10 && !groups[i].getGroupName().empty(); i++)
        {
            out << groups[i];
        }
        out.close();
    } 
    else
    {
        std::cout << "Read from file: " << std::endl;
        for (int i = 0; i<10; i++)
            if (!groups[i].getGroupName().empty()) std::cout << groups[i];
    }

    return 0;
}