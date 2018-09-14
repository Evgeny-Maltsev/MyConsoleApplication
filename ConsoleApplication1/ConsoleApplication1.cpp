// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <string>
#include <sstream>
#include <iostream>     // std::cout
#include <algorithm>    // std::remove used
#include <assert.h> 
#include <stdarg.h>
#include <fstream>
#include<thread>
#include<type_traits>
//#include<array>
#include<cstdlib>
#include<ctime>
#include<chrono>
#include <conio.h>
#include <stdio.h>


#include "PythonTest.h"

using namespace std;


int WaitKey()
{
	//putchar('\n');
	//cout << "\nPress any key...";
	//while ((getchar()) != '\n');
	//getchar();
	cout << endl;
	system("pause");
	return 0;
}
////////////////////////////////////////////////////

 

///////////////////////////////////////////////////
int main(int argc, char *argv[], char * envp[])
{	
	EmbeddedWay(argc, argv, envp);
	  

	return WaitKey();

}
