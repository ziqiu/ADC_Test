#include "nrf51.h"
#include "led.h"
#include "uart.h"
#include "nrf_delay.h"
#include "simple_uart.h"
#include "nrf_gpio.h"
uint16_t adc_result;
uint16_t adc_result1;


void Adc_Init()
{
	NRF_ADC->INTENSET = (ADC_INTENSET_END_Disabled << ADC_INTENSET_END_Pos);
	NRF_ADC->CONFIG	= (ADC_CONFIG_EXTREFSEL_None << ADC_CONFIG_EXTREFSEL_Pos)
										| (ADC_CONFIG_PSEL_AnalogInput2 << ADC_CONFIG_PSEL_Pos)
										| (ADC_CONFIG_REFSEL_VBG << ADC_CONFIG_REFSEL_Pos)
										| (ADC_CONFIG_INPSEL_AnalogInputOneThirdPrescaling << ADC_CONFIG_INPSEL_Pos)
										| (ADC_CONFIG_RES_10bit << ADC_CONFIG_RES_Pos);
	// enable ADC
	NRF_ADC->ENABLE = ADC_ENABLE_ENABLE_Enabled;
	NRF_ADC->TASKS_START = 1;
	
	while (!NRF_ADC->EVENTS_END)
	{}
	
	NRF_ADC->EVENTS_END	= 0;
	adc_result = NRF_ADC->RESULT;
	NRF_ADC->TASKS_STOP = 1;
}

void Adc1_Init()
{
	NRF_ADC->INTENSET = (ADC_INTENSET_END_Disabled << ADC_INTENSET_END_Pos);
	NRF_ADC->CONFIG	= (ADC_CONFIG_EXTREFSEL_None << ADC_CONFIG_EXTREFSEL_Pos)
										| (ADC_CONFIG_PSEL_AnalogInput3 << ADC_CONFIG_PSEL_Pos)
										| (ADC_CONFIG_REFSEL_VBG << ADC_CONFIG_REFSEL_Pos)
										| (ADC_CONFIG_INPSEL_AnalogInputOneThirdPrescaling << ADC_CONFIG_INPSEL_Pos)
										| (ADC_CONFIG_RES_10bit << ADC_CONFIG_RES_Pos);
	// enable ADC
	NRF_ADC->ENABLE = ADC_ENABLE_ENABLE_Enabled;
	NRF_ADC->TASKS_START = 1;
	
	while (!NRF_ADC->EVENTS_END)
	{}
	
	NRF_ADC->EVENTS_END	= 0;
	adc_result1 = NRF_ADC->RESULT;
	NRF_ADC->TASKS_STOP = 1;
}

int main (void)
{
	float result,result1;
	LED_Init();
	USART_Configuration();
	uart_exit();
	
	for (;;)
	{
		Adc_Init();
		result=adc_result*3600.00/1023;
		printf ("\n\rThe adc input = %.2f\n\r",result);
		Adc1_Init();
		result1=adc_result1*3600.0000/1023.0000/1000.0000;
		printf ("\n\rThe adc1 input = %.4f\n\r",result1);
		nrf_delay_ms (1000);
	}
}

