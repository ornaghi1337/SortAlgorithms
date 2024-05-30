#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <Windows.h>
#include "../globals.hh"
using namespace std;

void runSort(int*, int*, int*, int*, int);

void resetArray(int[], int);
void readFromFile(int[], int[], int[], int[], int*);
void swap(int* , int*);

void writeToFile(int , int , int , int , int);
void pushArr(int* , int , int );

void selectionSort(int [], int );
void insertionSort(int [], int );
void bubbleSort(int [], int );
void merge(int [], int , int , int , int );
void mergesortBU(int [], int , int , int );

void randFunz(int [], int );
