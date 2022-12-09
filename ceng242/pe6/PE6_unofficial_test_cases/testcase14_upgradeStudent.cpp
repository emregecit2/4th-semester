#include "Course.h"
#include "Student.h"
#include "Metu.h"

/********** GLOBALS *********/
Metu* metu;

vector<Freshman*> freshmans;
vector<Sophomore*> sophomores;
vector<Junior*> juniors;
vector<Senior*> seniors;

vector<Course*> courses;
/********** ******* *********/

void defineCourses();

int main()
{
  metu = new Metu();
  defineCourses();

  Sophomore* sophomore = new Sophomore(1234567, "Sophomore Human", "CENG");
  metu->registerStudent(sophomore);
  sophomores.push_back(sophomore);

  for (int i=0; i<15; i++) {
    OpenCourse& opencourse = metu->openCourse(*courses[i], "2021-2", 100, freshmans, sophomores, juniors, seniors);
    opencourse.finalize();
  }

	Junior* junior = metu->upgradeStudent(*sophomore);
  junior->printTranscript();

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

void defineCourses() {

  Course* ceng111 = new Course("Introduction To Computer Engineering Concepts");
    metu->registerCourse(*ceng111);
    courses.push_back(ceng111);

    Course* ceng140 = new Course("C Programming");
    metu->registerCourse(*ceng140);
    courses.push_back(ceng140);

  Course* math119 = new Course("Calculus with Analytic Geometry");
    metu->registerCourse(*math119);
    courses.push_back(math119);  

    Course* math120 = new Course("Calculus of Functions of Several Variables");
    math120->addPrerequisite(*math119);
    metu->registerCourse(*math120);
    courses.push_back(math120); 

    Course* math219 = new Course("Introduction To Differential Equations");
    math219->addPrerequisite(*math120);
    metu->registerCourse(*math219);
    courses.push_back(math219);   

    Course* math260 = new Course("Basic Linear Algebra");
    metu->registerCourse(*math260);
    courses.push_back(math260); 

    Course* ceng213 = new Course("Data Structures");
    ceng213->addPrerequisite(*ceng140);
    metu->registerCourse(*ceng213);
    courses.push_back(ceng213);

    Course* ceng223 = new Course("Discrete Computational Structures");
    metu->registerCourse(*ceng223);
    courses.push_back(ceng223);

    Course* ceng232 = new Course("Logic Design");
    ceng232->addPrerequisite(*ceng111);
    metu->registerCourse(*ceng232);
    courses.push_back(ceng232);

    Course* ceng242 = new Course("Programming Language Concepts");
    ceng242->addPrerequisite(*ceng111);
    ceng242->addPrerequisite(*ceng213);
    metu->registerCourse(*ceng242);
    courses.push_back(ceng242);

    Course* ceng280 = new Course("Formal Languages and Abstract Machines");
    ceng280->addPrerequisite(*ceng223);
    metu->registerCourse(*ceng280);
    courses.push_back(ceng280);

    Course* ceng315 = new Course("Algorithms");
    ceng315->addPrerequisite(*ceng213);
    metu->registerCourse(*ceng315);
    courses.push_back(ceng315);

    Course* ceng331 = new Course("Computer Organization");
    ceng331->addPrerequisite(*ceng232);
    metu->registerCourse(*ceng331);
    courses.push_back(ceng331);

    Course* ceng334 = new Course("Introduction To Operating Systems");
    ceng334->addPrerequisite(*ceng331);
    metu->registerCourse(*ceng334);
    courses.push_back(ceng334);

    Course* ceng336 = new Course("Introduction To Embedded Systems Development");
    ceng336->addPrerequisite(*ceng232);
    metu->registerCourse(*ceng336);
    courses.push_back(ceng336);

    Course* ceng350 = new Course("Software Engineering");
    ceng350->addPrerequisite(*ceng213);
    metu->registerCourse(*ceng350);
    courses.push_back(ceng350);

    Course* ceng351 = new Course("Data Management and File Structures");
    ceng351->addPrerequisite(*ceng213);
    metu->registerCourse(*ceng351);
    courses.push_back(ceng351);

    Course* ceng384 = new Course("Synals and Systems For Computer Engineers");
    ceng384->addPrerequisite(*math219);
    metu->registerCourse(*ceng384);
    courses.push_back(ceng384);

    Course* ceng435 = new Course("Data Communications and Networking");
    metu->registerCourse(*ceng435);
    courses.push_back(ceng435);

    Course* ceng477 = new Course("Introduction To Computer Graphics");
    metu->registerCourse(*ceng477);
    courses.push_back(ceng477);

    Course* ceng491 = new Course("Computer Engineering Design I");
    ceng491->addPrerequisite(*ceng350);
    metu->registerCourse(*ceng491);
    courses.push_back(ceng491);

    Course* ceng492 = new Course("Computer Engineering Design II");
    ceng492->addPrerequisite(*ceng491);
    metu->registerCourse(*ceng492);
    courses.push_back(ceng492);
}

enum Grade learnGrade(string course_name, int student_id) {

  Grade grades[9] = {AA, BA, BB, CB, CC, DC, DD, FF, NA};
  string courseNames[15] = {"Introduction To Computer Engineering Concepts",
                            "C Programming",
                            "Calculus with Analytic Geometry",
                            "Calculus of Functions of Several Variables",
                            "Introduction To Differential Equations",
                            "Data Structures",
                            "Discrete Computational Structures",
                            "Logic Design",
                            "Programming Language Concepts",
                            "Formal Languages and Abstract Machines",
                            "Algorithms",
                            "Computer Organization",
                            "Introduction To Operating Systems",
                            "Introduction To Embedded Systems Development",
                            "Software Engineering"};

  for (int c=0; c<15; c++)
    if (course_name == courseNames[c]) {
      if (student_id == 1234567)
        return grades[(c+2)%9];
      else
        return NA;
    }

}