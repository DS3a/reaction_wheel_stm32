#ifndef MAINPP_H_
#define MAINPP_H_
#include <stdint.h>

#ifdef __cplusplus
 extern "C" {
#endif

void setup(void);
void loop(void);
uint8_t get_direction(void);
uint16_t get_speed(void);

#ifdef __cplusplus
}
#endif


#endif /* MAINPP_H_ */