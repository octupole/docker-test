//============================================================================
// Name        : test-input.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include "TrjRead.h"

using namespace std;
int main(int argc, char ** argv)
{
	trj::TrjRead MyIn(argc,argv);
	MyIn.Input();

  return EXIT_SUCCESS;
}
