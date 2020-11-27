#pragma once
#include <iostream>
using namespace std;

bool PeselValidator(char* Tpesel,int * PESEL);

const char *sex(int *PESEL);

int getCtrlNumber(int *PESEL);

int getDay(int *PESEL);

int getMonth(int *PESEL);

int getYear(int *PESEL);

void printPesel(int *PESEL);
