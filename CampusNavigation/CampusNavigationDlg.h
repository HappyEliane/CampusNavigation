// CampusNavigationDlg.h : 头文件
//

#pragma once
#include "motioneffect.h"
#include "atltypes.h"
#include "MapImages.h"
#include "SkinH.h"
#include "afxwin.h"
#include "afxcmn.h"


// CCampusNavigationDlg 对话框
class CCampusNavigationDlg : public CDialog
{
// 构造
public:
	CCampusNavigationDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CAMPUSNAVIGATION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CMotionEffect m_mtneft;
	CPoint m_lastPoint;
	int m_sectionNum;
	afx_msg void OnBnClickedBlocksel();
	Check m_check;
	afx_msg void OnBnClickedRoadmark();
	int m_checkNum;
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton2();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
//	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	CMapImages m_mapImages;
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//afx_msg void OnBnClickedButton3();
//	afx_msg void OnBnClickedBuildingmark();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedBuildingmark();
	afx_msg void OnBnClickedDepartmark();
	afx_msg void OnBnClickedShoppingmark();
	MainPoints m_mainPoints;
	afx_msg void OnBnClickedShortestpath();
	void ShortestPath_FLOYD(MainPoints G, bool P[][32][32], int  D[][32]);
	
	CButton m_check2;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnTcnSelchangeTab3(NMHDR *pNMHDR, LRESULT *pResult);

	
/*	afx_msg void OnCbnSelchangeComboboxex2();*/
	
// 	CComboBoxEx m_begin;
// 	CComboBoxEx m_destination;
	CButton m_startlineto;
/*	CComboBoxEx m_search;*/
/*	afx_msg void OnCbnSelchangeComboboxex4();*/
	afx_msg void OnBnClickedButton1();
/*	CComboBoxEx m_location;*/
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton6();
	CButton m_butsearch;
	CButton m_butlocation;
/*	afx_msg void OnCbnSelchangeComboboxex1();*/
	CComboBox m_combbegin;
	CComboBox m_combdestion;
	CComboBox m_combcreat;
	CComboBox m_comblocation;
	afx_msg void OnCbnSelchangeCombo3();
	int nIndex1;
	int nIndex0;
	afx_msg void OnCbnSelchangeCombo4();
//	afx_msg void OnBnClickedCancel();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int idnum;
	int num;
	afx_msg void OnCbnSelchangeCombo6();
	afx_msg void OnBnClickedButton8();
	CButton m_clock;
	CButton m_roadmask;
	CButton m_building;
	CButton m_shopping;
	CButton m_department;
	CButton m_shortest;
	CButton m_normalsence;
	afx_msg void OnBnClickedButton9();
	//afx_msg void OnBnClickedButton3();
	CButton m_exitsence;
	CButton m_entersence;
	int nIndex2;
	afx_msg void OnCbnSelchangeCombo5();
	CButton m_showall;
	CButton m_clearall;
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	CComboBox m_combdepartment;
	afx_msg void OnCbnSelchangeCombo1();
	int nIndex3;
	
	int photonum;
	afx_msg void OnBnClickedButton12();
	void DepthFirst(ImagePoint *root);
	void DepthFirstR(ImagePoint* root);
	int m_deepphoto[70];
	
	int timernum;
	int deepimagenum;
	afx_msg void OnBnClickedButton13();
	CButton m_stopvisit;
	CButton m_beginvisit;
//	afx_msg void OnBnClickedOk();
	void DrawLineTo(POINT Startpoint,POINT EndPoint);
	afx_msg void OnBnClickedButton14();
	void ShowPoint(POINT Point);
	CButton m_wepass;
	afx_msg void OnBnClickedStopvisit();
	afx_msg void OnBnClickedEntersence();
//	afx_msg void OnBnClickedButton15();
};
