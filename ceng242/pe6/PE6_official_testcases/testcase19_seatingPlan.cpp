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

    metu->setClassroomSize(3, 6);
    metu->addCheatInfo(18, 90, "-");
    metu->addCheatInfo(18, 13, "|");
    metu->addCheatInfo(90, 36, "-");
    metu->addCheatInfo(36, 47, "-");
    metu->addCheatInfo(47, 30, "|");
    metu->addCheatInfo(30, 11, "-");
    metu->addCheatInfo(82, 80, "-");
    metu->addCheatInfo(65, 80, "|");
    metu->addCheatInfo(1, 65, "-");
    metu->addCheatInfo(12, 13, "-");
    metu->addCheatInfo(90, 1, "|");
    metu->printSeatingPlan();

    delete metu;

    return 0;

}

enum Grade learnGrade(string course_name, int student_id) {

    return NA;
}
