
// GenerateSonDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GenerateSon.h"
#include "GenerateSonDlg.h"
#include "afxdialogex.h"
#include "StoreapiDLL.h"
#include "iostream"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
	
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGenerateSonDlg �Ի���



CGenerateSonDlg::CGenerateSonDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGenerateSonDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGenerateSonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGenerateSonDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BtGenerateSon, &CGenerateSonDlg::OnGenerateSon)
	ON_BN_CLICKED(IDC_BtOpenFile, &CGenerateSonDlg::OnOpenUpdatafile)
	ON_BN_CLICKED(IDC_BtDownloadCD, &CGenerateSonDlg::OnOpenISOFile)
END_MESSAGE_MAP()


// CGenerateSonDlg ��Ϣ�������

BOOL CGenerateSonDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CGenerateSonDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGenerateSonDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CGenerateSonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CGenerateSonDlg::OnOpenUpdatafile()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(TRUE, NULL,
		NULL,
		OFN_FILEMUSTEXIST | OFN_SHAREAWARE | OFN_PATHMUSTEXIST,
		TEXT("(*.RyArmUdp)|*.RyArmUdp|�����ļ�(*.*)|*.*|"),
		NULL);
	if (dlg.DoModal() == IDOK)
	{
		UpdataFilePath = dlg.GetPathName();
		SetDlgItemText(IDC_Edit_UpdataFile, UpdataFilePath);
	}
}


void CGenerateSonDlg::OnOpenISOFile()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(TRUE, NULL,
		NULL,
		OFN_FILEMUSTEXIST | OFN_SHAREAWARE | OFN_PATHMUSTEXIST,
		TEXT("(*.iso)|*.iso|�����ļ�(*.*)|*.*|"),
		NULL);
	if (dlg.DoModal() == IDOK)
	{
		ISOFilePath = dlg.GetPathName();
		SetDlgItemText(IDC_Edit_ISOFile, ISOFilePath);
	}
}


void CGenerateSonDlg::OnGenerateSon()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	SetDlgItemText(IDC_LabUpdata, _T("  "));
	SetDlgItemText(IDC_LabDownload, _T("  "));
	Sleep(300);
	if (InitSon())
	{
		SetDlgItemText(IDC_LabUpdata, _T("Updata Son clok success"));
	}
	else
	{
		SetDlgItemText(IDC_LabUpdata, _T("Updata Son clok Failure"));
	}
	if (GenerateCD())
	{
		SetDlgItemText(IDC_LabDownload, _T("Download ISO file finish"));
	}
	else
	{
		SetDlgItemText(IDC_LabDownload, _T("Download ISO file Failure"));
	}
}


BOOL CGenerateSonDlg::InitSon()
{
	DWORD dwRet = 1;
	int nCount = 0;
	char AdminPin[32] = "FFFFFFFFFFFFFFFF";
	int nRemainCount = 255;

	DONGLE_HANDLE hDongle = NULL;
	DONGLE_HANDLE m_hDongle = NULL;
	
	memset(Dongle_info, 0, 32 * sizeof(DONGLE_INFO));
	dwRet = Dongle_Enum(Dongle_info, &nCount);
//	printf("Enum %d Dongle ARM. \n", nCount);

	BYTE Request[32] = { 0 };
	BYTE InitData[1024] = { 0 };
	int InitDataLeng = 1024;

	for (int i = 0; i < nCount; i++)
	{
		if (Dongle_info[i].m_IsMother == 0x01)
		{
			dwRet = Dongle_Open(&m_hDongle, i);
		}
	}

	for (int j = 0; j < nCount; j++)
	{
		if (Dongle_info[j].m_PID == 0xFFFFFFFF && Dongle_info[j].m_IsMother != 0x01)
		{
			dwRet = Dongle_Open(&hDongle, j);
			dwRet = Dongle_VerifyPIN(hDongle, FLAG_ADMINPIN, AdminPin, &nRemainCount);
			dwRet = Dongle_RequestInit(hDongle, Request);
			dwRet = Dongle_GetInitDataFromMother(m_hDongle, Request, InitData, &InitDataLeng);
			dwRet = Dongle_InitSon(hDongle, InitData, InitDataLeng);
		}
	}
	dwRet = Dongle_Close(m_hDongle);	
	if (dwRet != 0)
		return FALSE;
	else
	{
		if (!DownloadPackage(hDongle, nCount))
			return FALSE;
	}
	return TRUE;
}


BOOL CGenerateSonDlg::DownloadPackage(DONGLE_HANDLE hDongle, int nCount)
{
	DWORD dwRet = 1;

	for (int k = 0; k < nCount; k++)
	{
		if (Dongle_info[k].m_IsMother != 0x01 && Dongle_info[k].m_PID == 0xFFFFFFFF)
		{
			dwRet = Dongle_Open(&hDongle, k);

			char strUpdata[20480] = { 0 };

			std::string strPath = CStringA(UpdataFilePath);
			const char* filePath = strPath.c_str();
			FILE* fp = NULL;
			fopen_s(&fp, filePath, "rb");
			fseek(fp, 0, SEEK_END);
			int file_size;
			file_size = ftell(fp);;
			fseek(fp, 0, SEEK_SET);
			fread(&strUpdata, 1, file_size, fp);
			fclose(fp);
			fp = NULL;

			int size = strlen(strUpdata);
			dwRet = Dongle_Update(hDongle, (BYTE*)strUpdata, file_size);
			Dongle_Close(hDongle);	
		}
	}
	if (dwRet != 0)
		return FALSE;
	else
		return TRUE;
}


BOOL CGenerateSonDlg::GenerateCD()
{
	char cPartLetters[48] = { 0 };

	int nTotalCnt = ST_GetDiskLetter(cPartLetters);
	if (nTotalCnt == ST_ERR_PARAMENTS)
	{
		AfxMessageBox(_T("parameter error!"));
		
	}
	if (nTotalCnt <= 0)
	{
		AfxMessageBox(_T("no equipment!"));
	}

	std::string strPath = CStringA(ISOFilePath);
	const char* filePath = strPath.c_str();
	CHAR szFilePath[MAX_PATH] = { 0 };
	memcpy(szFilePath, filePath, strlen(filePath));
	int ret = 0;
	int tmp = 0;
	for (int i = 0; i < nTotalCnt; i++)
	{
		g_PartLetters[0] = cPartLetters[tmp];
		ret = ST_DownladTOCDROM(szFilePath, g_PartLetters[0], this);
		tmp += 3;
	}
	if (ret != 2)
		return FALSE;
	else
		return TRUE;
}


