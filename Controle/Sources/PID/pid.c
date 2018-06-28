
#include "pid.h"
#include "../PERIPHERAL/es670_peripheral_board.h"
int reference_value = 0;

/* ************************************************ */
/* Method name:        pid_init                     */
/* Method description: seta valores iniciais        */
/* Input params:       vector unsigned bits         */
/* Output params:      n/a                          */
/* ************************************************ */
void pid_init(PID_DATA *pid_data){
	pid_data->Pgain = 1;
	pid_data->Igain = 1;
	pid_data->Dgain = 1;
	pid_data->sensor_value_previous = 0;
	pid_data->error_sum = 0;
}

/* ************************************************ */
/* Method name:        pid_Set                      */
/* Method description:seta referência               */
/* Input params:       int iValor                   */
/* Output params:      n/a                          */
/* ************************************************ */
void pid_Set(int iValor){
	reference_value = iValor;
}
/* ************************************************ */
/* Method name:        pid_Control                  */
/* Method description: controle pid                 */
/* Input params:       PID_DATA *pid_data           */
/*                     double sensor_value          */
/* Output params:      n/a                          */
double pid_Control(PID_DATA *pid_data, double sensor_value){

	double Pterm, Iterm, Dterm;
	double error, difference;

	error = reference_value - sensor_value;
	Pterm = pid_data -> Pgain * error;
	pid_data->error_sum += error;

	Iterm = pid_data->Igain * pid_data->error_sum;
	difference = pid_data->sensor_value_previous - sensor_value;
	pid_data -> sensor_value_previous = sensor_value;
	Dterm = pid_data -> Dgain * difference;

	if(Pterm + Iterm + Dterm < 0){
		return 0;
	}
	else if(Pterm + Iterm + Dterm >100){
		return 100;
	}
	else{
		return (Pterm + Iterm + Dterm);
	}
}
