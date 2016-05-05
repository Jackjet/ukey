/*********************************************************************************************
Module StoreAPIDLL.h
*********************************************************************************************/
#ifndef _STOREAPIDLL_H_
#define _STOREAPIDLL_H_
#ifndef STOREAPIDLL_EXPORTS
#define STOREAPIDLL_API __declspec(dllimport)
#else
#define STOREAPIDLL_API __declspec(dllexport)
#endif

/*********************************************************************************************
Define error code
*********************************************************************************************/
#define ST_ERR_PARAMENTS					-1	//��������
#define ST_ERR_FAILED						-2	//����ʧ��
#define ST_ERR_SUCCESS						1	//�ɹ�
#define ST_ERR_FILE_OPEN_FAILED				15	//�ļ��޷���
#define ST_ERR_MODE_NOT_SUPPORT				16	//��֧�ֵ�ģʽ
#define ST_ERR_OPENDISK_FAIL				17	//�޷��򿪴���
#define ST_ERR_HIDDENSIZE_OVER				18	//����������̫��

#define WM_READ_SUCCESS						WM_USER+601
#define WM_READ_FAIL						WM_USER+602
#define WM_WRITE_SUCCESS					WM_USER+603
#define WM_WRITE_FAIL						WM_USER+604
#define WM_DELETE_SUCCESS					WM_USER+605
#define WM_DELETE_FAIL						WM_USER+606
#define WM_WRITECD_SUCCESS					WM_USER+607
#define WM_WRITECD_FAIL						WM_USER+608
#define WM_OPENHANDLE_FAIL					WM_USER+609
#define WM_PROGRESS							WM_USER+610
#define WM_REMOVALREFRESHOK					WM_USER+611
/*********************************************************************************************
Include
*********************************************************************************************/
#include <stdio.h>
#include <Afxwin.h>
/*********************************************************************************************
Global variables declare
*********************************************************************************************/
CHAR g_PartLetters[3]={0};
/*********************************************************************************************
Function declare
*********************************************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////////
//int ST_GetDiskLetter
//˵��:��ȡ���뵱ǰPC�˵ĸ����������̷�
//������CHAR* PartLetters,���ػ�ȡ���ķ���,�����̷��Էֺ�����,ͬһ���ֺ������ڵ���
//������ͬһ��Ӳ���ϵķ���,�硰H;IJ������ʾH��IJ����������ͬ��Ӳ��
//����ֵ��-1��ʾ�����������������ҵ��Ŀ��ƶ���������
STOREAPIDLL_API int __stdcall ST_GetDiskLetter(CHAR*PartLetters);

//////////////////////////////////////////////////////////////////////////////////////////////
//int __stdcall ST_GetDiskCurrentState
//˵��:��ȡ����ָ��Ӳ���ķ���ģʽ�͸�������������
//������DWORD *dwTotalSize Ӳ��������,DWORD *dwPubSize U������, DWORD *dwSecSize����������
//������DWORD *dwCdromSize CDROM����,DWORD *dwHiddenSize ����������,
//������CHAR cDiskLetter ָ����Ӳ���̷�
//����ֵ��-1��ʾ�������������������ģʽ
STOREAPIDLL_API int __stdcall ST_GetDiskCurrentState	(DWORD *dwTotalSize,DWORD *dwPubSize,
					DWORD *dwCdromSize,DWORD *dwSecSize,DWORD *dwHiddenSize ,CHAR cDiskLetter);
//////////////////////////////////////////////////////////////////////////////////////////////
//int __stdcall ST_SetDiskCurrentState
//˵��:����ָ��ģʽ��ָ�������������·���
//������DWORD dwPubSize U������, DWORD dwSecSize����������,DWORD dwCdromSize CDROM����,DWORD dwHiddenSize ����������,
//������int nCurrentMode ָ���ķ���ģʽ,CHAR cDiskLetter ָ����Ӳ���̷�;HWND pWnd=NULL��
//������ָ�����ھ�������շ����Ľ����Ϣ������ΪNULL��������Ϊnull������֪����ʱ������ɣ�
//����ֵ��1��ʾ�ɹ���������������
STOREAPIDLL_API int __stdcall ST_SetDiskCurrentState(DWORD dwPubSize , DWORD dwCdromSize,
			DWORD dwSecSize,DWORD dwHiddenSize, int nCurrentMode,CHAR cDiskLetter,HWND pWnd=NULL);
//////////////////////////////////////////////////////////////////////////////////////////////
//BOOL __stdcall ST_WriteHidderArea
//˵��:��������д������
//������CHAR cDiskLetter ָ����Ӳ���̷�;DWORD dwOffsetLun,д���ݵ���ʼ������
//������DWORD dwLunCounts��Ҫд���������;BYTE *Buf,��д������
//����ֵ��1��ʾ�ɹ���0��ʾʧ��
STOREAPIDLL_API BOOL __stdcall ST_WriteHidderArea(CHAR cDiskLetter,DWORD dwOffsetLun,
																DWORD dwLunCounts,BYTE *Buf);
//////////////////////////////////////////////////////////////////////////////////////////////
//BOOL __stdcall ST_ReadHidderArea
//˵��:��ȡ����������
//������CHAR cDiskLetter ָ����Ӳ���̷�;DWORD dwOffsetLun,��ȡ���ݵ���ʼ������
//������DWORD dwLunCounts��Ҫ��ȡ��������;BYTE *Buf,�������ݵĻ�����
//����ֵ��1��ʾ�ɹ���0��ʾʧ��
STOREAPIDLL_API BOOL __stdcall ST_ReadHidderArea(CHAR cDiskLetter,DWORD dwOffsetLun,
													 DWORD dwLunCounts,BYTE *Buf);
//////////////////////////////////////////////////////////////////////////////////////////////
//int __stdcall ST_DownladTOCDROM
//˵��:��CDROM������ISO�ļ�
//������CHAR *FilePathName,ISO�ļ��ľ���;CHAR cDiskLetter ָ����Ӳ���̷�;CWnd* pWnd = NULL��
//������ָ�������࣬����ISO�Ľ����Ϣ������ΪNULL��������Ϊnull������֪����ʱ����ISO��ɣ�
//����ֵ��1��ʾ�ɹ���������������
STOREAPIDLL_API int __stdcall ST_DownladTOCDROM(CHAR *FilePathName, CHAR cDiskLetter,
																			CWnd* pWnd = NULL);
//////////////////////////////////////////////////////////////////////////////////////////////
//BOOL __stdcall ST_GetSerialNumber
//˵��:��ȡӲ�����к�
//������CHAR cDiskLetter ָ����Ӳ���̷�;CHAR *cSN,�������ݵĻ�����
//����ֵ��1��ʾ�ɹ���0��ʾʧ��
STOREAPIDLL_API BOOL __stdcall ST_GetSerialNumber(CHAR cDiskLetter,CHAR *cSN);
//////////////////////////////////////////////////////////////////////////////////////////////
//BOOL __stdcall ST_GetPidAndVid
//˵��:��ȡӲ��VID��PID
//������CHAR cDiskLetter ָ����Ӳ���̷�;WORD *wVID,VID;WORD *wPID,PID
//����ֵ��1��ʾ�ɹ���0��ʾʧ��
STOREAPIDLL_API BOOL __stdcall ST_GetPidAndVid(CHAR cDiskLetter,WORD *wVID , WORD *wPID);
#endif