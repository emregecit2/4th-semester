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

    metu->setClassroomSize(2, 3);
    metu->addCheatInfo(18, 35, "-");
    metu->addCheatInfo(10, 45, "-");
    metu->addCheatInfo(35, 10, "|");
    metu->printSeatingPlan();

    delete metu;

    return 0;

}

enum Grade learnGrade(string course_name, int student_id) {

    return NA;
}
