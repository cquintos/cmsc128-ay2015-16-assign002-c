//******************************************************************************************************
//
// Subject: CMSC 128 - Introduction so Software Engineering
// Name: JC Carlo D.G. Quintos
// Section: AB-6L
// Professor: Prof. Reginald Recario
// Date Started: 7-9-16
// Programming Assginment 002: Programming a Simple Bioinformatics Library
// 
//******************************************************************************************************

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// FUNCTION PROTOTYPES

int getHammingDistance(char str1[], char str2[]);
int countSubstrPattern(char original[], char pattern[]);
bool isValidString(char str[], char alphabet[]);
int getSkew(char str[], int n);
int getMaxSkewN(char str[], int n);
int getMinSkewN(char str[], int n);

// MAIN PROGRAM

int main(){
	printf("A. FUNCTION 1 TEST CASES:\n");
	printf("1.)\t%d = 2\n", getHammingDistance("AACCTT", "GGCCTT"));
	printf("2.)\t%d = 5\n", getHammingDistance("TCGGA", "AAAAG"));
	printf("3.)\t%d = Error! Strings are not equal!\n", getHammingDistance("A", "AG"));

	printf("B. FUNCTION 2 TEST CASES:\n");
	printf("1.)\t%d = 1\n", countSubstrPattern("AATATATAGG", "GG"));
	printf("2.)\t%d = 3\n", countSubstrPattern("AATATATAGG", "ATA"));
	// Commented Out because it returns "BUS ERROR 10" which I don't know how to fix.
	//printf("3.)\t%d = 0\n", countSubstrPattern("AATATATAGG", "ACTGACTGACTG"));

	printf("C. FUNCTION 3 TEST CASES:\n");
	if(isValidString("AAGGCTATGC","ACGT")) printf("1.) TRUE = TRUE\n");
	else printf("1.) FALSE = TRUE\n");

	if(isValidString("AAGGCTATGa","ACGT")) printf("2.) TRUE = FALSE\n");
	else printf("2.) FALSE = FLASE\n");

	if(isValidString("ACGT","ACGT")) printf("3.) TRUE = TRUE\n");
	else printf("3.) FALSE = TRUE\n");

	if(isValidString("ACGT101_","ACGT")) printf("4.) TRUE = FALSE\n");
	else printf("4.) FALSE = FALSE\n");

	if(isValidString("091212345","0123456789")) printf("5.) TRUE = TRUE\n");
	else printf("5.) FALSE = TRUE\n");

	printf("D. FUNCTION 4 TEST CASES:\n");
	printf("1.)\t%d = 1\n", getSkew("GGCCAC", 1));
	printf("2.)\t%d = 2\n", getSkew("GGCCAC", 2));
	printf("3.)\t%d = 1\n", getSkew("GGCCAC", 3));
	printf("4.)\t%d = 0\n", getSkew("GGCCAC", 4));
	printf("5.)\t%d = 0\n", getSkew("GGCCAC", 5));

	printf("E. FUNCTION 5 TEST CASES:\n");
	printf("1.)\t%d = 1\n", getMaxSkewN("GGCCAC", 1));
	printf("2.)\t%d = 2\n", getMaxSkewN("GGCCAC", 2));
	printf("3.)\t%d = 2\n", getMaxSkewN("GGCCAC", 3));
	printf("4.)\t%d = 2\n", getMaxSkewN("GGCCAC", 4));
	printf("5.)\t%d = 2\n", getMaxSkewN("GGCCAC", 5));

	printf("F. FUNCTION 6 TEST CASES:\n");
	printf("1.)\t%d = 1\n", getMinSkewN("GGCCAC", 1));
	printf("2.)\t%d = 1\n", getMinSkewN("GGCCAC", 2));
	printf("3.)\t%d = 1\n", getMinSkewN("GGCCAC", 3));
	printf("4.)\t%d = 0\n", getMinSkewN("GGCCAC", 4));
	printf("5.)\t%d = 0\n", getMinSkewN("GGCCAC", 5));
	
	return 0;
}

// F U N C T I O N S

/*******************************************************************************************************
*	Given two strings str1 and str2 of same length (length must never be 0 or negative!), 			   *
*	the Hamming Distance of those two strings are the number of inversions per character 			   *
*	need to transform str1 to str2 or vise-versa. Simply put, the Hamming Distance of two 			   *
*	strings is the number of characters that differ in ith position from position 1 to strlen(str1).   *
*******************************************************************************************************/
int getHammingDistance(char str1[], char str2[]){
	int distance=-1, i;										// distance would be the hamming distance.
	if(strlen(str1)==strlen(str2) && strlen(str1)>0)		// Defensive programming. Avoids null strings.
		for(i=0, distance=0; i<strlen(str1); i++) 						// Loops to every letter in str1.
			if(str1[i]!=str2[i]) distance++;				// Hamming distance would increse if and only if str1 and str2, given in the same index, is the same.
	if(distance==-1) printf("Error! Strings are not equal!\n"); //-1 means error
	return distance;
}

/*******************************************************************************************************
*	Given a string original and pattern, we will count the number of occurrence of pattern in original.*
*******************************************************************************************************/
int countSubstrPattern(char original[], char pattern[]){
	int i, j, k, counter=0, substring=0;					// substring would be count of substring pattern
	if((strlen(original)>0 || strlen(pattern)>0) || strlen(pattern)>strlen(original))	// Defensive programming. Avoids null strings.
		for(i=0;i<strlen(original)-strlen(pattern)+1;i++,counter=0){	// Loops to every letter in the string original at index 0 until the length of the pattern could fit.
			for(j=i,k=0;k<strlen(pattern);j++, k++) 		// Loops to every letter in the string original at index i until the length of the pattern.
				if(original[j]==pattern[k]) counter++;		// Compares the letter at index j of the substring in the string original and the letter at index k of the string pattern.
			if(counter==strlen(pattern)) substring++;		// If all the letters are equal, it is a valid substring.
		}
	return substring;
}

/*******************************************************************************************************
*	Given an alphabet string where all letters are assumed to be unique, this function returns true    *
*	if the string str is a valid string based on the letters of alphabet.							   *
*******************************************************************************************************/
bool isValidString(char str[], char alphabet[]){
	int i, j;
	if(strlen(str)>0 && strlen(alphabet)>0){				// Defensive programming. Avoids null strings.
		for(i=0;i<strlen(str);i++){							// Loops to every letter in the string str.
			for(j=0;j<strlen(alphabet);j++)					// Loops to every letter in the string alphabet.
				if(alphabet[j]==str[i]) break;				// If one letter in the string alphabet is equal to the letter of str at index i, it is valid.
			if(j==strlen(alphabet)) return false;			// If none of the letter in the string alphabet matches, it is not valid.
		}
		return true;										// Returns true if all the letters in the string str are valid.
	}
	return false;											// By default, this function returns false.
}

/*******************************************************************************************************
*	Given a genome str of some length q (where q>0), it returns the number of Gs minus the number of   *
*	Cs in the first n nucleotides (q>=n). The value can be zero, negative or positive. The first       *
*	position is one (1) not zero(0) as we typically associate with string implementations.			   *
*******************************************************************************************************/
int getSkew(char str[], int n){
	int counter=0, i;										// Counter would be the number of G's minus the number of C's.
	if(strlen(str)>0 && strlen(str)>=n)						// Defensive programming. Avoids null string and invalid input of n.
		for(i=0;i<n;i++)									// Loop to every letter in the string str at index 0 until n.
			if(str[i]=='G'||str[i]=='C') str[i]=='G'?counter++:counter--;	// If the letter is G, counter would increment else decrement .
	return counter;											// Returns the number of G's minus C's.
}

/*******************************************************************************************************
*	Given a genome str of some length q (where q>0), it returns the maximum value of the number of     *
*	Gs minus the number of Cs in the first n nucleotides (q>=n). The value can be zero, negative or    *
*	positive. The first position is one (1) not zero(0) as we typically associate with string 		   *
*	implementations.		   																		   *
*******************************************************************************************************/
int getMaxSkewN(char str[], int n){
	int i, maximum=getSkew(str,1);							// Initializes maximum to the value of getSkew with n=1
	if(strlen(str)>0){										// Defensive programming
		for(i=1;i<n;i++)									// Iterates from 1 to N
			maximum=(maximum>getSkew(str,i))?maximum:getSkew(str,i); // Determines the maximum Skew
		return maximum;										// Returns the maximum Skew
	}
	return 0;
}

/*******************************************************************************************************
*	Given a genome str of some length q (where q>0), it returns the minimum value of the number of     *
*	Gs minus the number of Cs in the first n nucleotides (q>=n). The value can be zero, negative or    *
*	positive. The first position is one (1) not zero(0) as we typically associate with string 		   *
*	implementations.		   																		   *
*******************************************************************************************************/
int getMinSkewN(char str[], int n){
	int i, minimum=getSkew(str,1);							// Initializes minimum to the value of getSkew with n=1
	if(strlen(str)>0){										// Defensive programming
		for(i=1;i<=n;i++)									// Iterates from 1 to N
			minimum=(getSkew(str,i)<minimum)?getSkew(str,i):minimum; // Determines the minimum Skew
		return minimum;										// Returns the minimum Skew
	}
	return 0;
}
// E N D - O F - P R O G R A M