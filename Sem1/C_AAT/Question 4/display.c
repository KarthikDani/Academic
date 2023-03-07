#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void clear_screen() {
    // Clear the screen by printing ANSI escape code for clearing terminal
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

int main() {
    // Initialize the systolic, diastolic, and pulse values
    int systolic = 130;
    int diastolic = 77;
    int pulse = 60;

    // Define the maximum and minimum values for the blood pressure and pulse
    int max_bp = 200;
    int min_bp = 0;
    int max_pulse = 200;
    int min_pulse = 0;

    // Set the seed for random number generation
    srand(time(NULL));

    while (1) {
        // Generate a random value between -5 and +5 for systolic and diastolic
        int delta_bp = rand() % 11 - 5;
        systolic += delta_bp;
        diastolic += delta_bp;

        // Generate a random value between -2 and +2 for pulse
        int delta_pulse = rand() % 5 - 2;
        pulse += delta_pulse;

        // Limit the values to the range defined by min_bp and max_bp
        systolic = systolic > max_bp ? max_bp : systolic;
        systolic = systolic < min_bp ? min_bp : systolic;
        diastolic = diastolic > max_bp ? max_bp : diastolic;
        diastolic = diastolic < min_bp ? min_bp : diastolic;
        pulse = pulse > max_pulse ? max_pulse : pulse;
        pulse = pulse < min_pulse ? min_pulse : pulse;

        // Correct the systolic and diastolic values if they are outside of the ideal range
        if (systolic < 90 || systolic > 119) {
            systolic = 120;
        }
        if (diastolic < 60 || diastolic > 79) {
            diastolic = 80;
        }

        // Clear the screen and move the cursor to the top-left corner
        clear_screen();

        // Print the top border
        printf("+----------------------------------------+\n");

        // Print the systolic and diastolic blood pressure values
        printf("| Systolic Blood Pressure:  %3d mmHg    |\n", systolic);
        printf("| Diastolic Blood Pressure: %3d mmHg    |\n", diastolic);

        // Calculate the percentage of the blood pressure value within the range
        float bp_percent = (float)(systolic - min_bp) / (float)(max_bp - min_bp);

        // Calculate the number of blocks to display on the bar graph
        int bp_blocks = (int)(bp_percent * 20);

        // Print the blood pressure bar graph
        printf("| [");
        for (int i = 0; i < bp_blocks; i++) {
            printf("#");
        }
        for (int i = 0; i < (20 - bp_blocks); i++) {
            printf("-");
        }
        printf("] %.0f%%          |\n", bp_percent * 100);

        // Calculate the percentage of the pulse value within the range
        float pulse_percent = (float)(pulse - min_pulse) / (float)(max_pulse - min_pulse);

        // Calculate the number of blocks to display on the bar graph
        int pulse_blocks = (int)(pulse);    // Print the pulse bar graph
        printf("| [");
        for (int i = 0; i < pulse_blocks; i++) {
        printf("#");
        }
        for (int i = 0; i < (20 - pulse_blocks); i++) {
        printf("-");
        }
        printf("] %.0f BPM        |\n", pulse_percent * 100);

        // Print the bottom border
        printf("+----------------------------------------+\n");

        // Wait for 1 second before refreshing the display
        sleep(1);
}

return 0;
}
