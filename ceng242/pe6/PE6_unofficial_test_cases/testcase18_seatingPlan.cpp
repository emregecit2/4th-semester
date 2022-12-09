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

    metu->setClassroomSize(6, 3);
    metu->addCheatInfo(65, 58, "-");
    metu->addCheatInfo(65, 80, "|");
    metu->addCheatInfo(12, 13, "-");
    metu->addCheatInfo(23, 26, "-");
    metu->addCheatInfo(18, 13, "|");
    metu->addCheatInfo(12, 26, "|");
    metu->addCheatInfo(80, 1, "|");
    metu->addCheatInfo(1, 18, "-");
    metu->addCheatInfo(23, 24, "|");
    metu->printSeatingPlan();

    delete metu;

    return 0;

}

enum Grade learnGrade(string course_name, int student_id) {

    return NA;
}
