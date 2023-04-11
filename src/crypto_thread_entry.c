#include "crypto_thread.h"
/* Crypto_Thread entry function */
/* pvParameters contains TaskHandle_t */
void crypto_thread_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);

    /* TODO: add your own code here */
    while (1)
    {
        vTaskDelay (1);
    }
}
