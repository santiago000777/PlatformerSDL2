#pragma once

#include<iostream>
#include <cmath>
#include <string>       
#include <windows.h>
#include <winuser.h>
#include <conio.h>  
#include <stdlib.h>
#include <dos.h>
#include <stdio.h>
#include <fcntl.h>
#include <locale.h>
#include <thread>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <random>
#include <ctime>
#include <map>

#define DEBUG()	if(GetAsyncKeyState(VK_ESCAPE)) {__debugbreak();}
#define PI		3.14159265359


bool PressedKey(short key) {
	short i = GetAsyncKeyState(toupper(key));
	if ((i & 0x8000) == 0) {
		return false;
	}
	return true;
}