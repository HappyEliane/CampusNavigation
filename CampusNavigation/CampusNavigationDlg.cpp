// CampusNavigationDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CampusNavigation.h"
#include "CampusNavigationDlg.h"
#include "MotionEffect.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


bool p[32][32][32];
int  d[32][32];
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CCampusNavigationDlg 对话框




CCampusNavigationDlg::CCampusNavigationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCampusNavigationDlg::IDD, pParent)
	, m_lastPoint(0)
	, m_sectionNum(0)
	, m_checkNum(6)
	, nIndex1(0)
	, nIndex0(0)
	, idnum(0)
	, num(0)
	, nIndex2(0)
	, nIndex3(0)
	, photonum(0)
	, timernum(0)
	, deepimagenum(0)
{
	for (int j=0;j<70;j++)
	{
		m_deepphoto[j]=0;
	}
	
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_check.block=false;
	m_check.building=true;
	m_check.department=false;
	m_check.rood=true;
	m_check.shopping=false;
	m_check.magnified=false;
	m_check.infoshow=false;
	m_check.firstshow=true;
	m_check.wsad=false;

	m_check.normal=true;
	m_check.route=false;
	m_check.normalsence=false;
	m_check.search=false;

	m_check.combbegin=false;
	m_check.combend=false;
	m_check.clearall=false;
	m_check.showall=false;
	m_check.combsearch=false;
	m_check.combdepart=false;

	m_check.beginvisitsence=false;
	m_check.stopvisitsence=false;
	m_check.enternormal=false;
	m_check.exitnormal=false;

	m_mainPoints.vexnum=32;

	m_mainPoints.points[0].x=354;
	m_mainPoints.points[0].y=628;
	m_mainPoints.description[0]=CString("南门");

	m_mainPoints.points[1].x=287;
	m_mainPoints.points[1].y=416;
	m_mainPoints.description[1]=CString("H楼");

	m_mainPoints.points[2].x=354;
	m_mainPoints.points[2].y=597;
	m_mainPoints.description[2]=CString("宋健");

	m_mainPoints.points[3].x=355;
	m_mainPoints.points[3].y=586;
	m_mainPoints.description[3]=CString("节点0");

	m_mainPoints.points[4].x=287;
	m_mainPoints.points[4].y=563;
	m_mainPoints.description[4]=CString("节点1");

	m_mainPoints.points[5].x=287 ;
	m_mainPoints.points[5].y=449;
	m_mainPoints.description[5]=CString("节点2");

	m_mainPoints.points[6].x=262 ;
	m_mainPoints.points[6].y=449;
	m_mainPoints.description[6]=CString("G楼");

	m_mainPoints.points[7].x=234;
	m_mainPoints.points[7].y=449;
	m_mainPoints.description[7]=CString("节点7");

	m_mainPoints.points[8].x=205;	
	m_mainPoints.points[8].y=449;
	m_mainPoints.description[8]=CString("M楼");

	m_mainPoints.points[9].x=178 ;
	m_mainPoints.points[9].y=449;
	m_mainPoints.description[9]=CString("节点8");

	m_mainPoints.points[10].x=178;
	m_mainPoints.points[10].y=369;
	m_mainPoints.description[10]=CString("节点9");

	m_mainPoints.points[11].x=178;
	m_mainPoints.points[11].y=319;
	m_mainPoints.description[11]=CString("七公寓");

	m_mainPoints.points[12].x=178;
	m_mainPoints.points[12].y=297;
	m_mainPoints.description[12]=CString("节点10");

	m_mainPoints.points[13].x=178;
	m_mainPoints.points[13].y=286;
	m_mainPoints.description[13]=CString("节点11");

	m_mainPoints.points[14].x=178;
	m_mainPoints.points[14].y=245;
	m_mainPoints.description[14]=CString("八公寓");

	m_mainPoints.points[15].x=178;
	m_mainPoints.points[15].y=203;
	m_mainPoints.description[15]=CString("九公寓(学子)");   

	m_mainPoints.points[16].x=178;
	m_mainPoints.points[16].y=177;
	m_mainPoints.description[16]=CString("节点12");

	m_mainPoints.points[17].x=178;
	m_mainPoints.points[17].y=123;
	m_mainPoints.description[17]=CString("节点13");

	m_mainPoints.points[18].x=178;
	m_mainPoints.points[18].y=85;
	m_mainPoints.description[18]=CString("N楼正门");

	m_mainPoints.points[19].x=127;
	m_mainPoints.points[19].y=121;
	m_mainPoints.description[19]=CString("N楼南门");

	m_mainPoints.points[20].x=73;
	m_mainPoints.points[20].y=109;
	m_mainPoints.description[20]=CString("西北门");

	m_mainPoints.points[21].x=287;
	m_mainPoints.points[21].y=416;
	m_mainPoints.description[21]=CString("图书馆");

	m_mainPoints.points[22].x=233;
	m_mainPoints.points[22].y=413;
	m_mainPoints.description[22]=CString("B楼（语言文学院）");

	m_mainPoints.points[23].x=287;
	m_mainPoints.points[23].y=368;
	m_mainPoints.description[23]=CString("五公寓");

	m_mainPoints.points[24].x=258;
	m_mainPoints.points[24].y=314;
	m_mainPoints.description[24]=CString("学苑");

	m_mainPoints.points[25].x=233;
	m_mainPoints.points[25].y=369;
	m_mainPoints.description[25]=CString("节点15");

	m_mainPoints.points[26].x=236;
	m_mainPoints.points[26].y=306;
	m_mainPoints.description[26]=CString("三公寓");

	m_mainPoints.points[27].x=222;
	m_mainPoints.points[27].y=283;
	m_mainPoints.description[27]=CString("四公寓");

	m_mainPoints.points[28].x=178;
	m_mainPoints.points[28].y=343;
	m_mainPoints.description[28]=CString("二公寓");

	m_mainPoints.points[29].x=271;
	m_mainPoints.points[29].y=332;
	m_mainPoints.description[29]=CString("一公寓");

	m_mainPoints.points[30].x=178;
	m_mainPoints.points[30].y=214;
	m_mainPoints.description[30]=CString("六公寓");


	m_mainPoints.points[31].x=95;
	m_mainPoints.points[31].y=202;
	m_mainPoints.description[31]=CString("十公寓");



	for (int i=0;i<32;i++)
	{
		for (int j=0;j<32;j++)
		{
			m_mainPoints.arcs[i][j]=10000;
		}

	}

	
	m_mainPoints.arcs[0][2]=m_mainPoints.arcs[2][0]=106;


	m_mainPoints.arcs[2][3]=m_mainPoints.arcs[3][2]=21;

	m_mainPoints.arcs[3][4]=m_mainPoints.arcs[4][3]=128;

	m_mainPoints.arcs[4][5]=m_mainPoints.arcs[5][4]=190;

	m_mainPoints.arcs[5][6]=m_mainPoints.arcs[6][5]=5;
	m_mainPoints.arcs[5][21]=m_mainPoints.arcs[21][5]=60;


	m_mainPoints.arcs[6][7]=m_mainPoints.arcs[7][6]=43;

	m_mainPoints.arcs[7][8]=m_mainPoints.arcs[8][7]=45;
	m_mainPoints.arcs[7][22]=m_mainPoints.arcs[22][7]=55;

	m_mainPoints.arcs[8][9]=m_mainPoints.arcs[9][8]=55;

	m_mainPoints.arcs[9][10]=m_mainPoints.arcs[10][9]=139;

	m_mainPoints.arcs[10][28]=m_mainPoints.arcs[28][10]=40;
	m_mainPoints.arcs[10][25]=m_mainPoints.arcs[25][10]=90;

	m_mainPoints.arcs[11][12]=m_mainPoints.arcs[12][11]=175;
	m_mainPoints.arcs[11][28]=m_mainPoints.arcs[28][11]=43;

	m_mainPoints.arcs[12][13]=m_mainPoints.arcs[13][12]=42;
	m_mainPoints.arcs[12][27]=m_mainPoints.arcs[27][12]=78;

	m_mainPoints.arcs[13][14]=m_mainPoints.arcs[14][13]=30;


	m_mainPoints.arcs[14][30]=m_mainPoints.arcs[30][14]=47;

	m_mainPoints.arcs[15][16]=m_mainPoints.arcs[16][15]=42;
	m_mainPoints.arcs[15][30]=m_mainPoints.arcs[30][15]=57;

	m_mainPoints.arcs[16][17]=m_mainPoints.arcs[17][16]=88;
	m_mainPoints.arcs[16][31]=m_mainPoints.arcs[31][16]=167;


	m_mainPoints.arcs[17][18]=m_mainPoints.arcs[18][17]=64;
	m_mainPoints.arcs[17][19]=m_mainPoints.arcs[19][17]=90;

	m_mainPoints.arcs[19][20]=m_mainPoints.arcs[20][19]=96;

	m_mainPoints.arcs[21][22]=m_mainPoints.arcs[22][21]=95;
	m_mainPoints.arcs[21][23]=m_mainPoints.arcs[23][21]=75;


	m_mainPoints.arcs[22][25]=m_mainPoints.arcs[25][22]=70;

	m_mainPoints.arcs[23][25]=m_mainPoints.arcs[25][23]=92;
	m_mainPoints.arcs[23][29]=m_mainPoints.arcs[29][23]=85;


	m_mainPoints.arcs[24][29]=m_mainPoints.arcs[29][24]=27;
	m_mainPoints.arcs[24][26]=m_mainPoints.arcs[26][24]=42;


	m_mainPoints.arcs[26][27]=m_mainPoints.arcs[27][26]=36;


	

}

void CCampusNavigationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//	DDX_Control(pDX, IDC_COMBOBOXEX1, m_begin);
	//	DDX_Control(pDX, IDC_COMBOBOXEX2, m_destination);
	DDX_Control(pDX, IDC_BUTTON7, m_startlineto);
	// 	DDX_Control(pDX, IDC_COMBOBOXEX3, m_search);
	/*	DDX_Control(pDX, IDC_COMBOBOXEX4, m_location);*/
	DDX_Control(pDX, IDC_BUTTON6, m_butsearch);
	DDX_Control(pDX, IDC_BUTTON1, m_butlocation);
	DDX_Control(pDX, IDC_COMBO3, m_combbegin);
	DDX_Control(pDX, IDC_COMBO4, m_combdestion);
	DDX_Control(pDX, IDC_COMBO5, m_combcreat);
	//DDX_Control(pDX, IDC_COMBO6, m_comblocation);
	DDX_Control(pDX, IDC_BLOCKSEL, m_clock);
	DDX_Control(pDX, IDC_ROADMARK, m_roadmask);
	DDX_Control(pDX, IDC_BUILDINGMARK, m_building);
	DDX_Control(pDX, IDC_SHOPPINGMARK, m_shopping);
	DDX_Control(pDX, IDC_DEPARTMARK, m_department);
	DDX_Control(pDX, IDC_SHORTESTPATH, m_shortest);
	DDX_Control(pDX, IDC_BUTTON2, m_normalsence);
	DDX_Control(pDX, IDC_BUTTON9, m_exitsence);
	DDX_Control(pDX, IDC_BUTTON3, m_entersence);
	DDX_Control(pDX, IDC_BUTTON10, m_showall);
	DDX_Control(pDX, IDC_BUTTON11, m_clearall);
	DDX_Control(pDX, IDC_COMBO1, m_combdepartment);
	DDX_Control(pDX, IDC_BUTTON13, m_stopvisit);
	DDX_Control(pDX, IDC_BUTTON12, m_beginvisit);
	DDX_Control(pDX, IDC_BUTTON14, m_wepass);
}

BEGIN_MESSAGE_MAP(CCampusNavigationDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BLOCKSEL, &CCampusNavigationDlg::OnBnClickedBlocksel)
	ON_BN_CLICKED(IDC_ROADMARK, &CCampusNavigationDlg::OnBnClickedRoadmark)
	ON_BN_CLICKED(IDC_BUTTON2, &CCampusNavigationDlg::OnBnClickedButton2)
ON_WM_LBUTTONUP()
ON_WM_KEYDOWN()
//ON_BN_CLICKED(IDC_BUTTON3, &CCampusNavigationDlg::OnBnClickedButton3)
ON_WM_RBUTTONUP()
//ON_BN_CLICKED(IDC_BUILDINGNAME, &CCampusNavigationDlg::OnBnClickedBuildingname)
ON_BN_CLICKED(IDC_BUILDINGMARK, &CCampusNavigationDlg::OnBnClickedBuildingmark)
ON_BN_CLICKED(IDC_DEPARTMARK, &CCampusNavigationDlg::OnBnClickedDepartmark)
ON_BN_CLICKED(IDC_SHOPPINGMARK, &CCampusNavigationDlg::OnBnClickedShoppingmark)
ON_WM_SETCURSOR()
ON_BN_CLICKED(IDC_SHORTESTPATH, &CCampusNavigationDlg::OnBnClickedShortestpath)
ON_EN_CHANGE(IDC_EDIT1, &CCampusNavigationDlg::OnEnChangeEdit1)
//ON_NOTIFY(TCN_SELCHANGE, IDC_TAB3, &CCampusNavigationDlg::OnTcnSelchangeTab3)
//ON_CBN_SELCHANGE(IDC_COMBOBOXEX2, &CCampusNavigationDlg::OnCbnSelchangeComboboxex2)
/*ON_CBN_SELCHANGE(IDC_COMBOBOXEX4, &CCampusNavigationDlg::OnCbnSelchangeComboboxex4)*/
ON_BN_CLICKED(IDC_BUTTON1, &CCampusNavigationDlg::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON5, &CCampusNavigationDlg::OnBnClickedButton5)
ON_BN_CLICKED(IDC_BUTTON7, &CCampusNavigationDlg::OnBnClickedButton7)
ON_BN_CLICKED(IDC_BUTTON6, &CCampusNavigationDlg::OnBnClickedButton6)
// ON_CBN_SELCHANGE(IDC_COMBOBOXEX1, &CCampusNavigationDlg::OnCbnSelchangeComboboxex1)
ON_CBN_SELCHANGE(IDC_COMBO3, &CCampusNavigationDlg::OnCbnSelchangeCombo3)
ON_CBN_SELCHANGE(IDC_COMBO4, &CCampusNavigationDlg::OnCbnSelchangeCombo4)
//ON_BN_CLICKED(IDCANCEL, &CCampusNavigationDlg::OnBnClickedCancel)
ON_WM_TIMER()
/*ON_CBN_SELCHANGE(IDC_COMBO6, &CCampusNavigationDlg::OnCbnSelchangeCombo6)*/
ON_BN_CLICKED(IDC_BUTTON8, &CCampusNavigationDlg::OnBnClickedButton8)
ON_BN_CLICKED(IDC_BUTTON9, &CCampusNavigationDlg::OnBnClickedButton9)
//ON_BN_CLICKED(IDC_BUTTON3, &CCampusNavigationDlg::OnBnClickedButton3)
ON_CBN_SELCHANGE(IDC_COMBO5, &CCampusNavigationDlg::OnCbnSelchangeCombo5)
ON_BN_CLICKED(IDC_BUTTON10, &CCampusNavigationDlg::OnBnClickedButton10)
ON_BN_CLICKED(IDC_BUTTON11, &CCampusNavigationDlg::OnBnClickedButton11)
ON_CBN_SELCHANGE(IDC_COMBO1, &CCampusNavigationDlg::OnCbnSelchangeCombo1)
//ON_BN_CLICKED(IDC_BUTTON12, &CCampusNavigationDlg::OnBnClickedButton12)
ON_BN_CLICKED(IDC_BUTTON12, &CCampusNavigationDlg::OnBnClickedButton12)
//ON_BN_CLICKED(IDC_BUTTON13, &CCampusNavigationDlg::OnBnClickedButton13)
ON_BN_CLICKED(IDC_BUTTON14, &CCampusNavigationDlg::OnBnClickedButton14)
ON_BN_CLICKED(IDC_STOPVISIT, &CCampusNavigationDlg::OnBnClickedStopvisit)
ON_BN_CLICKED(IDC_ENTERSENCE, &CCampusNavigationDlg::OnBnClickedEntersence)
//ON_BN_CLICKED(IDC_BUTTON15, &CCampusNavigationDlg::OnBnClickedButton15)
END_MESSAGE_MAP()


// CCampusNavigationDlg 消息处理程序

BOOL CCampusNavigationDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//载入新皮肤
	SkinH_Attach();
	SkinH_AdjustHSV(60,0,0);//设置皮肤颜色


((CButton *)GetDlgItem(IDC_ROADMARK))->SetCheck(TRUE);
((CButton *)GetDlgItem(IDC_BUILDINGMARK))->SetCheck(TRUE);

//((CButton *)GetDlgItem(IDC_COMBO4))->SetCheck(FALSE);

 m_checkNum=6;

 m_combbegin.ShowWindow(SW_HIDE);
 m_combdestion.ShowWindow(SW_HIDE);
 m_startlineto.ShowWindow(SW_HIDE);
 //m_comblocation.ShowWindow(SW_HIDE);
 m_combcreat.ShowWindow(SW_HIDE);
 m_butlocation.ShowWindow(SW_HIDE);
 m_entersence.ShowWindow(SW_HIDE);
 m_exitsence.ShowWindow(SW_HIDE);
 m_showall.ShowWindow(SW_HIDE);
 m_clearall.ShowWindow(SW_HIDE);
 m_combdepartment.ShowWindow(SW_SHOW);
 m_clock.ShowWindow(SW_SHOW);
 m_building.ShowWindow(SW_SHOW);
 m_roadmask.ShowWindow(SW_SHOW);
 m_shopping.ShowWindow(SW_SHOW);
 m_department.ShowWindow(SW_SHOW);
 m_shortest.ShowWindow(SW_HIDE);
 m_butlocation.ShowWindow(SW_HIDE);
 GetDlgItem(IDC_STATIC3)->ShowWindow(SW_HIDE);
 GetDlgItem(IDC_STATIC4)->ShowWindow(SW_HIDE);
 m_beginvisit.ShowWindow(SW_HIDE);
 m_stopvisit.ShowWindow(SW_HIDE);
 m_wepass.ShowWindow(SW_HIDE);



   SetTimer(1,5000,NULL);

  // 路线
       CRect rect;
       GetDlgItem(IDC_COMBO3)->GetWindowRect(&rect);
       GetDlgItem(IDC_COMBO3)->MoveWindow(640,145,rect.Width(),rect.Height(),1);
       GetDlgItem(IDC_COMBO4)->GetWindowRect(&rect);
       GetDlgItem(IDC_COMBO4)->MoveWindow(640,195,rect.Width(),rect.Height(),1);
       GetDlgItem(IDC_BUTTON14)->GetWindowRect(&rect);
       GetDlgItem(IDC_BUTTON14)->MoveWindow(800,100,rect.Width(),rect.Height(),1);
       GetDlgItem(IDC_BUTTON7)->GetWindowRect(&rect);
       GetDlgItem(IDC_BUTTON7)->MoveWindow(800,200,rect.Width(),rect.Height(),1);
       GetDlgItem(IDC_SHORTESTPATH)->GetWindowRect(&rect);
       GetDlgItem(IDC_SHORTESTPATH)->MoveWindow(800,300,rect.Width(),rect.Height(),1);
       GetDlgItem(IDC_STATIC3)->GetWindowRect(&rect);
       GetDlgItem(IDC_STATIC3)->MoveWindow(600,150,rect.Width(),rect.Height(),1);
       GetDlgItem(IDC_STATIC4)->GetWindowRect(&rect);
       GetDlgItem(IDC_STATIC4)->MoveWindow(600,200,rect.Width(),rect.Height(),1);
    
    //常规
       GetDlgItem(IDC_BLOCKSEL)->GetWindowRect(&rect);
       GetDlgItem(IDC_BLOCKSEL)->MoveWindow(640,100,rect.Width(),rect.Height(),1);
       GetDlgItem(IDC_ROADMARK)->GetWindowRect(&rect);
       GetDlgItem(IDC_ROADMARK)->MoveWindow(640,150,rect.Width(),rect.Height(),1);
       GetDlgItem(IDC_BUILDINGMARK)->GetWindowRect(&rect);
       GetDlgItem(IDC_BUILDINGMARK)->MoveWindow(640,200,rect.Width(),rect.Height(),1);
       GetDlgItem(IDC_DEPARTMARK)->GetWindowRect(&rect);
       GetDlgItem(IDC_DEPARTMARK)->MoveWindow(800,150,rect.Width(),rect.Height(),1);
       GetDlgItem(IDC_SHOPPINGMARK)->GetWindowRect(&rect);
       GetDlgItem(IDC_SHOPPINGMARK)->MoveWindow(800,100,rect.Width(),rect.Height(),1);
       GetDlgItem(IDC_COMBO1)->GetWindowRect(&rect);
       GetDlgItem(IDC_COMBO1)->MoveWindow(800,200,rect.Width(),rect.Height(),1);
       
    //实景模式
    
       GetDlgItem(IDC_ENTERSENCE)->GetWindowRect(&rect);
       GetDlgItem(IDC_ENTERSENCE)->MoveWindow(640,100,rect.Width(),rect.Height(),1);
       GetDlgItem(IDC_BUTTON9)->GetWindowRect(&rect);
       GetDlgItem(IDC_BUTTON9)->MoveWindow(800,100,rect.Width(),rect.Height(),1);
       GetDlgItem(IDC_BUTTON12)->GetWindowRect(&rect);
       GetDlgItem(IDC_BUTTON12)->MoveWindow(640,200,rect.Width(),rect.Height(),1);
       GetDlgItem(IDC_STOPVISIT)->GetWindowRect(&rect);
       GetDlgItem(IDC_STOPVISIT)->MoveWindow(800,200,rect.Width(),rect.Height(),1);
    

   //查找
       GetDlgItem(IDC_COMBO5)->GetWindowRect(&rect);
       GetDlgItem(IDC_COMBO5)->MoveWindow(640,100,rect.Width(),rect.Height(),1);
       GetDlgItem(IDC_BUTTON1)->GetWindowRect(&rect);
       GetDlgItem(IDC_BUTTON1)->MoveWindow(800,100,rect.Width(),rect.Height(),1);
       GetDlgItem(IDC_BUTTON10)->GetWindowRect(&rect);
       GetDlgItem(IDC_BUTTON10)->MoveWindow(640,200,rect.Width(),rect.Height(),1);
       GetDlgItem(IDC_BUTTON11)->GetWindowRect(&rect);
       GetDlgItem(IDC_BUTTON11)->MoveWindow(800,200,rect.Width(),rect.Height(),1);

 


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCampusNavigationDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCampusNavigationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		if (m_check.firstshow)
		{
			CDC *dc,dcMem;
			dc=GetDC();
			m_mtneft.GetDC(dc);
			m_mtneft.Appear(IDB_BUILDING2);
			m_check.firstshow=false;

			CBitmap card1;
			dcMem.CreateCompatibleDC(dc);
			card1.LoadBitmap(IDB_BITMAP28);
			dcMem.SelectObject(&card1);
			dc->BitBlt(585,380,368,360,&dcMem,0,0,SRCCOPY);
			DeleteObject(&card1);
															
			CDialog::OnPaint();
		}
		else
		{
			CDC *dc;
			dc=GetDC();
// 			
			m_mtneft.GetDC(dc);
			m_mtneft.Replace(IDB_BUILDING2);
			
			
			

			CDialog::OnPaint();

		}
		
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCampusNavigationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCampusNavigationDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString temp,t;
	temp.Format(_T("%d"),point.x);
	t.Format(_T("%d"),point.y);
	MessageBox(temp+_T(" ")+t);
	CDialog::OnLButtonDblClk(nFlags, point);
}

void CCampusNavigationDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	 if (m_checkNum%2==1 && !m_check.magnified&&m_check.normal)
	 {

		 if (point.x<=323 && point.y<=291)
		 {
			 if (m_sectionNum==3)
			 {
				 return;
			 }
			 m_sectionNum=3;
			 CDC *dc;
			 dc=GetDC();
			 m_mtneft.GetDC(dc);
			 m_mtneft.Replace(IDB_S3SELECTED);
		 }
		 if (point.x>=25 && point.y>387 && point.x<=305 && point.y<=654)
		 {
			 if (m_sectionNum==2)
			 {
				 return;
			 }
			 m_sectionNum=2;
			 CDC *dc;
			 dc=GetDC();
			 m_mtneft.GetDC(dc);
			 m_mtneft.Replace(IDB_S2SELECTED);
		 }
		 if (point.x>=322 && point.y>=293 && point.x<=563 && point.y<=664)
		 {  
			 if (m_sectionNum==1)
			 {
				 return;
			 }
			 m_sectionNum=1;
			 CDC *dc;
			 dc=GetDC();
			 m_mtneft.GetDC(dc);
			 m_mtneft.Replace(IDB_S1SELECTED);
			 
		 }
	}
	 if ((!m_check.department)&&(m_check.magnified==false)&&(m_checkNum%2!=1)&&(!m_check.normalsence)&&(!m_check.route)&&(!m_check.search))
	{
	
		if (point.x<162&&point.x>121&&point.y>71&&point.y<162)
		 {
	      
			 m_check.infoshow=true;
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			CDC *dc,dcMem;
			dc=GetDC();
			CBitmap figure1,figure2,scene,*OldBitMap;                     //创建位图对象。
			dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表

			figure1.LoadBitmap(IDB_ZUOSHANG);
			figure2.LoadBitmap(IDB_BUILDING_N);
			OldBitMap=dcMem.SelectObject(&figure1);    
			dc->BitBlt(130,70,539,511,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
			dcMem.SelectObject(&figure2);    
			dc->BitBlt(130,70,539,511,&dcMem,0,0,SRCPAINT);//再与图片2做or运算
			DeleteObject(figure2);
			DeleteObject(figure1);
			dcMem.DeleteDC();
			
		 

		 }
		 else if (point.x<128&&point.x>70&&point.y>180&&point.y<195)
		 {
			 m_check.infoshow=true;
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			CDC *dc,dcMem;
			dc=GetDC();
			CBitmap figure1,figure2,scene,*OldBitMap;                     //创建位图对象。
			dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表

			figure1.LoadBitmap(IDB_ZUOSHANG);
			figure2.LoadBitmap(IDB_DEPARTMENT10);
			OldBitMap=dcMem.SelectObject(&figure1);    
			dc->BitBlt(85,190,539,511,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
			dcMem.SelectObject(&figure2);    
			dc->BitBlt(85,190,539,511,&dcMem,0,0,SRCPAINT);//再与图片2做or运算
			DeleteObject(figure2);
			DeleteObject(figure1);
			dcMem.DeleteDC();
			

			 //SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));

		 }
		else if (point.x<177&&point.x>120&&point.y>203&&point.y<214)
		{

			m_check.infoshow=true;
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			CDC *dc,dcMem;
			dc=GetDC();
			CBitmap figure1,figure2,scene,*OldBitMap;                     //创建位图对象。
			dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表

			figure1.LoadBitmap(IDB_ZUOSHANG);
			figure2.LoadBitmap(IDB_DEPARTMENT9);
			OldBitMap=dcMem.SelectObject(&figure1);    
			dc->BitBlt(130,205,539,511,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
			dcMem.SelectObject(&figure2);    
			dc->BitBlt(120,205,539,511,&dcMem,0,0,SRCPAINT);//再与图片2做or运算
			DeleteObject(figure2);
			DeleteObject(figure1);
			dcMem.DeleteDC();
			
		}
		else if (point.x<172&&point.x>121&&point.y>231&&point.y<241)
		{

			m_check.infoshow=true;
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			CDC *dc,dcMem;
			dc=GetDC();
			CBitmap figure1,figure2,scene,*OldBitMap;                     //创建位图对象。
			dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表

			figure1.LoadBitmap(IDB_ZUOSHANG);
			figure2.LoadBitmap(IDB_DEPARTMENT8);
			OldBitMap=dcMem.SelectObject(&figure1);    
			dc->BitBlt(130,235,539,511,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
			dcMem.SelectObject(&figure2);    
			dc->BitBlt(120,235,539,511,&dcMem,0,0,SRCPAINT);//再与图片2做or运算
			DeleteObject(figure2);
			DeleteObject(figure1);
			dcMem.DeleteDC();

		}
		else if (point.x<156&&point.x>102&&point.y>320&&point.y<333)
		{

			m_check.infoshow=true;
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			CDC *dc,dcMem;
			dc=GetDC();
			CBitmap figure1,figure2,scene,*OldBitMap;                     //创建位图对象。
			dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表

			figure1.LoadBitmap(IDB_ZUOSHANG);
			figure2.LoadBitmap(IDB_DEPARTMENT7);
			OldBitMap=dcMem.SelectObject(&figure1);    
			dc->BitBlt(110,325,539,511,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
			dcMem.SelectObject(&figure2);    
			dc->BitBlt(110,325,539,511,&dcMem,0,0,SRCPAINT);//再与图片2做or运算
			DeleteObject(figure2);
			DeleteObject(figure1);
			dcMem.DeleteDC();


		}
		else if (point.x<249&&point.x>193&&point.y>223&&point.y<234)
		{

			m_check.infoshow=true;
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			CDC *dc,dcMem;
			dc=GetDC();
			CBitmap figure1,figure2,scene,*OldBitMap;                     //创建位图对象。
			dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表

			figure1.LoadBitmap(IDB_ZUOSHANG);
			figure2.LoadBitmap(IDB_DEPARTMENT6);
			OldBitMap=dcMem.SelectObject(&figure1);    
			dc->BitBlt(200,225,539,511,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
			dcMem.SelectObject(&figure2);    
			dc->BitBlt(200,225,539,511,&dcMem,0,0,SRCPAINT);//再与图片2做or运算
			DeleteObject(figure2);
			DeleteObject(figure1);
			dcMem.DeleteDC();

		}
		
		else if (point.x<230&&point.x>182&&point.y>273&&point.y<283)
		{

			m_check.infoshow=true;
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			CDC *dc,dcMem;
			dc=GetDC();
			CBitmap figure1,figure2,scene,*OldBitMap;                     //创建位图对象。
			dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表

			figure1.LoadBitmap(IDB_ZUOSHANG);
			figure2.LoadBitmap(IDB_DEPARTMENT4);
			OldBitMap=dcMem.SelectObject(&figure1);    
			dc->BitBlt(190,275,539,511,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
			dcMem.SelectObject(&figure2);    
			dc->BitBlt(190,275,539,511,&dcMem,0,0,SRCPAINT);//再与图片2做or运算
			DeleteObject(figure2);
			DeleteObject(figure1);
			dcMem.DeleteDC();

		}
		else if (point.x<302&&point.x>239&&point.y>283&&point.y<297)
		{
			

			m_check.infoshow=true;
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			CDC *dc,dcMem;
			dc=GetDC();
			CBitmap figure1,figure2,scene,*OldBitMap;                     //创建位图对象。
			dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表

			figure1.LoadBitmap(IDB_ZUOSHANG);
			figure2.LoadBitmap(IDB_XUEYUAN);
			OldBitMap=dcMem.SelectObject(&figure1);    
			dc->BitBlt(240,290,539,511,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
			dcMem.SelectObject(&figure2);    
			dc->BitBlt(240,290,539,511,&dcMem,0,0,SRCPAINT);//再与图片2做or运算
			DeleteObject(figure2);
			DeleteObject(figure1);
			dcMem.DeleteDC();

		}
		
		else if (point.x<231&&point.x>183&&point.y>302&&point.y<312)
		{

			m_check.infoshow=true;
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			CDC *dc,dcMem;
			dc=GetDC();
			CBitmap figure1,figure2,scene,*OldBitMap;                     //创建位图对象。
			dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表

			figure1.LoadBitmap(IDB_ZUOXIA);
			figure2.LoadBitmap(IDB_DEPARTMENT3);
			OldBitMap=dcMem.SelectObject(&figure1);    
			dc->BitBlt(190,35,539,511,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
			dcMem.SelectObject(&figure2);    
			dc->BitBlt(190,35,539,511,&dcMem,0,0,SRCPAINT);//再与图片2做or运算
			DeleteObject(figure2);
			DeleteObject(figure1);
			dcMem.DeleteDC();

		
		}
		else if (point.x<276&&point.x>228&&point.y>326&&point.y<335)
		{

			m_check.infoshow=true;
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			CDC *dc,dcMem;
			dc=GetDC();
			CBitmap figure1,figure2,scene,*OldBitMap;                     //创建位图对象。
			dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表

			figure1.LoadBitmap(IDB_ZUOSHANG);
			figure2.LoadBitmap(IDB_DEPARTMENT1);
			OldBitMap=dcMem.SelectObject(&figure1);    
			dc->BitBlt(235,325,539,511,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
			dcMem.SelectObject(&figure2);    
			dc->BitBlt(235,325,539,511,&dcMem,0,0,SRCPAINT);//再与图片2做or运算
			DeleteObject(figure2);
			DeleteObject(figure1);
			dcMem.DeleteDC();

		}
		else if (point.x<225&&point.x>176&&point.y>335&&point.y<350)
		{

			m_check.infoshow=true;
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			CDC *dc,dcMem;
			dc=GetDC();
			CBitmap figure1,figure2,scene,*OldBitMap;                     //创建位图对象。
			dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表

			figure1.LoadBitmap(IDB_ZUOSHANG);
			figure2.LoadBitmap(IDB_DEPARTMENT2);
			OldBitMap=dcMem.SelectObject(&figure1);    
			dc->BitBlt(185,335,539,511,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
			dcMem.SelectObject(&figure2);    
			dc->BitBlt(185,335,539,511,&dcMem,0,0,SRCPAINT);//再与图片2做or运算
			DeleteObject(figure2);
			DeleteObject(figure1);
			dcMem.DeleteDC();

		}
		else if (point.x<290&&point.x>236&&point.y>351&&point.y<362)
		{

			m_check.infoshow=true;
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			CDC *dc,dcMem;
			dc=GetDC();
			CBitmap figure1,figure2,scene,*OldBitMap;                     //创建位图对象。
			dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表

			figure1.LoadBitmap(IDB_ZUOSHANG);
			figure2.LoadBitmap(IDB_DEPARTMENT5);
			OldBitMap=dcMem.SelectObject(&figure1);    
			dc->BitBlt(235,350,539,511,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
			dcMem.SelectObject(&figure2);    
			dc->BitBlt(230,345,539,511,&dcMem,0,0,SRCPAINT);//再与图片2做or运算
			DeleteObject(figure2);
			DeleteObject(figure1);
			dcMem.DeleteDC();

		}
		else if (point.x<276&&point.x>245&&point.y>380&&point.y<395)
		{

			m_check.infoshow=true;
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			CDC *dc,dcMem;
			dc=GetDC();
			CBitmap figure1,figure2,scene,*OldBitMap;                     //创建位图对象。
			dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表

			figure1.LoadBitmap(IDB_ZUOXIA);
			figure2.LoadBitmap(IDB_BUILDING_B);
			OldBitMap=dcMem.SelectObject(&figure1);    
			dc->BitBlt(245,120,539,511,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
			dcMem.SelectObject(&figure2);    
			dc->BitBlt(245,120,539,511,&dcMem,0,0,SRCPAINT);//再与图片2做or运算
			DeleteObject(figure2);
			DeleteObject(figure1);
			dcMem.DeleteDC();

		}
		else if (point.x<226&&point.x>186&&point.y>417&&point.y<425)
		{

			m_check.infoshow=true;
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			CDC *dc,dcMem;
			dc=GetDC();
			CBitmap figure1,figure2,scene,*OldBitMap;                     //创建位图对象。
			dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表

			figure1.LoadBitmap(IDB_ZUOXIA);
			figure2.LoadBitmap(IDB_BUILDING_M);
			OldBitMap=dcMem.SelectObject(&figure1);    
			dc->BitBlt(195,140,539,511,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
			dcMem.SelectObject(&figure2);    
			dc->BitBlt(195,140,539,511,&dcMem,0,0,SRCPAINT);//再与图片2做or运算
			DeleteObject(figure2);
			DeleteObject(figure1);
			dcMem.DeleteDC();

		}
		else if (point.x<280&&point.x>244&&point.y>416&&point.y<425)
		{
            m_check.infoshow=true;
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			CDC *dc,dcMem;
			dc=GetDC();
			CBitmap figure1,figure2,scene,*OldBitMap;                     //创建位图对象。
			dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表

			figure1.LoadBitmap(IDB_ZUOXIA);
			figure2.LoadBitmap(IDB_BUILDING_G);
			OldBitMap=dcMem.SelectObject(&figure1);    
			dc->BitBlt(248,148,539,511,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
			dcMem.SelectObject(&figure2);    
			dc->BitBlt(248,148,539,511,&dcMem,0,0,SRCPAINT);//再与图片2做or运算
			DeleteObject(figure2);
			DeleteObject(figure1);
			dcMem.DeleteDC();
			

			//SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));

		}
		else if (point.x<362&&point.x>326&&point.y>391&&point.y<405)
		{
			m_check.infoshow=true;
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			CDC *dc,dcMem;
			dc=GetDC();
			CBitmap figure1,figure2,scene,*OldBitMap;                     //创建位图对象。
			dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表

			figure1.LoadBitmap(IDB_YOUXIA);
			figure2.LoadBitmap(IDB_BUILDING_H);
			OldBitMap=dcMem.SelectObject(&figure1);    
			dc->BitBlt(70,145,539,511,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
			dcMem.SelectObject(&figure2);    
			dc->BitBlt(70,145,539,511,&dcMem,0,0,SRCPAINT);//再与图片2做or运算
			DeleteObject(figure2);
			DeleteObject(figure1);
			dcMem.DeleteDC();


		}
		else if (point.x<116&&point.x>104&&point.y>434&&point.y<445)
		{

			m_check.infoshow=true;
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			CDC *dc,dcMem;
			dc=GetDC();
			CBitmap figure1,figure2,scene,*OldBitMap;                     //创建位图对象。
			dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表

			figure1.LoadBitmap(IDB_ZUOXIA);
			figure2.LoadBitmap(IDB_TBUILDING_A);
			OldBitMap=dcMem.SelectObject(&figure1);    
			dc->BitBlt(100,175,539,511,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
			dcMem.SelectObject(&figure2);    
			dc->BitBlt(100,175,539,511,&dcMem,0,0,SRCPAINT);//再与图片2做or运算
			DeleteObject(figure2);
			DeleteObject(figure1);
			dcMem.DeleteDC();

		}
		else if (point.x<180&&point.x>68&&point.y>452&&point.y<461)
		{

			m_check.infoshow=true;
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			CDC *dc,dcMem;
			dc=GetDC();
			CBitmap figure1,figure2,scene,*OldBitMap;                     //创建位图对象。
			dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表

			figure1.LoadBitmap(IDB_ZUOXIA);
			figure2.LoadBitmap(IDB_TBUILDING_B);
			OldBitMap=dcMem.SelectObject(&figure1);    
			dc->BitBlt(70,180,539,511,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
			dcMem.SelectObject(&figure2);    
			dc->BitBlt(70,180,539,511,&dcMem,0,0,SRCPAINT);//再与图片2做or运算
			DeleteObject(figure2);
			DeleteObject(figure1);
			dcMem.DeleteDC();

		}
		
		               
		else if (point.x<489&&point.x>406&&point.y>587&&point.y<597)
		{

			m_check.infoshow=true;
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			CDC *dc,dcMem;
			dc=GetDC();
			CBitmap figure1,figure2,scene,*OldBitMap;                     //创建位图对象。
			dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表

			figure1.LoadBitmap(IDB_YOUXIA);
			figure2.LoadBitmap(IDB_SONGJIAN);
			OldBitMap=dcMem.SelectObject(&figure1);    
			dc->BitBlt(160,345,539,511,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
			dcMem.SelectObject(&figure2);    
			dc->BitBlt(160,345,539,511,&dcMem,0,0,SRCPAINT);//再与图片2做or运算
			DeleteObject(figure2);
			DeleteObject(figure1);
			dcMem.DeleteDC();


		}
		else if (point.x<499&&point.x>480&&point.y>587&&point.y<642)
		{//工商银行

			/*m_check.infoshow=true;
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			CDC *dc,dcMem;
			dc=GetDC();
			CBitmap figure1,figure2,scene,*OldBitMap;                     //创建位图对象。
			dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表

			figure1.LoadBitmap(IDB_ZUOSHANG);
			figure2.LoadBitmap(IDB_DEPARTMENT6);
			OldBitMap=dcMem.SelectObject(&figure1);    
			dc->BitBlt(200,225,539,511,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
			dcMem.SelectObject(&figure2);    
			dc->BitBlt(200,225,539,511,&dcMem,0,0,SRCPAINT);//再与图片2做or运算
			DeleteObject(figure2);
			DeleteObject(figure1);
			dcMem.DeleteDC();*/

		}
		else if (point.x<406&&point.x>296&&point.y>296&&point.y<374)
		{//情人坡

			/*m_check.infoshow=true;
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			CDC *dc,dcMem;
			dc=GetDC();
			CBitmap figure1,figure2,scene,*OldBitMap;                     //创建位图对象。
			dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表

			figure1.LoadBitmap(IDB_ZUOSHANG);
			figure2.LoadBitmap(IDB_DEPARTMENT6);
			OldBitMap=dcMem.SelectObject(&figure1);    
			dc->BitBlt(200,225,539,511,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
			dcMem.SelectObject(&figure2);    
			dc->BitBlt(200,225,539,511,&dcMem,0,0,SRCPAINT);//再与图片2做or运算
			DeleteObject(figure2);
			DeleteObject(figure1);
			dcMem.DeleteDC();*/


		}
		else if (point.x<233&&point.x>189&&point.y>183&&point.y<213)
		{

			m_check.infoshow=true;
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			CDC *dc,dcMem;
			dc=GetDC();
			CBitmap figure1,figure2,scene,*OldBitMap;                     //创建位图对象。
			dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表

			figure1.LoadBitmap(IDB_ZUOSHANG);
			figure2.LoadBitmap(IDB_XUEZI);
			OldBitMap=dcMem.SelectObject(&figure1);    
			dc->BitBlt(185,195,539,511,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
			dcMem.SelectObject(&figure2);    
			dc->BitBlt(180,195,539,511,&dcMem,0,0,SRCPAINT);//再与图片2做or运算
			DeleteObject(figure2);
			DeleteObject(figure1);
			dcMem.DeleteDC();

		}
		else if (m_check.infoshow)
		{
			m_check.infoshow=false;
			CDC *dc;
			dc=GetDC();
			m_mtneft.GetDC(dc);
			switch (m_checkNum)
			{
			case 0:
				m_mtneft.Replace(IDB_BUILDING2);
				break;

				break;
			case 2:

				m_mtneft.Replace(IDB_MROADMARK);
				break;

			case 4:
				m_mtneft.Replace(IDB_BUILDING1);
				break;
			case 6:

				m_mtneft.Replace(IDB_BUILDING2);
				break;
			case 16:
				m_mtneft.Replace(IDB_SHOPPING1);
				break;
			case 18:
				m_mtneft.Replace(IDB_SHOPPING2);
				break;


			};

		}


	}

	CDialog::OnMouseMove(nFlags, point);
}

void CCampusNavigationDlg::OnBnClickedBlocksel()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!m_check.block)
	{
		m_checkNum+=1;
		m_check.block=true;
		GetDlgItem(IDC_ROADMARK)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUILDINGMARK)->EnableWindow(FALSE);
		GetDlgItem(IDC_DEPARTMARK)->EnableWindow(FALSE);
		GetDlgItem(IDC_SHOPPINGMARK)->EnableWindow(FALSE);
		CDC *dc;
		dc=GetDC();
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_MMAIN);
	}
	else
	{
		m_checkNum-=1;
		m_check.block=false;
		GetDlgItem(IDC_ROADMARK)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUILDINGMARK)->EnableWindow(TRUE);
		GetDlgItem(IDC_DEPARTMARK)->EnableWindow(TRUE);
		GetDlgItem(IDC_SHOPPINGMARK)->EnableWindow(TRUE);
		CDC *dc;
		switch(m_checkNum)
		{
		case 0:
			m_mtneft.Replace(IDB_MMAIN);
			break;
		case 2:
			m_mtneft.Replace(IDB_MROADMARK);
			break;
		case 4:
			m_mtneft.Replace(IDB_BUILDING1);
			break;
		case 6:
			m_mtneft.Replace(IDB_BUILDING2);
			break;
		}


	}
}
void CCampusNavigationDlg::OnBnClickedRoadmark()
{
	// TODO: 在此添加控件通知处理程序代码

	if (!m_check.rood)
	{
		m_checkNum+=2;
		m_check.rood=true;
		switch (m_checkNum)
		{
		case 2:
			m_mtneft.Replace(IDB_MROADMARK);
			break;
		case 6:
			m_mtneft.Replace(IDB_BUILDING2);
			break;
 		case 18:
 			m_mtneft.Replace(IDB_SHOPPING2);
 			break;


		}
		
	}
	else
	{
		m_check.rood=false;
		m_checkNum-=2;
		
		switch (m_checkNum)
		{
		case 0:
			m_mtneft.Replace(IDB_MMAIN);
			break;
		case 4:
			m_mtneft.Replace(IDB_BUILDING1);
			break;
		case 16:
			m_mtneft.Replace(IDB_SHOPPING1);
			break;
		}
		
	}
}



void CCampusNavigationDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_check.department)
	{
		KillTimer(2);
	
	}
	deepimagenum=0;
	m_check.normal=false;
	m_check.normalsence=true;
	m_check.route=false;
	m_check.search=false;


	CDC *dc,dcMem;
	dc=GetDC();
	m_mtneft.GetDC(dc);
	m_mtneft.Appear(IDB_BUILDING2);


	
	
	m_combbegin.ShowWindow(SW_HIDE);
	m_combdestion.ShowWindow(SW_HIDE);
	m_startlineto.ShowWindow(SW_HIDE);
	//m_comblocation.ShowWindow(SW_HIDE);
	m_combcreat.ShowWindow(SW_HIDE);
	m_butlocation.ShowWindow(SW_HIDE);
	m_shortest.ShowWindow(SW_HIDE);
	m_clock.ShowWindow(SW_HIDE);
	m_building.ShowWindow(SW_HIDE);
	m_roadmask.ShowWindow(SW_HIDE);
	m_shopping.ShowWindow(SW_HIDE);
	m_department.ShowWindow(SW_HIDE);
	m_entersence.ShowWindow(SW_SHOW);
	m_exitsence.ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC4)->ShowWindow(SW_HIDE);
	m_showall.ShowWindow(SW_HIDE);
	m_clearall.ShowWindow(SW_HIDE);
	m_combdepartment.ShowWindow(SW_HIDE);
	m_beginvisit.ShowWindow(SW_SHOW);
	m_stopvisit.ShowWindow(SW_SHOW);
	m_wepass.ShowWindow(SW_HIDE);

	if (m_check.wsad)
	{
		m_check.wsad=false;
	}
	if (m_check.beginvisitsence)
	{
		m_check.beginvisitsence=false;
		KillTimer(3);
		timernum=0;

	}

}
	
	



BOOL CCampusNavigationDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message==WM_KEYUP ||pMsg->message==WM_KEYDOWN)
	{
		pMsg->hwnd=this->m_hWnd;

	}
	return CDialog::PreTranslateMessage(pMsg);
}




void CCampusNavigationDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (!m_check.magnified && m_check.block)
	{
		
			if (point.x<=323 && point.y<=291)
			{

				CDC *dc;
				dc=GetDC();
				m_mtneft.GetDC(dc);
				m_mtneft.Replace(IDB_SECTION3);	
				m_check.magnified=true;
				GetDlgItem(IDC_BLOCKSEL)->EnableWindow(FALSE);
			}
			if (point.x>=25 && point.y>387 && point.x<=305 && point.y<=654)
			{
				CDC *dc;
				dc=GetDC();
				m_mtneft.GetDC(dc);
				m_mtneft.Replace(IDB_SECTION2);
				m_check.magnified=true;
				GetDlgItem(IDC_BLOCKSEL)->EnableWindow(FALSE);
			}
			if (point.x>=322 && point.y>=293 && point.x<=563 && point.y<=664)
			{  
				CDC *dc;
				dc=GetDC();
				m_mtneft.GetDC(dc);
				m_mtneft.Replace(IDB_SECTION1);
				m_check.magnified=true;
				GetDlgItem(IDC_BLOCKSEL)->EnableWindow(FALSE);
			}

	}
	
	CDialog::OnLButtonUp(nFlags, point);
}

void CCampusNavigationDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_check.wsad&&m_check.normalsence)
	{
		CDC *dc;
	switch (nChar)
	{
	case 'W':
	case 'w':
		if (m_mapImages.m_curPoint->forward==NULL)
		{
			break;
		}
		m_mapImages.m_curPoint=m_mapImages.m_curPoint->forward;//将前面指针指向的图片赋值
		dc=GetDC();
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(m_mapImages.m_curPoint->imageId);//直接用replace函数覆盖
		break;
	case 'S':
	case 's':
		if (m_mapImages.m_curPoint->back==NULL)
		{
			break;
		}
		m_mapImages.m_curPoint=m_mapImages.m_curPoint->back;
		dc=GetDC();
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(m_mapImages.m_curPoint->imageId);
		break;
	case 'A':
		if (m_mapImages.m_curPoint->left==NULL)
		{
			break;
		}
		m_mapImages.m_curPoint=m_mapImages.m_curPoint->left;
		dc=GetDC();
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(m_mapImages.m_curPoint->imageId);
		break;
	case 'D':
		if (m_mapImages.m_curPoint->right==NULL)
		{
			break;
		}
		m_mapImages.m_curPoint=m_mapImages.m_curPoint->right;
		dc=GetDC();
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(m_mapImages.m_curPoint->imageId);
		break;
	default:
		break;
	}
	
	}
	else
	{
		return;
	}
	
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}

// void CCampusNavigationDlg::OnBnClickedButton3()
// {
// 	// TODO: 在此添加控件通知处理程序代码
// 	CDC *dc,m_dcMem;int i=0;
// 	dc=GetDC(); 
// 	CPen pen(PS_SOLID,6,RGB(230,27,94));
// 	dc->SelectObject(&pen);
// 	//m_dcMem.CreateCompatibleDC(dc);
// 	dc->MoveTo(355,628);
//  	for (i=628;i>=586;i--)
// 	{    Sleep(15);
// 		dc->LineTo(355,i);
// 	}
// 	
// 	
// 	for (i=355;i>284;i--)
// 	{
// 	    Sleep(15);
// 		double b=0.3239*i+(586-355*0.3239);
// 		dc->LineTo(i,b);
// 	}
// 	for (i=563;i>=454;i--)
// 	{
//        Sleep(15);
//        dc->LineTo(284,i);
// 	}
// 	
// 	
// 	dc->LineTo(262,449);
// 	dc->LineTo(234,449);
// 	dc->LineTo(205,449);
// 	dc->LineTo(178,449);
// 	dc->LineTo(178,369);
// 	dc->LineTo(178,319);
// 	dc->LineTo(178,297);
// 	dc->LineTo(178,270);
// 	dc->LineTo(178,245);
// 	dc->LineTo(178,203);
// 	dc->LineTo(177,177);
// 	dc->LineTo(176,123);
// 	dc->LineTo(127,121);
// 	dc->LineTo(73,109);
// 
// }

void CCampusNavigationDlg::OnBnClickedBuildingmark()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_check.shopping)
	{
		m_check.shopping=false;
		m_checkNum-=16;
	}
	if (m_check.department)
	{
		m_check.department=false;
		m_checkNum-=8;
	}

	if (!m_check.building)
	{
		m_checkNum+=4;
		m_check.building=true;
		switch (m_checkNum)
		{
		case 4:
			m_mtneft.Replace(IDB_BUILDING1);
			break;
		case 6:
			m_mtneft.Replace(IDB_BUILDING2);
			break;
		}

	}
	else
	{
		m_checkNum-=4;
		m_check.building=false;
		switch (m_checkNum)
		{
		case 0:
			m_mtneft.Replace(IDB_MMAIN);
			break;
		case 2:
			m_mtneft.Replace(IDB_MROADMARK);
			break;
		}

	}

	((CButton *)GetDlgItem(IDC_SHOPPINGMARK))->SetCheck(FALSE);
	((CButton *)GetDlgItem(IDC_DEPARTMARK))->SetCheck(FALSE);

}

void CCampusNavigationDlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_check.magnified&&m_check.normal)
	{
		m_check.magnified=false;
		m_mtneft.Replace(IDB_MMAIN);
		GetDlgItem(IDC_BLOCKSEL)->EnableWindow(TRUE);

	}
	CDialog::OnRButtonUp(nFlags, point);
}

//void CCampusNavigationDlg::OnBnClickedBuildingname()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	
//}

void CCampusNavigationDlg::OnBnClickedDepartmark()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!m_check.department)
	{
		m_checkNum+=8;
		m_check.department=true;

		GetDlgItem(IDC_ROADMARK)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUILDINGMARK)->EnableWindow(FALSE);
		GetDlgItem(IDC_BLOCKSEL)->EnableWindow(FALSE);
		GetDlgItem(IDC_SHOPPINGMARK)->EnableWindow(FALSE);
      
		CDC *dc,dcMem;
		dc=GetDC();
		CBitmap figure3,figure4;                     //创建位图对象。
		dcMem.CreateCompatibleDC(dc);    
		figure3.LoadBitmap(IDB_BIT_H1);
		 figure4.LoadBitmap(IDB_BIT_H2);
		 dcMem.SelectObject(&figure3);    
		 dc->BitBlt(0,100,549,501,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
		 dcMem.SelectObject(&figure4);    
		 dc->BitBlt(0,100,549,501,&dcMem,0,0,SRCPAINT);
		 SetTimer(2,5000,NULL);
		
	
	}
	else
	{
		KillTimer(2);
		m_check.department=false;
		m_checkNum-=8;
		GetDlgItem(IDC_ROADMARK)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUILDINGMARK)->EnableWindow(TRUE);
		//	GetDlgItem(IDC_DEPARTMARK)->EnableWindow(FALSE);
		GetDlgItem(IDC_BLOCKSEL)->EnableWindow(TRUE);
		GetDlgItem(IDC_SHOPPINGMARK)->EnableWindow(TRUE);

		switch (m_checkNum)
		{


		case 0:
			m_mtneft.Replace(IDB_MMAIN);
			break;
		case 6:
			m_mtneft.Replace(IDB_BUILDING2);
			break;
		case 16:
			m_mtneft.Replace(IDB_SHOPPING1);
			break;
		case 18:
			m_mtneft.Replace(IDB_SHOPPING2);
			break;


		}
	}
}




void CCampusNavigationDlg::OnBnClickedShoppingmark()
{
	// TODO: 在此添加控件通知处理程序代码
	
	if(m_check.building)
	{
		m_check.building=false;
		m_checkNum-=4;
	}
	if (m_check.department)
	{
		m_check.department=false;
		m_checkNum-=8;
	}	

	if (!m_check.shopping)
	{
		m_checkNum+=16;
		m_check.shopping=true;
		switch (m_checkNum)
		{
		case 16:
			m_mtneft.Replace(IDB_SHOPPING1);
			break;
		case 18:
			m_mtneft.Replace(IDB_SHOPPING2);
			break;
		}

	}
	else
	{
		m_checkNum-=16;
		m_check.shopping=false;
		switch (m_checkNum)
		{
		case 0:
			m_mtneft.Replace(IDB_MMAIN);
			break;
		case 2:
			m_mtneft.Replace(IDB_MROADMARK);
			break;
		}

	}
	
	((CButton *)GetDlgItem(IDC_BUILDINGMARK))->SetCheck(FALSE);
	((CButton *)GetDlgItem(IDC_DEPARTMARK))->SetCheck(FALSE);
	
}

// BOOL CCampusNavigationDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
// {
// 	// TODO: 在此添加消息处理程序代码和/或调用默认值
// 	switch(pWnd->GetDlgCtrlID())
// 	{
// 	case IDC_BUTTON1:
// 		{
// 			SetCursor(AfxGetApp()->LoadCursor(IDC_HAND));
// 			GetDlgItem(IDC_TEXT)->ShowWindow(SW_SHOW);
// 			GetDlgItem(IDC_TEXT)->SetWindowsText("output the information!");
// 			return TRUE;
// 			break;
// 		}
// 		
// 	default://when you leave the hot
// 		{
// 			GetDlgItem(IDC_TEXT)->ShowWindow(SW_HIDE);
// 			SetCursor(AfxGetApp()->LoadCursor(IDC_ARROW));
// 			return TRUE;
// 		}
// 
// 	}
// 
// 	return CDialog::OnSetCursor(pWnd, nHitTest, message);
// }

void CCampusNavigationDlg::OnBnClickedShortestpath()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_check.route&&m_check.combbegin)
	{
	
		CDC *dc;
		dc=GetDC();
		// 			
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
	m_mainPoints.vexnum=32;
	ShortestPath_FLOYD(m_mainPoints,p,d);
	//MessageBox(_T("ADSF"));
	int startpoint,endpoint;
	switch (nIndex0)
	{
	case 0:
		startpoint=22;
		break;
	case 1:
		startpoint=6;
		break;
	case 2:
		startpoint=8;
		break;
	case 3:
		startpoint=18;
		break;
	case 4:
		startpoint=19;
		break;
	case 5:
		startpoint=14;
		break;
	case 6:
		startpoint=28;
		break;
	case 7:
		startpoint=15;
		break;
	case 8:
		startpoint=30;
		break;
	case 9:
		startpoint=0;
		break;
	case 10:
		startpoint=11;
		break;
	case 11:
		startpoint=26;
		break;
	case 12:
		startpoint=31;
		break;
	case 13:
		startpoint=27;
		break;
	case 14:
		startpoint=21;
		break;
	case 15:
		startpoint=23;
		break;
	case 16:
		startpoint=20;
		break;
	case 17:
		startpoint=24;
		break;
	case 18:
		startpoint=15;
		break;
	case 19:
		startpoint=29;
		break;
	case 20:
		startpoint=21;
		break;
	
	}
	switch (nIndex1)
	{
	case 0:
		endpoint=22;
		break;
	case 1:
		endpoint=6;
			break;
	case 2:
		endpoint=8;
			break;
	case 3:
		endpoint=18;
			break;
	case 4:
		endpoint=19;
			break;
	case 5:
		endpoint=14;
			break;
	case 6:
		endpoint=28;
			break;
	case 7:
		endpoint=15;
			break;
	case 8:
		endpoint=30;
			break;
	case 9:
		endpoint=0;
			break;
	case 10:
		endpoint=11;
			break;
	case 11:
		endpoint=26;
			break;
	case 12:
		endpoint=31;
			break;
	case 13:
		endpoint=27;
			break;
	case 14:
		endpoint=21;
			break;
	case 15:
		endpoint=23;
			break;
	case 16:
		endpoint=20;
			break;
	case 17:
		endpoint=24;
			break;
	case 18:
		endpoint=15;
			break;
	case 19:
		endpoint=29;
			break;
	case 20:
		endpoint=21;
			break;

	}
	int pass[32];
	int i,j;
	for (i=0;i<32;i++)
	{
		pass[i]=0;
	}

 
	for ( i=0;i<=31;i++)
	{
	   if (p[startpoint][endpoint][i]==true)
	   {
		pass[i]=1;

	   }
	
	}

	
	int visited[32];
	for (i=0;i<32;i++)
	{
		visited[i]=0;
	}
	if (startpoint!=endpoint)
	{
	
for (j=0;j<32;j++)
{
	for (i=0;i<32;i++)
	{
		if( (visited[i]==0)&&(pass[i]!=0)&&(m_mainPoints.arcs[startpoint][i]<10000)&&(startpoint!=i))
		{
			visited[startpoint]=1;
			DrawLineTo(m_mainPoints.points[startpoint],m_mainPoints.points[i]);
			startpoint=i;
			break;

		}
     }
		
	}
}
}

}

void CCampusNavigationDlg::ShortestPath_FLOYD(MainPoints G, bool P[][32][32], int D[][32])
{
	int v,w,u;
	for (v=0;v<m_mainPoints.vexnum;v++)
	{
		for (w=0;w<m_mainPoints.vexnum;w++)
		{
			D[v][w]=G.arcs[v][w];
			for (u=0;u<G.vexnum;u++)
			{
				P[v][w][u]=false;
			}
			if (D[v][w]<10000)
			{
				P[v][w][v]=true;
				P[v][w][w]=true;

			}
		}
		
	}
	for (u=0;u<G.vexnum;u++)
	{
		for (v=0;v<G.vexnum;v++)
		{
			for (w=0;w<G.vexnum;w++)
			{
				if (D[v][u]+D[u][w]<D[v][w])
				{
					D[v][w]=D[v][u]+D[u][w];
					for (int i=0;i<G.vexnum;i++)
					{
						P[v][w][i]=P[v][u][i] || P[u][w][i]; 
					}
				}
			}
			
		}
	}
}

void CCampusNavigationDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

// void CCampusNavigationDlg::OnCbnSelchangeComboboxex2()
// {
// 	// TODO: 在此添加控件通知处理程序代码
// }

// void CCampusNavigationDlg::OnCbnSelchangeComboboxex4()
// {
// 	// TODO: 在此添加控件通知处理程序代码
// }

void CCampusNavigationDlg::OnBnClickedButton1()
{
	if (m_check.combsearch)
	{
	
	CDC *dc,dcMem1,dcMem2;
	dc=GetDC();
	CBitmap figure1,figure2,*OldBitMap;                     //创建位图对象。
	dcMem1.CreateCompatibleDC(dc); 

	
   
	switch (nIndex2)
	{
	case 0:
		{

		
		figure1.LoadBitmap(IDB_BIT_SIGN_2);
		figure2.LoadBitmap(IDB_BIT_SIGN_1);
		OldBitMap=dcMem1.SelectObject(&figure1);
		dc->BitBlt(380,390,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(380,390,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		DeleteObject(figure2);
		DeleteObject(figure1);
		dcMem1.DeleteDC();
		break;
		}
	case 1:
		figure1.LoadBitmap(IDB_BIT_SIGN_2);
		figure2.LoadBitmap(IDB_BIT_SIGN_1);
		OldBitMap=dcMem1.SelectObject(&figure1);
		dc->BitBlt(240,366,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(240,366,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算
		DeleteObject(figure2);
		DeleteObject(figure1);
		dcMem1.DeleteDC();
		
		break;
	case 2:
		figure1.LoadBitmap(IDB_BIT_SIGN_2);
		figure2.LoadBitmap(IDB_BIT_SIGN_1);
		OldBitMap=dcMem1.SelectObject(&figure1);
		dc->BitBlt(318,374,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(318,374,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		DeleteObject(figure2);
		DeleteObject(figure1);
		dcMem1.DeleteDC();
		break;
	case 3:
		figure1.LoadBitmap(IDB_BIT_SIGN_2);
		figure2.LoadBitmap(IDB_BIT_SIGN_1);
		OldBitMap=dcMem1.SelectObject(&figure1);
		dc->BitBlt(190,398,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(190,398,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		DeleteObject(figure2);
		DeleteObject(figure1);
		dcMem1.DeleteDC();
		break;
	case 4:
		figure1.LoadBitmap(IDB_BIT_SIGN_2);
		figure2.LoadBitmap(IDB_BIT_SIGN_1);
		OldBitMap=dcMem1.SelectObject(&figure1);
		dc->BitBlt(120,46,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(120,46,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		DeleteObject(figure2);
		DeleteObject(figure1);
		dcMem1.DeleteDC();
		break;
	case 5:
		figure1.LoadBitmap(IDB_BIT_SIGN_2);
		figure2.LoadBitmap(IDB_BIT_SIGN_1);
		OldBitMap=dcMem1.SelectObject(&figure1);
		dc->BitBlt(113,215,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(113,215,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		DeleteObject(figure2);
		DeleteObject(figure1);
		dcMem1.DeleteDC();
		break;
	case 6:
		figure1.LoadBitmap(IDB_BIT_SIGN_2);
		figure2.LoadBitmap(IDB_BIT_SIGN_1);
		OldBitMap=dcMem1.SelectObject(&figure1);
		dc->BitBlt(168,320,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(168,320,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		DeleteObject(figure2);
		DeleteObject(figure1);
		dcMem1.DeleteDC();
		break;
	case 7:
		figure1.LoadBitmap(IDB_BIT_SIGN_2);
		figure2.LoadBitmap(IDB_BIT_SIGN_1);
		OldBitMap=dcMem1.SelectObject(&figure1);
		dc->BitBlt(115,195,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(115,195,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		DeleteObject(figure2);
		DeleteObject(figure1);
		dcMem1.DeleteDC();
		break;
	case 8:
		figure1.LoadBitmap(IDB_BIT_SIGN_2);
		figure2.LoadBitmap(IDB_BIT_SIGN_1);
		OldBitMap=dcMem1.SelectObject(&figure1);
		dc->BitBlt(192,208,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(192,208,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		DeleteObject(figure2);
		DeleteObject(figure1);
		dcMem1.DeleteDC();
		break;
	case 9:
		figure1.LoadBitmap(IDB_BIT_SIGN_2);
		figure2.LoadBitmap(IDB_BIT_SIGN_1);
		OldBitMap=dcMem1.SelectObject(&figure1);
		dc->BitBlt(98,310,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(98,310,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		DeleteObject(figure2);
		DeleteObject(figure1);
		dcMem1.DeleteDC();
		break;
	case 10:
		figure1.LoadBitmap(IDB_BIT_SIGN_2);
		figure2.LoadBitmap(IDB_BIT_SIGN_1);
		OldBitMap=dcMem1.SelectObject(&figure1);
		dc->BitBlt(173,285,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(173,285,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		DeleteObject(figure2);
		DeleteObject(figure1);
		dcMem1.DeleteDC();
		break;
	case 11:
		figure1.LoadBitmap(IDB_BIT_SIGN_2);
		figure2.LoadBitmap(IDB_BIT_SIGN_1);
		OldBitMap=dcMem1.SelectObject(&figure1);
		dc->BitBlt(65,171,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(65,171,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		DeleteObject(figure2);
		DeleteObject(figure1);
		dcMem1.DeleteDC();
		break;
	case 12:
		figure1.LoadBitmap(IDB_BIT_SIGN_2);
		figure2.LoadBitmap(IDB_BIT_SIGN_1);
		OldBitMap=dcMem1.SelectObject(&figure1);
		dc->BitBlt(176,258,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(176,258,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		DeleteObject(figure2);
		DeleteObject(figure1);
		dcMem1.DeleteDC();
		break;
	case 13:
		figure1.LoadBitmap(IDB_BIT_SIGN_2);
		figure2.LoadBitmap(IDB_BIT_SIGN_1);
		OldBitMap=dcMem1.SelectObject(&figure1);
		dc->BitBlt(234,335,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(234,335,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		DeleteObject(figure2);
		DeleteObject(figure1);
		dcMem1.DeleteDC();
		break;
	case 14:
		figure1.LoadBitmap(IDB_BIT_SIGN_2);
		figure2.LoadBitmap(IDB_BIT_SIGN_1);
		OldBitMap=dcMem1.SelectObject(&figure1);
		dc->BitBlt(236,269,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(236,269,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		DeleteObject(figure2);
		DeleteObject(figure1);
		dcMem1.DeleteDC();
		break;
	case 15:
		figure1.LoadBitmap(IDB_BIT_SIGN_2);
		figure2.LoadBitmap(IDB_BIT_SIGN_1);
		OldBitMap=dcMem1.SelectObject(&figure1);
		dc->BitBlt(179,168,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(179,168,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		DeleteObject(figure2);
		DeleteObject(figure1);
		dcMem1.DeleteDC();
		break;
	case 16:
		figure1.LoadBitmap(IDB_BIT_SIGN_2);
		figure2.LoadBitmap(IDB_BIT_SIGN_1);
		OldBitMap=dcMem1.SelectObject(&figure1);
		dc->BitBlt(221,310,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(221,310,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		DeleteObject(figure2);
		DeleteObject(figure1);
		dcMem1.DeleteDC();
		break;
// 	case 17:
// 		figure1.LoadBitmap(IDB_BIT_SIGN_2);
// 		figure2.LoadBitmap(IDB_BIT_SIGN_1);
// 		OldBitMap=dcMem1.SelectObject(&figure1);
// 		dc->BitBlt(301,283,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
// 		dcMem1.SelectObject(&figure2);
// 		dc->BitBlt(301,283,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算
// 
// 		DeleteObject(figure2);
// 		DeleteObject(figure1);
// 		dcMem1.DeleteDC();
// 		break;
	

	     }
	}
}
	


void CCampusNavigationDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_check.department)
	{
		KillTimer(2);
	
	}
	
	m_check.normal=false;
	m_check.normalsence=false;
	m_check.route=true;
	m_check.search=false;
	CDC *dc;
	dc=GetDC();		
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
       m_combcreat.ShowWindow(SW_HIDE);
	 //  m_comblocation.ShowWindow(SW_HIDE);
	   
	  
		m_combbegin.ShowWindow(SW_SHOW);
	   m_combdestion.ShowWindow(SW_SHOW);
	   m_startlineto.ShowWindow(SW_SHOW);
	   m_butlocation.ShowWindow(SW_HIDE);
	 	m_entersence.ShowWindow(SW_HIDE);
		m_butlocation.ShowWindow(SW_HIDE);
	   m_exitsence.ShowWindow(SW_HIDE);
       m_shortest.ShowWindow(SW_SHOW);
	   m_clock.ShowWindow(SW_HIDE);
	   m_building.ShowWindow(SW_HIDE);
	   m_roadmask.ShowWindow(SW_HIDE);
	   m_shopping.ShowWindow(SW_HIDE);
	   m_department.ShowWindow(SW_HIDE);
	   m_showall.ShowWindow(SW_HIDE);
	   m_clearall.ShowWindow(SW_HIDE);
	   m_wepass.ShowWindow(SW_HIDE);

	   
	   m_beginvisit.ShowWindow(SW_HIDE);
	   m_stopvisit.ShowWindow(SW_HIDE);

	m_combdepartment.ShowWindow(SW_HIDE);
	m_wepass.ShowWindow(SW_SHOW);

	   GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
	   if (m_check.wsad)
	   {
		   m_check.wsad=false;
	   }
	   if (m_check.beginvisitsence)
	   {
		   m_check.beginvisitsence=false;
		   KillTimer(3);
		   timernum=0;

	   }
	   
}

void CCampusNavigationDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_check.combbegin)
	{
	
	CDC *dc,m_dcMem,dcMem1;
	int i=0;
	dc=GetDC(); 
	dcMem1.CreateCompatibleDC(dc); 
	CPen pen(PS_SOLID,5,RGB(230,27,94));
	dc->SelectObject(&pen);
	
	if (nIndex0==nIndex1)
	{
		return;

	}
	if (nIndex0==0&&nIndex1==1)
	{
		//m_dcMem.CreateCompatibleDC(dc)
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);

		dc->MoveTo(255,409);
		for (i=255;i<=285;i++)
		{   
			
			Sleep(15);
			dc->LineTo(i,412);
			
			
			
		}
		for (i=412;i<=449;i++)
			{   
				Sleep(15);
			    dc->LineTo(286,i);
			     
	     	}
		for (i=287;i>=260;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
			


		}
	


	}
	if (nIndex0==0&&nIndex1==2)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);

		dc->MoveTo(256,413);
		for (i=256;i>=235;i--)
		{    Sleep(15);
		dc->LineTo(i,413);
		
		

		}
		for (i=413;i<=448;i++)
		{    Sleep(15);
		dc->LineTo(235,i);
		
		}
		for (i=235;i>=203;i--)
		{
			Sleep(15);
			dc->LineTo(i,448);
			
			
		}
		

	}
if (nIndex0==0&&nIndex1==3)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);

		dc->MoveTo(256,413);
		for (i=256;i>=233;i--)
		{    Sleep(15);
		dc->LineTo(i,413);
		}
		for (i=413;i>=370;i--)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for(i=370;i>=83;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
	}

	if (nIndex0==0&&nIndex1==4)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);

		dc->MoveTo(256,413);
		for (i=256;i>=233;i--)
		{    Sleep(15);
		dc->LineTo(i,413);
		}
		for (i=413;i>=370;i--)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for(i=370;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for(i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
	}
	if (nIndex0==0&&nIndex1==5)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);

		dc->MoveTo(256,413);
		for (i=256;i>=233;i--)
		{    Sleep(15);
		dc->LineTo(i,413);
		}
		for (i=413;i>=370;i--)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for(i=370;i>=245;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		
	}
	if (nIndex0==0&&nIndex1==6)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);

		dc->MoveTo(256,413);
		for (i=256;i>=233;i--)
		{    Sleep(15);
		dc->LineTo(i,413);
		}
		for (i=413;i>=370;i--)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for(i=370;i>=346;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
	}
	if (nIndex0==0&&nIndex1==7)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);

		dc->MoveTo(256,413);
		for (i=256;i>=233;i--)
		{    Sleep(15);
		dc->LineTo(i,413);
		}
		for (i=413;i>=370;i--)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for(i=370;i>=216;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
	}
	if (nIndex0==0&&nIndex1==8)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);

		dc->MoveTo(256,413);
		for (i=256;i>=233;i--)
		{    Sleep(15);
		dc->LineTo(i,413);
		}
		for (i=413;i>=370;i--)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for(i=370;i>=216;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for(i=177;i<=204;i++)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}
	}
	if (nIndex0==0&&nIndex1==9)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);

		dc->MoveTo(256,413);
		for (i=256;i>=233;i--)
		{    Sleep(15);
		dc->LineTo(i,413);
		}
		for (i=413;i<=449;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=284;i++)
		{
			Sleep(15);
			dc->LineTo(i,449);
		}
		for(i=449;i<=563;i++)
		{
			Sleep(15);
			dc->LineTo(284,i);
		}
		for (i=284;i<=355;i++)
		{
	    Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
		}
		for(i=586;i<=640;i++)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}
	}
	if (nIndex0==0&&nIndex1==10)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);

		dc->MoveTo(256,413);
		for (i=256;i>=233;i--)
		{    Sleep(15);
		dc->LineTo(i,413);
		}
		for (i=413;i>=370;i--)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for(i=177;i>=109;i--)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
		
	}
	if (nIndex0==0&&nIndex1==11)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);

		dc->MoveTo(256,413);
		for (i=256;i>=233;i--)
		{    Sleep(15);
		dc->LineTo(i,413);
		}
		for (i=413;i>=370;i--)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=326;i--)
		{    Sleep(15);
		dc->LineTo(177,i);
		}
		for (i=177;i<=195;i++)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=195;i<=213;i++)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		

	}
	if (nIndex0==0&&nIndex1==12)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);

		dc->MoveTo(256,413);
		for (i=256;i>=233;i--)
		{    Sleep(15);
		dc->LineTo(i,413);
		}
		for (i=413;i>=370;i--)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for(i=370;i>=176;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for(i=177;i>=88;i--)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
	}
	if (nIndex0==0&&nIndex1==13)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);

		dc->MoveTo(256,413);
		for (i=256;i>=233;i--)
		{    Sleep(15);
		dc->LineTo(i,413);
		}
		for (i=413;i>=370;i--)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for(i=370;i>=302;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for(i=177;i<=224;i++)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}
	}
	if (nIndex0==0&&nIndex1==14)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
			
	
		dc->MoveTo(256,413);
		for (i=256;i<=285;i++)
		{    Sleep(15);
		dc->LineTo(i,413);
		}
		for (i=413;i<=417;i++)
		{    Sleep(15);
		dc->LineTo(285,i);
		}
	}
	if (nIndex0==0&&nIndex1==15)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
			
	
		dc->MoveTo(256,413);
		for (i=256;i<=285;i++)
		{    Sleep(15);
		dc->LineTo(i,413);
		}
		for (i=413;i>=369;i--)
		{    Sleep(15);
		dc->LineTo(285,i);
		}
	}
	if (nIndex0==0&&nIndex1==16)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);

		dc->MoveTo(256,413);
		for (i=256;i>=233;i--)
		{    Sleep(15);
		dc->LineTo(i,413);
		}
		for (i=413;i>=370;i--)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for(i=370;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for(i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for(i=127;i>=73;i--)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==0&&nIndex1==17)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
			
	
		dc->MoveTo(256,413);
		for (i=256;i<=285;i++)
		{    Sleep(15);
		dc->LineTo(i,413);
		}
		for (i=413;i>=369;i--)
		{    Sleep(15);
		dc->LineTo(285,i);
		}
		for (i=285;i>=260;i--)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		
	}
	if (nIndex0==0&&nIndex1==18)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);

		dc->MoveTo(256,413);
		for (i=256;i>=233;i--)
		{    Sleep(15);
		dc->LineTo(i,413);
		}
		for (i=413;i>=370;i--)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for(i=370;i>=197;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
	}
	if (nIndex0==0&&nIndex1==19)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
			
	
		dc->MoveTo(256,413);
		for (i=256;i<=285;i++)
		{    Sleep(15);
		dc->LineTo(i,413);
		}
		for (i=413;i>=369;i--)
		{    Sleep(15);
		dc->LineTo(285,i);
		}
		for (i=285;i>=269;i--)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}

		
	}
	if (nIndex0==0&&nIndex1==20)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);

		dc->MoveTo(256,413);
		for (i=256;i<=287;i++)
		{    Sleep(15);
		dc->LineTo(i,413);
		}
		for (i=413;i<=459;i++)
		{    Sleep(15);
		dc->LineTo(287,i);
		}
		for (i=287;i<=355;i++)
		{    Sleep(15);
		dc->LineTo(i,459);
		}
		
		
	}
///////////////////////////////////////////////////////////////////
if (nIndex0==1&&nIndex1==0)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
		

	dc->MoveTo(260,450);
	for (i=260;i<=287;i++)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}
	
	for (i=450;i>=413;i--)
	{    Sleep(15);
	dc->LineTo(287,i);
	}
	for (i=287;i>=256;i--)
	{    Sleep(15);
	dc->LineTo(i,413);

	}
	
}
if (nIndex0==1&&nIndex1==2)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
		

	dc->MoveTo(260,450);
	for (i=260;i>=204;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}
}
if (nIndex0==1&nIndex1==3)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(260,450);
	for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=370;i>=83;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}
}

if (nIndex0==1&&nIndex1==4)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(260,450);
	for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=370;i>=121;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}
	for(i=177;i>=127;i--)
	{
		Sleep(15);
		dc->LineTo(i,121);
	}
}
if (nIndex0==1&&nIndex1==5)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(260,450);
	for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=370;i>=245;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}
}
if (nIndex0==1&&nIndex1==6)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(260,450);
	for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=370;i>=346;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}

}
if (nIndex0==1&&nIndex1==7)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(260,450);
	for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=370;i>=216;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}
}
if (nIndex0==1&&nIndex1==8)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(260,450);
	for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=370;i>=216;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}
	for(i=177;i<=204;i++)
	{
		Sleep(15);
		dc->LineTo(i,216);
	}
}
if (nIndex0==1&&nIndex1==9)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);

	dc->MoveTo(260,450);
	for(i=260;i<=287;i++)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}
	
	for(i=449;i<=563;i++)
	{
		Sleep(15);
		dc->LineTo(284,i);
	}
	for (i=284;i<=355;i++)
	{
    Sleep(15);
	double b=0.3239*i+(586-355*0.3239);
	dc->LineTo(i,b);
	}
	for(i=586;i<=640;i++)
	{
		Sleep(15);
		dc->LineTo(355,i);
	}
}
if (nIndex0==1&&nIndex1==10)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(260,450);
	for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=177;i>=109;i--)
	{
		Sleep(15);
		double b=0.11765*i+362-109*0.11765;
		dc->LineTo(i,b);
	}
	
}
if (nIndex0==1&&nIndex1==11)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(260,450);
	for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for (i=370;i>=326;i--)
	{    Sleep(15);
	dc->LineTo(177,i);
	}
	for (i=177;i<=195;i++)
	{
		Sleep(15);
		dc->LineTo(i,326);
	}
	for (i=195;i<=213;i++)
	{
		Sleep(15);
		double b=-0.5*i+326+195*0.5;
		dc->LineTo(i,b);
	}
}
if (nIndex0==1&&nIndex1==12)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(260,450);
	for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=370;i>=176;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}
	for(i=177;i>=88;i--)
	{
		Sleep(15);
		dc->LineTo(i,176);
	}
}
/*if (nIndex0==0&&nIndex1==13)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);

	dc->MoveTo(256,413);
	for (i=256;i>=233;i--)
	{    Sleep(15);
	dc->LineTo(i,413);
	}
	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=370;i>=302;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}
	for(i=177;i<=224;i++)
	{
		Sleep(15);
		double b=-0.34*i+302+177*0.34;
		dc->LineTo(i,b);
	}
}*/
if (nIndex0==1&&nIndex1==13)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(260,450);
	for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=370;i>=302;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}
	for(i=177;i<=224;i++)
	{
		Sleep(15);
		double b=-0.34*i+302+177*0.34;
		dc->LineTo(i,b);
	}
}
if (nIndex0==1&&nIndex1==14)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(260,450);
	for (i=260;i<=287;i++)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=450;i>=417;i--)
	{    Sleep(15);
	dc->LineTo(287,i);
	}
}
if (nIndex0==1&&nIndex1==15)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(260,450);
	for (i=260;i<=287;i++)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=450;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(287,i);
	}
}
if (nIndex0==1&&nIndex1==16)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(260,450);
	for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=370;i>=121;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}
	for(i=177;i>=127;i--)
	{
		Sleep(15);
		dc->LineTo(i,121);
	}
	for(i=127;i>=73;i--)
	{
		Sleep(15);
		double b=0.2222*i+109-73*0.2222;
		dc->LineTo(i,b);
	}
}
if (nIndex0==1&&nIndex1==17)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(260,450);
	for (i=260;i<=287;i++)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=450;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(287,i);
	}
	for (i=285;i>=260;i--)
	{    Sleep(30);
		double b=2.16*i+315-260*2.16;
	dc->LineTo(i,b);
	}
}
if (nIndex0==1&&nIndex1==18)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(260,450);
	for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=370;i>=197;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}
}
if (nIndex0==1&&nIndex1==19)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(260,450);
	for (i=260;i<=287;i++)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=450;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(287,i);
	}
	for (i=285;i>=269;i--)
	{    Sleep(30);
		double b=2.16*i+315-260*2.16;
	dc->LineTo(i,b);
	}

}
if (nIndex0==1&&nIndex1==20)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(260,450);
	for (i=260;i<=287;i++)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=450;i<=459;i++)
	{    Sleep(15);
	dc->LineTo(287,i);
	}
	for (i=287;i<=357;i++)
	{    Sleep(15);
		
	dc->LineTo(i,459);
	}
}
//////////////////////////////////////////////////////////////////////////	
if (nIndex0==2&&nIndex1==0)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(204,450);
	for (i=204;i<=233;i++)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=450;i>=413;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i<=256;i++)
	{    Sleep(15);
		
	dc->LineTo(i,413);
	}
}
if (nIndex0==2&&nIndex1==1)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(204,450);
	for (i=204;i<=260;i++)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

}
if (nIndex0==2&&nIndex1==3)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(204,450);
	for (i=204;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=450;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(177,i);
	}
	for(i=370;i>=83;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}
}

if (nIndex0==2&&nIndex1==4)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(204,450);
	for (i=204;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=450;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(177,i);
	}
	for(i=370;i>=121;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}
	for(i=177;i>=127;i--)
	{
		Sleep(15);
		dc->LineTo(i,121);
	}
}

if (nIndex0==2&&nIndex1==5)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(204,450);
	for (i=204;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=450;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(177,i);
	}
	for(i=370;i>=245;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}

}
if (nIndex0==2&&nIndex1==6)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(204,450);
	for (i=204;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=450;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(177,i);
	}
	for(i=370;i>=346;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}
}
if (nIndex0==2&&nIndex1==7)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(204,450);
	for (i=204;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=450;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(177,i);
	}
	for(i=370;i>=216;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}
}
if (nIndex0==2&&nIndex1==8)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(204,450);
	for (i=204;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=450;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(177,i);
	}
	for(i=370;i>=216;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}
	for(i=177;i<=204;i++)
	{
		Sleep(15);
		dc->LineTo(i,216);
	}
}
if (nIndex0==2&&nIndex1==9)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(204,450);
	for (i=204;i<=260;i++)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}
	for(i=260;i<=287;i++)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}
	
	for(i=449;i<=563;i++)
	{
		Sleep(15);
		dc->LineTo(284,i);
	}
	for (i=284;i<=355;i++)
	{
    Sleep(15);
	double b=0.3239*i+(586-355*0.3239);
	dc->LineTo(i,b);
	}
	for(i=586;i<=640;i++)
	{
		Sleep(15);
		dc->LineTo(355,i);
	}
}
if (nIndex0==2&&nIndex1==10)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(204,450);
	for (i=204;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=450;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(177,i);
	}
	for(i=177;i>=109;i--)
	{
		Sleep(15);
		double b=0.11765*i+362-109*0.11765;
		dc->LineTo(i,b);
	}
}
if (nIndex0==2&&nIndex1==11)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(204,450);
	for (i=204;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=450;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(177,i);
	}
	for (i=370;i>=326;i--)
	{    Sleep(15);
	dc->LineTo(177,i);
	}
	for (i=177;i<=195;i++)
	{
		Sleep(15);
		dc->LineTo(i,326);
	}
	for (i=195;i<=213;i++)
	{
		Sleep(15);
		double b=-0.5*i+326+195*0.5;
		dc->LineTo(i,b);
	}
}
if (nIndex0==2&&nIndex1==12)
{
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(204,450);
	for (i=204;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=450;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(177,i);
	}
	for(i=370;i>=176;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}
	for(i=177;i>=88;i--)
	{
		Sleep(15);
		dc->LineTo(i,176);
	}
}
	if (nIndex0==2&&nIndex1==13)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,450);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}

		for (i=450;i>=370;i--)
		{    Sleep(15);
		dc->LineTo(177,i);
		}
		for(i=370;i>=302;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for(i=177;i<=224;i++)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}
	}
	if (nIndex0==2&&nIndex1==14)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,450);
		for (i=204;i<=260;i++)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
		for (i=260;i<=287;i++)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}

		for (i=450;i>=417;i--)
		{    Sleep(15);
		dc->LineTo(287,i);
		}
	}
	if (nIndex0==2&&nIndex1==15)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,450);
		for (i=204;i<=260;i++)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
		for (i=260;i<=287;i++)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}

		for (i=450;i>=370;i--)
		{    Sleep(15);
		dc->LineTo(287,i);
		}
		
	}
	if (nIndex0==2&&nIndex1==16)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,450);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}

		for (i=450;i>=370;i--)
		{    Sleep(15);
		dc->LineTo(177,i);
		}
		for(i=370;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for(i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for(i=127;i>=73;i--)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}
	}
	if (nIndex0==2&&nIndex1==17)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,450);
		for (i=204;i<=260;i++)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
		for (i=260;i<=287;i++)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}

		for (i=450;i>=370;i--)
		{    Sleep(15);
		dc->LineTo(287,i);
		}
		for (i=285;i>=260;i--)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
	}
	if (nIndex0==2&&nIndex1==18)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,450);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}

		for (i=450;i>=370;i--)
		{    Sleep(15);
		dc->LineTo(177,i);
		}
		for(i=370;i>=197;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
	}
	if (nIndex0==2&&nIndex1==19)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,450);
		for (i=204;i<=260;i++)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
		for (i=260;i<=287;i++)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}

		for (i=450;i>=370;i--)
		{    Sleep(15);
		dc->LineTo(287,i);
		}
		for (i=285;i>=269;i--)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}

	}
	if (nIndex0==2&&nIndex1==20)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,450);
		for (i=204;i<=260;i++)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
		for (i=260;i<=287;i++)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}

		for (i=450;i<=459;i++)
		{    Sleep(15);
		dc->LineTo(287,i);
		}
		for (i=287;i<=357;i++)
		{    Sleep(15);
			
		dc->LineTo(i,459);
		}
	}
	///////////////////////////////////////////////////////////////////////
	if (nIndex0==3&&nIndex1==0)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,83);
		for (i=83;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=413;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=256;i++)
		{    Sleep(15);
			
		dc->LineTo(i,413);
		}
	}
	if (nIndex0==3&&nIndex1==1)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,83);
		for (i=83;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=260;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}
	}
	if (nIndex0==3&&nIndex1==2)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,83);
		for (i=83;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}
	}
	

	if (nIndex0==3&&nIndex1==4)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,83);
		for (i=83;i<=121;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}

		
	}
	if (nIndex0==3&&nIndex1==5)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,83);
		for (i=83;i<=245;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
	}
	if (nIndex0==3&&nIndex1==6)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,83);
		for (i=83;i<=346;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
	}
	if (nIndex0==3&&nIndex1==7)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,83);
		for (i=83;i<=216;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
	}
	if (nIndex0==3&&nIndex1==8)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,83);
		for (i=83;i<=216;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}
	}
	if (nIndex0==3&&nIndex1==9)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,83);
		for (i=83;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=260;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}
		for(i=260;i<=287;i++)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
		
		for(i=449;i<=563;i++)
		{
			Sleep(15);
			dc->LineTo(284,i);
		}
		for (i=284;i<=355;i++)
		{
	    Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
		}
		for(i=586;i<=640;i++)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}
	}
	if (nIndex0==3&&nIndex1==10)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,83);
		for (i=83;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=109;i--)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}

		
	}
	if (nIndex0==3&&nIndex1==11)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,83);
		for (i=83;i<=326;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=195;i++)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=195;i<=213;i++)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
	}
	if (nIndex0==3&&nIndex1==12)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,83);
		for (i=83;i<=176;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=88;i--)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}

	}
	if (nIndex0==3&&nIndex1==13)
	{
		
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,83);
		for (i=83;i<=302;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=222;i++)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==3&&nIndex1==14)
	{
			m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,83);
		for (i=83;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i<=417;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
	}
	if (nIndex0==3&&nIndex1==15)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,83);
		for (i=83;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
	}
	if (nIndex0==3&&nIndex1==16)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,83);
		for (i=83;i<=121;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for(i=127;i>=73;i--)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}
		
	}
	if (nIndex0==3&&nIndex1==17)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,83);
		for (i=83;i<=302;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=222;i++)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}
		for(i=222;i<=243;i++)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for(i=243;i<=260;i++)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==3&&nIndex1==18)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,83);
		for (i=83;i<=197;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		
	}
	if (nIndex0==3&&nIndex1==19)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,83);
		for (i=83;i<=360;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for(i=177;i<=225;i++)
		{
			Sleep(15);
			double b=-0.521*i+360+177*0.521;

			dc->LineTo(i,b);
		}
		for(i=225;i<=234;i++)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for(i=234;i<=250;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
	}
	if (nIndex0==3&&nIndex1==20)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,83);
		for (i=83;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i<=460;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i<=355;i++)
		{
			Sleep(15);
			dc->LineTo(i,460);
		}

	}
	///////////////////////////////////////////////////////////////////////
	if (nIndex0==4&&nIndex1==0)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(127,121);
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=413;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=256;i++)
		{    Sleep(15);
			
		dc->LineTo(i,413);
		}

	}
	if (nIndex0==4&&nIndex1==1)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(127,121);
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=260;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}

	}
	if (nIndex0==4&&nIndex1==2)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(127,121);
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}
	
	}
	if (nIndex0==4&&nIndex1==3)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(127,121);
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i>=83;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}

	if (nIndex0==4&&nIndex1==5)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(127,121);
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=245;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==4&&nIndex1==6)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(127,121);
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=346;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==4&&nIndex1==7)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(127,121);
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=216;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==4&&nIndex1==8)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(127,121);
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=216;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}

	}
	if (nIndex0==4&&nIndex1==9)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(127,121);
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=260;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}
		for(i=260;i<=287;i++)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
		
		for(i=449;i<=563;i++)
		{
			Sleep(15);
			dc->LineTo(284,i);
		}
		for (i=284;i<=355;i++)
		{
	    Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
		}
		for(i=586;i<=640;i++)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}

	}
	if (nIndex0==4&&nIndex1==10)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(127,121);
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=109;i--)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==4&&nIndex1==11)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(127,121);
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=326;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=195;i++)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=195;i<=213;i++)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==4&&nIndex1==12)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(127,121);
		for (i=121;i<=176;i++)
		{
			Sleep(15);
			dc->LineTo(127,i);
		}
		for (i=121;i>=88;i--)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
		
	}
	if (nIndex0==4&&nIndex1==13)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(127,121);
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=302;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=222;i++)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==4&&nIndex1==14)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(127,121);
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i<=417;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}

	}
	if (nIndex0==4&&nIndex1==15)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(127,121);
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

	}
	if (nIndex0==4&&nIndex1==16)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(127,121);
		for(i=127;i>=73;i--)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==4&&nIndex1==17)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(127,121);
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=302;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=222;i++)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}
		for(i=222;i<=243;i++)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for(i=243;i<=260;i++)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==4&&nIndex1==18)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(127,121);
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=197;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==4&&nIndex1==19)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(127,121);
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=360;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for(i=177;i<=225;i++)
		{
			Sleep(15);
			double b=-0.521*i+360+177*0.521;

			dc->LineTo(i,b);
		}
		for(i=225;i<=234;i++)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for(i=234;i<=250;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==4&&nIndex1==20)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(127,121);
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i<=460;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i<=355;i++)
		{
			Sleep(15);
			dc->LineTo(i,460);
		}

	}
	//////////////////////////////////////////////
	if (nIndex0==5&&nIndex1==0)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,245);
		for (i=245;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=413;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=256;i++)
		{    Sleep(15);
			
		dc->LineTo(i,413);
		}
	
	}
	if (nIndex0==5&&nIndex1==1)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,245);
		for (i=245;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=260;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}

	}
	if (nIndex0==5&&nIndex1==2)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,245);
		for (i=245;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}

	}
	if (nIndex0==5&&nIndex1==3)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,245);
		for (i=245;i>=83;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
	}

	if (nIndex0==5&&nIndex1==4)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,245);
		for (i=245;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}


	}
	
	if (nIndex0==5&&nIndex1==6)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,245);
		for (i=245;i<=346;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
	}
	if (nIndex0==5&&nIndex1==7)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,245);
		for (i=245;i>=216;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==5&&nIndex1==8)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,245);
		for (i=245;i<=216;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}

	}
	if (nIndex0==5&&nIndex1==9)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,245);
		for (i=245;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=260;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}
		for(i=260;i<=287;i++)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
		
		for(i=449;i<=563;i++)
		{
			Sleep(15);
			dc->LineTo(284,i);
		}
		for (i=284;i<=355;i++)
		{
	    Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
		}
		for(i=586;i<=640;i++)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}

	}
	if (nIndex0==5&&nIndex1==10)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,245);
		for (i=245;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=109;i--)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}


	}
	if (nIndex0==5&&nIndex1==11)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,245);
		for (i=245;i<=326;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=195;i++)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=195;i<=213;i++)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==5&&nIndex1==12)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,245);
		for (i=245;i<=176;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=88;i--)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}

	}
	if (nIndex0==5&&nIndex1==13)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,245);
		for (i=245;i<=302;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=222;i++)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==5&&nIndex1==14)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,245);
		for (i=245;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i<=417;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}

	}
	if (nIndex0==5&&nIndex1==15)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,245);
		for (i=245;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

	}
	if (nIndex0==5&&nIndex1==16)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,245);
		for (i=245;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for(i=127;i>=73;i--)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==5&&nIndex1==17)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,245);
		for (i=245;i<=302;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=222;i++)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}
		for(i=222;i<=243;i++)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for(i=243;i<=260;i++)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
	}
	if (nIndex0==5&&nIndex1==18)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,245);
		for (i=245;i>=197;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==5&&nIndex1==19)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,245);
		for (i=245;i<=360;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for(i=177;i<=225;i++)
		{
			Sleep(15);
			double b=-0.521*i+360+177*0.521;

			dc->LineTo(i,b);
		}
		for(i=225;i<=234;i++)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for(i=234;i<=250;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
	}
	if (nIndex0==5&&nIndex1==20)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,245);
		for (i=245;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i<=460;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i<=355;i++)
		{
			Sleep(15);
			dc->LineTo(i,460);
		}

	}
	///////////////////////////////////////////////
	if (nIndex0==6&&nIndex1==0)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,346);
		for (i=346;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=413;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=256;i++)
		{    Sleep(15);
			
		dc->LineTo(i,413);
		}
	}
	if (nIndex0==6&&nIndex1==1)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,346);
		for (i=346;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=260;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}

	}
	if (nIndex0==6&&nIndex1==2)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,346);
		for (i=346;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}	
	}
	if (nIndex0==6&&nIndex1==3)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,346);
		for (i=346;i>=83;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}

	if (nIndex0==6&&nIndex1==4)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,346);
		for (i=346;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}


	}
	if (nIndex0==6&&nIndex1==5)
	{
		
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,346);
		for (i=346;i>=245;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
	}
	
	if (nIndex0==6&&nIndex1==7)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,346);
		for (i=346;i>=216;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==6&&nIndex1==8)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,346);
		for (i=346;i>=216;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}

	}
	if (nIndex0==6&&nIndex1==9)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,346);
		for (i=346;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=260;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}
		for(i=260;i<=287;i++)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
		
		for(i=449;i<=563;i++)
		{
			Sleep(15);
			dc->LineTo(284,i);
		}
		for (i=284;i<=355;i++)
		{
	    Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
		}
		for(i=586;i<=640;i++)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}

	}
	if (nIndex0==6&&nIndex1==10)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,346);
		for (i=346;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=109;i--)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
	}
	if (nIndex0==6&&nIndex1==11)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(210,345);
		for(i=210;i<=225;i++)
		{
			Sleep(15);
			double b=-0.521*i+360+177*0.521;
			dc->LineTo(i,b);
		}
		for(i=225;i>=213;i--)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		
	}
	if (nIndex0==6&&nIndex1==12)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,346);
		for (i=346;i>=176;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=88;i--)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}

	}
	if (nIndex0==6&&nIndex1==13)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(210,345);
		for(i=210;i<=225;i++)
		{
			Sleep(15);
			double b=-0.521*i+360+177*0.521;
			dc->LineTo(i,b);
		}
		for(i=225;i>=213;i--)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for (i=213;i<=235;i++)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}

		for(i=235;i>=222;i--)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
	}
	if (nIndex0==6&&nIndex1==14)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(210,345);
		for(i=210;i<=225;i++)
		{
			Sleep(15);
			double b=-0.521*i+360+177*0.521;

			dc->LineTo(i,b);
		}
		for(i=225;i<=234;i++)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for(i=234;i<=250;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for(i=250;i<=270;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for (i=270;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for (i=369;i<=417;i++)
		{    Sleep(30);
		dc->LineTo(285,i);
		}

	}
	if (nIndex0==6&&nIndex1==15)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(210,345);
		for(i=210;i<=225;i++)
		{
			Sleep(15);
			double b=-0.521*i+360+177*0.521;

			dc->LineTo(i,b);
		}
		for(i=225;i<=234;i++)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for(i=234;i<=250;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for(i=250;i<=270;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for (i=270;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}

	}
	if (nIndex0==6&&nIndex1==16)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,346);
		for (i=346;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for(i=127;i>=73;i--)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==6&&nIndex1==17)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(210,343);
		for(i=210;i<=225;i++)
		{
			Sleep(15);
			double b=-0.521*i+360+177*0.521;
			dc->LineTo(i,b);
		}
		for(i=225;i<=234;i++)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for(i=234;i<=270;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;

			dc->LineTo(i,b);
		}
		for(i=270;i>=260;i--)
		{
			Sleep(30);
			double b=2.16*i+315-260*2.16;
			dc->LineTo(i,b);
		}
	}
	if (nIndex0==6&&nIndex1==18)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,346);
		for (i=346;i>=197;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==6&&nIndex1==19)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(210,345);
		for(i=210;i<=225;i++)
		{
			Sleep(15);
			double b=-0.521*i+360+177*0.521;

			dc->LineTo(i,b);
		}
		for(i=225;i<=234;i++)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for(i=234;i<=250;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==6&&nIndex1==20)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,346);
		for (i=346;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i<=460;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i<=355;i++)
		{
			Sleep(15);
			dc->LineTo(i,460);
		}
	}
	////////////////////////////////////////////////
	if (nIndex0==7&&nIndex1==0)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,216);
		for (i=216;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=413;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=256;i++)
		{    Sleep(15);
			
		dc->LineTo(i,413);
		}

	}
	if (nIndex0==7&&nIndex1==1)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,216);
		for (i=216;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=260;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}

	}
	if (nIndex0==7&&nIndex1==2)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,216);
		for (i=216;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}

	}
	if (nIndex0==7&&nIndex1==3)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,216);
		for (i=216;i>=83;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}

	if (nIndex0==7&&nIndex1==4)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,216);
		for (i=216;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}

	}
	if (nIndex0==7&&nIndex1==5)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,216);
		for (i=216;i<=245;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==7&&nIndex1==6)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,216);
		for (i=216;i<=346;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	
	if (nIndex0==7&&nIndex1==8)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,216);
		for (i=177;i<=204;i++)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}


	}
	if (nIndex0==7&&nIndex1==9)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,216);
		for (i=216;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=260;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}
		for(i=260;i<=287;i++)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
		
		for(i=449;i<=563;i++)
		{
			Sleep(15);
			dc->LineTo(284,i);
		}
		for (i=284;i<=355;i++)
		{
	    Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
		}
		for(i=586;i<=640;i++)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}

	}
	if (nIndex0==7&&nIndex1==10)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,216);
		for (i=216;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=109;i--)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==7&&nIndex1==11)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,216);
		for (i=216;i<=326;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=195;i++)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=195;i<=213;i++)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==7&&nIndex1==12)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,216);
		for (i=216;i>=176;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=88;i--)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}

	}
	if (nIndex0==7&&nIndex1==13)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,216);
		for (i=216;i<=302;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=222;i++)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==7&&nIndex1==14)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,216);
		for (i=216;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i<=417;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}

	}
	if (nIndex0==7&&nIndex1==15)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,216);
		for (i=216;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

	}
	if (nIndex0==7&&nIndex1==16)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,216);
		for (i=216;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for(i=127;i>=73;i--)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==7&&nIndex1==17)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,216);
		for (i=216;i<=302;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=222;i++)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}
		for(i=222;i<=243;i++)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for(i=243;i<=260;i++)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==7&&nIndex1==18)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,216);
		for (i=216;i>=197;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==7&&nIndex1==19)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,216);
		for (i=216;i<=360;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for(i=177;i<=225;i++)
		{
			Sleep(15);
			double b=-0.521*i+360+177*0.521;

			dc->LineTo(i,b);
		}
		for(i=225;i<=234;i++)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for(i=234;i<=250;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==7&&nIndex1==20)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,216);
		for (i=216;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i<=460;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i<=355;i++)
		{
			Sleep(15);
			dc->LineTo(i,460);
		}


	}
	///////////////////////////////////////////////////
	if (nIndex0==8&&nIndex1==0)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,216);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}
		for (i=216;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=413;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=256;i++)
		{    Sleep(15);
			
		dc->LineTo(i,413);
		}


	}
	if (nIndex0==8&&nIndex1==1)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,216);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}
		for (i=216;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=260;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}

	}
	if (nIndex0==8&&nIndex1==2)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,216);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}
		for (i=216;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}

	}
	if (nIndex0==8&&nIndex1==3)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,216);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}
		for (i=216;i>=83;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}

	if (nIndex0==8&&nIndex1==4)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,216);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}
		for (i=216;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}

	}
	if (nIndex0==8&&nIndex1==5)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,216);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}
		for (i=216;i<=245;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==8&&nIndex1==6)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,216);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}
		for (i=216;i<=346;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==8&&nIndex1==7)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,216);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}

	}
	
	if (nIndex0==8&&nIndex1==9)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,216);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}
		for (i=216;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=260;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}
		for(i=260;i<=287;i++)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
		
		for(i=449;i<=563;i++)
		{
			Sleep(15);
			dc->LineTo(284,i);
		}
		for (i=284;i<=355;i++)
		{
	    Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
		}
		for(i=586;i<=640;i++)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}

	}
	if (nIndex0==8&&nIndex1==10)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,216);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}
		for (i=216;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=109;i--)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==8&&nIndex1==11)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,216);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}
		for (i=216;i<=326;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=195;i++)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=195;i<=213;i++)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==8&&nIndex1==12)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,216);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}
		for (i=216;i<=176;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=88;i--)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}

	}
	if (nIndex0==8&&nIndex1==13)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,216);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}
		for (i=216;i<=302;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=222;i++)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==8&&nIndex1==14)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,216);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}
		for (i=216;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i<=417;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}

	}
	if (nIndex0==8&&nIndex1==15)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,216);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}
		for (i=216;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

	}
	if (nIndex0==8&&nIndex1==16)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,216);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}
		for (i=216;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for(i=127;i>=73;i--)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==8&&nIndex1==17)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,216);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}
		for (i=216;i<=302;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=222;i++)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}
		for(i=222;i<=243;i++)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for(i=243;i<=260;i++)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==8&&nIndex1==18)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,216);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}
		for (i=216;i>=197;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==8&&nIndex1==19)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,216);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}
		for (i=216;i<=360;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for(i=177;i<=225;i++)
		{
			Sleep(15);
			double b=-0.521*i+360+177*0.521;

			dc->LineTo(i,b);
		}
		for(i=225;i<=234;i++)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for(i=234;i<=250;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==8&&nIndex1==20)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(204,216);
		for (i=204;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}
		for (i=216;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i<=460;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i<=355;i++)
		{
			Sleep(15);
			dc->LineTo(i,460);
		}

	}
	//////////////////////////////////////////////////
	if (nIndex0==9&&nIndex1==0)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,640);
		for(i=640;i>=586;i--)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}
		for (i=355;i>=284;i--)
		{
			 Sleep(15);
			double b=0.3239*i+(586-355*0.3239);
			dc->LineTo(i,b);
		}
		for(i=563;i>=450;i--)
		{
		Sleep(15);
		dc->LineTo(284,i);
		}
		for(i=450;i>=413;i--)
		{
			Sleep(15);
			dc->LineTo(286,i);
		}
		for(i=286;i>=256;i--)
		{
			Sleep(15);
			dc->LineTo(i,413);
		}

	}
	if (nIndex0==9&&nIndex1==1)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,640);
		for(i=640;i>=586;i--)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}
		for (i=355;i>=284;i--)
		{
			Sleep(15);
			double b=0.3239*i+(586-355*0.3239);
			dc->LineTo(i,b);
		}
		for(i=563;i>=449;i--)
		{
	  		Sleep(15);
			dc->LineTo(284,i);
		}
		for(i=284;i>=260;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}

	}
	if (nIndex0==9&&nIndex1==2)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,640);
		for(i=640;i>=586;i--)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}
		for (i=355;i>=284;i--)
		{
			Sleep(15);
			double b=0.3239*i+(586-355*0.3239);
			dc->LineTo(i,b);
		}
		for(i=563;i>=449;i--)
		{
	  		Sleep(15);
			dc->LineTo(284,i);
		}
		for(i=284;i>=260;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
		for (i=260;i>=204;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}


	}
	if (nIndex0==9&&nIndex1==3)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,640);
		for(i=640;i>=586;i--)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}
		for (i=355;i>=284;i--)
		{
			Sleep(15);
			double b=0.3239*i+(586-355*0.3239);
			dc->LineTo(i,b);
		}
		for(i=563;i>=449;i--)
		{
	  		Sleep(15);
			dc->LineTo(284,i);
		}
		for(i=284;i>=260;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
	for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=370;i>=83;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}

	}

	if (nIndex0==9&&nIndex1==4)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,640);
		for(i=640;i>=586;i--)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}
		for (i=355;i>=284;i--)
		{
			Sleep(15);
			double b=0.3239*i+(586-355*0.3239);
			dc->LineTo(i,b);
		}
		for(i=563;i>=449;i--)
		{
	  		Sleep(15);
			dc->LineTo(284,i);
		}
		for(i=284;i>=260;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
		for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=370;i>=121;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}
	for(i=177;i>=127;i--)
	{
		Sleep(15);
		dc->LineTo(i,121);
	}
	}
	if (nIndex0==9&&nIndex1==5)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,640);
		for(i=640;i>=586;i--)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}
		for (i=355;i>=284;i--)
		{
			Sleep(15);
			double b=0.3239*i+(586-355*0.3239);
			dc->LineTo(i,b);
		}
		for(i=563;i>=449;i--)
		{
	  		Sleep(15);
			dc->LineTo(284,i);
		}
		for(i=284;i>=260;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
		for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=370;i>=245;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}
		

	}
	if (nIndex0==9&&nIndex1==6)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,640);
		for(i=640;i>=586;i--)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}
		for (i=355;i>=284;i--)
		{
			Sleep(15);
			double b=0.3239*i+(586-355*0.3239);
			dc->LineTo(i,b);
		}
		for(i=563;i>=449;i--)
		{
	  		Sleep(15);
			dc->LineTo(284,i);
		}
		for(i=284;i>=260;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
			for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=370;i>=346;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}

	}
	if (nIndex0==9&&nIndex1==7)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,640);
		for(i=640;i>=586;i--)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}
		for (i=355;i>=284;i--)
		{
			Sleep(15);
			double b=0.3239*i+(586-355*0.3239);
			dc->LineTo(i,b);
		}
		for(i=563;i>=449;i--)
		{
	  		Sleep(15);
			dc->LineTo(284,i);
		}
		for(i=284;i>=260;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
			for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=370;i>=216;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}

	}
	if (nIndex0==9&&nIndex1==8)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,640);
		for(i=640;i>=586;i--)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}
		for (i=355;i>=284;i--)
		{
			Sleep(15);
			double b=0.3239*i+(586-355*0.3239);
			dc->LineTo(i,b);
		}
		for(i=563;i>=449;i--)
		{
	  		Sleep(15);
			dc->LineTo(284,i);
		}
		for(i=284;i>=260;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
		for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=370;i>=216;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}
	for(i=177;i<=204;i++)
	{
		Sleep(15);
		dc->LineTo(i,216);
	}

	}
	
	if (nIndex0==9&&nIndex1==10)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,640);
		for(i=640;i>=586;i--)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}
		for (i=355;i>=284;i--)
		{
			Sleep(15);
			double b=0.3239*i+(586-355*0.3239);
			dc->LineTo(i,b);
		}
		for(i=563;i>=449;i--)
		{
	  		Sleep(15);
			dc->LineTo(284,i);
		}
		for(i=284;i>=260;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
		for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=177;i>=109;i--)
	{
		Sleep(15);
		double b=0.11765*i+362-109*0.11765;
		dc->LineTo(i,b);
	}

	}
	if (nIndex0==9&&nIndex1==11)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,640);
		for(i=640;i>=586;i--)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}
		for (i=355;i>=284;i--)
		{
			Sleep(15);
			double b=0.3239*i+(586-355*0.3239);
			dc->LineTo(i,b);
		}
		for(i=563;i>=449;i--)
		{
	  		Sleep(15);
			dc->LineTo(284,i);
		}
		for(i=284;i>=260;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
			for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for (i=370;i>=326;i--)
	{    Sleep(15);
	dc->LineTo(177,i);
	}
	for (i=177;i<=195;i++)
	{
		Sleep(15);
		dc->LineTo(i,326);
	}
	for (i=195;i<=213;i++)
	{
		Sleep(15);
		double b=-0.5*i+326+195*0.5;
		dc->LineTo(i,b);
	}

	}
	if (nIndex0==9&&nIndex1==12)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,640);
		for(i=640;i>=586;i--)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}
		for (i=355;i>=284;i--)
		{
			Sleep(15);
			double b=0.3239*i+(586-355*0.3239);
			dc->LineTo(i,b);
		}
		for(i=563;i>=449;i--)
		{
	  		Sleep(15);
			dc->LineTo(284,i);
		}
		for(i=284;i>=260;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
			for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=370;i>=176;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}
	for(i=177;i>=88;i--)
	{
		Sleep(15);
		dc->LineTo(i,176);
	}

	}
	if (nIndex0==9&&nIndex1==13)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,640);
		for(i=640;i>=586;i--)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}
		for (i=355;i>=284;i--)
		{
			Sleep(15);
			double b=0.3239*i+(586-355*0.3239);
			dc->LineTo(i,b);
		}
		for(i=563;i>=449;i--)
		{
	  		Sleep(15);
			dc->LineTo(284,i);
		}
		for(i=284;i>=260;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
		for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=370;i>=302;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}
	for(i=177;i<=224;i++)
	{
		Sleep(15);
		double b=-0.34*i+302+177*0.34;
		dc->LineTo(i,b);
	}

	}
	if (nIndex0==9&&nIndex1==14)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(355,640);
	for(i=640;i>=586;i--)
	{
		Sleep(15);
		dc->LineTo(355,i);
	}
	for (i=355;i>=284;i--)
	{
		Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
	}
	for(i=563;i>=449;i--)
	{
	  	Sleep(15);
		dc->LineTo(284,i);
	}
	for (i=450;i>=417;i--)
	{    Sleep(15);
	dc->LineTo(287,i);
	}


	}
	if (nIndex0==9&&nIndex1==15)
	{
		m_mtneft.GetDC(dc);
m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(355,640);
	for(i=640;i>=586;i--)
	{
		Sleep(15);
		dc->LineTo(355,i);
	}
	for (i=355;i>=284;i--)
	{
		Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
	}
	for(i=563;i>=449;i--)
	{
	  	Sleep(15);
		dc->LineTo(284,i);
	}
	for (i=450;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(287,i);
	}


	}
	if (nIndex0==9&&nIndex1==16)
	{
		m_mtneft.GetDC(dc);
m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(355,640);
	for(i=640;i>=586;i--)
	{
		Sleep(15);
		dc->LineTo(355,i);
	}
	for (i=355;i>=284;i--)
	{
		Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
	}
	for(i=563;i>=449;i--)
	{
	  	Sleep(15);
		dc->LineTo(284,i);
	}
for(i=284;i>=260;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}
	for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=370;i>=121;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}
	for(i=177;i>=127;i--)
	{
		Sleep(15);
		dc->LineTo(i,121);
	}
	for(i=127;i>=73;i--)
	{
		Sleep(15);
		double b=0.2222*i+109-73*0.2222;
		dc->LineTo(i,b);
	}


	}
	if (nIndex0==9&&nIndex1==17)
	{m_mtneft.GetDC(dc);
m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(355,640);
	for(i=640;i>=586;i--)
	{	
		Sleep(15);
		dc->LineTo(355,i);
	}
	for (i=355;i>=284;i--)
	{
		Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
	}
	for(i=563;i>=449;i--)
	{
	  	Sleep(15);
		dc->LineTo(284,i);
	}

	for (i=450;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(287,i);
	}
	for (i=285;i>=260;i--)
	{    Sleep(30);
		double b=2.16*i+315-260*2.16;
	dc->LineTo(i,b);
	}


	}
	if (nIndex0==9&&nIndex1==18)
	{
		m_mtneft.GetDC(dc);
m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(355,640);
	for(i=640;i>=586;i--)
	{	
		Sleep(15);
		dc->LineTo(355,i);
	}
	for (i=355;i>=284;i--)
	{
		Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
	}
	for(i=563;i>=449;i--)
	{
	  	Sleep(15);
		dc->LineTo(284,i);
	}
for(i=284;i>=260;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=260;i>=233;i--)
	{
		Sleep(15);
		dc->LineTo(i,450);
	}

	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=413;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(233,i);
	}
	for (i=233;i>=177;i--)
	{
		Sleep(15);
		dc->LineTo(i,370);
	}
	for(i=370;i>=197;i--)
	{
		Sleep(15);
		dc->LineTo(177,i);
	}

	}
	if (nIndex0==9&&nIndex1==19)
	{
		m_mtneft.GetDC(dc);
m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(355,640);
	for(i=640;i>=586;i--)
	{	
		Sleep(15);
		dc->LineTo(355,i);
	}
	for (i=355;i>=284;i--)
	{
		Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
	}
	for(i=563;i>=449;i--)
	{
	  	Sleep(15);
		dc->LineTo(284,i);
	}
for (i=450;i>=370;i--)
	{    Sleep(15);
	dc->LineTo(287,i);
	}
	for (i=285;i>=269;i--)
	{    Sleep(30);
		double b=2.16*i+315-260*2.16;
	dc->LineTo(i,b);
	}
	}
	if (nIndex0==9&&nIndex1==20)
	{
		m_mtneft.GetDC(dc);
m_mtneft.Replace(IDB_BUILDING2);
	dc->MoveTo(355,640);
	for(i=640;i>=586;i--)
	{	
		Sleep(15);
		dc->LineTo(355,i);
	}
	for (i=355;i>=284;i--)
	{
		Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
	}
	for(i=563;i>=459;i--)
	{
	  	Sleep(15);
		dc->LineTo(284,i);
	}
	for (i=287;i<=357;i++)
	{    Sleep(15);
		
	dc->LineTo(i,459);
	}
	}
	/////////////////////////////////////////////
	if (nIndex0==10&&nIndex1==0)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(109,362);

		for(i=109;i<=177;i++)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
		for (i=370;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=413;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=256;i++)
		{    Sleep(15);
			
		dc->LineTo(i,413);
		}

	}
	if (nIndex0==10&&nIndex1==1)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(109,362);

		for(i=109;i<=177;i++)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
		
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=260;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}

	}
	if (nIndex0==10&&nIndex1==2)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(109,362);

		for(i=109;i<=177;i++)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
		for (i=370;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}

	}
	if (nIndex0==10&&nIndex1==3)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(109,362);

		for(i=109;i<=177;i++)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
		for (i=370;i>=83;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		
	}

	if (nIndex0==10&&nIndex1==4)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(109,362);

		for(i=109;i<=177;i++)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
		for (i=370;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}

	}
	if (nIndex0==10&&nIndex1==5)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(109,362);

		for(i=109;i<=177;i++)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
		for (i=370;i>=245;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==10&&nIndex1==6)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(109,362);

		for(i=109;i<=177;i++)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
		for (i=370;i>=346;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==10&&nIndex1==7)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(109,362);

		for(i=109;i<=177;i++)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
		for (i=370;i>=216;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==10&&nIndex1==8)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(109,362);

		for(i=109;i<=177;i++)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
		for (i=370;i>=216;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}

	}
	if (nIndex0==10&&nIndex1==9)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(109,362);

		for(i=109;i<=177;i++)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
		for (i=370;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=260;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}
		for(i=260;i<=287;i++)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
		
		for(i=449;i<=563;i++)
		{
			Sleep(15);
			dc->LineTo(284,i);
		}
		for (i=284;i<=355;i++)
		{
	    Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
		}
		for(i=586;i<=640;i++)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}

	}
	
	if (nIndex0==10&&nIndex1==11)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(109,362);

		for(i=109;i<=177;i++)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
		for (i=370;i>=326;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=195;i++)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=195;i<=213;i++)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==10&&nIndex1==12)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(109,362);

		for(i=109;i<=177;i++)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
		for (i=370;i>=176;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=88;i--)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}

	}
	if (nIndex0==10&&nIndex1==13)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(109,362);

		for(i=109;i<=177;i++)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
		for (i=370;i>=302;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=222;i++)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==10&&nIndex1==14)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(109,362);

		for(i=109;i<=177;i++)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
		for (i=370;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i<=417;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}

	}
	if (nIndex0==10&&nIndex1==15)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(109,362);

		for(i=109;i<=177;i++)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
		for (i=370;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

	}
	if (nIndex0==10&&nIndex1==16)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(109,362);

		for(i=109;i<=177;i++)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
		for (i=370;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for(i=127;i>=73;i--)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==10&&nIndex1==17)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(109,362);

		for(i=109;i<=177;i++)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
		for (i=370;i>=302;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=222;i++)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}
		for(i=222;i<=243;i++)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for(i=243;i<=260;i++)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==10&&nIndex1==18)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(109,362);

		for(i=109;i<=177;i++)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
		for (i=370;i>=197;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==10&&nIndex1==19)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(109,362);

		for(i=109;i<=177;i++)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
		for (i=370;i>=360;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for(i=177;i<=225;i++)
		{
			Sleep(15);
			double b=-0.521*i+360+177*0.521;

			dc->LineTo(i,b);
		}
		for(i=225;i<=234;i++)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for(i=234;i<=250;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==10&&nIndex1==20)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(109,362);

		for(i=109;i<=177;i++)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
		for (i=370;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i<=460;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i<=355;i++)
		{
			Sleep(15);
			dc->LineTo(i,460);
		}


	}
	///////////////////////////////////////////
	if (nIndex0==11&&nIndex1==0)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(213,317);
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=413;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=256;i++)
		{    Sleep(15);
			
		dc->LineTo(i,413);
		}


	}
	if (nIndex0==11&&nIndex1==1)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(213,317);
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=260;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}

	}
	if (nIndex0==11&&nIndex1==2)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(213,317);
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}

	}
	if (nIndex0==11&&nIndex1==3)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(213,317);
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=83;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
	}

	if (nIndex0==11&&nIndex1==4)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(213,317);
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}

	}
	if (nIndex0==11&&nIndex1==5)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(213,317);
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=245;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==11&&nIndex1==6)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(213,317);
		for(i=213;i<=225;i++)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for(i=225;i>=210;i--)
		{
			Sleep(15);
			double b=-0.521*i+360+177*0.521;
			dc->LineTo(i,b);
		}
		
	}
	if (nIndex0==11&&nIndex1==7)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(213,317);
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=216;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==11&&nIndex1==8)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(213,317);
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=216;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}

	}
	if (nIndex0==11&&nIndex1==9)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(213,317);
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=260;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}
		for(i=260;i<=287;i++)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
		
		for(i=449;i<=563;i++)
		{
			Sleep(15);
			dc->LineTo(284,i);
		}
		for (i=284;i<=355;i++)
		{
	    Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
		}
		for(i=586;i<=640;i++)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}

	}
	if (nIndex0==11&&nIndex1==10)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(213,317);
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=109;i--)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}

	}
	
	if (nIndex0==11&&nIndex1==12)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(213,317);
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=176;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=88;i--)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}

	}
	if (nIndex0==11&&nIndex1==13)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(213,317);
		for (i=213;i<=235;i++)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}

		for(i=235;i>=222;i--)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}		
	}
	if (nIndex0==11&&nIndex1==14)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(213,317);
		for(i=213;i<=234;i++)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for(i=234;i<=250;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for(i=250;i<=270;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for (i=270;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for (i=369;i<=417;i++)
		{    Sleep(30);
		dc->LineTo(285,i);
		}
	}
	if (nIndex0==11&&nIndex1==15)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(213,317);
		for(i=213;i<=234;i++)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for(i=234;i<=250;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for(i=250;i<=270;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for (i=270;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}

	}
	if (nIndex0==11&&nIndex1==16)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(213,317);
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for(i=127;i>=73;i--)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==11&&nIndex1==17)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(213,317);
		for (i=213;i<=235;i++)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}

		for(i=235;i<=243;i++)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for(i=243;i<=260;i++)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
	}
	if (nIndex0==11&&nIndex1==18)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(213,317);
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=197;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==11&&nIndex1==19)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(213,317);
		for(i=213;i<=234;i++)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for(i=234;i<=250;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		

	}
	if (nIndex0==11&&nIndex1==20)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(213,317);
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i<=460;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i<=355;i++)
		{
			Sleep(15);
			dc->LineTo(i,460);
		}
	}
	/////////////////////////////////////////////////////////////////////
	if (nIndex0==12&&nIndex1==0)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(88,176);
		for (i=88;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
		for (i=176;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=413;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=256;i++)
		{    Sleep(15);
			
		dc->LineTo(i,413);
		}

	}
	if (nIndex0==12&&nIndex1==1)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(88,176);
		for (i=88;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
		for (i=176;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=260;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}

	}
	if (nIndex0==12&&nIndex1==2)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(88,176);
		for (i=88;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
		for (i=176;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}

	}
	if (nIndex0==12&&nIndex1==3)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(88,176);
		for (i=88;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
		for (i=176;i>=83;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
	}

	if (nIndex0==12&&nIndex1==4)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(88,176);
		for (i=88;i<=127;i++)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
		for (i=176;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(127,i);
		}


	}
	if (nIndex0==12&&nIndex1==5)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(88,176);
		for (i=88;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
		for (i=176;i<=245;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==12&&nIndex1==6)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(88,176);
		for (i=88;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
		for (i=176;i<=346;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==12&&nIndex1==7)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(88,176);
		for (i=88;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
		for (i=176;i<=216;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==12&&nIndex1==8)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(88,176);
		for (i=88;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
		for (i=176;i<=216;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}

	}
	if (nIndex0==12&&nIndex1==9)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(88,176);
		for (i=88;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
		for (i=176;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=260;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}
		for(i=260;i<=287;i++)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
		
		for(i=449;i<=563;i++)
		{
			Sleep(15);
			dc->LineTo(284,i);
		}
		for (i=284;i<=355;i++)
		{
	    Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
		}
		for(i=586;i<=640;i++)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}

	}
	if (nIndex0==12&&nIndex1==10)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(88,176);
		for (i=88;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
		for (i=176;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=109;i--)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==12&&nIndex1==11)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(88,176);
		for (i=88;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
		for (i=176;i<=326;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=195;i++)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=195;i<=213;i++)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}

	}
	
	if (nIndex0==12&&nIndex1==13)
	{	
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(88,176);
		for (i=88;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
		for (i=176;i<=302;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=222;i++)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==12&&nIndex1==14)
	{
			m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(88,176);
		for (i=88;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
		for (i=176;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i<=417;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}

	}
	if (nIndex0==12&&nIndex1==15)
	{
			m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(88,176);
		for (i=88;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
		for (i=176;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

	}
	if (nIndex0==12&&nIndex1==16)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(88,176);
		for (i=88;i<=127;i++)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
		for (i=176;i<=121;i++)
		{
			Sleep(15);
			dc->LineTo(127,i);
		}
		for(i=127;i>=73;i--)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==12&&nIndex1==17)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(88,176);
		for (i=88;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
		for (i=176;i<=302;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=222;i++)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}
		for(i=222;i<=243;i++)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for(i=243;i<=260;i++)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==12&&nIndex1==18)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(88,176);
		for (i=88;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
		for (i=176;i<=197;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==12&&nIndex1==19)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(88,176);
		for (i=88;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
		for (i=176;i<=360;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for(i=177;i<=225;i++)
		{
			Sleep(15);
			double b=-0.521*i+360+177*0.521;

			dc->LineTo(i,b);
		}
		for(i=225;i<=234;i++)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for(i=234;i<=250;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==12&&nIndex1==20)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(88,176);
		for (i=88;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
		for (i=176;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i<=460;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i<=355;i++)
		{
			Sleep(15);
			dc->LineTo(i,460);
		}

	}
	///////////////////////////////////////
	if (nIndex0==13&&nIndex1==0)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(222,284);
		for(i=222;i<=243;i++)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for(i=243;i<=260;i++)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for (i=260;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for (i=369;i<=413;i++)
		{
			Sleep(15);
			dc->LineTo(286,i);
		} 
		for (i=286;i>=256;i--)
		{
			Sleep(15);
			dc->LineTo(i,413);
		}

	}
	if (nIndex0==13&&nIndex1==1)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(222,284);
		for(i=222;i<=243;i++)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for(i=243;i<=260;i++)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for (i=260;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for (i=369;i<=450;i++)
		{
			Sleep(15);
			dc->LineTo(286,i);
		} 
		for (i=286;i>=260;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}

	}
	if (nIndex0==13&&nIndex1==2)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(222,284);
		for(i=222;i<=243;i++)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for(i=243;i<=260;i++)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for (i=260;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for (i=369;i<=450;i++)
		{
			Sleep(15);
			dc->LineTo(286,i);
		} 
		for (i=286;i>=204;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}

	}
	if (nIndex0==13&nIndex1==3)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(222,284);
		for (i=222;i>=177;i--)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}
		for (i=302;i>=83;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}

	if (nIndex0==13&&nIndex1==4)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(222,284);
		for (i=222;i>=177;i--)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}
		for (i=302;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}

	}
	if (nIndex0==13&&nIndex1==5)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(222,284);
		for (i=222;i>=177;i--)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}
		for (i=302;i>=245;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==13&&nIndex1==6)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(222,284);
		for(i=222;i<=235;i++)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for (i=235;i>=213;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for(i=213;i<=225;i++)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for(i=225;i>=210;i--)
		{
			Sleep(15);
			double b=-0.521*i+360+177*0.521;
			dc->LineTo(i,b);
		}
	}
	if (nIndex0==13&&nIndex1==7)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(222,284);
		for (i=222;i>=177;i--)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}
		for (i=302;i>=216;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==13&&nIndex1==8)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(222,284);
		for (i=222;i>=177;i--)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}
		for (i=302;i>=216;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}

	}
	if (nIndex0==13&&nIndex1==9)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(222,284);
		for(i=222;i<=243;i++)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for(i=243;i<=260;i++)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for (i=260;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for(i=369;i<=563;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i<=355;i++)
		{
	    Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
		}
		for(i=586;i<=640;i++)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}

	}
	if (nIndex0==13&&nIndex1==10)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(222,284);
		for (i=222;i>=177;i--)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}
		for (i=302;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=109;i--)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==13&&nIndex1==11)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(222,284);
		for(i=222;i<=235;i++)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for (i=235;i>=213;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
	}
	if (nIndex0==13&&nIndex1==12)
	{
		
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(222,284);
		for (i=222;i>=177;i--)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}
		for (i=302;i>=176;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=88;i--)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}

	}

	if (nIndex0==13&&nIndex1==14)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(222,284);
		for(i=222;i<=243;i++)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for(i=243;i<=260;i++)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for (i=260;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for (i=369;i<=418;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}

	}
	if (nIndex0==13&&nIndex1==15)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(222,284);
		for(i=222;i<=243;i++)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for(i=243;i<=260;i++)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for (i=260;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
	}
	if (nIndex0==13&&nIndex1==16)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(222,284);
		for (i=222;i>=177;i--)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}
		for (i=302;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for(i=127;i>=73;i--)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}

	}

	if (nIndex0==13&&nIndex1==17)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(222,284);
		for(i=222;i<=243;i++)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for(i=243;i<=260;i++)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
	}
	if (nIndex0==13&&nIndex1==18)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(222,284);
		for (i=222;i>=177;i--)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}
		for (i=302;i>=197;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==13&&nIndex1==19)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(222,284);
		for(i=222;i<=243;i++)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for(i=243;i<=260;i++)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for (i=260;i<=270;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
	}
	if (nIndex0==13&&nIndex1==20)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(222,284);
		for(i=222;i<=243;i++)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for(i=243;i<=260;i++)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for (i=260;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for (i=369;i<=460;i++)
		{    Sleep(30);
		dc->LineTo(285,i);
		}
		for (i=286;i<=355;i++)
		{    Sleep(30);
		dc->LineTo(i,460);
		}
	}/////////////////////////////////////////////////////
	if (nIndex0==14&&nIndex1==0)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(284,417);
		for (i=417;i>=413;i--)
		{
			Sleep(15);
			dc->LineTo(286,i);
		} 
		for (i=286;i>=256;i--)
		{
			Sleep(15);
			dc->LineTo(i,413);
		} 
	}
	if (nIndex0==14&&nIndex1==1)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(284,417);
		for (i=417;i>=450;i--)
		{
			Sleep(15);
			dc->LineTo(286,i);
		} 
		for (i=286;i>=260;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		} 

	}
	if (nIndex0==14&&nIndex1==2)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(284,417);
		for (i=417;i>=450;i--)
		{
			Sleep(15);
			dc->LineTo(286,i);
		} 
		for (i=286;i>=204;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		} 

	}
	if (nIndex0==14&nIndex1==3)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(284,417);
		for (i=417;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=83;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
	}


	if (nIndex0==14&&nIndex1==4)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(284,417);
		for (i=417;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}

	}
	if (nIndex0==14&&nIndex1==5)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(284,417);
		for (i=417;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=245;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==14&&nIndex1==6)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(284,417);
		for (i=417;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		
		for (i=285;i>=270;i--)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for(i=270;i>=250;i--)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for(i=250;i>=234;i--)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for(i=225;i>=210;i--)
		{
			Sleep(15);
			double b=-0.521*i+360+177*0.521;

			dc->LineTo(i,b);
		}

	}
	if (nIndex0==14&&nIndex1==7)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(284,417);
		for (i=417;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=216;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==14&&nIndex1==8)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(284,417);
		for (i=417;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=216;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}

	}
	if (nIndex0==14&&nIndex1==9)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(284,417);
		for(i=417;i<=563;i++)
		{
			Sleep(15);
			dc->LineTo(284,i);
		}
		for (i=284;i<=355;i++)
		{
	    Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
		}
		for(i=586;i<=640;i++)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}

	}
	if (nIndex0==14&&nIndex1==10)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(284,417);
		for (i=417;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=177;i>=109;i--)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==14&&nIndex1==11)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(284,417);
		for (i=417;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=260;i--)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for(i=260;i>=243;i--)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for(i=243;i>=235;i--)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for (i=235;i>=213;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==14&&nIndex1==12)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(284,417);
		for (i=417;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=176;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=88;i--)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}

	}
	if (nIndex0==14&&nIndex1==13)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(284,417);
		for (i=417;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=260;i--)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for(i=260;i>=243;i--)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for(i=243;i>=222;i--)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}

	}
	
	if (nIndex0==14&&nIndex1==15)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(284,417);
		for (i=417;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
	
	}
	if (nIndex0==14&&nIndex1==16)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(284,417);
		for (i=417;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		 for(i=127;i>=73;i--)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==14&&nIndex1==17)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(284,417);
		for (i=417;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=260;i--)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}

	}
	if (nIndex0==14&&nIndex1==18)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(284,417);
		for (i=417;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=197;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==14&&nIndex1==19)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(284,417);
		for (i=417;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		
		for (i=285;i>=270;i--)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for(i=270;i>=250;i--)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
	}
	if (nIndex0==14&&nIndex1==20)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(284,417);
		for (i=417;i<=460;i++)
		{
			Sleep(15);
			dc->LineTo(286,i);
		}
		for (i=286;i<=355;i++)
		{
			Sleep(15);
			dc->LineTo(i,460);
		}
	}////////////////////////////////////////////////////////////////
	if (nIndex0==15&&nIndex1==0)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(285,369);
		for (i=369;i<=413;i++)
		{
			Sleep(15);
			dc->LineTo(286,i);
		} 
		for (i=286;i>=256;i--)
		{
			Sleep(15);
			dc->LineTo(i,413);
		} 

	}
	if (nIndex0==15&&nIndex1==1)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(285,369);
		for (i=369;i<=450;i++)
		{
			Sleep(15);
			dc->LineTo(286,i);
		} 
		for (i=286;i>=260;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}

	}
	if (nIndex0==15&&nIndex1==2)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(285,369);
		for (i=369;i<=450;i++)
		{
			Sleep(15);
			dc->LineTo(286,i);
		} 
		for (i=286;i>=204;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}

	}
	if (nIndex0==15&nIndex1==3)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(285,369);
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=83;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}

	if (nIndex0==15&&nIndex1==4)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(285,369);
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}

	}
	if (nIndex0==15&&nIndex1==5)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(285,369);
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=245;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==15&&nIndex1==6)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(285,369);
		for (i=285;i>=270;i--)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for(i=270;i>=250;i--)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for(i=250;i>=234;i--)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for(i=225;i>=210;i--)
		{
			Sleep(15);
			double b=-0.521*i+360+177*0.521;

			dc->LineTo(i,b);
		}

	}
	if (nIndex0==15&&nIndex1==7)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(285,369);
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=216;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==15&&nIndex1==8)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(285,369);
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=216;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}

	}
	if (nIndex0==15&&nIndex1==9)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(285,369);
		for(i=369;i<=563;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i<=355;i++)
		{
	    Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
		}
		for(i=586;i<=640;i++)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}

	}
	if (nIndex0==15&&nIndex1==10)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(285,369);
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=177;i>=109;i--)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==15&&nIndex1==11)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(285,369);
		for (i=285;i>=260;i--)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for(i=260;i>=243;i--)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for(i=243;i>=235;i--)
		{
			Sleep(15);
			double b=1.7143*i+285-222*1.7143;
			dc->LineTo(i,b);
		}
		for (i=235;i>=213;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==15&&nIndex1==12)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(285,369);
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=176;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=88;i--)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}

	}
	if (nIndex0==15&&nIndex1==13)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(285,369);
		for (i=285;i>=260;i--)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for(i=260;i>=243;i--)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for(i=243;i>=222;i--)
		{
			Sleep(15);
			double b=1.7143*i+285-222*1.7143;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==15&&nIndex1==14)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(285,369);
		for (i=369;i<=418;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
	}
	
	if (nIndex0==15&&nIndex1==16)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(285,369);
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		 for(i=127;i>=73;i--)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==15&&nIndex1==17)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(285,369);
		for (i=285;i>=260;i--)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}

	}
	if (nIndex0==15&&nIndex1==18)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(285,369);
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=197;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==15&&nIndex1==19)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(285,369);
		
		for (i=285;i>=270;i--)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for(i=270;i>=250;i--)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==15&&nIndex1==20)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(285,369);
		for (i=369;i<=460;i++)
		{
			Sleep(15);
			dc->LineTo(286,i);
		}
		for (i=286;i<=355;i++)
		{
			Sleep(15);
			dc->LineTo(i,460);
		}

	}/////////////////////////////////////////////////////////////////
	if (nIndex0==16&&nIndex1==0)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(73,109);
		for(i=73;i<=127;i++)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);

		}
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=413;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=256;i++)
		{    Sleep(15);
			
		dc->LineTo(i,413);
		}


	}
	
	if (nIndex0==16&&nIndex1==1)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(73,109);
		for(i=73;i<=127;i++)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=260;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}

	}
	if (nIndex0==16&&nIndex1==2)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(73,109);
		for(i=73;i<=127;i++)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}

	}
	if (nIndex0==16&nIndex1==3)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(73,109);
		for(i=73;i<=127;i++)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}

	}

	if (nIndex0==16&&nIndex1==4)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(73,109);
		for(i=73;i<=127;i++)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i>=83;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
	}
	if (nIndex0==16&&nIndex1==5)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(73,109);
		for(i=73;i<=127;i++)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=245;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
	}
	if (nIndex0==16&&nIndex1==6)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(73,109);
		for(i=73;i<=127;i++)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=346;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==16&&nIndex1==7)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(73,109);
		for(i=73;i<=127;i++)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=216;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==16&&nIndex1==8)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(73,109);
		for(i=73;i<=127;i++)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=216;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}

	}
	if (nIndex0==16&&nIndex1==9)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(73,109);
		for(i=73;i<=127;i++)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=260;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}
		for(i=260;i<=287;i++)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
		
		for(i=449;i<=563;i++)
		{
			Sleep(15);
			dc->LineTo(284,i);
		}
		for (i=284;i<=355;i++)
		{
	    Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
		}
		for(i=586;i<=640;i++)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}

	}
	if (nIndex0==16&&nIndex1==10)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(73,109);
		for(i=73;i<=127;i++)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=109;i--)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==16&&nIndex1==11)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(73,109);
		for(i=73;i<=127;i++)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=326;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=195;i++)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=195;i<=213;i++)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==16&&nIndex1==12)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(73,109);
		for(i=73;i<=127;i++)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}
		for (i=121;i<=176;i++)
		{
			Sleep(15);
			dc->LineTo(127,i);
		}
		for (i=121;i>=88;i--)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}

	}
	if (nIndex0==16&&nIndex1==13)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(73,109);
		for(i=73;i<=127;i++)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=302;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=222;i++)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==16&&nIndex1==14)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(73,109);
		for(i=73;i<=127;i++)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i<=417;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}

	}
	if (nIndex0==16&&nIndex1==15)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(73,109);
		for(i=73;i<=127;i++)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

	}
	
	if (nIndex0==16&&nIndex1==17)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(73,109);
		for(i=73;i<=127;i++)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=302;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=222;i++)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}
		for(i=222;i<=243;i++)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for(i=243;i<=260;i++)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==16&&nIndex1==18)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(73,109);
		for(i=73;i<=127;i++)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=197;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
	}
	if (nIndex0==16&&nIndex1==19)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(73,109);
		for(i=73;i<=127;i++)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=360;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for(i=177;i<=225;i++)
		{
			Sleep(15);
			double b=-0.521*i+360+177*0.521;

			dc->LineTo(i,b);
		}
		for(i=225;i<=234;i++)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for(i=234;i<=250;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==16&&nIndex1==20)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(73,109);
		for(i=73;i<=127;i++)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}
		for (i=127;i<=177;i++)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for (i=121;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i<=460;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i<=355;i++)
		{
			Sleep(15);
			dc->LineTo(i,460);
		}

	}
	//////////////////////////////////////////////
	if (nIndex0==17&&nIndex1==0)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(260,315);
		for (i=260;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for (i=369;i<=413;i++)
		{
			Sleep(15);
			dc->LineTo(286,i);
		} 
		for (i=286;i>=256;i--)
		{
			Sleep(15);
			dc->LineTo(i,413);
		} 

	}
	if (nIndex0==17&&nIndex1==1)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(260,315);
		for (i=260;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for (i=369;i<=450;i++)
		{
			Sleep(15);
			dc->LineTo(286,i);
		} 
		for (i=286;i>=260;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}


	}
	if (nIndex0==17&&nIndex1==2)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(260,315);
		for (i=260;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for (i=369;i<=450;i++)
		{
			Sleep(15);
			dc->LineTo(286,i);
		} 
		for (i=286;i>=204;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}

	}
	if (nIndex0==17&nIndex1==3)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(260,315);
		for(i=260;i>=243;i--)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for(i=243;i>=235;i--)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for (i=235;i>=213;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=83;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}

	if (nIndex0==17&&nIndex1==4)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(260,315);
		for(i=260;i>=243;i--)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for(i=243;i>=235;i--)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for (i=235;i>=213;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}

	}
	if (nIndex0==17&&nIndex1==5)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(260,315);
		for(i=260;i>=243;i--)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for(i=243;i>=235;i--)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for (i=235;i>=213;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=245;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==17&&nIndex1==6)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(260,315);
		for(i=260;i<=270;i++)
		{
			Sleep(30);
			double b=2.16*i+315-260*2.16;
			dc->LineTo(i,b);
		} 
		for(i=270;i>=234;i--)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;

			dc->LineTo(i,b);
		} 
		for(i=234;i>=225;i--)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for(i=225;i>=210;i--)
		{
			Sleep(15);
			double b=-0.521*i+360+177*0.521;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==17&&nIndex1==7)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(260,315);
		for(i=260;i>=243;i--)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for(i=243;i>=235;i--)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for (i=235;i>=213;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=216;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==17&&nIndex1==8)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(260,315);
		for(i=260;i>=243;i--)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for(i=243;i>=235;i--)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for (i=235;i>=213;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=216;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}

	}
	if (nIndex0==17&&nIndex1==9)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(260,315);
		for (i=260;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for(i=369;i<=563;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i<=355;i++)
		{
	    Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
		}
		for(i=586;i<=640;i++)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}

	}
	if (nIndex0==17&&nIndex1==10)
	{m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(260,315);
		for(i=260;i>=243;i--)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for(i=243;i>=235;i--)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for (i=235;i>=213;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=109;i--)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==17&&nIndex1==11)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(260,315);
		for(i=260;i>=243;i--)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for(i=243;i>=235;i--)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for (i=235;i>=213;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==17&&nIndex1==12)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(260,315);
		for(i=260;i>=243;i--)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for(i=243;i>=235;i--)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for (i=235;i>=213;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=176;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=88;i--)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
	}
	if (nIndex0==17&&nIndex1==13)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(260,315);
		for(i=260;i>=243;i--)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for(i=243;i>=222;i--)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
	}
	if (nIndex0==17&&nIndex1==14)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(260,315);
		for (i=260;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for (i=369;i<=418;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}

	}
	if (nIndex0==17&&nIndex1==15)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(260,315);
		for (i=260;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
	}
	if (nIndex0==17&&nIndex1==16)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(260,315);
		for(i=260;i>=243;i--)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for(i=243;i>=235;i--)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for (i=235;i>=213;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for(i=127;i>=73;i--)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}

	}
	
	if (nIndex0==17&&nIndex1==18)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(260,315);
		for(i=260;i>=243;i--)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for(i=243;i>=235;i--)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for (i=235;i>=213;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=197;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==17&&nIndex1==19)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(260,315);
		for(i=260;i<=270;i++)
		{
			Sleep(30);
			double b=2.16*i+315-260*2.16;
			dc->LineTo(i,b);
		} 
		for(i=270;i>=250;i--)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;

			dc->LineTo(i,b);
		}
	}
	if (nIndex0==17&&nIndex1==20)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(260,315);
		for (i=260;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for (i=369;i<=460;i++)
		{
			Sleep(15);
			dc->LineTo(286,i);
		}
		for (i=286;i<=355;i++)
		{
			Sleep(15);
			dc->LineTo(i,460);
		}

	}
////////////////////////////////////////////////////////////
	if (nIndex0==18&&nIndex1==0)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,197);
		for (i=197;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=413;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=256;i++)
		{    Sleep(15);
			
		dc->LineTo(i,413);
		}

	}
	if (nIndex0==18&&nIndex1==1)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,197);
		for (i=197;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=260;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}

	}
	if (nIndex0==18&&nIndex1==2)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,197);
		for (i=197;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}

	}
	if (nIndex0==18&nIndex1==3)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,197);
		for (i=197;i>=83;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
	}

	if (nIndex0==18&&nIndex1==4)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,197);
		for (i=197;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}

	}
	if (nIndex0==18&&nIndex1==5)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,197);
		for (i=197;i<=245;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==18&&nIndex1==6)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,197);
		for (i=197;i<=346;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==18&&nIndex1==7)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,197);
		for (i=197;i<=216;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==18&&nIndex1==8)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,197);
		for (i=197;i<=216;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}

	}
	if (nIndex0==18&&nIndex1==9)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,197);
		for (i=197;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=233;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

		for (i=370;i<=450;i++)
		{    Sleep(15);
		dc->LineTo(233,i);
		}
		for (i=233;i<=260;i++)
		{    Sleep(15);
			
		dc->LineTo(i,450);
		}
		for(i=260;i<=287;i++)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}
		
		for(i=449;i<=563;i++)
		{
			Sleep(15);
			dc->LineTo(284,i);
		}
		for (i=284;i<=355;i++)
		{
	    Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
		}
		for(i=586;i<=640;i++)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}

	}
	if (nIndex0==18&&nIndex1==10)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,197);
		for (i=197;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=109;i--)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==18&&nIndex1==11)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,197);
		for (i=197;i<=326;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=195;i++)
		{	
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=195;i<=213;i++)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==18&&nIndex1==12)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,197);
		for (i=197;i>=176;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=88;i--)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}

	}
	if (nIndex0==18&&nIndex1==13)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,197);
		for (i=197;i<=302;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=222;i++)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==18&&nIndex1==14)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,197);
		for (i=197;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i<=417;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}

	}
	if (nIndex0==18&&nIndex1==15)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,197);
		for (i=197;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}

	}
	if (nIndex0==18&&nIndex1==16)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,197);
		for (i=197;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for(i=127;i>=73;i--)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==18&&nIndex1==17)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,197);
		for (i=197;i<=302;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=222;i++)
		{
			Sleep(15);
			double b=-0.34*i+302+177*0.34;
			dc->LineTo(i,b);
		}
		for(i=222;i<=243;i++)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for(i=243;i<=260;i++)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}

	}
	
	if (nIndex0==18&&nIndex1==19)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,197);
		for (i=197;i<=360;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for(i=177;i<=225;i++)
		{
			Sleep(15);
			double b=-0.521*i+360+177*0.521;

			dc->LineTo(i,b);
		}
		for(i=225;i<=234;i++)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for(i=234;i<=250;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==18&&nIndex1==20)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(177,197);
		for (i=197;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=285;i++)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i<=460;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i<=355;i++)
		{
			Sleep(15);
			dc->LineTo(i,460);
		}
	}
/////////////////////////////////////////////////////////////
	if (nIndex0==19&&nIndex1==0)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(250,341);
		for(i=250;i<=270;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for (i=270;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for (i=369;i<=413;i++)
		{
			Sleep(15);
			dc->LineTo(286,i);
		} 
		for (i=286;i>=256;i--)
		{
			Sleep(15);
			dc->LineTo(i,413);
		}

	}
	if (nIndex0==19&&nIndex1==1)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(250,341);
		for(i=250;i<=270;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for (i=270;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for (i=369;i<=450;i++)
		{
			Sleep(15);
			dc->LineTo(286,i);
		} 
		for (i=286;i>=260;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}

	}
	if (nIndex0==19&&nIndex1==2)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(250,341);
		for(i=250;i<=270;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for (i=270;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for (i=369;i<=450;i++)
		{
			Sleep(15);
			dc->LineTo(286,i);
		} 
		for (i=286;i>=204;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		}

	}
	if (nIndex0==19&nIndex1==3)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(250,341);
		for(i=250;i>=234;i--)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for(i=234;i>=213;i--)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=83;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}

	if (nIndex0==19&&nIndex1==4)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(250,341);
		for(i=250;i>=234;i--)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for(i=234;i>=213;i--)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}

	}
	if (nIndex0==19&&nIndex1==5)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(250,341);
		for(i=250;i>=234;i--)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for(i=234;i>=213;i--)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=245;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==19&&nIndex1==6)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(250,341);
		for(i=250;i>=234;i--)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		} 
		for(i=234;i>=225;i--)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		} 
		for(i=225;i>=210;i--)
		{
			Sleep(15);
			double b=-0.521*i+360+177*0.521;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==19&&nIndex1==7)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(250,341);
		for(i=250;i>=234;i--)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for(i=234;i>=213;i--)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=216;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	if (nIndex0==19&&nIndex1==8)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(250,341);
		for(i=250;i>=234;i--)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for(i=234;i>=213;i--)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=216;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}

	}
	if (nIndex0==19&&nIndex1==9)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(250,341);
		for(i=250;i<=270;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for (i=270;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for(i=369;i<=563;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i<=355;i++)
		{
	    Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
		}
		for(i=586;i<=640;i++)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}

	}
	if (nIndex0==19&&nIndex1==10)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(250,341);
		for(i=250;i>=234;i--)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for(i=234;i>=213;i--)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i<=370;i++)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=109;i--)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==19&&nIndex1==11)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(250,341);
		for(i=250;i>=234;i--)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for(i=234;i>=213;i--)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==19&&nIndex1==12)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(250,341);
		for(i=250;i>=234;i--)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for(i=234;i>=213;i--)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=176;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=88;i--)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}

	}
	if (nIndex0==19&&nIndex1==13)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(250,341);
		for(i=250;i<=270;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for (i=270;i>=260;i--)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for(i=260;i>=243;i--)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for(i=243;i>=222;i--)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
	}
	if (nIndex0==19&&nIndex1==14)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(250,341);
		for(i=250;i<=270;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for (i=270;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for (i=369;i<=418;i++)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}

	}
	if (nIndex0==19&&nIndex1==15)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(250,341);
		for(i=250;i<=270;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for (i=270;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}

	}
	if (nIndex0==19&&nIndex1==16)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(250,341);
		for(i=250;i>=234;i--)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for(i=234;i>=213;i--)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		for(i=127;i>=73;i--)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}

	}
	if (nIndex0==19&&nIndex1==17)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(250,341);
		for(i=250;i<=270;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for (i=270;i>=260;i--)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
	}
	if (nIndex0==19&&nIndex1==18)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(250,341);
		for(i=250;i>=234;i--)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for(i=234;i>=213;i--)
		{
			Sleep(15);
			double b=1.476*i+317-213*1.476;
			dc->LineTo(i,b);
		}
		for (i=213;i>=195;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
		for (i=195;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,326);
		}
		for (i=326;i>=197;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}

	}
	
	if (nIndex0==19&&nIndex1==20)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(250,341);
		for(i=250;i<=270;i++)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for (i=270;i<=285;i++)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}for (i=369;i<=460;i++)
		{
			Sleep(15);
			dc->LineTo(286,i);
		}
		for (i=286;i<=355;i++)
		{
			Sleep(15);
			dc->LineTo(i,460);
		}

	}
////////////////////////////////////////////////////////
	if (nIndex0==20&&nIndex1==0)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,460);
		for (i=355;i>=285;i--)
		{
			Sleep(15);
			dc->LineTo(i,460);
		}
		for (i=460;i>=413;i--)
		{
			Sleep(15);
			dc->LineTo(286,i);
		} 
		for (i=286;i>=256;i--)
		{
			Sleep(15);
			dc->LineTo(i,413);
		} 
	}
	if (nIndex0==20&&nIndex1==1)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,460);
		for (i=355;i>=285;i--)
		{
			Sleep(15);
			dc->LineTo(i,460);
		}
		for (i=460;i>=450;i--)
		{
			Sleep(15);
			dc->LineTo(286,i);
		} 
		for (i=286;i>=260;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		} 
	}
	if (nIndex0==20&&nIndex1==2)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,460);
		for (i=355;i>=285;i--)
		{
			Sleep(15);
			dc->LineTo(i,460);
		}
		for (i=460;i>=450;i--)
		{
			Sleep(15);
			dc->LineTo(286,i);
		} 
		for (i=286;i>=204;i--)
		{
			Sleep(15);
			dc->LineTo(i,450);
		} 
	}
	if (nIndex0==20&nIndex1==3)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,460);
		for (i=355;i>=285;i--)
		{
			Sleep(15);
			dc->LineTo(i,460);
		} 
		for (i=459;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=83;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
	}

	if (nIndex0==20&&nIndex1==4)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,460);
		for (i=355;i>=285;i--)
		{
			Sleep(15);
			dc->LineTo(i,460);
		} 
		for (i=459;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
	}
	if (nIndex0==20&&nIndex1==5)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,460);
		for (i=355;i>=285;i--)
		{
			Sleep(15);
			dc->LineTo(i,460);
		} 
		for (i=459;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=245;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
	}
	if (nIndex0==20&&nIndex1==6)
	{
					m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,460);
		for (i=355;i>=285;i--)
		{
			Sleep(15);
			dc->LineTo(i,460);
		} 
		for (i=459;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		
		for (i=285;i>=270;i--)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for(i=270;i>=250;i--)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for(i=250;i>=234;i--)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
		for(i=225;i>=210;i--)
		{
			Sleep(15);
			double b=-0.521*i+360+177*0.521;

			dc->LineTo(i,b);
		}
		
		
	}
	if (nIndex0==20&&nIndex1==7)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,460);
		for (i=355;i>=285;i--)
		{
			Sleep(15);
			dc->LineTo(i,460);
		} 
		for (i=459;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=216;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
	}
	if (nIndex0==20&&nIndex1==8)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,460);
		for (i=355;i>=285;i--)
		{
			Sleep(15);
			dc->LineTo(i,460);
		} 
		for (i=459;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=216;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i<=204;i++)
		{
			Sleep(15);
			dc->LineTo(i,216);
		}
	}
	if (nIndex0==20&&nIndex1==9)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,460);
		for (i=355;i>=285;i--)
		{
			Sleep(15);
			dc->LineTo(i,460);
		} 
		for(i=460;i<=563;i++)
		{
			Sleep(15);
			dc->LineTo(284,i);
		}
		for (i=284;i<=355;i++)
		{
	    Sleep(15);
		double b=0.3239*i+(586-355*0.3239);
		dc->LineTo(i,b);
		}
		for(i=586;i<=640;i++)
		{
			Sleep(15);
			dc->LineTo(355,i);
		}

	}
	if (nIndex0==20&&nIndex1==10)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,460);
		for (i=355;i>=285;i--)
		{
			Sleep(15);
			dc->LineTo(i,460);
		} 
		for (i=459;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=177;i>=109;i--)
		{
			Sleep(15);
			double b=0.11765*i+362-109*0.11765;
			dc->LineTo(i,b);
		}
		
	}
	if (nIndex0==20&&nIndex1==11)
	{
			
			m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,460);
		for (i=355;i>=285;i--)
		{
			Sleep(15);
			dc->LineTo(i,460);
		} 
		for (i=459;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=260;i--)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for(i=260;i>=243;i--)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for(i=243;i>=235;i--)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		for (i=235;i>=213;i--)
		{
			Sleep(15);
			double b=-0.5*i+326+195*0.5;
			dc->LineTo(i,b);
		}
	}
	if (nIndex0==20&&nIndex1==12)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,460);
		for (i=355;i>=285;i--)
		{
			Sleep(15);
			dc->LineTo(i,460);
		} 
		for (i=459;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=176;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=88;i--)
		{
			Sleep(15);
			dc->LineTo(i,176);
		}
	}
	if (nIndex0==20&&nIndex1==13)
	{
		
			m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,460);
		for (i=355;i>=285;i--)
		{
			Sleep(15);
			dc->LineTo(i,460);
		} 
		for (i=459;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=260;i--)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for(i=260;i>=243;i--)
		{
			Sleep(15);
			double b=-0.294*i+320+243*0.294;
			dc->LineTo(i,b);
		}
		for(i=243;i>=222;i--)
		{
			Sleep(15);
			double b=1.7143*i+284-222*1.7143;
			dc->LineTo(i,b);
		}
		
	}
	if (nIndex0==20&&nIndex1==14)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,460);
		for (i=355;i>=285;i--)
		{
			Sleep(15);
			dc->LineTo(i,460);
		} 
		for (i=459;i>=417;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
	}
	if (nIndex0==20&&nIndex1==15)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,460);
		for (i=355;i>=285;i--)
		{
			Sleep(15);
			dc->LineTo(i,460);
		} 
		for (i=459;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
	}
	if (nIndex0==20&&nIndex1==16)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,460);
		for (i=355;i>=285;i--)
		{
			Sleep(15);
			dc->LineTo(i,460);
		} 
		for (i=459;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=121;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
		for (i=177;i>=127;i--)
		{
			Sleep(15);
			dc->LineTo(i,121);
		}
		 for(i=127;i>=73;i--)
		{
			Sleep(15);
			double b=0.2222*i+109-73*0.2222;
			dc->LineTo(i,b);
		}
	}
	if (nIndex0==20&&nIndex1==17)
	{
		
			m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,460);
		for (i=355;i>=285;i--)
		{
			Sleep(15);
			dc->LineTo(i,460);
		} 
		for (i=459;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=260;i--)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
	}
	if (nIndex0==20&&nIndex1==18)
	{
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,460);
		for (i=355;i>=285;i--)
		{
			Sleep(15);
			dc->LineTo(i,460);
		} 
		for (i=459;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		for (i=285;i>=177;i--)
		{
			Sleep(15);
			dc->LineTo(i,370);
		}
		for (i=370;i>=197;i--)
		{
			Sleep(15);
			dc->LineTo(177,i);
		}
	}
	if (nIndex0==20&&nIndex1==19)
	{
			m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		dc->MoveTo(355,460);
		for (i=355;i>=285;i--)
		{
			Sleep(15);
			dc->LineTo(i,460);
		} 
		for (i=459;i>=370;i--)
		{
			Sleep(15);
			dc->LineTo(285,i);
		}
		
		for (i=285;i>=270;i--)
		{    Sleep(30);
			double b=2.16*i+315-260*2.16;
		dc->LineTo(i,b);
		}
		for(i=270;i>=250;i--)
		{
			Sleep(15);
			double b=-0.4375*i+348+234*0.4375;
			dc->LineTo(i,b);
		}
	}
	
///////////////////////////////////////////////
	
}

	
}
void CCampusNavigationDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_check.department)
	{
		KillTimer(2);
	
	}
	m_check.normal=false;
	m_check.normalsence=false;
	m_check.route=false;
	m_check.search=true;//只有查找模式可以进行
	

	m_combbegin.ShowWindow(SW_HIDE);
	m_combdestion.ShowWindow(SW_HIDE);
	m_startlineto.ShowWindow(SW_HIDE);
//	m_comblocation.ShowWindow(SW_HIDE);
	m_combcreat.ShowWindow(SW_SHOW);
	m_butlocation.ShowWindow(SW_SHOW);
    m_shortest.ShowWindow(SW_HIDE);
	m_clock.ShowWindow(SW_HIDE);
	m_building.ShowWindow(SW_HIDE);
	m_roadmask.ShowWindow(SW_HIDE);
	m_shopping.ShowWindow(SW_HIDE);
	m_department.ShowWindow(SW_HIDE);
	m_entersence.ShowWindow(SW_HIDE);
	m_exitsence.ShowWindow(SW_HIDE);
	m_butlocation.ShowWindow(SW_SHOW);
	 GetDlgItem(IDC_STATIC3)->ShowWindow(SW_HIDE);
	 GetDlgItem(IDC_STATIC4)->ShowWindow(SW_HIDE);
	 m_showall.ShowWindow(SW_SHOW);
	 m_clearall.ShowWindow(SW_SHOW);
	 m_combdepartment.ShowWindow(SW_HIDE);
	 m_beginvisit.ShowWindow(SW_HIDE);
	 m_stopvisit.ShowWindow(SW_HIDE);
	 CDC *dc;
	 dc=GetDC();
	 // 			
	 m_mtneft.GetDC(dc);
	 m_mtneft.Replace(IDB_BUILDING2);//显示按钮设置
	 


	 
	 if (m_check.wsad)
	 {
		 m_check.wsad=false;
	 }
	 if (m_check.beginvisitsence)
	 {
		 m_check.beginvisitsence=false;
		 KillTimer(3);
		 timernum=0;

	 }
}

// void CCampusNavigationDlg::OnCbnSelchangeComboboxex1()
// {
// 	// TODO: 在此添加控件通知处理程序代码
// }

void CCampusNavigationDlg::OnCbnSelchangeCombo3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_check.combbegin=true;
    nIndex0=m_combbegin.GetCurSel();

}

void CCampusNavigationDlg::OnCbnSelchangeCombo4()
{

	// TODO: 在此添加控件通知处理程序代码
	m_check.combend=true;
	nIndex1=m_combdestion.GetCurSel();
}

//void CCampusNavigationDlg::OnBnClickedCancel()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	OnCancel();
//}

void CCampusNavigationDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
if (nIDEvent==1)
{   
	idnum=174;
	num=num+1;
    num=num%29;
    idnum=idnum+num;
	if(idnum!=195)
	{
		CBitmap card1;
    CDC  *dc,dcMem;
    dc=GetDC();
    dcMem.CreateCompatibleDC(dc);
    card1.LoadBitmap(idnum);
    dcMem.SelectObject(&card1);
    dc->BitBlt(585,380,365,350,&dcMem,0,0,SRCCOPY);
    DeleteObject(&card1);
   }
}
    
if (nIDEvent==2)
   {
	
	 photonum=photonum%4;

	 CDC *dc,dcMem;
	 dc=GetDC();
	 CBitmap figure1,figure2,figure3,figure4,figure5,figure6,figure7,figure8;                     //创建位图对象。
	 dcMem.CreateCompatibleDC(dc);                       //创建与当前设备描述表兼容的临时设备描述表
	 m_mtneft.GetDC(dc);
	 m_mtneft.Replace(IDB_BUILDING2);
	 if (photonum==0)
	 {
		 figure1.LoadBitmap(IDB_BIT_SONGJIAN1);
		 figure2.LoadBitmap(IDB_BIT_SONGJIAN2);
		 dcMem.SelectObject(&figure1);    
		 dc->BitBlt(0,300,549,501,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
		 dcMem.SelectObject(&figure2);    
		 dc->BitBlt(0,300,549,501,&dcMem,0,0,SRCPAINT);
	 }
	else if (photonum==1)
	 {
		 figure5.LoadBitmap(IDB_BIT_N1);
		 figure6.LoadBitmap(IDB_BIT_N2);
		 dcMem.SelectObject(&figure5);    
		 dc->BitBlt(73,15,549,501,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
		 dcMem.SelectObject(&figure6);    
		 dc->BitBlt(73,15,549,501,&dcMem,0,0,SRCPAINT);
	 }
	else if(photonum==2)
	 {
		 figure1.LoadBitmap(IDB_BIT_B1);
		 figure2.LoadBitmap(IDB_BIT_B2);
		 dcMem.SelectObject(&figure1);    
		 dc->BitBlt(200,200,549,501,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
		 dcMem.SelectObject(&figure2);    
		 dc->BitBlt(200,200,549,501,&dcMem,0,0,SRCPAINT);

	 }
	  else
	 {
		 figure3.LoadBitmap(IDB_BIT_H1);
		 figure4.LoadBitmap(IDB_BIT_H2);
		 dcMem.SelectObject(&figure3);    
		 dc->BitBlt(0,100,549,501,&dcMem,0,0,SRCAND);   //将图片1与背景做and运算 
		 dcMem.SelectObject(&figure4);    
		 dc->BitBlt(0,100,549,501,&dcMem,0,0,SRCPAINT);
		 // 		DeleteObject(figure3);
	   }
	   photonum=photonum+1;

    }
if(nIDEvent==3)
{
        	timernum=timernum+1;
			

				
	        CDC *dc,dcMem1;
			dc=GetDC(); 
	 		CBitmap figure1; 
			dcMem1.CreateCompatibleDC(dc); 
			figure1.LoadBitmap(m_deepphoto[timernum]);
			dcMem1.SelectObject(&figure1);
	 		dc->BitBlt(24,26,549,501,&dcMem1,0,0,SRCCOPY);
	 		dc->DeleteDC();
			if(timernum==57)
			{
				KillTimer(3);
				timernum=0;
			}

}
	
	CDialog::OnTimer(nIDEvent);
}

void CCampusNavigationDlg::OnCbnSelchangeCombo6()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CCampusNavigationDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码

	m_combbegin.ShowWindow(SW_HIDE);
	m_combdestion.ShowWindow(SW_HIDE);
	m_startlineto.ShowWindow(SW_HIDE);
//	m_comblocation.ShowWindow(SW_HIDE);
	m_combcreat.ShowWindow(SW_HIDE);
	m_butlocation.ShowWindow(SW_HIDE);
	m_entersence.ShowWindow(SW_HIDE);
	m_exitsence.ShowWindow(SW_HIDE);
	m_showall.ShowWindow(SW_HIDE);
	m_clearall.ShowWindow(SW_HIDE);
	m_combdepartment.ShowWindow(SW_SHOW);
	m_beginvisit.ShowWindow(SW_HIDE);
	m_stopvisit.ShowWindow(SW_HIDE);
	m_wepass.ShowWindow(SW_HIDE);



	m_clock.ShowWindow(SW_SHOW);
	m_building.ShowWindow(SW_SHOW);
	m_roadmask.ShowWindow(SW_SHOW);
	m_shopping.ShowWindow(SW_SHOW);
	m_department.ShowWindow(SW_SHOW);
	m_shortest.ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC4)->ShowWindow(SW_HIDE);


	m_check.normal=true;
	m_check.normalsence=false;
	m_check.route=false;
	m_check.search=false;
	if (m_check.wsad)
	{
		m_check.wsad=false;
	}
	if (m_check.beginvisitsence)
	{
		m_check.beginvisitsence=false;
		KillTimer(3);
		timernum=0;

	}
	
}

void CCampusNavigationDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	

		m_check.wsad=false;//不能进行人工寻路
		m_check.beginvisitsence=false;//不能自动观光
		CDC *dc;	
		dc=GetDC();
		m_mtneft.GetDC(dc);
		m_mtneft.Replace(IDB_BUILDING2);
		m_check.wsad==false;
		KillTimer(3);
		timernum=0;
		deepimagenum=0;
	


	
}

void CCampusNavigationDlg::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	
	
		

	
}

void CCampusNavigationDlg::OnCbnSelchangeCombo5()
{
	// TODO: 在此添加控件通知处理程序代码
	nIndex2=m_combcreat.GetCurSel();
	m_check.combsearch=true;
	CDC *dc;
	dc=GetDC();
	// 			
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);

}

void CCampusNavigationDlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
m_check.showall=true;
	CDC *dc,dcMem1,dcMem2;
	dc=GetDC();
	CBitmap figure1,figure2,*OldBitMap;                     //创建位图对象。
	dcMem1.CreateCompatibleDC(dc); 

    figure1.LoadBitmap(IDB_BIT_SIGN_2);
	figure2.LoadBitmap(IDB_BIT_SIGN_1);
	dcMem1.SelectObject(&figure1);
	dc->BitBlt(380,390,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
	dcMem1.SelectObject(&figure2);
	dc->BitBlt(380,390,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算
    dcMem1.SelectObject(&figure1);
	dc->BitBlt(240,366,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
	dcMem1.SelectObject(&figure2);
	dc->BitBlt(240,366,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算


	
	
		dcMem1.SelectObject(&figure1);
		dc->BitBlt(318,374,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(318,374,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		
		dcMem1.SelectObject(&figure1);
		dc->BitBlt(190,398,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(190,398,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		
		
		dcMem1.SelectObject(&figure1);
		dc->BitBlt(120,46,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(120,46,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

	
		
		dcMem1.SelectObject(&figure1);
		dc->BitBlt(113,215,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(113,215,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		
		
		dcMem1.SelectObject(&figure1);
		dc->BitBlt(168,320,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(168,320,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		
		dcMem1.SelectObject(&figure1);
		dc->BitBlt(115,195,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(115,195,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		
		
	dcMem1.SelectObject(&figure1);
		dc->BitBlt(192,208,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(192,208,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		
	dcMem1.SelectObject(&figure1);
		dc->BitBlt(98,310,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(98,310,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

	
		
		dcMem1.SelectObject(&figure1);
		dc->BitBlt(173,285,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(173,285,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		
		
		dcMem1.SelectObject(&figure1);
		dc->BitBlt(65,171,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(65,171,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		
		
		dcMem1.SelectObject(&figure1);
		dc->BitBlt(176,258,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(176,258,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		
		
		dcMem1.SelectObject(&figure1);
		dc->BitBlt(234,335,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(234,335,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		
		
		dcMem1.SelectObject(&figure1);
		dc->BitBlt(236,269,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(236,269,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		
		dcMem1.SelectObject(&figure1);
		dc->BitBlt(179,168,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(179,168,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

		
		
		dcMem1.SelectObject(&figure1);
		dc->BitBlt(221,310,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
		dcMem1.SelectObject(&figure2);
		dc->BitBlt(221,310,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算
	     DeleteObject(figure2);
		DeleteObject(figure1);
		dcMem1.DeleteDC();

}

void CCampusNavigationDlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	m_check.clearall=true;
	m_check.showall=false;
	CDC *dc;
	dc=GetDC();
	// 			
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);

}

void CCampusNavigationDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_check.combdepart=true;
	nIndex3=m_combcreat.GetCurSel();
}

void CCampusNavigationDlg::OnBnClickedButton12()//开始观光按钮（自动展示深度优先搜索）
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_check.wsad==false)//不允许使用前后左右键
	{
		m_check.beginvisitsence=true;//开始观光啦~~~
		CDC *dc,dcMem;
		CBitmap card1,card2;
		dc=GetDC();
		dcMem.CreateCompatibleDC(dc);
		card1.LoadBitmap(IDB_NORMALSENCE);
		dcMem.SelectObject(&card1);
		dc->BitBlt(25,429,538,235,&dcMem,0,0,SRCCOPY);

		card2.LoadBitmap(IDB_STARTPOINT);
		dcMem.SelectObject(&card2);
		dc->BitBlt(25,25,538,500,&dcMem,0,0,SRCCOPY);
		DeleteObject(&card1);
		DeleteObject(&card2);//把第一张图片和学校简介的图片载入
		if (m_check.normalsence)
		{
		DepthFirst(m_mapImages.m_startPoint);//左中深度优先搜索
		DepthFirstR(m_mapImages.m_firstPoint);//中右深度优先搜索
		SetTimer(3,2000,NULL);//开观光timer3的图片
		deepimagenum=0;
		}
	}
	
	
}

void CCampusNavigationDlg::DepthFirst(ImagePoint *root)//左中深度优先搜索算法
{	
	ImagePoint *curmap;
	if (root!=NULL)
	{
		
		curmap=root;
		
		m_deepphoto[deepimagenum]=curmap->imageId;//从大门口的图片开始遍历
		deepimagenum++;
		DepthFirst(curmap->forward);//中线遍历
		DepthFirst(curmap->left);//左线遍历
		
	
		
			
	}
	else
	{
		return;
	}
	

	
	
}

void CCampusNavigationDlg::DepthFirstR(ImagePoint* root)
{
	ImagePoint *curmap;
	if (root!=NULL)
	{
		
		curmap=root;
		m_deepphoto[deepimagenum]=curmap->imageId;
		deepimagenum++;
// 		CDC *dc,dcMem1;
// 		dc=GetDC(); 
// 		CBitmap figure1; 
// 		dcMem1.CreateCompatibleDC(dc); 
// 		figure1.LoadBitmap(curmap->imageId);
// 		dcMem1.SelectObject(&figure1);
// 		dc->BitBlt(221,310,549,501,&dcMem1,0,0,SRCCOPY);
// 		dc->DeleteDC();
// 		
		DepthFirstR(curmap->right);//右线遍历
		DepthFirstR(curmap->forward);//中线遍历

		//	DepthFirst(curmap->right);


	}
	else
	{
		return;
	}

}

void CCampusNavigationDlg::DrawLineTo(POINT Startpoint,POINT EndPoint)
{
	   
	
		CDC *dc,m_dcMem,dcMem1;
		dc=GetDC(); 
		dcMem1.CreateCompatibleDC(dc); 
		CPen pen(PS_SOLID,5,RGB(230,27,94));
		dc->SelectObject(&pen);
		dc->MoveTo(Startpoint.x,Startpoint.y);

		if((Startpoint.x==EndPoint.x)&&(Startpoint.y!=EndPoint.y))
		{
			if (Startpoint.y<=EndPoint.y)
			{
				for(int i=Startpoint.y;i<=EndPoint.y;i++)
			   {
				Sleep(10);
				dc->LineTo(EndPoint.x,i);
			  }

			}
			else
			{
				for(int i=Startpoint.y;i>=EndPoint.y;i--)
				{
					Sleep(10);
					dc->LineTo(EndPoint.x,i);
				}
			}
			
			

		}
		else if((Startpoint.x!=EndPoint.x)&&(Startpoint.y==EndPoint.y))
		{
			if (Startpoint.x<=EndPoint.x)
			{
				for(int i=Startpoint.x;i<=EndPoint.x;i++)
			{
				Sleep(10);
				dc->LineTo(i,EndPoint.y);
			}
			}
			else
			{
				for(int i=Startpoint.x;i>=EndPoint.x;i--)
				{
					Sleep(10);
					dc->LineTo(i,EndPoint.y);
				}

			}
			

		}
		else if((Startpoint.x!=EndPoint.x)&&(Startpoint.y!=EndPoint.y))
		{
			dc->LineTo(EndPoint.x,EndPoint.y);

		}
		

}

void CCampusNavigationDlg::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_check.route&&m_check.combbegin&&m_check.combend)
	{
	m_check.wepass=true;
	CDC *dc;
	dc=GetDC();
	// 			
	m_mtneft.GetDC(dc);
	m_mtneft.Replace(IDB_BUILDING2);
	m_mainPoints.vexnum=32;
	ShortestPath_FLOYD(m_mainPoints,p,d);
	//MessageBox(_T("ADSF"));
	int startpoint,endpoint;
	switch (nIndex0)
	{
	case 0:
		startpoint=22;
		break;
	case 1:
		startpoint=6;
		break;
	case 2:
		startpoint=8;
		break;
	case 3:
		startpoint=18;
		break;
	case 4:
		startpoint=19;
		break;
	case 5:
		startpoint=14;
		break;
	case 6:
		startpoint=28;
		break;
	case 7:
		startpoint=15;
		break;
	case 8:
		startpoint=30;
		break;
	case 9:
		startpoint=0;
		break;
	case 10:
		startpoint=11;
		break;
	case 11:
		startpoint=26;
		break;
	case 12:
		startpoint=31;
		break;
	case 13:
		startpoint=27;
		break;
	case 14:
		startpoint=21;
		break;
	case 15:
		startpoint=23;
		break;
	case 16:
		startpoint=20;
		break;
	case 17:
		startpoint=24;
		break;
	case 18:
		startpoint=15;
		break;
	case 19:
		startpoint=29;
		break;
	case 20:
		startpoint=21;
		break;

	}
	switch (nIndex1)
	{
	case 0:
		endpoint=22;
		break;
	case 1:
		endpoint=6;
		break;
	case 2:
		endpoint=8;
		break;
	case 3:
		endpoint=18;
		break;
	case 4:
		endpoint=19;
		break;
	case 5:
		endpoint=14;
		break;
	case 6:
		endpoint=28;
		break;
	case 7:
		endpoint=15;
		break;
	case 8:
		endpoint=30;
		break;
	case 9:
		endpoint=0;
		break;
	case 10:
		endpoint=11;
		break;
	case 11:
		endpoint=26;
		break;
	case 12:
		endpoint=31;
		break;
	case 13:
		endpoint=27;
		break;
	case 14:
		endpoint=21;
		break;
	case 15:
		endpoint=23;
		break;
	case 16:
		endpoint=20;
		break;
	case 17:
		endpoint=24;
		break;
	case 18:
		endpoint=15;
		break;
	case 19:
		endpoint=29;
		break;
	case 20:
		endpoint=21;
		break;

	}
if (startpoint!=endpoint)
{

	int i=0;
		ShowPoint(m_mainPoints.points[startpoint]);

	for ( i=0;i<=31;i++)
	{
		if (p[startpoint][endpoint][i]==true)
		{
			
			 ShowPoint(m_mainPoints.points[i]);

		}


	}
	ShowPoint(m_mainPoints.points[endpoint]);
	}
	}


}

void CCampusNavigationDlg::ShowPoint(POINT Point)
{
	Sleep(400);
	
	CDC *dc,dcMem1,dcMem2;
	dc=GetDC();
	CBitmap figure1,figure2,*OldBitMap;                     //创建位图对象。
	dcMem1.CreateCompatibleDC(dc); 

    figure1.LoadBitmap(IDB_BIT_SIGN_2);
	figure2.LoadBitmap(IDB_BIT_SIGN_1);
	OldBitMap=dcMem1.SelectObject(&figure1);
    dc->BitBlt(Point.x-10,Point.y-20,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
	dcMem1.SelectObject(&figure2);
	dc->BitBlt(Point.x-10,Point.y-20,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算

	DeleteObject(figure2);
	DeleteObject(figure1);
	dcMem1.DeleteDC();
	



}

void CCampusNavigationDlg::OnBnClickedStopvisit()
{
	// TODO: 在此添加控件通知处理程序代码
	m_check.beginvisitsence=false;//停止观光
	KillTimer(3);//图片停止显示
	timernum=0;
	deepimagenum=0;


}

void CCampusNavigationDlg::OnBnClickedEntersence()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_check.beginvisitsence==false)
	{
		CDC *dc,dcMem;
		CBitmap card1;
		dc=GetDC();
		dcMem.CreateCompatibleDC(dc);
		card1.LoadBitmap(IDB_NORMALSENCE);
		dcMem.SelectObject(&card1);
		dc->BitBlt(25,429,538,235,&dcMem,0,0,SRCCOPY);//导入学校简介的图片
		DeleteObject(&card1);
		m_check.wsad=true;//进行手动寻路
		m_mtneft.Replace(IDB_STARTPOINT);//导入南大门的图片，从南大门开始
		this->SetFocus();//将光标聚到图片上来
	}

}

//void CCampusNavigationDlg::OnBnClickedButton15()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	
//	CDC *dc,dcMem1,dcMem2;
//	dc=GetDC();
//	CBitmap figure1,figure2,*OldBitMap;                     //创建位图对象。
//	dcMem1.CreateCompatibleDC(dc); 
//
//	
//   switch (nIndex3)
//	{
//	case 0:
//		{
//
//		
//		figure1.LoadBitmap(IDB_BIT_SIGN_2);
//		figure2.LoadBitmap(IDB_BIT_SIGN_1);
//		OldBitMap=dcMem1.SelectObject(&figure1);
//		dc->BitBlt(380,390,549,501,&dcMem1,0,0,SRCAND);   //将图片1与背景做and运算 
//		dcMem1.SelectObject(&figure2);
//		dc->BitBlt(380,390,549,501,&dcMem1,0,0,SRCPAINT);//再与图片2做or运算
//
//		DeleteObject(figure2);
//		DeleteObject(figure1);
//		dcMem1.DeleteDC();
//		break;
//		}
//		
//	}
//	
//}
