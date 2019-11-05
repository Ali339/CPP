/* Ali Zaib */
  /* Exam Statistics */
  #include <iostream>
  #include <fstream>
  using namespace std;
  int main()
  {
  int id, correct, wrong, answered, grade, TQ, student, omitted,
  maxgrade, maxgradeid, maxcpid;
 
  double CP ,maxcp ;

  TQ = 50; //total questions
 
  student = 0;
  maxcp = 0;
  maxgrade = 0;

 // Declare and open input file
  ifstream infile
  ("C:\\Users\\ALI\\Desktop\\CISC 1110\\CHAPTER3\\myinput.txt");
 // Declare and open output file
 ofstream outfile
 ("C:\\Users\\ALI\\Desktop\\CISC 1110\\CHAPTER3\\Assignment3.txt");

 // Set decimal precision
 outfile.setf(ios::fixed,ios::floatfield);
 outfile.precision(3);
 // Left alignment of out file
 outfile << left ;
 outfile << " Ali Zaib " << endl;
 outfile << " Assignment #3" << endl << endl;

  // Table title
 outfile << " \t\t\t\t\t\t\t\t EXAMINATION STATISTICS " << endl << endl;
  // Table headers
 outfile << "Student ID" << "\tCorrect" << "\t\tWrong" << "\t\tAnswered" << "\tOmitted" << "\t\tCorrect \%" << 	 "\tGrade" << "\t\t C/W Ratio"
 	<< "\t\t10 or More Omitted " <<endl;

 // Read ID
 cout << "Please enter an ID (enter -1 to stop): ";
 infile >> id;
 // Check for fake ID
 while (id != -1)
 {
 // Read right answers
 cout << "Please enter correct : ";
 infile >> correct;
 // Read wrong answers
 cout << "Please enter wrong : ";
 infile >> wrong ;
 // Calculate total questions answered
 answered = wrong + correct;
 // Check if answered more than total questions (50)
 if (answered > 50)
 {
 outfile.width (16);
 outfile << id;
 outfile.width (16);
 outfile << correct;
 outfile.width (16);
 outfile << wrong ;
 outfile.width (16);
 outfile << "answered > 50";
 outfile.width (16);
 outfile << "Error";
 outfile.width (16);
 outfile << "Error";
 outfile.width (17);
 outfile << "Error";
 outfile.width (23);
 outfile << "answered > 50";
 outfile.width (19);
 outfile << "answered > 50" ;
 outfile << endl ;
 }
 else
 {
 /* Check if no question has been answered to avoid the
 executional error to calculate CP (Correctt/answered) */
 if ( answered == 0 )
 {
 outfile.width (16);
 outfile << id;
 outfile.width (16);
 outfile << correct;
 outfile.width (16);
 outfile << wrong ;
 outfile.width (16);
 outfile << answered;
 outfile.width (16);
 outfile << "50";
 outfile.width (16);
 outfile << "Error";
 outfile.width (17);
 outfile << "Error";
 outfile.width (23);
 outfile << "0 answered";
 outfile.width (19);
 outfile << "All omitted" ;
outfile << endl ;
 }
 else
 {
 // Type casting for real division.
 CP = (double) correct / answered;

 // To calculate numeical grade
 grade = 2 * correct;
 // To calculate questions omitted
 omitted = TQ - answered;
 {
 outfile.width (16);
 outfile << id;
 outfile.width (16);
 outfile << correct;
 outfile.width (16);
 outfile << wrong ;
 outfile.width (16);
 outfile << answered;
 outfile.width (16);
 outfile << omitted;
 outfile.width (16);
 outfile << CP;
 outfile.width (17);
 outfile << grade;
 }

 //To check if right answers are more than wrong
 if ( correct > wrong )
 {
 outfile.width (23);
 outfile << "Correct > Wrong";
 }

 //To check if right answers are less than wrong
 if ( correct < wrong )
 {
 outfile.width (23);
 outfile << "Correct < Wrong";
 }

 //To check if right and wrong are same
 if (correct == wrong )
 {
 outfile.width (23);
 outfile << "Correct = Wrong";
 }

 /*To check if 10 or more than 10 questions
 have been omitted*/
 if ( omitted >= 10)
 {
 outfile.width (19);
 outfile << "Yes" ;
 outfile << endl ;
 }
 else
 {
 outfile.width (19);
 outfile << "No";
 outfile << endl ;
 }
 // To track the student with best numeric grade
 if ( (100 - grade ) < ( 100 - maxgrade))
 {
 maxgrade = grade;
 maxgradeid = id;
 }

 /*To track the student with best correct
 percentage*/
 if ( (1 -CP ) < ( 1 - maxcp))
 {
 maxcp = CP;
 maxcpid = id;
 }
 }
 }
 // Student counter
 student++;
 // To read a new ID
 cout << "Please enter an ID (enter -1 to stop): ";
 infile >> id;
 }

 outfile <<"\nWe have processed " << student << " students" << endl;
 outfile << "Maximum Correct Percentage is " << maxcp
 << " of student with id " << maxcpid << endl;
 outfile << "Maximum Numeric Grade is " << maxgrade
 << " of student with id " << maxgradeid << endl;

 // Closing input file
 infile.close();
 // Closing output file
 outfile.close();
 return 0;
 }