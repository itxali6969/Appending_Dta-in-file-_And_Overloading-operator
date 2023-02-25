#include <iostream>   //header file containing info (like function prototypes etc.) about cout and cin objects.
#include <stdlib.h>    //a general purpose standard library in C.
#include <cstring>    //header file containing info about string manipulation functions.
#include <fstream>  //header file containing info about functions relating creating, reading and writing files.
using namespace std;
                       
ofstream outfile; //Since outfile is global, it can be used in all functions in this program.

class String {
	private:
		char txt [20];     //an array of 20 characters.
	public:
	String () {                    //a default constructor.
		strcpy(txt,""); // In strcpy () is function, the data member txt is initialized to an empty string.
	}
	
	friend istream &operator >> (istream &input, String &s);                // insertion and extraction operators are overloaded.
	friend ostream &operator << (ostream &output, const String &s); //Since these are not member functions of this class, so declared as friend to this class.

//the + operator is overloaded to concatenate two strings.					          	
String operator + (const String &s1) {     
		outfile.open ("my.txt", ios :: app);  //a file Sample.txt is opened in append mode so that previous contents of the file shouldn't be overwritten.
		String temp;	                   //an object of class String is created.
		strcat (txt, s1.txt);            //Two strings are concatenated.
		strcpy (temp.txt, txt);     //string in txt is copied in txt belonging to object temp.
		outfile << temp.txt;      //string in txt is written in the file Sample.txt.
		outfile << "\n";           //a new line is inserted in the file.
		outfile.close ();        //file Sample.txt  is closed.
		return temp;            //the object temp is returned.
	}   
};
//extraction operator >> is overloaded in such a way that it takes istream object as a parameter, uses it to get a string from the user and then write this string in a file.
istream & operator >> (istream & in, String &s) { 
       outfile.open ("my.txt", ios :: app);  //a file Sample.txt is opened in append mode. 
       in. getline (s.txt,20);                              //getline() is one of the functions belonging to istream object input.
        outfile << s.txt;                                   //string in txt is written in the file Sample.txt.
        outfile << "\n";                                 //a new line is inserted in the file.
        outfile.close ();                              //file Sample.txt  is closed.
        return in;                                      //the object temp is returned.     
}    
 //insertion operator << is overloaded in such a way that it takes ostream object as a parameter and display it on the screen.
ostream & operator << (ostream &out, const String &s) {
    out << s.txt;    //string in txt is displayed on the screen.
    return out;     //the object out is returned.     
}
int main () {	
String s1, s2;	                          //two instances of class String are created using default constructor.	
cout << "Enter First Name:";  //here overloaded << operator is not called because passed parameter is a string not an object of class String.
cin >> s1;                               //overloaded >> operator is called: an istream object cin and an object s1 of class String is passed.
cout << "Enter Last Name:";
cin >> s2;                             //overloaded >> operator is called: an istream object cin and an object s2 of class String is passed.
String s3 = s1+s2; //overloaded + operator is called which concatenates the two strings belonging to objects s1 & s2 and return a concatenated string which is stored in object s3.
cout << "FullName is " << s3;  //here the first insertion operator << simply displays the string on the screen while the 2nd << operator is overloaded because an object s3 is passed.
}

