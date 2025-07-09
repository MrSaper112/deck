#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void my_task(void *pvParameters) {
    while (1) {
        printf("Task running on core %d\n", xPortGetCoreID());
        vTaskDelay(pdMS_TO_TICKS(1000));  // 1 second delay
    }
}

void app_main(void) {
    printf("Starting FreeRTOS task...\n");

    xTaskCreatePinnedToCore(
        my_task,           // Function
        "MyTask",          // Name
        2048,              // Stack size in words
        NULL,              // Parameters
        5,                 // Priority
        NULL,              // Task handle
        0                  // Core (0 or 1 on ESP32/ESP32-S3)
    );
}
