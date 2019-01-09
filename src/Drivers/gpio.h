/*
* File      : gpio.h
* This file is part of RT-Thread RTOS
* COPYRIGHT (C) 2015, RT-Thread Development Team
*
* The license and distribution terms for this file may be
* found in the file LICENSE in this distribution or at
* http://www.rt-thread.org/license/LICENSE
*
* Change Logs:
* Date           Author       Notes
* 2015-01-05     Bernard      the first version
*/
#ifndef GPIO_H__
#define GPIO_H__

#include "Rtdef.h"
#include "stm32f2xx.h"

struct stm32_hw_pin_userdata
{
  int pin;
  uint32_t mode;
};

#define PIN_USERDATA_END {-1,0}

extern struct stm32_hw_pin_userdata stm32_pins[];

//pin no
enum
{
  	PIN_NO_CAN_PWR					= 37,			//can1_pwr	DO
  	PIN_NO_CAN2_EN 					= 53,			//can2_en  
  	PIN_NO_EC20_PWRON				= 58,			//ec20 pwron	DO
  	PIN_NO_EC20_DTR 				= 59,			//ec20 dtr	DO
  	PIN_NO_EC20_AP_READY 			= 60,			//ec20������˯��״̬���   DI
  	PIN_NO_EC20_PWRKEY 				= 61,			//ec20 pwrkey		DO
	PIN_NO_CAN1_EN					= 67, 			//can1_en

};

int stm32_hw_pin_init(void);

/****************��������********************************************
//��������	:gpio_out_init
//����		:��ʼ��GPIO�������
//����		:pin:gpio�ܽű��
//���		:
//ʹ����Դ	:
//ȫ�ֱ���	:   
//���ú���	:
//�ж���Դ	:  
//����		:
//��ע		:
*********************************************************************/
void gpio_out_init(rt_base_t pin);
/****************��������********************************************
//��������	:gpio_out_on
//����		:����GPIO�������Ϊ��(������1)
//����		:pin:gpio�ܽű��
//���		:
//ʹ����Դ	:
//ȫ�ֱ���	:   
//���ú���	:
//�ж���Դ	:  
//����		:
//��ע		:
*********************************************************************/
void gpio_out_on(rt_base_t pin);
/****************��������********************************************
//��������	:gpio_out_off
//����		:����GPIO�������Ϊ��(������0)
//����		:pin:gpio�ܽű��
//���		:
//ʹ����Դ	:
//ȫ�ֱ���	:   
//���ú���	:
//�ж���Դ	:  
//����		:
//��ע		:
*********************************************************************/
void gpio_out_off(rt_base_t pin);
/****************��������********************************************
//��������	:gpio_in_init
//����		:��ʼ��GPIO��������
//����		:pin:gpio�ܽű��
//���		:
//ʹ����Դ	:
//ȫ�ֱ���	:   
//���ú���	:
//�ж���Դ	:  
//����		:
//��ע		:
*********************************************************************/
void gpio_in_init(rt_base_t pin);
/****************��������********************************************
//��������	:gpio_pin_read
//����		:��ȡ��������״̬
//����		:pin:gpio�ܽű��
//���		:
//ʹ����Դ	:
//ȫ�ֱ���	:   
//���ú���	:
//�ж���Դ	:  
//����		:��ǰIO��״ֵ̬,0��1
//��ע		:
*********************************************************************/
int gpio_pin_read(rt_base_t pin);

/****************��������********************************************
//��������	:gpio_irq_install
//����		:gpio�ն�װ�غ���
//����		:IoNum ����ֵ,�ο�GPIO_OUT_IN_NUMö��
//���		:
//ʹ����Դ	:
//ȫ�ֱ���	:   
//���ú���	:
//�ж���Դ	:  
//����		:
//��ע		:
*********************************************************************/
rt_err_t gpio_irq_install(rt_base_t pin, rt_base_t pinMode, void (*hdr)(void *args),rt_uint32_t irqMode,void  *args);

#endif
