// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <cmath>

unsigned int faStr1(const char *str) {
    int n = strlen(str);
    bool spase = false;
    bool letter = false;
    bool numb = false;
    bool inWord = false;
    int count = 0;
    char simbol;
    for (int i = 0; i < n; i++) {
        simbol = str[i];
        if (simbol == ' ') {
            spase = true;
            if (inWord && !numb) {
                count += 1;
            }
            inWord = false;
            letter = false;
            numb = false;
        }
        if (simbol >= 'A' && simbol <= 'z') {
            letter = true;
            if (spase || i == 0) {
                inWord = true;
            }
            spase = false;
        }
        if (simbol >= '0' && simbol <= '9') {
            numb = true;
        }
        if (i == n - 1) {
            if (inWord && !numb) {
                count += 1;
            }
        }
    }
    return count;
}

unsigned int faStr2(const char *str) {
    int n = strlen(str);
    bool spase = false;
    bool numb = false;
    bool inWord = false;
    bool middle = false;
    bool start = false;
    int count = 0;
    char simbol;
    for (int i = 0; i < n; i++) {
        simbol = str[i];
        if (simbol == ' ') {
            spase = true;
            if (inWord && !numb && !middle) {
                count += 1;
            }
            inWord = false;
            numb = false;
            middle = false;
        }
        if (simbol >= 'A' && simbol <= 'Z') {
            if (spase || i == 0) {
                inWord = true;
                start = true;
            } else {
                middle = true;
            }
            spase = false;
        }
        if (simbol >= '!' && simbol <= '@') {
            numb = true;
        }
        if (i == n - 1) {
            if (inWord && !numb && !middle) {
                count += 1;
            }
        }
    }
    return count;
}

unsigned int faStr3(const char *str) {
    int n = strlen(str);
    bool spase = false;
    bool inWord = false;
    int count = 0;
    int len = 0;
    int result;
    char simbol;
    for (int i = 0; i < n; i++) {
        simbol = str[i];
        if (simbol == ' ') {
            spase = true;
            if (inWord) {
                count += 1;
            }
            inWord = false;
        }
        if (simbol >= 'A' && simbol <= 'z') {
            if (spase || i == 0) {
                inWord = true;
            }
            len += 1;
            spase = false;
        }
        if (i == n - 1) {
            if (inWord) {
                count += 1;
            }
        }
    }
    result = round(len / count);
    return result;
}
