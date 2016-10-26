//
//  main.c
//  Summer_Vacation_Al_0728
//
//  Created by ChoiJimin on 2016/07/28.
//  Copyright © 2016年 ChoiJimin. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

int MatchCounter(char SourceText[], int Textlen, char Pattern[], int Patlen);

int main(int argc, char** argv) {
    char* SourceText = "ggxgxggggggxggxx";
    char* Pattern = "gxg";

    printf("一致するものの数は %d ", MatchCounter(SourceText,
            strlen(SourceText), Pattern, strlen(Pattern)));

    return (EXIT_SUCCESS);
}

int MatchCounter(char SourceText[], int Textlen, char Pattern[], int Patlen) {
    int Counter, i, j, k;
    int Matchflg;

    /*
    printf("SourceText = %s, TextLen = %d, Pattern = %s, Patlen = %d\n\n",
            SourceText, Textlen, Pattern, Patlen);
*/
    Counter = 0;
    i = 0;
    while ((i + Patlen) <= Textlen) {
        j = i;
        k = 0;
        Matchflg=TRUE;
        while ((k < Patlen) && (Matchflg == TRUE)) {
            if (SourceText[j] == Pattern[k]) {
                j++;
                k++;
            } else {
                Matchflg = FALSE;
            }
        }
        if (k == Patlen) {
            Counter = Counter + 1;
            i = i + Patlen;
        } else {
            i = i + 1;
        }
    }
    return Counter;
}
