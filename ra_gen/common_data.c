/* generated common source file - do not edit */
#include "common_data.h"
ioport_instance_ctrl_t g_ioport_ctrl;
const ioport_instance_t g_ioport =
{ .p_api = &g_ioport_on_ioport, .p_ctrl = &g_ioport_ctrl, .p_cfg = &g_bsp_pin_cfg, };
SemaphoreHandle_t g_sw1_semaphore;
#if 1
StaticSemaphore_t g_sw1_semaphore_memory;
#endif
void rtos_startup_err_callback(void *p_instance, void *p_data);
void g_common_init(void)
{
    g_sw1_semaphore =
#if 1
            xSemaphoreCreateBinaryStatic (&g_sw1_semaphore_memory);
#else
                xSemaphoreCreateBinary();
                #endif
    if (NULL == g_sw1_semaphore)
    {
        rtos_startup_err_callback (g_sw1_semaphore, 0);
    }
}
