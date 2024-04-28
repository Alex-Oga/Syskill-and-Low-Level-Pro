#include <stdio.h>

void string_copy(const char* source, char* destination) {

	// Your inline assembly code goes here. Note that volatile keyword ensure that the assembly code will not be moved around by the compiler
	asm volatile (
	    "mov %[src], %%rsi\n"   // Move the source address to rsi
	    // Continue with the string copy using appropriate instructions

	:   // Use these as needed
	:   // Use these as needed
	:   // Use these as needed
	);
}

int string_cmp(const char* str1, char* str2) {
	
	// Your inline assembly code goes here. Note that volatile keyword ensure that the assembly code will not be moved around by the compiler
	asm volatile (
	    "mov %[src], %%rsi\n"   // Move the source address to rsi
	    // Continue with the string copy using appropriate instructions
	   
	:   // Use these as needed
	:   // Use these as needed
	:   // Use these as needed
	);
}

int main() {
	char source1[50] = "Hello, World!";
	char source2[50] = "Hello, World";
	char destination[50];
	
	string_copy(source1, destination);
	
	printf("Original string: %s\n", source1);
	printf("Copied string: %s\n", destination);
	
	printf("String Cmp between %s and %s: %d\n", source1, source2, string_cmp(source1, source2));
	printf("String Cmp between %s and %s: %d\n", source1, destination, string_cmp(source1, destination));
	
	return 0;
}
