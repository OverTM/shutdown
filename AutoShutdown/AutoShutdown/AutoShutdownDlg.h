
// AutoShutdownDlg.h : ͷ�ļ�
//
#include <Mmsystem.h.>

#pragma once


// CAutoShutdownDlg �Ի���
class CAutoShutdownDlg : public CDialogEx
{
// ����
public:
	CAutoShutdownDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_AUTOSHUTDOWN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	BOOL WinShutDown(UINT uFags);

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

	afx_msg void OnAbout();
	afx_msg void OnQuit();
	afx_msg void OnAuthor();
	afx_msg void OnStartup();
	afx_msg void OnUpdateStartup(CCmdUI *pCmdUI);
	afx_msg void OnSelecttiming();
	afx_msg void OnSelectminute();
	afx_msg void OnBnClickedStart();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedStop();
	afx_msg void OnMinidlg();
	afx_msg void OnShutdown();
	afx_msg void OnReboot();
	afx_msg void OnLogout();
	afx_msg void OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu);
	afx_msg void OnClock();
	afx_msg void OnUpdateClock(CCmdUI *pCmdUI);
	afx_msg void OnUpdateShutdown(CCmdUI *pCmdUI);
	afx_msg void OnUpdateReboot(CCmdUI *pCmdUI);
	afx_msg void OnUpdateLogout(CCmdUI *pCmdUI);
	afx_msg void OnUpdateStart(CCmdUI *pCmdUI);
	afx_msg void OnDestroy();
	afx_msg void OnTraydlg();
	afx_msg void OnClose();
	afx_msg void OnMainapp();
	afx_msg void OnFrontdlg();
	afx_msg void OnUpdateFrontdlg(CCmdUI *pCmdUI);
	afx_msg BOOL OnQueryEndSession();

	//�ؼ�����
	CEdit m_CountDown;
	CButton m_SelectTiming;
	CDateTimeCtrl m_TimingTime;
	CEdit m_TimingMinute;
	CEdit m_CurrentTime;
	CDateTimeCtrl m_TimingDate;
	CEdit m_CurrentDate;
	CMenu menu;
	CMenu *ntfMenu;
	CButton m_Custom;

	CRect rectLarge,rectSmall,rectSeparate;  //����������Ϣ��������С����Ϣ��
	NOTIFYICONDATA ntfId;  //����ͼ��ṹ��
	CString strTips;  //����ͼ����ʾ����ʾ
	LONGLONG m_LongTime;  //����ʱ����
	short m_Mode;  //����ָ��ʱ�䣬���е���Ӧģʽ
	HKEY hKey;
	MCI_OPEN_PARMS open;
	DWORD DeviceID;  //�����豸ID
	CString strSoundPath;  //�Զ�������·��

	bool m_bSelect;  //��־��ʱ��ʽ��ȷ��ʱ�䶨ʱ���ӳٶ�ʱ
	bool m_Status;  //�Ƿ�������ʱ
	bool m_bFront;  //�Ƿ���ǰ����ʾ
	bool m_bIsDlgNormal;  //�����Ƿ�������ʾ
	bool m_bIsSound;  //�Ƿ����ڲ�������
	bool m_bCustomSound;  //�Ƿ�ѡ���Զ�������
	bool m_bIsStartUp;  //�Ƿ��Զ��ػ�
};
