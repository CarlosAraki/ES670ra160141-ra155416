/* ************************************************** */
/* Method name: 	   timer_initTPM1AsPWM        */
/* Method description: configure Timer1 to act as PWM */
/* Input params:	   n/a 			      */
/* Outpu params:	   n/a 			      */
/* ************************************************** */
void timer_initTPM1AsPWM(void);

/* ************************************************ */
/* Method name:        timer_changeHeaterPwm        */
/* Method description: change the cooler pwm        */
/* Input params:       pwm desired (percentage)     */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_changeHeaterPwm(int iPwm);

/* ************************************************ */
/* Method name:        timer_initHeater             */
/* Method description: Initialize the heater device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_initHeater(void);
