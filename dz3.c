#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    FILE *input, *output, *output1;
    char a, s[30][30];
    char s2[30][30];
    int i = 0, j = 0, count = 0, b = 0, v = 0;

    input = fopen("input.txt", "r"); 
    while (!feof(input)) {
        fscanf(input, "%c", &a);
        if (a == '1' || a == '0') { 
            s[i][j] = a;
            j++;
        }
        if (a == '\n') { 
            i++;
            j = 0;
        }
    }
    for (int n = 0; n < j; n++) { 
        count = 0;
        for (int m = 0; m <= i; m++) {
            if (s[m][n] == '1' && count == 0) {
                count++;
                b = m;
            }
            else if (s[m][n] == '1') {
                count++;
                if (count == 2) { 
                    s2[b][m] = '1';
                    s2[m][b] = '1';
                }
            }
        }
        if (count == 1) {
            v = 1;
        }
    }
    output1 = fopen("output1.txt", "w");
    for (int m = 0; m <= i; m++) {
        fprintf(output1, "%d: ", m + 1);
        count = 0;
        for (int n = 0; n <= i; n++) {
            if (s2[m][n] == '1') {
                fprintf(output1, "%d ", n + 1);
                count++;
            }
        }
        fprintf(output1, "\n");
    }
    for (int m = 0; m < i; m++) {
        for (int k = m + 1; k <= i; k++) {
            count = 0;
            for (int n = 0; n < j; n++) {
                if (s[m][n] == '1' && s[k][n] == '1') {
                    count++;
                }
            }
            if (count > 1) {
                v = 1;
            }
        }
    }
    if (v == 1) {
        fprintf(output1, "Граф не является простым");
    }
    else {
        if (j > ((i - 2) * (i - 1) / 2)) {
            fprintf(output1, "Граф связный");
        }
        else {
            fprintf(output1, "Граф несвязный");
        }
    }
    fclose(output1);
    output = fopen("output.gv", "w"); 
    fprintf(output, "graph G {\n");
    fprintf(output, "node [shape = circle];\n");
    for (int n = 0; n < j; n++) {
        count = 0;
        for (int m = 0; m <= i; m++) {
            if (s[m][n] == '1' && count == 0) {
                count++;
                b = m + 1;
            }
            else if (s[m][n] == '1') {
                count++;
                if (count == 2) {
                    fprintf(output, "%d -- %d\n", b, m + 1);
                }
            }
        }
        if (count == 1) {
            fprintf(output, "%d -- %d\n", b, b);
        }
    }
    for (int m = 0; m <= i; m++) { 
        count = 0;
        for (int n = 0; n < j; n++) {
            if (s[m][n] == '1') {
                count++;
            }
        }
        if (count == 0) { 
            fprintf(output, "%d\n", m + 1);
        }
    }
    fprintf(output, "}");
    fclose(output);
    system("dot output.gv -Tpng -o graph.png");
    system("graph.png");
    return 0;
}
