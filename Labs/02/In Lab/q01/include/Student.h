#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

#include "Course.h"

class Course;

class Student {
private:
    std::string name;
    std::vector<Course*> enrolledCourses;

public:
    Student(const std::string& name);
    void enrollCourse(Course* course);
    const std::string& getName() const;
    const std::vector<Course*>& getEnrolledCourses() const;
};

#endif