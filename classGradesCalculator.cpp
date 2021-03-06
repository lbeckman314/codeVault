//----------------------------------------------------------------------------------------------------------
// PURPOSE --------- This program outputs average scores and final grades for a given class grade set
// AUTHOR ---------- liam beckman
// DATE ------------ 01 december 2016 thursday
// SOURCES --------- http://stackoverflow.com/questions/19205024/how-to-return-a-struct-from-a-function-in-c
// ASSIGNMENT ------ cs161 lab 2 program 1 (due 01 december 2016 thursday)
// COMPILED WITH --- gcc (Ubuntu 5.4.1-2ubuntu1~16.04) 5.4.1 20160904 in Sublime Text 3 Build 3126
//-----------------------------------------------------------------------------------------------------------

#include <iostream>     //cin, cout
#include <fstream>      //ifstream, .open(), .close()
#include <iomanip>      //setw(), setprecision(), fixed
#include <cctype>       //tolower()
using namespace std;


struct Student          //our student structure!
    {
        string name;    //name of student
        int asgn[10];   //assignment scores (10 total)
        int quiz[10];   //quiz scores (10 total)
        int lab[10];    //lab scores (10 total)
        int midterm;    //midterm score
        int final;      //final score
    };

const int numberOfStudents = 20;    //number of students in the class

void loadData(Student students[20]);                //loads the class data from the input file to the students[] array
void printData(Student students[20]);               //outputs the class data from students[] array
double computeFinalGrade(Student stu);              //calculates the FINAL GRADE FOR A GIVEN STUDENT stu
double findQuiz10Average(Student students[20]);     //calculates the class's average score for the LAST QUIZ
Student lowestGradeStudent(Student students[20]);   //calculates who has the LOWEST GRADE
Student highestGradeStudent(Student students[20]);  //calculates who has the HIGHEST GRADE
void outputFinalGrades(Student students[20]);       //calculates the AVERAGE GRADE for the class
double averageGrade(Student students[20]);          //outputs the CLASS GRADES



//---------------------------------------------------------------------------------------//


int main()
{
    Student students[20];       //array of 20 Student structures
    loadData(students);         //load the data from the txt
    printData(students);        //output the data
    cout << "\n";
    cout << "final grade for " << students[0].name << ": " << computeFinalGrade(students[0]) << endl;   //final grade for first student
    cout << "avg grade for quiz 10: " << findQuiz10Average(students) << endl;                           //average grade for last quiz
    cout << "stdnt w/ lowest grade: " << lowestGradeStudent(students).name                          //student with lowest grade
         << " (grade: " << fixed << setprecision(2) << computeFinalGrade(lowestGradeStudent(students)) << ")" << endl;  //
    cout << "\n";

    outputFinalGrades(students);    //output class grades

    return 0;
}


//---------------------------------------------------------------------------------------//


void loadData(Student students[20]) //
{
    ifstream gradeFile;                             //initialize input file 
    string gradeFilePath;                           //initialize input file path
    cout << "enter path to grades file: ";          //prompt user for file path
    //gradeFilePath = "CS161Grades.txt";            //TEMPORARY
    //getchar();                                    //TEMPORARY
    cin >> gradeFilePath;                           //input file path

    gradeFile.open(gradeFilePath.c_str());          //open the input file

    int index = 0;                                  //index of students for loops below...
    while(index < numberOfStudents)                 //while there are still students to input...
    {
        gradeFile.ignore(256, '\n');                //ignore the first-line header of grade file
        gradeFile >> students[index].name;          //input the NAME of the student
        for (int i = 0; i < 10; i++)                 
             gradeFile >> students[index].asgn[i];  //input the assignment scores of the student
        for (int i = 0; i < 10; i++)      
             gradeFile >> students[index].quiz[i];  //input the quiz scores of the student
        for (int i = 0; i < 10; i++)      
             gradeFile >> students[index].lab[i];   //input the lab scores of the student   
        gradeFile >> students[index].midterm >> students[index].final;  //input the midterm and final scores of the student
        index++;                                    //increment student index
    }

    gradeFile.close();                              //close the input file
}


//---------------------------------------------------------------------------------------//


void printData(Student students[20])        //function to output the student data
{
    cout << "\n";
    cout << left << setw(8) << "Name" << setw(32) << "Assignments"  //output HEADER
         << setw(32) << "Quizzes" << setw(32) << "Labs" 
         << setw(5) << "Midt" << "Final" << endl;
    cout << "\n";
    
    for (int i = 0; i < numberOfStudents; i++)  //for every student....
    {
        cout << students[i].name << "\t";                           //output NAME
        
        for (int n = 0; n < 10; n++)            //for every assignment...
            cout << setw(2) << students[i].asgn[n] << " ";          //output ASSIGNMENTS
        
        cout << "\t";
        for (int n = 0; n < 10; n++)            //for every quiz...
            cout << setw(2) << students[i].quiz[n] << " ";          //output QUIZZES
        
        cout << "\t";
        for (int n = 0; n < 10; n++)            //for every lab...
            cout << setw(2)  << students[i].lab[n] << " ";          //output LABS
        
        cout << "\t" << students[i].midterm     //for the midterm and final...
             << "   " << students[i].final << endl;                 //output MIDTERM and FINAL
    }
}


//---------------------------------------------------------------------------------------//


double computeFinalGrade(Student stu)       //function to compute the final grade of a given student
{
    double finalGrade = 0;  //the final grade (out of 100) for student stu
    
    double attend = 1;      //full points for attendance
    double asgnSum = 0;     //gross score total for ASSIGNMENTS
    double quizSum = 0;     //gross score total for QUIZZES
    double labSum = 0;      //gross score total for LABS
    double midtermSum = stu.midterm;    //gross score total for MIDTERM
    double finalSum = stu.final;        //gross score total for FINAL
    
    
    for (int i = 0; i < 10; i++)    //for every assignment, quiz, and lab
    {
        //finalGrade += (stu.asgn[i]/100 * .30) + (stu.quiz[i]/100 * .20) + (stu.lab[i]/100 * .15);
        asgnSum += stu.asgn[i];     //add assignment i score to score total for ASSIGNMENTS 
        quizSum += stu.quiz[i];     //add quiz i score to score total for QUIZZES
        labSum += stu.lab[i];       //add lab i score to score total for LABS
    }

    asgnSum /= 1000;        //divide by max possible score total for ASSIGNMENTS
    quizSum /= 1000;        //divide by max possible score total for QUIZZES
    labSum /= 1000;         //divide by max possible score total for LABS
    midtermSum /= 100;      //divide by max possible score total for MIDTERMS
    finalSum /= 100;        //divide by max possible score total for FINALS
    
    /*FOR DIAGNOSTICS
    cout << "asgnGrade = " << asgnSum << endl;      //assignment grade
    cout << "quizGrade = " << quizSum << endl;      //quiz grade
    cout << "labGrade = " << labSum << endl;        //lab grade
    cout << "midteGrade = " << midtermSum << endl;  //midterm grade
    cout << "FINALGrade = " << finalSum << endl;    //final grade
    */

    finalGrade = (asgnSum * 30) + (quizSum* 20) + (labSum* 15)
               + (midtermSum* 15) + (finalSum* 15) + (attend * 5);      //calculate the final grade with WEIGHTED SCORES
    return finalGrade;      //return the final grade
}


//---------------------------------------------------------------------------------------//


double findQuiz10Average(Student students[20])  //function to find the average score for the last quiz
{
    double totalScore = 0;                      //
    for (int i = 0; i < numberOfStudents; i++)  //for every student...
        totalScore += students[i].quiz[9];      //add their score to the sum total score for quiz 10 
    double averageScore = totalScore / 20;      //calculate average score
    return averageScore;                        //
}


//---------------------------------------------------------------------------------------//


Student lowestGradeStudent(Student students[20])    //function to calculate who has the LOWEST grade
{
    Student lowestGrade = students[0];              //initially set the LOWEST grade student to the first student in the class
    for (int i = 0; i < numberOfStudents; i++)      //for every student in the class
    {
        if (computeFinalGrade(students[i]) < computeFinalGrade(lowestGrade))    //if student i's grade is less than the student with the LOWEST grade
            lowestGrade = students[i];              //student i is then set to be the student with the LOWEST grade
    }
    return lowestGrade;                             //return the student with the LOWEST grade
}


//---------------------------------------------------------------------------------------//


Student highestGradeStudent(Student students[20])   //function to calculate who has the HIGHEST grade
{
    Student highestGrade = students[0];             //initially set the HIGHEST grade student to the first student in the class
    for (int i = 0; i < numberOfStudents; i++)      //for every student in the class
    {
        if (computeFinalGrade(students[i]) > computeFinalGrade(highestGrade))   //if student i's grade is less than the student with the HIGHEST grade
            highestGrade = students[i];             //student i is then set to be the student with the HIGHEST grade
    }
    return highestGrade;                            //return the student with the HIGHEST grade
}


//---------------------------------------------------------------------------------------//


double averageGrade(Student students[20])           //function to calculate the average grade for the class
{
    double average = 0;                             //
    for (int i = 0; i < numberOfStudents; i++)      //for every student in the class
        average += computeFinalGrade(students[i]);  //add their grade to the total
    average /= numberOfStudents;                    //and divide by the number of students in the class
    return average;                                 //return average grade
}


//---------------------------------------------------------------------------------------//


void outputFinalGrades(Student students[20])        //function to output the class grades
{
    for (int i = 0; i < numberOfStudents; i++)      //for every student in the class
    {   
        if (students[i].name == lowestGradeStudent(students).name)              //if student i is the student with the LOWEST grade,
            cout << left << setw(10) << setfill('-') << students[i].name        //then output their name
                 << fixed << setprecision(2) << computeFinalGrade(students[i])  //and grade
                 << " <---- lowest grade" << endl;                              //followed by "<---- LOWEST grade"
        
        else if (students[i].name == highestGradeStudent(students).name)        //if student i is the student with the HIGHEST grade,
            cout << left << setw(10) << setfill('-') << students[i].name        //then output their name
                 << fixed << setprecision(2) << computeFinalGrade(students[i])  //and grade
                 << " <---- highest grade" << endl;                             //followed by "<---- HIGHEST grade"
        
        else
            cout << left << setw(10) << setfill('-') << students[i].name        //otherwise, just output their name
                 << fixed << setprecision(2) << computeFinalGrade(students[i])  //and grade
                 << endl;                               
    }
    
    cout << "\nAverage Grade for class of " << numberOfStudents                 //output the average grade for the class 
             << " students : " << averageGrade(students) << endl;               //
}

/*
-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
~ ~ ~ ~ ~ ~ ~ ~ Poem of the Day! ~ ~ ~ ~ ~ ~ ~ ~ ~
-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

Today's Poem:
"Homework" from "Arthur's Almost Live Not Real Music Festival". 

https://www.youtube.com/watch?v=r_fQzShBJEQl 
-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

Class, you really worked hard today. (You can say that again!)

Okay...
Class, you really worked hard today.

Now that the school day is through.
I've got something special for you. (I hope it's ice cream!)

Just a little homework, tonight!
Just a little homework, tonight!
Just a little homework, tonight!
Just a little homework, tonight!
(Yeah) 

Read 19 chapters of history.
List 63 adverbs alphabetically! (Neatness counts!)
Chart the journey that Balboa took
Do the first thousand problems in your new math book...

Just a little homework, tonight! (That's a lot of homework!)
Just a little homework, tonight!
Just a little homework, tonight!
Just a little homework, tonight!

Write about global warming for extra credit (Global what?!)
Check the spelling, don't forget to edit!

Tomorrow's going to be another day
that's when you get to hear me say...

Just a little homework, tonight! (That's a lot of homework!)
Just a little homework, tonight!
Just a little homework, tonight!
Just a little homework, tonight!

Buster, pay attention! (Why, i, i, i...)

There's a quiz tomorrow! (I think I'm going to die-i-i-i...)

Just a little homework tonight...
Just a little homework tonight...
Just a little homework tonight... 

-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
*/