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
#include "../library/bioinformatics.h"

// MAIN PROGRAM

int main(){
	// TEST CASES
	printf("A. FUNCTION 1 TEST CASES:\n");
	printf("1.)\t%d = 2\n", getHammingDistance("AACCTT", "GGCCTT"));
	printf("2.)\t%d = 5\n", getHammingDistance("TCGGA", "AAAAG"));
	if(getHammingDistance("A", "AG") == -1)
		 printf("3.)\tError! Strings are not equal! = Error! Strings are not equal!\n");
	else printf("3.)\t%d = Error! Strings are not equal!\n", getHammingDistance("A", "AG"));
	
	printf("B. FUNCTION 2 TEST CASES:\n");
	printf("1.)\t%d = 1\n", countSubstrPattern("AATATATAGG", "GG"));
	printf("2.)\t%d = 3\n", countSubstrPattern("AATATATAGG", "ATA"));
	// Commented Out because it returns "BUS ERROR 10" which I don't know how to fix.
	printf("3.)\t%d = 0\n", countSubstrPattern("AATATATAGG", "ACTGACTGACTG"));

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
