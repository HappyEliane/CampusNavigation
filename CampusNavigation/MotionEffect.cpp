#include "stdafx.h"
#include "MotionEffect.h"
#include "CampusNavigation.h"
CMotionEffect::CMotionEffect()
{
}
CMotionEffect::CMotionEffect(CDC *dc)
{
	m_dc=dc;
}
CMotionEffect::CMotionEffect(CPaintDC dc)
{
	m_dc=&dc;
}
CMotionEffect::~CMotionEffect()
{

}
void CMotionEffect::Appear(int bmId)
{
	CBitmap bm;
	CDC m_dcMem;
	m_dcMem.CreateCompatibleDC(m_dc);
	bm.LoadBitmap(bmId);
	bm.GetBitmap(&m_bminfo);//获取位图信息
	m_oldbitmap=m_dcMem.SelectObject(&bm);
	m_dc->SetStretchBltMode(HALFTONE);
	for (int i=0;i<=100;i+=2)
	{
		m_dc->StretchBlt(25,25,m_bminfo.bmWidth*i/100,m_bminfo.bmHeight*i/100,
			&m_dcMem,0,0,m_bminfo.bmWidth,m_bminfo.bmHeight,SRCCOPY);
	}
	
	m_dcMem.SelectObject(m_oldbitmap);
	DeleteObject(&bm);
}

void CMotionEffect::GetBitmap(int BtmId)
{
	DeleteObject(&m_bitmap);
	m_bitmap.LoadBitmap(IDB_MRDS1SEL);
	m_bitmap.GetBitmap(&m_bminfo);//获取位图信息
}

void CMotionEffect::GetDC(CDC* dc)
{
	m_dc=dc;
}

void CMotionEffect::Replace(int bmId)
{
	CBitmap bm;
	CDC m_dcMem;
	m_dcMem.CreateCompatibleDC(m_dc);
	bm.LoadBitmap(bmId);
	bm.GetBitmap(&m_bminfo);//获取位图信息
	m_oldbitmap=m_dcMem.SelectObject(&bm);
	m_dc->SetStretchBltMode(HALFTONE);
	m_dc->StretchBlt(25,25,m_bminfo.bmWidth,m_bminfo.bmHeight,
		&m_dcMem,0,0,m_bminfo.bmWidth,m_bminfo.bmHeight,SRCCOPY);
	m_dcMem.SelectObject(m_oldbitmap);
	DeleteObject(&bm);
}

