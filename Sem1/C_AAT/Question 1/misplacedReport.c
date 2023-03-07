#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *input_file, *output_file;
    char buffer[1000];

    // Open the input file for reading
    input_file = fopen("Report1_1.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    // Open the output file for writing
    output_file = fopen("output_corrected.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    // Read the input file line by line
    while (fgets(buffer, 1000, input_file)) {
        // Check if the line contains the information that needs to be modified
        if (strstr(buffer, "Age:")) {
            // Replace the age value with 43
            fprintf(output_file, "Age: 43 years old\n");
        } else if (strstr(buffer, "Gender:")) {
            // Replace the gender value with "Male"
            fprintf(output_file, "Gender: Male\n");
        } else if (strstr(buffer, "Blood Pressure:")) {
            // Replace the blood pressure value with "125/70 mg"
            fprintf(output_file, "Blood Pressure: 125/70 mg\n");
        } else {
            // Copy the line to the output file as is
            fprintf(output_file, "%s", buffer);
        }
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}
