#include "Course.h"
#include "Student.h"
#include "Metu.h"

int main()
{
    Metu* metu = new Metu();

    Freshman* freshman = new Freshman(1234567, "Freshman Human", "CENG");
    metu->registerStudent(freshman);

	Sophomore* sophomore = metu->upgradeStudent(*freshman);
    sophomore->printTranscript();

    delete metu;

    return 0;
}

void Freshman::printTranscript() const {
   
   cout << "ID: " << this->getId() << endl;
   cout << "The student is at her/his 1st year." << endl; 
   cout << "COURSES:" << endl;
   for (int i=0; i < this->listCourses().size(); i++)
      cout << this->listCourses()[i]->getName() << " : \t" << this->listCourses()[i]->getGrade() << endl;

}

void Sophomore::printTranscript() const {
   
   cout << "ID: " << this->getId() << endl;
   cout << "The student is at her/his 2nd year." << endl; 
   cout << "COURSES:" << endl;
   for (int i=0; i < this->listCourses().size(); i++)
      cout << this->listCourses()[i]->getName() << " : \t" << this->listCourses()[i]->getGrade() << endl;

}

void Junior::printTranscript() const {
   
   cout << "ID: " << this->getId() << endl;
   cout << "The student is at her/his 3rd year." << endl; 
   cout << "COURSES:" << endl;
   for (int i=0; i < this->listCourses().size(); i++)
      cout << this->listCourses()[i]->getName() << " : \t" << this->listCourses()[i]->getGrade() << endl;

}

void Senior::printTranscript() const {
   
   cout << "ID: " << this->getId() << endl;
   cout << "The student is at her/his 4th year." << endl; 
   cout << "COURSES:" << endl;
   for (int i=0; i < this->listCourses().size(); i++)
      cout << this->listCourses()[i]->getName() << " : \t" << this->listCourses()[i]->getGrade() << endl;

}

enum Grade learnGrade(string course_name, int student_id) {

    return AA;
}