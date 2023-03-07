#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Patient {
    char name[70];
    int age;
    char gender[10];
    int blood_pressure_sys;
    int blood_pressure_dia;
    int blood_sugar_fasting;
    int blood_sugar_post_food;
    int triglycerides;
};

int main() {
    struct Patient patient;

    FILE *input_file;
    input_file = fopen("Report 1_3.txt", "r");
    char line[100];
    char *token;
    char *name_pos;

    while (fgets(line, 100, input_file) != NULL) {
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
            strcpy(patient.gender, token);
        } else if (strstr(token, "Blood Pressure") != NULL) {
            token = strtok(NULL, "/");
            patient.blood_pressure_sys = atoi(token);
            token = strtok(NULL, ":");
            patient.blood_pressure_dia = atoi(token);
        } else if (strstr(token, "Fasting") != NULL) {
            token = strtok(NULL, ":");
            patient.blood_sugar_fasting = atoi(token);
        } else if (strstr(token, "Post food") != NULL) {
            token = strtok(NULL, ":");
            patient.blood_sugar_post_food = atoi(token);
        } else if (strstr(token, "Triglycerides") != NULL) {
            token = strtok(NULL, ":");
            patient.triglycerides = atoi(token);
        }
    }

    // Close file
    fclose(input_file);

    // Open file for writing output
    FILE *file;
    file = fopen("output.txt", "w");

    // Write patient details to file
    fprintf(file, "Patient Personal Details\n");
    fprintf(file, "Patient Name: %s\n", patient.name);
    fprintf(file, "Age: %d years old\n", patient.age);
    fprintf(file, "Gender: %s\n", patient.gender);

    // Write current and accepted levels to file
    fprintf(file, "Current Levels\n");
    fprintf(file, "Blood Pressure: %d/%d mg\n", patient.blood_pressure_sys, patient.blood_pressure_dia);
    fprintf(file, "Blood Sugar Fasting: %d mg/dL\n", patient.blood_sugar_fasting);
    fprintf(file, "Blood Sugar Post Food: %d mg/dL\n", patient.blood_sugar_post_food);
    fprintf(file, "Triglycerides: %d mg/dL\n\n", patient.triglycerides);

    fprintf(file, "Accepted Levels\n");
    fprintf(file, "Blood Pressure: 120/80\n");
    fprintf(file, "Blood Sugar Fasting: 70-100 mg/dL\n");
    fprintf(file, "Blood Sugar Post Food: Below 140 mg/dL\n");
    fprintf(file, "Triglycerides: Below 150 mg/dL\n\n");

    // Compare current levels with accepted levels
    int bp_sys_diff = patient.blood_pressure_sys - 120;
    int bp_dia_diff = patient.blood_pressure_dia - 80;
    int bs_fasting_diff = patient.blood_sugar_fasting - 70;
    int bs_post_food_diff = patient.blood_sugar_post_food - 140;
    int triglycerides_diff = patient.triglycerides - 150;

    if (bp_sys_diff > 50 || bp_dia_diff > 50 || bs_fasting_diff > 50 || bs_post_food_diff > 50 || triglycerides_diff > 50) {
        fprintf(file, "At Risk\n");
    } else if (bp_sys_diff > 20 || bp_dia_diff > 20 || bs_fasting_diff > 20 || bs_post_food_diff > 20 || triglycerides_diff > 20) {
        fprintf(file, "Borderline\n");
    } else {
        fprintf(file, "Healthy\n");
    }

    // Close file
    fclose(file);

    return 0;
}