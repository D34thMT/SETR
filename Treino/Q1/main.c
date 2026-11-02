#include <stdio.h>
#include "sensor.h"

int main(void) {
    // 1. Init the system
    tempInit();
    printf("System initialized.\n");

    // Try to get the maximum temperature before registering any temperature (should fail)
    float maxVal = 0.0f;
    if (tempMax(&maxVal) == ERROR_NO_DATA) {
        printf("Could not get maximum temperature (no readings yet).\n");
    } else {
        printf("Unexpected success getting max temperature: %.1f\n", maxVal);
    }

    // Add temperatures -10.0, 10.0, 20.0, 60.0, 25.0
    float test_values[5] = {-10.0f, 10.0f, 20.0f, 60.0f, 25.0f};
    for (int i = 0; i < 5; i++) {
        int result = tempAdd(test_values[i]);
        if (result == SUCESS) {
            printf("Successfully added temperature: %.1f\n", test_values[i]);
        } else {
            printf("Failed to add temperature: %.1f (Error code: %d)\n", test_values[i], result);
        }
    }

    // Print the maximum temperature (60.0), checking for success
    if (tempMax(&maxVal) == 0) {
        printf("Maximum temperature registered: %.1f (Expected: 60.0)\n", maxVal);
    } else {
        printf("Failed to retrieve maximum temperature.\n");
    }

    // Print the last temperature added to the system (25.0), checking for success
    float lastVal = 0.0f;
    if (tempLast(&lastVal) == 0) {
        printf("Last temperature registered: %.1f (Expected: 25.0)\n", lastVal);
    } else {
        printf("Failed to retrieve last temperature.\n");
    }

    return 0;
}