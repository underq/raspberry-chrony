#include <bcm2835.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>

#define PIN RPI_GPIO_P1_07 /*GPIO 4 = real pin position 7*/

int main(int argc, char **arcgv) {

  if(!bcm2835_init()) {
    return 1;
  }


  // Define port mode
  bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_set_pud(PIN, BCM2835_GPIO_PUD_DOWN);
  printf("watching...\n");

  while(1) {
    printf("%d", bcm2835_gpio_lev(PIN));

    delay(1);
  }
}
