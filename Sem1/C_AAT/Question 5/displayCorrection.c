#include <stdio.h>

int main() {
    int systolic = 77;
    int diastolic = 130;
    int corrected_systolic = 0;
    int corrected_diastolic = 0;
    
    printf("+----------------+\n");
    printf("|   Blood Press   |\n");
    printf("+----------------+\n");
    printf("|   Systolic: %3d |\n", systolic);
    printf("|  Diastolic: %3d |\n", diastolic);
    printf("+----------------+\n");
    
    if (systolic < 90 || diastolic < 60) {
        printf("| Error Value     |\n");
        corrected_systolic = diastolic;
        corrected_diastolic = systolic;
    } else if (systolic >= 90 && systolic <= 119 && diastolic >= 60 && diastolic <= 79) {
        printf("| Ideal BP        |\n");
        corrected_systolic = systolic;
        corrected_diastolic = diastolic;
    } else if (systolic >= 120 && systolic <= 129 && diastolic >= 80 && diastolic <= 84) {
        printf("| Elevated BP     |\n");
        corrected_systolic = systolic;
        corrected_diastolic = diastolic;
    } else if (systolic >= 130 && systolic <= 139 || diastolic >= 85 && diastolic <= 89) {
        printf("| Stage 1 HTN     |\n");
        corrected_systolic = 120;
        corrected_diastolic = 80;
    } else if (systolic >= 140 && systolic <= 180 || diastolic >= 90 && diastolic <= 120) {
        printf("| Stage 2 HTN     |\n");
        corrected_systolic = 120;
        corrected_diastolic = 80;
    } else {
        printf("| HTN Crisis      |\n");
        corrected_systolic = 120;
        corrected_diastolic = 80;
    }
    
    printf("+----------------+\n");
    printf("| Corrected Value |\n");
    printf("+----------------+\n");
    printf("|   Systolic: %3d |\n", corrected_systolic);
    printf("|  Diastolic: %3d |\n", corrected_diastolic);
    printf("+----------------+\n");
    printf("| Display         |\n");
    printf("+----------------+\n");
    printf("|   Systolic: %3d |\n", corrected_systolic);
    printf("|  Diastolic: %3d |\n", corrected_diastolic);
    printf("+----------------+\n");
    
    return 0;
}
