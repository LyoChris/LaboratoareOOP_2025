#pragma once

void strcpy(char* dest, const char* str) {
	while (*str) {
		*dest++ = *str++;
	}
	*dest = '\0';
}