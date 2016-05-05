
// GenerateSonDlg.h : ͷ�ļ�
//

#pragma once
#include "Dongle_API.h"


// CGenerateSonDlg �Ի���
class CGenerateSonDlg : public CDialogEx
{
// ����
public:
	CGenerateSonDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GENERATESON_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString UpdataFilePath;
	CString ISOFilePath;

	afx_msg void OnGenerateSon();

	DONGLE_INFO Dongle_info[32];

	BOOL InitSon();
	BOOL DownloadPackage(DONGLE_HANDLE hDongle, int nCount);
	BOOL GenerateCD();

	afx_msg void OnOpenUpdatafile();
	afx_msg void OnOpenISOFile();
};
