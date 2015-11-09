#include "contiki.h"
#include <stdio.h> /* For printf() */
/*---------------------------------------------------------------------------*/
PROCESS(hello_world_process1, "Hello world process");
PROCESS(hello_world_process2, "Hello world process");
AUTOSTART_PROCESSES(&hello_world_process1, &hello_world_process2);
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(hello_world_process1, ev, data)
{
  static struct etimer periodic;
  PROCESS_BEGIN();
  etimer_set(&periodic, CLOCK_SECOND * 10);
  while(1) {
    PROCESS_YIELD();
    if(etimer_expired(&periodic)) {
      etimer_reset(&periodic);
      printf("Hello, world (1) %d\n", (int) clock_time());
    }
  }
  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(hello_world_process2, ev, data)
{
  static clock_time_t last_clock = 0;
  PROCESS_BEGIN();
  while(1) {
    PROCESS_PAUSE();
    if((clock_time() / CLOCK_SECOND) > last_clock) {
      printf("Hello, world (2) %d %d\n", (int) clock_time(), (int)last_clock);
    }
    last_clock = (clock_time() / CLOCK_SECOND);
  }
  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
