 // Bowling Scores
  //Ali Zaib
  #include <iostream>
  #include <fstream>
  using namespace std;
  int validgroup (int score1, int score2, int score3, ofstream & out);
  void onegamescore(int score,ofstream &out1);
  int average3scores(int score1, int score2, int score3);
 
 
  int main()
  {
  int score1, score2 , score3, groupcount , validcount, invalidcount,
  average;
  groupcount = 0 ;
 
  validcount = 0;
  invalidcount = 0;
  //Declare and open input file
  ifstream infile ("C:\\Users\\ALI\\Desktop\\CISC 1110\\CHAPTER4\\input.txt");
  //Declare and open output file
  ofstream outfile
  ("C:\\Users\\ALI\\Desktop\\CISC 1110\\CHAPTER4\\Assignment4.txt");
 
  outfile << "Ali Zaib" << endl;
  outfile << "BOWLING SCORES"<<endl<<endl;
  //To read first score
  cout << "Enter Score1 (enter -9999 to stop) ";
  infile >> score1;
 
  //Setting sentinel
  while (score1 != -9999)
 
  {
 
  //To read second score
  cout << "Enter Score2 ";
  infile >> score2;
  //To read third score
  cout << "Enter Score3 ";
  infile >> score3;
  //To print 3 scores by main
  outfile << "Score1 = " << score1 << endl ;
  outfile << "Score2 = " << score2 << endl ;
  outfile << "Score3 = " << score3 << endl ;
 
 
  /*To call validgroup function to validate scores (0-300) and process
  them further*/
  if (validgroup (score1, score2, score3, outfile) == 1)
  {
  //To count valid groups
  validcount++;
  //To call the function(onegamescore) to rate 3 scores
  onegamescore(score1, outfile);
  onegamescore(score2, outfile);
  onegamescore(score3, outfile);
  //To call the function (average3score) to calculate the average
  average = average3scores(score1, score2, score3);
  outfile << "AVERAGE SCORE = " <<average <<endl ;
  //To call the function(onegamescore) to rate average score
  onegamescore(average, outfile);
  }
  else
  invalidcount++; //Counter for invalid groups
  //3 blank lines after processing a group
  outfile <<endl<<endl<<endl ;
 
 
  //Counter for all groups processed (valid+invalid)
  groupcount++;
  //To read the score of new group
  cout << "Enter Score1 (enter -9999 to stop) ";
  infile >> score1;
 
  }
 
  outfile << "We have processed " << groupcount << " groups" << endl;
  outfile << "We have processed " << validcount << " valid groups" <<endl;
  outfile << "We have processed " << invalidcount << " invalid groups" <<endl;
 
  //closing output file
  outfile.close();
  //Closing input file
  infile.close();
 
  return 0;
 
  }
 
  /*
  *validgroup()
  * Input:
  * ofstream & out - a reference to the output file
  * score1
  * score2
  * score3
  * Process:
  * Validates the scores by checking if the scores are between 0 and 300
 * and moving on to the next score
 * Output:
 * prints the valid scores and returns value of valid for further processing
 */


 int validgroup (int score1, int score2, int score3, ofstream & out)
 {
 int valid = 1; //Local variable

 if(score1>=0 and score1<=300)

 out<< "Score1 is " << score1
 << " which is between 0 and 300 (valid score)"<<endl;


 if(score1<0 )
 {
 out<< "Score1 is " << score1
 << " which is less than 0 (invalid score)"<<endl;
 valid = 0;
 }


 if(score1>300 )
 {
 out<< "Score1 is " << score1
 << " which is more than 300 (invalid score)"<<endl;
 valid = 0;
 }


 if(score2>=0 and score2<=300)

 out<< "Score2 is " << score2
 << " which is between 0 and 300 (valid score)"<<endl;

 if(score2<0 )
 {
 out<< "Score2 is " << score2
 << " which is less than 0 (invalid score)"<<endl;
 valid = 0;
 }


 if(score2>300 )
 {
 out<< "Score2 is " << score2
 << " which is more than 300 (invalid score)"<<endl;
 valid = 0;
 }


 if(score3>=0 and score3<=300)

 out<< "Score3 is " << score3
 << " which is between 0 and 300 (valid score)"<<endl;

 if(score3<0 )
 {
 out<< "Score3 is " << score3
 << " which is less than 0 (invalid score)"<<endl;
 valid = 0;
 }


 if(score3>300 )
 {
 out<< "Score3 is " << score3
 << " which is more than 300 (invalid score)"<<endl;
 valid = 0;
 }


 if (valid==0)

 out << "GROUP IS INVALID"<<endl;

 else

 out << "GROUP IS VALID"<<endl;



 return (valid);
 }
 /*
 * onegamescore()
 * Input:
 * ofstream & out1 - a reference to the output file
 * score
  * Process:
 * rating the score by evaluating it with the given parameters
 * Output:
 * prints a rating for the given score
 */

 void onegamescore(int score,ofstream &out1)
 {
 if(score >= 250 and score <= 300)
 out1<< "Score: " << score << " Rating: Professional game." <<endl;

 if(score >= 200 and score <= 249)
 out1<< "Score: " << score << " Rating: Excellent game." <<endl;

 if(score >= 140 and score <= 199)
 out1<< "Score: " << score << " Rating: Very good game." <<endl;

if(score >= 100 and score <= 139)
 out1<< "Score: " << score << " Rating: Good game." <<endl;
 if(score >= 50 and score <= 99)
 out1<< "Score: " << score << " Rating: Poor game." <<endl;

 if(score <50)
 out1<< "Score: " << score << " Rating: Horrible game." <<endl;
 }
 /*
 * avg3escore()
 * Input:
 * score1
 * score2
  * score3
 * Process:
 * calculate the average score (score1+score2+score3/3)
 * Output:
  * Return the average scores to main to print
 */

 int average3scores(int score1, int score2, int score3)
 {
 int average ;
 average = (score1 + score2 + score3)/3;
 return (average);
 }