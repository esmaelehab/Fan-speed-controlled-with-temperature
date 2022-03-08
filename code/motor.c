/******************************************************************************
 *
 * Module: MOTOR
 *
 * File Name: motor.c
 *
 * Description: source file for the MOTOR driver
 *
 * Author: Esmael Ehab
 *
 *******************************************************************************/

#include "motor.h"
#include "gpio.h"
#include "pwm.h"

void DcMotor_Init(void)
{
	/*
	 * setup the motor's two pins as output pins
	 */
	GPIO_setupPinDirection(MOTOR_PORT_ID, MOTOR_PIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT_ID, MOTOR_PIN2_ID, PIN_OUTPUT);

	/*
	 *  Stop at the DC-Motor at the beginning through the GPIO driver
	 */
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN1_ID, LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN2_ID, LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	PWM_Timer0_Start(speed);

	if (state == CW)
	{
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN2_ID, LOGIC_LOW);
	}
	else if (state == A_CW)
	{
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN1_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN2_ID, LOGIC_HIGH);
	}
	else if(state == OFF)
	{
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN1_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN2_ID, LOGIC_LOW);
	}
}

