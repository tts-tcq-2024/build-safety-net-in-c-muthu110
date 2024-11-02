#include <stdio.h>
#include <string.h>
#include <ctype.h>

char get_soundex_code(char c) {
    // Map of characters to Soundex codes
    switch (toupper(c)) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0';
    }
}

int is_vowel(char c) {
    return strchr("AEIOUY", toupper(c)) != NULL;
}

int should_skip_character(char currentChar, char prevChar) {
    return (currentChar == 'H' || currentChar == 'W') && !is_vowel(prevChar);
}

void generate_soundex(const char *name, char *soundex) {
    if (name == NULL || strlen(name) == 0) {
        soundex[0] = '\0';
        return;
    }

    soundex[0] = toupper(name[0]);
    int soundex_len = 1;
    char prev_code = '0';
    char prev_char = soundex[0];

    for (int i = 1; i < strlen(name) && soundex_len < 4; i++) {
        char current_char = toupper(name[i]);
        
        if (should_skip_character(current_char, prev_char)) continue;

        char code = get_soundex_code(current_char);
        if (code != '0' && code != prev_code) {
            soundex[soundex_len++] = code;
        }
        
        prev_code = code;
        prev_char = current_char;
    }

    while (soundex_len < 4) {
        soundex[soundex_len++] = '0';
    }
    soundex[soundex_len] = '\0';
}

int main() {
    char soundex[5];
    generate_soundex("Example", soundex);
    printf("Soundex code: %s\n", soundex);
    return 0;
}
