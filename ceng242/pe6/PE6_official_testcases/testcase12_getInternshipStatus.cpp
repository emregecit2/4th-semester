#include "Course.h"
#include "Student.h"
#include "Metu.h"

/********** GLOBALS *********/
Metu* metu;

vector<Freshman*> freshmans;
vector<Sophomore*> sophomores;
vector<Junior*> juniors;
vector<Senior*> seniors;
/********** ******* *********/

void defineStudents();

int main()
{
	metu = new Metu();
	defineStudents();

	for (int i=0; i<10; i++) {
		sophomores[i]->doAnInternship(1);
        juniors[i]->doAnInternship(2);
        seniors[i]->doAnInternship(1);
        seniors[i]->doAnInternship(2);
    }
    for (int i=0; i<10; i++) {
        cout << "Internship status of the student with id " << sophomores[i]->getId() << " is: " << 
        (sophomores[i]->getInternshipStatus(1) ? "PASS" : "FAIL") << " and " << 
        (sophomores[i]->getInternshipStatus(2) ? "PASS" : "FAIL") << ".\n";
    }
    for (int i=0; i<10; i++) {
        cout << "Internship status of the student with id " << juniors[i]->getId() << " is: " << 
        (juniors[i]->getInternshipStatus(1) ? "PASS" : "FAIL") << " and " << 
        (juniors[i]->getInternshipStatus(2) ? "PASS" : "FAIL") << ".\n";
    }
    for (int i=0; i<10; i++) {
        cout << "Internship status of the student with id " << seniors[i]->getId() << " is: " << 
        (seniors[i]->getInternshipStatus(1) ? "PASS" : "FAIL") << " and " << 
        (seniors[i]->getInternshipStatus(2) ? "PASS" : "FAIL") << ".\n";
    }
    
    delete metu;

    return 0;
}

void defineStudents() {

    for (int i=2765431, j=0; j<10; i++, j++) {
        Sophomore* sophomore = new Sophomore(i, "Sophomore Human", "CENG");
        metu->registerStudent(sophomore);
        sophomores.push_back(sophomore);
    }

    for (int i=3765421, j=0; j<10; i++, j++) {
        Junior* junior = new Junior(i, "Junior Human", "CENG");
        metu->registerStudent(junior);
        juniors.push_back(junior);
    }

    for (int i=4765321, j=0; j<10; i++, j++) {
        Senior* senior = new Senior(i, "Senior Human", "CENG");
        metu->registerStudent(senior);
        seniors.push_back(senior);
    }

}

enum Grade learnGrade(string course_name, int student_id) {

    Grade grades[9] = {AA, BA, BB, CB, CC, DC, DD, FF, NA};

    if (course_name == "INTERNSHIP-1") {
        for (int i=2765431, j=0; j<10; i++, j++) {
            if (student_id == i)
                return grades[j%9];
        for (int i=3765421, j=0; j<10; i++, j++)
            if (student_id == i)
                return grades[(j+3)%9];
        for (int i=4765321, j=0; j<10; i++, j++)
            if (student_id == i)
                return grades[(j+7)%9];
        }
    }
    else if (course_name == "INTERNSHIP-2") {
        for (int i=2765431, j=0; j<10; i++, j++)
            if (student_id == i)
                return grades[8-j%9];
        for (int i=3765421, j=0; j<10; i++, j++)
            if (student_id == i)
                return grades[(j+2)%9];
        for (int i=4765321, j=0; j<10; i++, j++)
            if (student_id == i) 
                return grades[(4+j)%9];
    }
    else
        return NA;
}