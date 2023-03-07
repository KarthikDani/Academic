#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Patient {
    char name[70];
    int age;
    char gender[10];
};

int main() {
    struct Patient patient;

    FILE *file1, *file2, *file3, *outfile;
    char buffer[100];

    char line[100];
    char *token;
    char *name_pos;

    // Open input files for reading
    file1 = fopen("Report 2_1.txt", "r");
    file2 = fopen("Report 2_2.txt", "r");
    file3 = fopen("Report 2_3.txt", "r");

    // Open output file for writing
    outfile = fopen("compiled_report.txt", "w");

    while (fgets(line, 100, file1) != NULL) {
    token = strtok(line, ":");
    name_pos = strstr(token, "Patient Name");
    if (name_pos != NULL) {
        token = strtok(NULL, ":");
        token[strcspn(token, "\n")] = '\0';
        strcpy(patient.name, token);
    } 
    else if (strcmp(token, "Age") == 0) {
        token = strtok(NULL, ":");
        patient.age = atoi(token);
    } else if (strcmp(token, "Gender") == 0) {
        token = strtok(NULL, ":");
        strncpy(patient.gender, token, sizeof(patient.gender) - 1);
        patient.gender[sizeof(patient.gender) - 1] = '\0';
    }
}
    // Copy contents of report1 to output file
    while (fgets(buffer, 100, file1) != NULL) {
        fprintf(outfile, "%s", buffer);
    }

    // Copy contents of report2 to output file
    while (fgets(buffer, 100, file2) != NULL) {
        fprintf(outfile, "%s", buffer);
    }

    // Copy contents of report3 to output file
    while (fgets(buffer, 100, file3) != NULL) {
        fprintf(outfile, "%s", buffer);
    }

    // Close files
    fclose(file1);
    fclose(file2);
    fclose(file3);
    fclose(outfile);

    printf("Reports combined successfully\n");

    return 0;
}