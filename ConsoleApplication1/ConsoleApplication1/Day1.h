#pragma once

#include "stdafx.h"

bool isUnique(char str[]){
	int itr = 0;
	int itr2;
	while (str[itr] != NULL){
		std::cout << "str[itr] = " << str[itr] << std::endl;
		itr2 = itr + 1;
		while (str[itr2] != NULL){
			std::cout << "     str[itr2] = " << str[itr2] << std::endl;
			if (str[itr] == str[itr2])
				return false;
			itr2++;
		}
		itr++;
	}
	return true;
}

void reverse(char* str){
	int length = 0;
	while (str[length] != NULL)
		length++;
	int itr = 0; length--;
	while (itr < length){
		char temp = str[itr];
		str[itr] = str[length];
		str[length] = temp;
		itr++; length--;
	}
}

bool isPermutation(char* a, char* b){
	int aLength = 0; int bLength = 0;
	while (a[aLength] != NULL)
		aLength++;
	while (b[bLength] != NULL)
		bLength++;
	if (aLength != bLength)
		return false;
	std::vector<bool> marked(5, false);
	int itr = 0;
	while (a[itr] != NULL){
		int itr2 = 0;
		while (b[itr2] != NULL){
			if (a[itr] == b[itr2]){
				if (marked[itr2])
					itr2++;
				else{
					marked[itr2] = true;
					break;
				}
			}
			else
				itr2++;
		}
		if (b[itr2] == NULL)
			return false;
		itr++;
	}
	return true;
}