
// ShutdownDlg.h : ͷ�ļ�
//

#pragma once
#include "afxdtctl.h"
#include "afxwin.h"


// CShutdownDlg �Ի���
class CShutdownDlg : public CDialog
{
// ����
public:
	CShutdownDlg(CWnd* pParent = NULL);	// ��׼���캯��
	BOOL WinShutDown(UINT uFags);

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

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
	afx_msg void OnBnClickedAbout();
	CDateTimeCtrl m_Timing;
	CEdit m_Second;
	CDateTimeCtrl m_CurrentDate;
//	CDateTimeCtrl m_CurrentTime;
//	afx_msg void OnDtnDatetimechangeTiming(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedxtiming();
	bool m_Bool;
	afx_msg void OnBnClickedxsecond();
	afx_msg void OnBnClickedStart();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CEdit m_CEdit;
//	afx_msg void OnDtnDatetimechangeTiming(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnEnChangeEdit();
	afx_msg void OnBnClickedTomorrow();
	CEdit m_BackTime;
	long m_LongTime;
	afx_msg void OnBnClickedCancel();
//	afx_msg void OnBnClickedHide();
	NOTIFYICONDATA m_ntIcon;
	CButton m_btnSet;
	bool m_TomorrowBool;
	afx_msg void OnBnClickedHide();
};
