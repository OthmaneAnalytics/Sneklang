#include <stdio.h>

int main() {
	int max_recursive_calls = 100;
	char io_mode = 'w';
	float throttle_speed = 0.2;
	char *will_never_hear_again = "Hey TJ, when is the memory course in C gonna be done?";
	int sneklang_default_max_threads = 8;
	char sneklang_default_perms = 'r';
	float sneklang_default_pi = 3.14159;
	char *sneklang_title = "Sneklang";
 
	printf("Default max threads: %d\nCustom perms: %c\nConstant pi value: %f\nSneklang title: %s", sneklang_default_max_threads, sneklang_default_perms, sneklang_default_pi, sneklang_title);
	// don't touch below this line
	printf("Max recursive calls: %d\n", max_recursive_calls);
	printf("IO mode: %c\n", io_mode);
	printf("Throttle speed: %f\n", throttle_speed);
	return 0;
}
