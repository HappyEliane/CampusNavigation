#pragma once

typedef struct Check
{
	bool block;
	bool rood;
	bool building;
	bool department;
	bool shopping;
	bool magnified;
	bool infoshow;
	bool firstshow;
	bool wsad;
	bool normalsence;
	bool route;
	bool search;
	bool normal;
	bool showall;
	bool clearall;
	bool combsearch;
	bool combbegin;
	bool combend;
	bool combdepart;

	bool enternormal;
	bool exitnormal;
	bool beginvisitsence;
	bool stopvisitsence;
	bool wepass;
}Check;

class CMotionEffect
{
public:
	CMotionEffect(void);
	CMotionEffect(CDC* dc);
	CMotionEffect(CPaintDC dc);
	~CMotionEffect();

	void Appear(int bmId);
	void GetBitmap(int bmId);
protected:
	CBitmap m_bitmap;
	CBitmap* m_oldbitmap;
	CDC *m_dc;
	BITMAP m_bminfo;
	RECT m_rect;
public:
	void GetDC(CDC* dc);
	void Replace(int bmId);
	void DownToUp(int bmId);
};