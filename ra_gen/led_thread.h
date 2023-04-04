/* generated thread header file - do not edit */
#ifndef LED_THREAD_H_
#define LED_THREAD_H_
#include "bsp_api.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "hal_data.h"
#ifdef __cplusplus
                extern "C" void led_thread_entry(void * pvParameters);
                #else
extern void led_thread_entry(void *pvParameters);
#endif
#include "r_icu.h"
#include "r_external_irq_api.h"
FSP_HEADER
/** External IRQ on ICU Instance. */
extern const external_irq_instance_t g_external_irq00;

/** Access the ICU instance using these structures when calling API functions directly (::p_api is not used). */
extern icu_instance_ctrl_t g_external_irq00_ctrl;
extern const external_irq_cfg_t g_external_irq00_cfg;

#ifndef external_irq00_callback
void external_irq00_callback(external_irq_callback_args_t *p_args);
#endif
FSP_FOOTER
#endif /* LED_THREAD_H_ */
