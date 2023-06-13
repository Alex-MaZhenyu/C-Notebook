#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 int main() {
    FILE *file;
    char line[100];
     // Open the file
    file = fopen("example.txt", "r");
     // Read each line and output it
    while (fgets(line, sizeof(line), file)) {
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == ' ') {
                printf("\n");
            } else {
                printf("%c", line[i]);
            }
        }
    }
     // Close the file
    fclose(file);
     system("pause");
     return 0;
}