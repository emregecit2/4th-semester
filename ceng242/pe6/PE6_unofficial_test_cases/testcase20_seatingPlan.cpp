#include "Course.h"
#include "Student.h"
#include "Metu.h"

int main()
{
    Metu* metu = new Metu();

    for (int i = 1; i <= 100; i++) {
        Student* student = new Student(i, "Stu Dent", "CENG");
        metu->registerStudent(student);
    }

    metu->setClassroomSize(7, 7);
    metu->addCheatInfo(18, 35, "-");
    metu->addCheatInfo(18, 13, "|");
    metu->addCheatInfo(7, 19, "|");
    metu->addCheatInfo(23, 26, "-");
    metu->addCheatInfo(51, 36, "-");
    metu->addCheatInfo(36, 47, "-");
    metu->addCheatInfo(47, 30, "|");
    metu->addCheatInfo(30, 11, "-");
    metu->addCheatInfo(82, 80, "-");
    metu->addCheatInfo(65, 80, "|");
    metu->addCheatInfo(1, 65, "-");
    metu->addCheatInfo(12, 13, "-");
    metu->addCheatInfo(35, 10, "|");
    metu->addCheatInfo(10, 45, "-");
    metu->addCheatInfo(19, 20, "-");
    metu->addCheatInfo(65, 58, "-");
    metu->addCheatInfo(58, 51, "-");
    metu->addCheatInfo(32, 49, "-");
    metu->addCheatInfo(24, 32, "|");
    metu->addCheatInfo(23, 24, "|");
    metu->addCheatInfo(12, 26, "|");
    metu->addCheatInfo(30, 29, "|");
    metu->addCheatInfo(45, 7, "|");
    metu->addCheatInfo(7, 3, "-");
    metu->addCheatInfo(4, 6, "|");
    metu->addCheatInfo(2, 6, "-");
    metu->addCheatInfo(49, 2, "-");
    metu->addCheatInfo(51, 39, "|");
    metu->addCheatInfo(39, 35, "|");
    
    metu->printSeatingPlan();

    delete metu;

    return 0;

}

enum Grade learnGrade(string course_name, int student_id) {

    return NA;
}
