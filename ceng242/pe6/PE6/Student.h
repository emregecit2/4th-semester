#ifndef __STUDENT_H__
#define __STUDENT_H__


#include "Course.h"

//////////////////////////////////////////////////////
//    DO NOT CHANGE *PUBLIC PARTS* IN THIS FILE!    //
//////////////////////////////////////////////////////

enum Grade learnGrade(string course_name, int student_id);

/****************************************************/
/****               *** STUDENT ***              ****/
class Student {
protected:
	unsigned int id;
	string fullname;
	string department;
	vector<CourseInstance *> courses;
	bool upgrade = false;
	unsigned int credits = 0;
	unsigned int points = 0;
	// You can add your own variables/methods here.

public:
	// Do NOT change the below part.
	Student(int id, string fullname, string department);
	~Student();
	Student(const Student&);
	int getId() const;
	float getGPA() const;
	vector<const CourseInstance*> listCourses() const;
	void gradeCourse(const OpenCourse& openCourse);
	void setUpgradeStatus();

};

/****************************************************/
/****              *** FRESHMAN ***              ****/
class Freshman : public Student {
protected:

public:

	// Do NOT change the below part.
	Freshman(int id, string fullname, string department);
	~Freshman();
	Freshman(const Freshman&);
	bool addCourse(const OpenCourse&);
	void printTranscript() const;	// Do not confuse. This will be implemented by the PE admin.

};

/****************************************************/
/****              *** SOPHOMORE ***             ****/
class Sophomore : public Freshman {
protected:
	bool internship1 = false;
	bool internship2 = false;

public:

	// Do NOT change the below part.
	Sophomore(int id, string fullname, string department);
	Sophomore(const Freshman&);
	~Sophomore();
	Sophomore(const Sophomore&);
	void doAnInternship(int);
	bool getInternshipStatus(int);
	void printTranscript() const;	// Do not confuse. This will be implemented by the PE admin.
};

/****************************************************/
/****                *** JUNIOR ***              ****/
class Junior : public Sophomore {

private:

	// You can add your own variables/methods here.

protected:
	
	// You can add your own variables/methods here.

public:

	// Do NOT change the below part.
	Junior(int, string, string);
	Junior(const Sophomore&);
	~Junior();
	Junior(const Junior&);
	void selectElectiveCourse();
	void printTranscript() const;	// Do not confuse. This will be implemented by the PE admin.
};

/****************************************************/
/****                *** SENIOR ***              ****/
class Senior : public Junior {

private:

	// You can add your own variables/methods here.

protected:
	
	// You can add your own variables/methods here.

public:

	// Do NOT change the below part.
	Senior(int, string, string);
	Senior(const Junior&);
	~Senior();
	Senior(const Senior&);
	bool graduate();
	void printTranscript() const;	// Do not confuse. This will be implemented by the PE admin.
};

#endif

