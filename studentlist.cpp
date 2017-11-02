//Alanna Croysdale
//This program allows the user to create a list of students with their gpa names and IDs.
//Students can be added and deleted. The list of students can be printed
//The program ends with a quit command

#include <iostream>
#include <vector>
#include <string.h>
#include <iomanip>

using namespace std;

struct Student {
  string firstname;
  string lastname;
  int id;
  float gpa;
};

vector<Student*> student_list;


Student* Add(); //adds a student
void Print(vector<Student*> student_list); //prints all students
vector<Student*> Delete(vector<Student*> student_list, int chosenID); //deletes a student

int chosenID = 0;

int main()
{
  string input;  

  cout << "Student List\n\nType 'ADD' to add a new student, 'PRINT' to display all stored students, and 'DELETE' to remove a student. Type 'QUIT' to exit the program" << endl;

  do {
    cin >> input;
    if (input == "ADD"){
      //Add creates a new student struct pointer and adds it to the vector of students
      student_list.push_back(Add());
    }
    
    else if (input == "PRINT") {
      Print(student_list);
    }
    else if (input == "DELETE") {

      cout << "What is the id of the student you'd like to remove? ";
      cin >> chosenID;
      
      //Delete removes the inputted student struct from the vector and deletes the pointer
      student_list=Delete(student_list, chosenID);
    }

  } while(input != "QUIT"); //while the user has not entered 'QUIT'
  
  return 0;
}

 
//Makes a new student struct pointer
Student* Add(){
   
  Student* NewPtr = new Student;
  vector<Student *>::iterator n, end;
  cout << "What is the student's first name? ";
  cin >> NewPtr->firstname;
  cout << "What is the student's last name? ";
  cin >> NewPtr->lastname;
  cout << "What is the student id? ";
  cin >> NewPtr->id;
  //If there is already a student with that id, prompt user to enter a different id
  for (n=student_list.begin(), end = student_list.end(); n != end; ++n){
    while ( (*n)->id == NewPtr->id){
      cout << "There is already a student with that id.\n Please enter a different id. ";
      cin >> NewPtr->id;
    }
  }
  cout << "What is the student's gpa? ";
  cin >> NewPtr->gpa;
  return NewPtr;
}

//Prints all the values in all the Student* structs in student_list
void Print(vector<Student*> student_list){
  vector<Student *>::iterator n, end;

  //Prints the number of structs in the vector and therefore the number of students
  cout << "# of students: " << student_list.size() << endl;

  //For each struct in the vector, prints the first and last name,
  //the id and the gpa.
  for (n=student_list.begin(), end = student_list.end(); n != end; ++n){
    cout << "Name: " << (*n)->firstname << " " << (*n)->lastname
	 << " ID: " << (*n)->id
	 << " GPA: " << fixed << setprecision(2) << (*n)->gpa << endl;
  }
}


//Looks through all the structs in the vector
//Deletes struct which has the selected student id
vector<Student*> Delete(vector<Student*> student_list, int chosenID){

  bool valid = false;
  vector<Student *>::iterator n, end;
  for (n=student_list.begin(), end = student_list.end(); n != end; ++n) 
  {
    if ((*n)->id == chosenID)
	{
	  valid = true;
      delete *n; // Deletes what n is pointing to
      student_list.erase(n);
	  break;
	}
  }
  //If there a no structs in the vector with the chosen id
  if (valid == false)
    {
      cout << "The Id does not exists" << endl;
    }

  return student_list;
}
