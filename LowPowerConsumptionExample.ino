#define BOARD_PCA10040 1

extern "C" {
#include "nrf5_sdk.h"
}
#include "pwrm.h"

int i;
void setup() {
  i = 0;
  nrf_gpio_cfg_sense_input(13 , NRF_GPIO_PIN_PULLUP, NRF_GPIO_PIN_SENSE_LOW);
//  nrf_gpio_cfg_sense_input(2 , NRF_GPIO_PIN_PULLUP, NRF_GPIO_PIN_SENSE_LOW);
  nrf_gpio_cfg_output(BSP_LED_0);
  nrf_gpio_pin_clear(BSP_LED_0);
}

void loop() {
  vTaskDelay(250);
  if (i++ < 30)
  {
    nrf_gpio_pin_toggle(BSP_LED_0);
  }
  else
  {
    nrf_gpio_pin_set(BSP_LED_0);
    //SwitchOffPeripherals();
    DeepSleep();
    //sd_power_system_off();
  }
}
