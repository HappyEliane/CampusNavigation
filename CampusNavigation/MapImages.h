#pragma once

typedef struct ImagePoint
{
	int imageId;
	struct ImagePoint *forward;
	struct ImagePoint *back;
	struct ImagePoint *left;
	struct ImagePoint *right;
	CString description;
	
}ImagePoint;

typedef struct MainPoints
{
	int imageId[2][10];
	CString description[32];
	POINT points[32];
	int arcs[32][32];
	int vexnum;
}MainPoints;

class CMapImages
{
public:
	CMapImages(void);
	~CMapImages(void);
    
	ImagePoint *m_startPoint;
	ImagePoint *m_curPoint;
	void Initialize(void);
   int i;
	ImagePoint *m_firstPoint;
	ImagePoint *m_secontPoint;
	ImagePoint *m_thirdPoint;
	
};
