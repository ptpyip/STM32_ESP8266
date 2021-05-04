#ifndef __ESP8266_H_
#define __ESP8266_H_

#include "stm32f10x.h"

#define ESP8266_BUF_SIZE   128

#define ACK_SUCCESS   1
#define ACK_DEFEAT    0

typedef enum
{
  TCP,
  UDP
} Conn_Type;

#pragma pack(1)
typedef struct
{
  unsigned char* buf;
  u16 size;
  u16 front;
  u16 rear;
}ESP_BufTypeDef;

#pragma pack()

extern ESP_BufTypeDef ESP_RX_BUF;
extern ESP_BufTypeDef ESP_TX_BUF;

void ESP8266_Init(void);
u8   ESP8266_Send_Cmd(char *cmd, char *ack, u16 waittime);
u8   ESP8266_Send_Cmd2(char *cmd, char *ack, char *ack2, u16 waittime);
void ESP8266_Send_Data(u8 *data);

void ESP8266_Reset(void);
void ESP8266_Set_Echo_Off(void);
u8   ESP8266_Set_Stationmode(void);
u8   ESP8266_Set_APmode(char *ap_ssid, char *ap_pwd, char chl, char ecn);
u8   ESP8266_Connect_AP(const char *ssid, const char *passwd);
u8   ESP8266_Set_Link_Mux(u8 mode);
u8   ESP8266_Connect_TCP(const char *addr, const char *port);
u8   ESP8266_Connect_UDP(const char *addr, const char *port);
u8   ESP8266_Quit_Passthrough(void);
u8   ESP8266_Start_Passthrough(void);
u8   ESP8266_Passthrough_Request(Conn_Type type, const char *addr, char *port, void (*function)());

void Passthrough_Echo_Test(char *request);

void Buff_Init(ESP_BufTypeDef* buff, u16 size);
void Buff_Print(ESP_BufTypeDef* buff);
void Buff_PrintHex(ESP_BufTypeDef* buff);
void Buff_Print_All(ESP_BufTypeDef* buff);
void Buff_Push(ESP_BufTypeDef* buff, unsigned char byte);
unsigned char Buff_Pop(ESP_BufTypeDef* buff);


#endif