// MainDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AutoShutdown.h"
#include "MainDialog.h"
#include "afxdialogex.h"


// MainDialog �Ի���

IMPLEMENT_DYNAMIC(MainDialog, CDialog)

MainDialog::MainDialog(CWnd* pParent /*=NULL*/)
	: CDialog(MainDialog::IDD, pParent)
{

}

MainDialog::~MainDialog()
{
}

void MainDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MainDialog, CDialog)
END_MESSAGE_MAP()


// MainDialog ��Ϣ�������

