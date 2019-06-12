

#include <platform/types.h>
#include "hal/uc/gpio.h"


static inline void led_init(PORTSELECTOR_t port,
                            PINSELECTOR_t  pin){
    gpio_conf_output(port, pin);
}

static inline void led_on(PORTSELECTOR_t port,
                          PINSELECTOR_t  pin){
    #if BOARD_LED_POLARITY == 1 
        gpio_set_output_high(port, pin);
    #else
        gpio_set_output_low(port, pin);
    #endif
}

static inline void led_off(PORTSELECTOR_t port,
                           PINSELECTOR_t  pin){
    #if BOARD_LED_POLARITY == 1 
        gpio_set_output_low(port, pin);
    #else
        gpio_set_output_high(port, pin);
    #endif
}

static inline void led_toggle(PORTSELECTOR_t port,
                              PINSELECTOR_t  pin){
        gpio_set_output_toggle(port, pin);
}
