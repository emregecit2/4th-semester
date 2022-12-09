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

void defineStudents();
void defineCourses();

int main()
{
    metu = new Metu();
    defineStudents();
    defineCourses();

    for (int i=0; i<15; i++) {
      OpenCourse& opencourse = metu->openCourse(*courses[i], "2021-2", 45, freshmans, sophomores, juniors, seniors);
      opencourse.finalize();
    }

    Sophomore* sophomore = metu->upgradeStudent(*freshmans[7]);
    sophomore->printTranscript();
    cout << endl;

    Sophomore* junior = metu->upgradeStudent(*sophomore);
    junior->printTranscript();
    cout << endl;

  	Senior* senior = metu->upgradeStudent(*juniors[5]);
    senior->printTranscript();

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

void defineStudents() {

  for (int i=1765432, j=0; j<10; i++, j++) {
    Freshman* freshman = new Freshman(i, "Freshman Human", "CENG");
      metu->registerStudent(freshman);
      freshmans.push_back(freshman);
  }

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

void defineCourses() {

    Course* ceng111 = new Course("CENG111_Introduction To Computer Engineering Concepts");
    metu->registerCourse(*ceng111);
    courses.push_back(ceng111);

    Course* ceng140 = new Course("CENG140_C Programming");
    metu->registerCourse(*ceng140);
    courses.push_back(ceng140);

    Course* math119 = new Course("MATH119_Calculus with Analytic Geometry");
    metu->registerCourse(*math119);
    courses.push_back(math119);  

    Course* math120 = new Course("MATH120_Calculus of Functions of Several Variables");
    math120->addPrerequisite(*math119);
    metu->registerCourse(*math120);
    courses.push_back(math120); 

    Course* math219 = new Course("MATH219_Introduction To Differential Equations");
    math219->addPrerequisite(*math120);
    metu->registerCourse(*math219);
    courses.push_back(math219);   

    Course* math260 = new Course("MATH260_Basic Linear Algebra");
    metu->registerCourse(*math260);
    courses.push_back(math260); 

    Course* ceng213 = new Course("CENG213_Data Structures");
    ceng213->addPrerequisite(*ceng140);
    metu->registerCourse(*ceng213);
    courses.push_back(ceng213);

    Course* ceng223 = new Course("CENG223_Discrete Computational Structures");
    metu->registerCourse(*ceng223);
    courses.push_back(ceng223);

    Course* ceng232 = new Course("CENG232_Logic Design");
    ceng232->addPrerequisite(*ceng111);
    metu->registerCourse(*ceng232);
    courses.push_back(ceng232);

    Course* ceng242 = new Course("CENG242_Programming Language Concepts");
    ceng242->addPrerequisite(*ceng111);
    ceng242->addPrerequisite(*ceng213);
    metu->registerCourse(*ceng242);
    courses.push_back(ceng242);

    Course* ceng280 = new Course("CENG280_Formal Languages and Abstract Machines");
    ceng280->addPrerequisite(*ceng223);
    metu->registerCourse(*ceng280);
    courses.push_back(ceng280);

    Course* ceng315 = new Course("CENG315_Algorithms");
    ceng315->addPrerequisite(*ceng213);
    metu->registerCourse(*ceng315);
    courses.push_back(ceng315);

    Course* ceng331 = new Course("CENG331_Computer Organization");
    ceng331->addPrerequisite(*ceng232);
    metu->registerCourse(*ceng331);
    courses.push_back(ceng331);

    Course* ceng334 = new Course("CENG334_Introduction To Operating Systems");
    ceng334->addPrerequisite(*ceng331);
    metu->registerCourse(*ceng334);
    courses.push_back(ceng334);

    Course* ceng336 = new Course("CENG336_Introduction To Embedded Systems Development");
    ceng336->addPrerequisite(*ceng232);
    metu->registerCourse(*ceng336);
    courses.push_back(ceng336);

    Course* ceng350 = new Course("CENG350_Software Engineering");
    ceng350->addPrerequisite(*ceng213);
    metu->registerCourse(*ceng350);
    courses.push_back(ceng350);

    Course* ceng351 = new Course("CENG351_Data Management and File Structures");
    ceng351->addPrerequisite(*ceng213);
    metu->registerCourse(*ceng351);
    courses.push_back(ceng351);

    Course* ceng384 = new Course("CENG384_Synals and Systems For Computer Engineers");
    ceng384->addPrerequisite(*math219);
    metu->registerCourse(*ceng384);
    courses.push_back(ceng384);

    Course* ceng435 = new Course("CENG435_Data Communications and Networking");
    metu->registerCourse(*ceng435);
    courses.push_back(ceng435);

    Course* ceng477 = new Course("CENG477_Introduction To Computer Graphics");
    metu->registerCourse(*ceng477);
    courses.push_back(ceng477);

    Course* ceng491 = new Course("CENG491_Computer Engineering Design I");
    ceng491->addPrerequisite(*ceng350);
    metu->registerCourse(*ceng491);
    courses.push_back(ceng491);

    Course* ceng492 = new Course("CENG492_Computer Engineering Design II");
    ceng492->addPrerequisite(*ceng491);
    metu->registerCourse(*ceng492);
    courses.push_back(ceng492);
}

enum Grade learnGrade(string course_name, int student_id) {

  Grade grades[9] = {AA, BA, BB, CB, CC, DC, DD, FF, NA};
  string courseNames[15] = {"CENG111_Introduction To Computer Engineering Concepts",
                            "CENG140_C Programming",
                            "MATH119_Calculus with Analytic Geometry",
                            "MATH120_Calculus of Functions of Several Variables",
                            "MATH219_Introduction To Differential Equations",
                            "CENG213_Data Structures",
                            "CENG223_Discrete Computational Structures",
                            "CENG232_Logic Design",
                            "CENG242_Programming Language Concepts",
                            "CENG280_Formal Languages and Abstract Machines",
                            "CENG315_Algorithms",
                            "CENG331_Computer Organization",
                            "CENG334_Introduction To Operating Systems",
                            "CENG336_Introduction To Embedded Systems Development",
                            "CENG350_Software Engineering"};

    for (int c=0; c<15; c++) {
        if (course_name == courseNames[c]) {
            for (int i=1765432, j=0; j<10; i++, j++) {
                if (student_id == i)
                    return grades[(c+j)%9];
            }
            for (int i=2765431, j=0; j<10; i++, j++) {
                if (student_id == i)
                    return grades[(c+j*2)%9];
            }
            for (int i=3765421, j=0; j<10; i++, j++) {
                if (student_id == i)
                    return grades[(c+j*3)%9];
            }
            for (int i=4765321, j=0; j<10; i++, j++) {
                if (student_id == i)
                    return grades[(c+j*4)%9];
            }
        }
    }

    return NA;

}