#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define BASEPOINTER 0x004833D4
#define OFFSET 0x000067C0


print_progress(size_t count, size_t max); // Function which draws a progress bar using ASCII characters: the first parameter is the current value, while the second one the maximum length of the bar. From https://gist.github.com/amullins83/24b5ef48657c08c4005a8fab837b7499

int main(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Gets the handle of the cmd and stores it to hConsole
    UINT_PTR address = BASEPOINTER; // Base address which holds the pointer to the battery value (the pointer which points to the battery value will often change, but the base address which points to it will always stay the same
    UINT_PTR value = NULL; // Initialize value to NULL, will be used in lines 24-32
    DWORD pid; // Initializing the pid value, which is later used in line 14
    HANDLE hwnd = FindWindowA(NULL, "G930"); // Gets the handle of the G930 window and saves it to the variable hwnd
    if(hwnd == NULL){ // Displays an error and exits the program with code 1 if the G930 window does not exist
        printf("FindWindow Error.");
        exit(1);
    }
    GetWindowThreadProcessId(hwnd,&pid); // Gets the G930 window process ID and saves it to the pid variable
    HANDLE phandle = OpenProcess(PROCESS_VM_READ,0,pid); // Opens the G930 process to memory reading
    if(phandle == NULL){ // If not able to apply the memory read flag to the process exits the program with code 1
        printf("OpenProcess Error.");
        exit(1);
    }
    ReadProcessMemory(phandle,(void*)address,&value,sizeof(value),0); // Reads the pointer stored in the base address and stores it to value
    address = value + OFFSET; // Adds the offset to the pointer stored in the base address
    while(1){ // Endless loop
        ReadProcessMemory(phandle,(void*)address,&value,sizeof(value),0); // Reads the battery value from the pointer
        if(((value*100)/601) >= 25){ // If battery value in percentage >= 25
            SetConsoleTextAttribute(hConsole, 10); // Change text color to light green
        }
        if(((value*100)/601) < 25 && ((value*100)/601) > 10){ // If battery value in percentage < 25 and > 10
            SetConsoleTextAttribute(hConsole, 14); // Change text color to light yellow
        }
        if(((value*100)/601) <= 10){ // If battery value in percentage <= 10
            SetConsoleTextAttribute(hConsole, 12); // Change text color to light red
        }
        print_progress(((value*100)/601), 100); // Call to the print_progress function: the first parameter is the value in percentage (converted via a proportion), while the second one is the length of the progress bar
        printf("  %d%%", (value*100)/601); // Prints the percentage value at the end of the progress bar
        Sleep(5000); // Wait for 5 seconds
        system("cls"); // Clear console output
    }
    return 0;
}

print_progress(size_t count, size_t max) // See function declaration
{
	const char prefix[] = "[";
	const char suffix[] = "]";
	const size_t prefix_length = sizeof(prefix) - 1;
	const size_t suffix_length = sizeof(suffix) - 1;
	char *buffer = calloc(max + prefix_length + suffix_length + 1, 1); // +1 for \0
	size_t i = 0;

	strcpy(buffer, prefix);
	for (; i < max; ++i)
	{
		buffer[prefix_length + i] = i < count ? '#' : ' ';
	}

	strcpy(&buffer[prefix_length + i], suffix);
	printf("\b%c[2K\r%s", 27, buffer);
	fflush(stdout);
	free(buffer);
}

