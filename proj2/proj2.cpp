  // Assignment # 2.
  // Ali Zaib.
  #include <iostream>
  #include <cmath>
  #include <fstream>
  using namespace std;
 
  int main()
  {

 double x , y , yclosest , xclosest , pos , neg , zero ;
 yclosest = 0 ;
 pos = 0 ;
 neg = 0 ;
 zero = 0 ;
 ofstream cout ;
 cout.open
 ("C:\\Users\\ALI\\Desktop\\CISC 1110\\CHAPTER 2\\Assignment2cout.txt") ;
 cout << "Ali Zaib" << endl ;
 cout << "Assignment # 2 " << endl << endl;
 cout << "\t\tThis is the out put of my first program" << endl << endl ;
 cout << "\tX\t\tY\t\t\tMessage" << endl ;

 for( x = -3 ; x <= 4 ; x = x + 0.50 )

 {
 y = (9 * x * x * x - 27 * x * x - 4 * x + 12) /
 (sqrt(3 * x * x + 1) + abs(5 - x * x * x * x )) ;
 cout << "\t" << x << "\t\t" << y ;
 if ( y < 0 )
 { cout << " \t\tY is negative" ;
 neg = neg + 1 ; }
 if (y == 0 )
 { cout << " \t\t\tY is Zero" ;
 zero = zero + 1 ; }
 if (y > 0 )
 { cout << " \t\tY is positive" ;
 pos = pos + 1 ; }
 if (( 10 - y ) < ( 10 - yclosest ))
 { yclosest = y ;
 xclosest = x ; }


 cout << endl ;

 }
 cout <<endl << endl ;
 cout << " \t\t The program is halting." << endl <<endl ;
 cout << "The closest value of y to 10 is " << yclosest
 << " given when x is at " << xclosest << "." << endl << endl ;
 cout << " \t\t(Counting of results yielded by formula) " << endl <<endl ;
 cout << " Positive Results" << " \tNegative Results"
 << "\tZero Results" << endl<< endl ;
 cout << pos << "\t\t\t\t" << neg << "\t\t\t" << zero << endl ;

 cout.close();
 return 0;
 }