#include "math.h"
#include "string.h"
#include "stdlib.h"
#include "absacc.h"
#include "ftrx.h"

/************************************************
*ȫ�ֱ���:  ��������ʹ�õı���,��֧�ֶ���ʱ��ʼ��,�����������г�ʼ��.
************************************************/
//�������������
extern unsigned char InOutBuf[0x400];
//��չ������
extern unsigned char ExtendBuf[0x400];


/************************************************
*������:  �������. 
************************************************/
int main(void)
{	

	WORD wErrCode = 0;
	
	WORD dataLen = 128;
	WORD Len = 32;
	BYTE strOutput[32] = {0};

	
	wErrCode = rsa_pri(0x1111, InOutBuf, dataLen, strOutput,&Len, MODE_DECODE);
	
	wErrCode = rsa_pri(0x1111, strOutput, Len, InOutBuf, &dataLen, MODE_ENCODE);

	return wErrCode;
}
