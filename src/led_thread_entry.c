#include "led_thread.h"
#include "debug.h"
void led_thread_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED(pvParameters);
    extern bsp_leds_t g_bsp_leds;
    bsp_leds_t Leds = g_bsp_leds;
    uint8_t led_level = BSP_IO_LEVEL_HIGH;
    g_external_irq00.p_api->open(g_external_irq00.p_ctrl,
                                 g_external_irq00.p_cfg);
    g_external_irq00.p_api->enable(g_external_irq00.p_ctrl);

    while (1)
    {
        g_ioport.p_api->pinWrite(&g_ioport_ctrl, Leds.p_leds[BSP_LED_LED3], led_level);
        if (led_level == BSP_IO_LEVEL_HIGH)
        {
            led_level = BSP_IO_LEVEL_LOW;
        }
        else
        {
            led_level = BSP_IO_LEVEL_HIGH;
        }
        xSemaphoreTake(g_sw1_semaphore, portMAX_DELAY);
        log_error("SemaphoreTake %f!\r\n",-0.01234);
    }
}
/* callback function for the SW1 push button; sets the semaphore */
void external_irq00_callback(external_irq_callback_args_t *p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);
    xSemaphoreGiveFromISR(g_sw1_semaphore, NULL);
}
