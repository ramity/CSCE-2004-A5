#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>//needed for setw

using namespace std;

int const COURSE_MAX = 10;

double gpa(int n, const char grades[], const int hours[])
{
  // ‘n’ is the number of courses in the array (the size)
  // ‘grades’ is an array of letter grades
  // ‘hours’ is an array of credit hours
  // The function returns the gpa calculated in the function.
  // The basic idea and logic of the body of this function
  // should be the similar to project 3.

  double tempGradePointsSum = 0;
  double tempCreditHoursSum = 0;
  double tempGradePointRep = -1;

  for(int courseNumber = 0; courseNumber < n; courseNumber++)
  {
    if(grades[courseNumber] == 'A')
    {
      tempGradePointRep = 4;
    }
    else if(grades[courseNumber] == 'B')
    {
      tempGradePointRep = 3;
    }
    else if(grades[courseNumber] == 'C')
    {
      tempGradePointRep = 2;
    }
    else if(grades[courseNumber] == 'D')
    {
      tempGradePointRep = 1;
    }
    else if(grades[courseNumber] == 'F')
    {
      tempGradePointRep = 0;
    }
    else
    {
      tempGradePointRep = -1;
    }

    if(tempGradePointRep >= 0)
    {
      tempGradePointsSum += (hours[courseNumber] * tempGradePointRep);
      tempCreditHoursSum += hours[courseNumber];
    }
  }

  //display/calculate gpa
  return (tempGradePointsSum / tempCreditHoursSum);
}

double semesterGpa(int n, const string times[], const char grades[], const int hours[], string semester)
{
  // ‘n’ is the number of courses in the array (the size)
  // ‘times’ is an array of semester and year a course was taken
  // ‘grades’ is an array of letter grades
  // ‘hours’ is an array of credit hours
  // The value of ‘semester’ contains the semester and
  // year for which we want to compute the gpa.
  double tempGradePointsSum = 0;
  double tempCreditHoursSum = 0;
  double tempGradePointRep = -1;

  for(int courseNumber = 0; courseNumber < n; courseNumber++)
  {
    if(times[courseNumber] == semester)
    {
      if(grades[courseNumber] == 'A')
      {
        tempGradePointRep = 4;
      }
      else if(grades[courseNumber] == 'B')
      {
        tempGradePointRep = 3;
      }
      else if(grades[courseNumber] == 'C')
      {
        tempGradePointRep = 2;
      }
      else if(grades[courseNumber] == 'D')
      {
        tempGradePointRep = 1;
      }
      else if(grades[courseNumber] == 'F')
      {
        tempGradePointRep = 0;
      }
      else
      {
        tempGradePointRep = -1;
      }

      if(tempGradePointRep >= 0)
      {
        tempGradePointsSum += (hours[courseNumber] * tempGradePointRep);
        tempCreditHoursSum += hours[courseNumber];
      }
    }
  }

  return (tempGradePointsSum / tempCreditHoursSum);
}

int DRule(int n, char grades[], int hours[])
{
  int calculation = 0;

  for(int z = 0;z < n;z++)
  {
    if(grades[z] == 1)
    {
      calculation += hours[z];
    }
  }

  return calculation;
}

void print(int n, string names[], string times[], string numbers[], char grades[], int hours[])
{
  // ‘names’ is an array of course names
  // ‘numbers’ is an array of course numbers
  // The meanings of all other parameters are similar to
  // those in the earlier functions.
  // The function lists all course information, one piece per
  // line in the order in which the user entered the course
  // information. E.g.: name, time, number, grade, hours.
  // Also, the first line should be the number of courses

  cout << "Displaying (" << n << " of " << n << ") courses." << endl;
  cout << endl;
  cout << "Course Name" << setw(20) << "Semester" << setw(20) << "Course Number" << setw(20) << "Grade" << setw(20) << "Hour" << endl;
  //lists all courses
  for(int z = 0;z<n;z++)
  {
    cout << names[z] << setw(20) << times[z] << setw(20) << numbers[z] << setw(20) << grades[z] << setw(20) << hours[z] << endl;
  }
}

void getCourse(string& name, string& time, string& number, char& grade, int& hours, int n)
{
  // Get a new course from the user, and put the values into
  // each of the function parameters.
  // Note that since we must pass the value read in this
  // function back to the caller, many parameters are passed
  // by reference, the & after the type.
  // ‘name’ for the course name.
  // ‘time’ for when the course was taken.
  // ‘number’ for course number.
  // ‘grade’ for the letter grade of the course.
  // ‘hours’ for credit hours of the course.
  // ‘n’ for the next course count.
  bool validSelection = false;

  while(!validSelection)
  {
    cout << "Enter the course name (e.g. Programming Foundations I) for class number " << n << endl;

    getline(cin,name);

    if(name == "")
    {
      cout << "Invalid input. Please try again." << endl;
    }
    else
    {
      validSelection = true;
    }
  }

  validSelection = false;

  while(!validSelection)
  {
    cout << "Enter the semester (e.g. Spring 2016) for class number " << n << endl;

    getline(cin,time);

    if(time == "")
    {
      cout << "Invalid input. Please try again." << endl;
    }
    else
    {
      validSelection = true;
    }
  }

  validSelection = false;

  while(!validSelection)
  {
    cout << "Enter the course number (e.g. CSCE 2004) for class number " << n << endl;

    getline(cin,number);

    if(number == "")
    {
      cout << "Invalid input. Please try again." << endl;
    }
    else
    {
      validSelection = true;
    }
  }

  validSelection = false;

  while(!validSelection)
  {
    cout << "Enter the grade (A,B,C,D,F,W,I) for class number " << n << endl;

    string tempString = "";

    getline(cin,tempString);


    if(tempString == "A" || tempString == "a")
    {
      grade = 'A';
      validSelection = true;
    }
    else if(tempString == "B" || tempString == "b")
    {
      grade = 'B';
      validSelection = true;
    }
    else if(tempString == "C" || tempString == "c")
    {
      grade = 'C';
      validSelection = true;
    }
    else if(tempString == "D" || tempString == "d")
    {
      grade = 'D';
      validSelection = true;
    }
    else if(tempString == "F" || tempString == "f")
    {
      grade = 'F';
      validSelection = true;
    }
    else if(tempString == "W" || tempString == "w")
    {
      grade = 'W';
      validSelection = true;
    }
    else if(tempString == "I" || tempString == "i")
    {
      grade = 'I';
      validSelection = true;
    }
    else
    {
      cout << "Invalid user input, please try again" << endl;
    }
  }

  validSelection = false;

  while(!validSelection)
  {
    cout << "Enter the course hours (1 ... 5) for class number " << n << endl;

    cin >> hours;

    if(hours >= 1 && hours <= 5)
    {
      validSelection = true;
    }
    else
    {
      cout << "Invalid user input, please try again." << endl;
    }
  }

  cin.ignore();
}

char menu()
{
  // This function does not have any parameters and returns a
  // a character, which is the user’s menu choice.
  // In this function, the menu is shown,
  // then the user’s choice is read and validated.
  // Finally, it returns the validated menu choice (e.g. ‘A’).
  bool validSelection = false;
  char menuSelector;
  string tempString;

  while(!validSelection)
  {
    cout << "Please enter the character next to the choice you wish to pick." << endl;
    cout << "Here are your options:" << endl;
    cout << "A(a) . Compute the GPA of all courses" << endl;
    cout << "B(b) . List all courses" << endl;
    cout << "C(c) . Compute the total credit hours of the courses with grade D" << endl;
    cout << "D(d) . Compute the GPA for a particular semester" << endl;
    cout << "E(e) . Add another course to the course list" << endl;
    cout << "Q(q) . Quit the program" << endl;
    cout << "Please choose one of the above" << endl;

    getline(cin,tempString);

    if(tempString == "A" || tempString == "a")
    {
      validSelection = true;
      menuSelector = 'A';
    }
    else if(tempString == "B" || tempString == "b")
    {
      validSelection = true;
      menuSelector = 'B';
    }
    else if(tempString == "C" || tempString == "c")
    {
      validSelection = true;
      menuSelector = 'C';
    }
    else if(tempString == "D" || tempString == "d")
    {
      validSelection = true;
      menuSelector = 'D';
    }
    else if(tempString == "E" || tempString == "e")
    {
      validSelection = true;
      menuSelector = 'E';
    }
    else if(tempString == "Q" || tempString == "q")
    {
      validSelection = true;
      menuSelector = 'Q';
    }
    else
      cout << "Invalid selection. Please try again.";
  }

  return menuSelector;
}

int main ()
{
  int courses = 0;
  string tempString = "";

  cout << "Welcome to PFI course management system v1" << endl;

  bool validSelection = false;

  while(!validSelection)
  {
    cout << "Enter the number of classes for the system [1," << COURSE_MAX << "]" << endl;

    cin >> courses;

    if(cin.fail())
    {
      courses = 0;

      cout << "The supplied input was not within specified bounds. Please try again." << endl;
    }
    else
    {
      if(courses >=1 && courses <= COURSE_MAX)
      {
        validSelection = true;
      }
      else
      {
        cout << "The supplied input was not within specified bounds. Please try again." << endl;
      }
    }

    cin.clear();
    cin.ignore();
  }

  //initalizes all array vars based on defined validated input above
  string courseNames[COURSE_MAX] = "";
  string semesters[COURSE_MAX] = "";
  string courseNumbers[COURSE_MAX] = "";
  //stores as numerical equiv of letter grade for easier calculation
  //typecasted as doubles to allow for easier calculation
  char courseGrades[COURSE_MAX] = {0};
  int courseHours[COURSE_MAX] = {0};

  for(int step = 0;step < courses;step++)
  {
    validSelection = false;

    while(!validSelection)
    {
      cout << "Enter the course name (e.g. Programming Foundations I) for your class number " << step + 1 << endl;

      getline(cin,courseNames[step]);

      if(courseNames[step] == "")
      {
        cout << "Invalid input. Please try again." << endl;
      }
      else
      {
        validSelection = true;
      }
    }

    validSelection = false;

    while(!validSelection)
    {
      cout << "Enter the semester (e.g. Spring 2016) for your class number " << step + 1 << endl;

      getline(cin,semesters[step]);

      if(semesters[step] == "")
      {
        cout << "Invalid input. Please try again." << endl;
      }
      else
      {
        validSelection = true;
      }
    }

    validSelection = false;

    while(!validSelection)
    {
      cout << "Enter the course number (e.g. CSCE 2004) for your class number" << step + 1 << endl;

      getline(cin,courseNumbers[step]);

      if(courseNumbers[step] == "")
      {
        cout << "Invalid input. Please try again." << endl;
      }
      else
      {
        validSelection = true;
      }
    }

    validSelection = false;

    while(!validSelection)
    {
      cout << "Enter the grade (A,B,C,D,F,W,I) for your class number" << step + 1 << endl;

      tempString = "";

      getline(cin,tempString);


      if(tempString == "A" || tempString == "a")
      {
        courseGrades[step] = 'A';
        validSelection = true;
      }
      else if(tempString == "B" || tempString == "b")
      {
        courseGrades[step] = 'B';
        validSelection = true;
      }
      else if(tempString == "C" || tempString == "c")
      {
        courseGrades[step] = 'C';
        validSelection = true;
      }
      else if(tempString == "D" || tempString == "d")
      {
        courseGrades[step] = 'D';
        validSelection = true;
      }
      else if(tempString == "F" || tempString == "f")
      {
        courseGrades[step] = 'F';
        validSelection = true;
      }
      else if(tempString == "W" || tempString == "w")
      {
        courseGrades[step] = 'W';
        validSelection = true;
      }
      else if(tempString == "I" || tempString == "i")
      {
        courseGrades[step] = 'I';
        validSelection = true;
      }
      else
      {
        cout << "Invalid user input, please try again" << endl;
      }
    }

    validSelection = false;

    while(!validSelection)
    {
      cout << "Enter the course hours (1 ... 5) for your class number" << (step + 1) << endl;

      cin >> courseHours[step];

      if(courseHours[step] >= 1 && courseHours[step] <= 5)
      {
        validSelection = true;
      }
      else
      {
        cout << "Invalid user input, please try again." << endl;
      }
    }

    cin.ignore();
  }

  string menuSelector;

  cout << "Welcome to the interactive menu-driven part of the GPA and Course storage program." << endl;

  while(true)
  {
    menuSelector = menu();

    if(menuSelector == "A" || menuSelector == "a")
    {
      cout << "Congratulations, your GPA was " << gpa(courses, courseGrades, courseHours) << endl;
    }
    else if(menuSelector == "B" || menuSelector == "b")
    {
      print(courses, courseNames, semesters, courseNumbers, courseGrades, courseHours);
    }
    else if(menuSelector == "C" || menuSelector == "c")
    {
      cout << "Total hours with D grades are " << DRule(courses, courseGrades, courseHours) << endl;
    }
    else if(menuSelector == "D" || menuSelector == "d")
    {
      validSelection = false;

      double tempGPA = 0;
      string selectedSemester = "";
      int semesterIndex;

      while(!validSelection)
      {
        cout << "Please input desired semester for calculation" << endl;

        getline(cin,selectedSemester);

        double tempClasses = 0;

        for(int z = 0; z<courses;z++)
        {
          if(semesters[z] == selectedSemester)
          {
            tempClasses++;
          }
        }

        if(tempClasses == 0)
        {
          cout << "Desired semester: " << selectedSemester << " was not found. Please try again." << endl;
        }
        else
        {
          validSelection = true;
        }
      }

      cout << "Congratulations, your GPA was " << semesterGpa(courses, semesters, courseGrades, courseHours, selectedSemester) << " in " << selectedSemester << endl;
    }
    else if(menuSelector == "E" || menuSelector == "e")
    {
      if(courses + 1 < COURSE_MAX)
      {
        courses++;

        getCourse(courseNames[courses - 1], semesters[courses - 1], courseNumbers[courses - 1], courseGrades[courses - 1], courseHours[courses - 1], courses);
      }
      else
      {
        cout << "Unable to add more than 10 classes" << endl;
      }
    }
    else if(menuSelector == "Q" || menuSelector == "q")
    {
      //"escapes all logic"
      return 0;
    }
  }
}
