/* file: seg7.h */ 

#ifndef SEG7_H_
#define SEG7_H_

/* function: seg7_init
 * Initializes the seven segment display device
 * return value: none
 * arguements:   none
 */
void seg7_init (void);

/* function: seg7_put
 * Sends data to the a seven segment digit
 * return value: none
 * arguements: segid: a 3-bit value to specify the seven segment digit
 *                    to be updated. range: 0 (right most) to 7 (left most).
 *             segments: a 7 bit value to designate the state of led
 *                       segments. The values are positioned as follows.
 *                       0bgfedcba. The value for the encoding use reverse
 *                       logic values. (0=on and 1=off)
 *
 *                       +-a-+
 *                       f   b
 *                       |-g-|
 *                       e   c
 *                       +-d-+                      
 */
void seg7_put (unsigned int segid, unsigned int segments);

#endif /* SEG7_H_ */