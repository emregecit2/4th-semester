#ifndef __METU_H__
#define __METU_H__


#include "Course.h"
#include "Student.h"

#define GRAPH_SIZE 10000000

//////////////////////////////////////////////////////
//    DO NOT CHANGE *PUBLIC PARTS* IN THIS FILE!    //
//////////////////////////////////////////////////////

/****************************************************/
/****                *** METU ***                ****/

class Metu {

private:
	vector<Student*> students;
	vector<const Course*> courses_;
	vector<const OpenCourse*> opencourses;
	int row_size;
	int column_size;
	int *graph[GRAPH_SIZE] = {} ;
	int *coordinates[GRAPH_SIZE] = {};
	void dfs(int);

public:

	// Do NOT change the below part.
	Metu();
	~Metu();

	Student& getStudent(int);
	void registerStudent(Student*);
	void registerCourse(const Course&);
	OpenCourse& openCourse(const Course&, string, int, vector<Freshman*>, vector<Sophomore*>, vector<Junior*>, vector<Senior*>);

	Sophomore* upgradeStudent(Freshman&);
	Junior* upgradeStudent(Sophomore&);
	Senior* upgradeStudent(Junior&);

	void setClassroomSize(int, int);
	void addCheatInfo(int, int, string);
	void printSeatingPlan();

};

#endif