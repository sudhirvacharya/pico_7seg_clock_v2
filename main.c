#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/rtc.h"
#include "pico/util/datetime.h"
#include "PicoTM1637.h"

/* TM1637 pins — change if needed */
#define CLK_PIN  0
#define DIO_PIN  1

/* Convert 24hr → 12hr */
static void to_12hr(int h24, int *h12, bool *pm)
{
    if (h24 == 0)        { *h12 = 12; *pm = false; }
    else if (h24 < 12)   { *h12 = h24; *pm = false; }
    else if (h24 == 12)  { *h12 = 12;  *pm = true;  }
    else                 { *h12 = h24 - 12; *pm = true; }
}

/* Set initial time */
static void set_time(void)
{
    datetime_t t = {
        .year  = 2026,
        .month = 3,
        .day   = 20,
        .dotw  = 5,
        .hour  = 14,   /* 2:30 PM */
        .min   = 30,
        .sec   = 0
    };
    rtc_set_datetime(&t);
    sleep_us(64);
}

int main(void)
{
    stdio_init_all();

    /* Init RTC */
    rtc_init();
    set_time();

    /* Init TM1637 display */
    TM1637_init(CLK_PIN, DIO_PIN);
    TM1637_set_brightness(4);   /* 0=dim, 7=max */

    printf("12hr clock started\n");

    while (true) {
        datetime_t t;
        rtc_get_datetime(&t);

        int  h12;
        bool pm;
        to_12hr(t.hour, &h12, &pm);

        /* Display HH:MM with colon */
        TM1637_display_both(h12, t.min, true);

        sleep_ms(1000);   /* update every second */
    }

    return 0;
}
