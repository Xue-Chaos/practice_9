#include <ioCC2530.h>  

#define D3 P1_0     // P1_0����ΪP1_0
#define D4 P1_1     // P1_1����ΪP1_1
#define D5 P1_3     // P1_2����ΪP1_3
#define D6 P1_4     // P1_3����ΪP1_4
#define SW1  P1_2

char data[]="����LED�ƴ���΢��״̬��";
char data1[]="����LED�ƴ�����ʾ����״̬��";
char data2[]="����LED�ƴ���Ϩ��״̬!";

unsigned char C_AN;         //��ʱ�䰴�����ɿ���־
unsigned char ZC_AN_2;      //���������ڶ��±�־
unsigned char count;        //��ֵ
unsigned char count_DSQ;    //��ʱ��������

void delay(int delaytime)
{
  int i=0,j=0;
  for(i=0;i<240;i++)
    for(j=0;j<delaytime;j++);
}

void initLed()
{
/*********������1��ʼ�����е�LED�Ʋ���******************************/  
 // P1SEL&=~0x1F;  //P1.0~P1.4����ΪGPIO
  P1DIR|=0x1B;   //P1.0 P1.1 P1.3 P1.4 ����Ϊ���
 // P1DIR&=~0x04;  //P1.2����Ϊ����
  D3=D4=D5=D6=0;     //����LED���ϵ紦��Ϩ��״̬ P1 = 0X00
/*********������1����******************************/ 
}

void initial_usart_tx()
{
    PERCFG = 0X00;
    P0SEL |= 0X3C;
    P2DIR &= ~0XC0;
    U0CSR = 0X80;
/*********������5��ʼ��������Ϊ115200******************************/   
    U0GCR = 11;
    U0BAUD = 216;      //���ô��ڲ�����Ϊ115200
/*********������5******************************/    
    UTX0IF = 0;
}

void initial_t1()     //��ʱ��1����
{
/*������6��ʼ��128��Ƶ��������/������ģʽ���Ƚ�ֵT1CC0Ϊ62500,���������ж�*/   
    T1CC0L = 62500&0xFF;//��T1CC0L = 0X24; ���㶨ʱ0.25��250����//ʵ�ʶ�ʱ500����
    T1CC0H = ((62500&0xFF00)>>8);//��T1CC0H = 0XF4;     
    T1CTL |= 0X0F;    //������ʱ��1��128��Ƶ��������������ģʽ
//    TIMIF |= 0X40;    //ʹ���˶�ʱ��1������ж����� 
    EA = 1;            //ʹ�ܵ�Ƭ�����ж�
/*********������6����******************************/         
}

void uart_tx_string(char *data_tx, int len)
{
    unsigned int j;
    for(j=0;j<len;j++)
    {
        U0DBUF = *data_tx++;
        while(UTX0IF == 0);
        UTX0IF = 0;
    }  
}

#pragma vector = T1_VECTOR
__interrupt void TI_ISR(void)
{
    IRCON = 0X00;
    if(C_AN == 1)        //��ˮ�ƣ�ÿ��仯
    {
/*����7��ʼ������D4->D3->D6->D5��˳��,ÿ��1�����ε���һ����*/
        if(count_DSQ == 2)
        {
            D4 = 1;
            D3 = 0;
            D6 = 0;
            D5 = 0;
        }  
        if(count_DSQ == 4)
        {
            D4 = 0;
            D3 = 1;
            D6 = 0;
            D5 = 0;
        }
        if(count_DSQ == 6)
        {
            D4 = 0;
            D3 = 0;
            D6 = 1;
            D5 = 0;
        }
        if(count_DSQ == 8)
        {
            D4 = 0;
            D3 = 0;
            D6 = 0;
            D5 = 1;
            count_DSQ = 0;
        }
    }   
/************������7����***************/
    count_DSQ++;
    
    if(ZC_AN_2 == 1)    //0x0~0xf��ʾ��ÿ���1
    {
        if(count_DSQ == 2)
        {
            D4 = 0;
            D3 = 0;
            D6 = 0;
            D5 = 0;
        }  
        if(count_DSQ == 4)
        {
            D4 = 0;
            D3 = 0;
            D6 = 0;
            D5 = 1;
        }
        if(count_DSQ == 6)
        {
            D4 = 0;
            D3 = 0;
            D6 = 1;
            D5 = 0;
        }
        if(count_DSQ == 8)
        {
            D4 = 0;
            D3 = 0;
            D6 = 1;
            D5 = 1;
        }
        if(count_DSQ == 10)
        {
            D4 = 0;
            D3 = 1;
            D6 = 0;
            D5 = 0;
        }  
        if(count_DSQ == 12)
        {
            D4 = 0;
            D3 = 1;
            D6 = 0;
            D5 = 1;
        }
        if(count_DSQ == 14)
        {
            D4 = 0;
            D3 = 1;
            D6 = 1;
            D5 = 0;
        }
        if(count_DSQ == 16)
        {
            D4 = 0;
            D3 = 1;
            D6 = 1;
            D5 = 1;
        }
        if(count_DSQ == 18)
        {
            D4 = 1;
            D3 = 0;
            D6 = 0;
            D5 = 0;
        }  
        if(count_DSQ == 20)
        {
            D4 = 1;
            D3 = 0;
            D6 = 0;
            D5 = 1;
        }
        if(count_DSQ == 22)
        {
            D4 = 1;
            D3 = 0;
            D6 = 1;
            D5 = 0;
        }
        if(count_DSQ == 24)
        {
            D4 = 1;
            D3 = 0;
            D6 = 1;
            D5 = 1;
        }
        if(count_DSQ == 26)
        {
            D4 = 1;
            D3 = 1;
            D6 = 0;
            D5 = 0;
        }  
        if(count_DSQ == 28)
        {
            D4 = 1;
            D3 = 1;
            D6 = 0;
            D5 = 1;
        }
        if(count_DSQ == 30)
        {
            D4 = 1;
            D3 = 1;
            D6 = 1;
            D5 = 0;
        }
        if(count_DSQ == 32)
        {
            D4 = 1;
            D3 = 1;
            D6 = 1;
            D5 = 1;
            count_DSQ = 0;
        }
    }
  
}

void main(void)
{
    CLKCONCMD &= ~0X7F;        //0X80 ѡ����һ��32MHz��ʱ��Դ
    while(CLKCONSTA & 0X40);   //�ȴ������ȶ�
    initial_usart_tx();
    initial_t1();             //���ö�ʱ�����ú���
    initLed();
    while(1)
    {
      
        if(SW1 == 0)
        {
            delay(30);
            if(SW1 == 0)
            {
                D4 = 0;D3 = 0;D6 = 0;D5 = 0;  //Ϩ���
                T1IE = 1;                     //����ʱ��
                C_AN = 1;                     //���������ɿ���־
                ZC_AN_2 = 0;                  //������2�����־
                count_DSQ = 0;                //��ʱ����������0
                while(!SW1);                  //�ȴ�������
                T1IE = 0;                     //�����ɺ�ض�ʱ��
                count_DSQ = 0;                //��ʱ����������0
                C_AN = 0;                     //�����ɺ󳤰�����־��0
                count++;	              //��¼��������
                switch(count) 
                {
                    case 1: 
                      
                      /*������2��ʼ�����ڷ��͡�����LED�ƴ���΢��״̬����*/
                      uart_tx_string(data, sizeof(data));
                      D4 = 1;D3 = 1;D6 = 1;D5 = 1;
                      delay(1);
                      D4 = 0;D3 = 0;D6 = 0;D5 = 0;
                      delay(39);
                      break;
                      /***************������2����**********************/
                    case 2: 
                      /*������3��ʼ���������е�LED�Ʋ�����ʹ�ܶ�ʱ��1�жϣ�
                      ʹ��LED��ʵ��ÿ1���1��ʾ0x0~0xF��
                      �����ڷ��͡�����LED�ƴ�����ʾ����״̬����*/
                      D4 = 0;D3 = 0;D6 = 0;D5 = 0;
                      T1IE = 1;
                      ZC_AN_2 = 1;
                      uart_tx_string(data1, sizeof(data1));
                      break;
                      /********************������3����**********************/
                    default:
                      /*������4��ʼ����ֵ���㣬��ֹ��ʱ��1�жϣ�
                      ���ڷ��͡�����LED�ƴ���Ϩ��״̬����*/
//                      P1=0X00;
                      count=0;
                      T1IE = 0;
                      uart_tx_string(data2, sizeof(data2));
                      break; 
                      /************������4����**************/
                }
            }
        }
        if(count == 1)  //΢��
        {
            D4 = 1;
            D3 = 1;
            D6 = 1;
            D5 = 1;
            delay(1);
            D4 = 0;
            D3 = 0;
            D6 = 0;
            D5 = 0;
            delay(39);
        }        
    }  
}