#pragma once
#include <unordered_map>




class c_globals {
public:
	bool active = true;
	bool copied{ false };
	char user_name[255] = "user";
	char pass_word[255] = "pass";

	int dimensioneArray;

	int contaElementi = 0;
	const int maxElementiTime = 100;


	int* insertionTime = new int[maxElementiTime];
	int* selectionTime = new int[maxElementiTime];
	int* bubbleTime = new int[maxElementiTime];
	int* mergeTime = new int[maxElementiTime];
};

inline c_globals globals;