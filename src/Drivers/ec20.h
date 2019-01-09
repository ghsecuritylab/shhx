#ifndef __EC20_H__
#define __EC20_H__

#include <stm32f2xx.h>

#ifdef __cplusplus
 extern "C" {
#endif 


enum ec20_stage 
{
  EC20_STAGE_RDY,
  EC20_STAGE_01,
  EC20_STAGE_02,
  EC20_STAGE_03,
  EC20_STAGE_04,
  EC20_STAGE_FINISHED,
  
};

struct ec20_ctx
{
  rt_device_t dev;											//�豸�����̳�
  
  rt_tick_t	onceticks;									//�����ʱ�����εδ���
  rt_tick_t	periodicticks;							//�����ʱ��ѭ���δ���

  rt_base_t	modempwronpin;							//ģ���Դ�ܽź�
  rt_base_t	modempwrkeypin;							//ģ�鿪���ܽź�
  rt_base_t	modemdtrpin;								//ģ��DTR�ܽ�
  rt_base_t	modemaprdypin;								//ģ��˯��״̬����
  
  enum ec20_stage stage;								//״̬
  
  const struct ec20_process	* ec20_proc;			//����ָ��
  
  rt_sem_t   sem;
  rt_event_t event;
  rt_timer_t timer;
  rt_int32_t semtick;
  
  rt_uint8_t *revbuf;
  //rt_uint8_t *sendbuf;
  
  rt_thread_t tid;
  
};

typedef enum ec20_stage (*ec20_callback)(struct ec20_ctx *ctx);

struct ec20_process
{
	//const char *modemcmd;
  enum ec20_stage  process_index;
  ec20_callback	ec20_cb;
};
typedef struct ec20_process	*ec20_process_t;


rt_err_t ec20_comm_mount(const char *devname);

#ifdef __cplusplus
 extern "C" }
#endif 

#endif

