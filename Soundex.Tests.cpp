#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "soundex.h"
// Function prototype for generate_soundex
void generate_soundex(const char *name, char *soundex);

void testEmptyString() {
    char soundex[5];
    generate_soundex("", soundex);
    assert(strcmp(soundex, "") == 0);
}

void testNullString() {
    char soundex[5];
    generate_soundex(NULL, soundex);
    assert(strcmp(soundex, "") == 0);
}

void testSingleCharacter() {
    char soundex[5];
    generate_soundex("A", soundex);
    assert(strcmp(soundex, "A000") == 0);
}

void testVowels() {
    char soundex[5];
    generate_soundex("AEIOU", soundex);
    assert(strcmp(soundex, "A000") == 0);
}

void testConsonants() {
    char soundex[5];
    generate_soundex("Smith", soundex);
    assert(strcmp(soundex, "S530") == 0);

    generate_soundex("Robert", soundex);
    assert(strcmp(soundex, "R163") == 0);
}

void testRepeatedConsonants() {
    char soundex[5];
    generate_soundex("Ttfn", soundex);
    assert(strcmp(soundex, "T315") == 0);
}

void testPadding() {
    char soundex[5];
    generate_soundex("Wright", soundex);
    assert(strcmp(soundex, "W623") == 0);

    generate_soundex("Park", soundex);
    assert(strcmp(soundex, "P620") == 0);
}

void testMixedCase() {
    char soundex[5];
    generate_soundex("RoBeRt", soundex);
    assert(strcmp(soundex, "R163") == 0);
}

void testHAndWHandling() {
    char soundex[5];
    generate_soundex("RWH", soundex);
    assert(strcmp(soundex, "R000") == 0);
}

int main() {
    testEmptyString();
    testNullString();
    testSingleCharacter();
    testVowels();
    testConsonants();
    testRepeatedConsonants();
    testPadding();
    testMixedCase();
    testHAndWHandling();

    printf("All tests passed successfully.\n");
    return 0;
}
