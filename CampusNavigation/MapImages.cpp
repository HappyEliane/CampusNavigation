#include "StdAfx.h"
#include "MapImages.h"
#include "resource.h"

CMapImages::CMapImages(void)
: m_startPoint(0)
, m_firstPoint(0)
{
	Initialize();
}

CMapImages::~CMapImages(void)
{
}

void CMapImages::Initialize(void)
{
	m_startPoint=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_startPoint->imageId=IDB_STARTPOINT;
	m_startPoint->forward=NULL;
	m_startPoint->back=NULL;
	m_startPoint->left=NULL;
	m_startPoint->right=NULL;
    m_curPoint=m_startPoint;

	m_curPoint->forward=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->forward->back=m_curPoint;
	m_curPoint=m_curPoint->forward;
	m_curPoint->imageId=IDB_SOUTHDOOR_SONGJIAN_1;
	m_curPoint->forward=NULL;
	m_curPoint->left=NULL;
	m_curPoint->right=NULL;
	m_firstPoint=m_curPoint;

	m_curPoint=m_firstPoint;
	m_curPoint->left=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->left->right=m_curPoint;
	m_curPoint=m_curPoint->left;
	m_curPoint->imageId=IDB_SOUTHDOOR_WEST_TECH_HOUSE_1;
	m_curPoint->forward=NULL;
	m_curPoint->back=NULL;
	m_curPoint->left=NULL;

	for(i=1;i<8;i++)
	{
		m_curPoint->left=(ImagePoint *)malloc(sizeof(ImagePoint));
		m_curPoint->left->right=m_curPoint;
		m_curPoint=m_curPoint->left;
		m_curPoint->imageId=IDB_SOUTHDOOR_WEST_TECH_HOUSE_1+i;
		m_curPoint->forward=NULL;
		m_curPoint->back=NULL;
	}
	
	

// 	m_curPoint->left=(ImagePoint *)malloc(sizeof(ImagePoint));
// 	m_curPoint->left->right=m_curPoint;
// 	m_curPoint=m_curPoint->left;
// 	m_curPoint->imageId=IDB_SOUTHDOOR_WEST_TECH_HOUSE_9;
// 	m_curPoint->forward=NULL;
// 	m_curPoint->back=NULL;
	m_curPoint->left=NULL;

	





	m_curPoint=m_firstPoint;
// 	m_curPoint->right=(ImagePoint *)malloc(sizeof(ImagePoint));
// 	m_curPoint->right->left=m_curPoint;
// 	m_curPoint=m_curPoint->right;
// 	m_curPoint->imageId=IDB_SOUTHDOOR_SONGJIAN_1;
// 	m_curPoint->forward=NULL;
// 	m_curPoint->back=NULL;
// 	m_curPoint->right=NULL;


	for (i=1;i<4;i++)
	{
		m_curPoint->right=(ImagePoint *)malloc(sizeof(ImagePoint));
		m_curPoint->right->left=m_curPoint;
		m_curPoint=m_curPoint->right;
		m_curPoint->imageId=IDB_SOUTHDOOR_SONGJIAN_1+i;
		m_curPoint->forward=NULL;
		m_curPoint->back=NULL;
	}
        m_curPoint->right=NULL;

	m_curPoint=m_firstPoint;
	m_curPoint->forward=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->forward->back=m_curPoint;
	m_curPoint=m_curPoint->forward;
	m_curPoint->imageId=IDB_SOUTHDOOR_C0_1;
	m_curPoint->left=NULL;
	m_curPoint->right=NULL;

	m_curPoint->forward=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->forward->back=m_curPoint;
	m_curPoint=m_curPoint->forward;
	m_curPoint->imageId=IDB_SOUTHDOOR_C0_2;
	m_curPoint->forward=NULL;

	m_secontPoint=m_curPoint;

    m_curPoint=m_secontPoint;
	m_curPoint->right=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->right->left=m_curPoint;
	m_curPoint=m_curPoint->right;
	m_curPoint->imageId=IDB_C0_RIGHT_HR1;
	m_curPoint->forward=NULL;
	m_curPoint->back=NULL;

	m_curPoint->right=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->right->left=m_curPoint;
	m_curPoint=m_curPoint->right;
	m_curPoint->imageId=IDB_C0_RIGHT_HR2;
	m_curPoint->forward=NULL;
	m_curPoint->back=NULL;

	m_curPoint->right=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->right->left=m_curPoint;
	m_curPoint=m_curPoint->right;
	m_curPoint->imageId=IDB_C0_RIGHT_HR3;
	m_curPoint->forward=NULL;
	m_curPoint->back=NULL;
	m_curPoint->right=NULL;

	m_curPoint->forward=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->forward->back=m_curPoint;
	m_curPoint=m_curPoint->forward;
	m_curPoint->imageId=IDB_C0_RIGHT_HR4;
	m_curPoint->left=NULL;
	m_curPoint->right=NULL;

	m_curPoint->forward=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->forward->back=m_curPoint;
	m_curPoint=m_curPoint->forward;
	m_curPoint->imageId=IDB_C0_RIGHT_HR5;
	m_curPoint->left=NULL;
	m_curPoint->right=NULL;
	m_curPoint->forward=NULL;






	m_curPoint=m_secontPoint;
	m_curPoint->left=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->left->right=m_curPoint;
	m_curPoint=m_curPoint->left;
	m_curPoint->imageId=IDB_c0_c1_1;
	m_curPoint->forward=NULL;
	m_curPoint->back=NULL;
	for(i=1;i<4;i++)
	{
		m_curPoint->left=(ImagePoint *)malloc(sizeof(ImagePoint));
		m_curPoint->left->right=m_curPoint;
		m_curPoint=m_curPoint->left;
		m_curPoint->imageId=IDB_c0_c1_1-i;
		m_curPoint->forward=NULL;
		m_curPoint->back=NULL;

	}
	m_curPoint->left=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->left->right=m_curPoint;
	m_curPoint=m_curPoint->left;
	m_curPoint->imageId=IDB_c0_c1_5;
	m_curPoint->back=NULL;
	m_curPoint->left=NULL;

	m_curPoint->forward=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->forward->back=m_curPoint;
	m_curPoint=m_curPoint->forward;
	m_curPoint->imageId=IDB_C1_C2_1;
	m_curPoint->left=NULL;
	m_curPoint->right=NULL;
	
	m_curPoint->forward=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->forward->back=m_curPoint;
	m_curPoint=m_curPoint->forward;
	m_curPoint->imageId=IDB_C1_C2_2;
	m_curPoint->left=NULL;
	m_curPoint->right=NULL;


	m_curPoint->forward=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->forward->back=m_curPoint;
	m_curPoint=m_curPoint->forward;
	m_curPoint->imageId=IDB_C1_C2_3;
	m_curPoint->left=NULL;
	m_curPoint->right=NULL;

	m_thirdPoint=m_curPoint;

	m_curPoint=m_thirdPoint;
	m_curPoint->left=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->left->right=m_curPoint;
	m_curPoint=m_curPoint->left;
	m_curPoint->imageId=IDB_C2_C7_1;
	m_curPoint->back=NULL;
	m_curPoint->forward=NULL;
	for (i=1;i<=2;i++)
	{
		m_curPoint->left=(ImagePoint *)malloc(sizeof(ImagePoint));
		m_curPoint->left->right=m_curPoint;
		m_curPoint=m_curPoint->left;
		m_curPoint->imageId=IDB_C2_C7_1-i;
		m_curPoint->back=NULL;
		m_curPoint->forward=NULL;
	}
	m_curPoint->left=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->left->right=m_curPoint;
	m_curPoint=m_curPoint->left;
	m_curPoint->imageId=IDB_C2_C7_4;
	m_curPoint->back=NULL;
	m_curPoint->forward=NULL;

	m_curPoint->left=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->left->right=m_curPoint;
	m_curPoint=m_curPoint->left;
	m_curPoint->imageId=IDB_C7_C8_1;
	m_curPoint->back=NULL;
	m_curPoint->forward=NULL;

	m_curPoint->left=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->left->right=m_curPoint;
	m_curPoint=m_curPoint->left;
	m_curPoint->imageId=IDB_C7_C8_2;
	m_curPoint->back=NULL;
	m_curPoint->forward=NULL;

	m_curPoint->left=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->left->right=m_curPoint;
	m_curPoint=m_curPoint->left;
	m_curPoint->imageId=IDB_C7_C8_3;
	m_curPoint->back=NULL;
	m_curPoint->forward=NULL;

	m_curPoint->left=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->left->right=m_curPoint;
	m_curPoint=m_curPoint->left;
	m_curPoint->imageId=IDB_C7_C8_4;
	m_curPoint->back=NULL;
	m_curPoint->forward=NULL;

	m_curPoint->left=NULL;

	m_curPoint->forward=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->forward->back=m_curPoint;
	m_curPoint=m_curPoint->forward;
	m_curPoint->imageId=IDB_C8_N_1;
	m_curPoint->left=NULL;
	m_curPoint->right=NULL;
	for (i=256;i<=257;i++)
	{
		m_curPoint->forward=(ImagePoint *)malloc(sizeof(ImagePoint));
		m_curPoint->forward->back=m_curPoint;
		m_curPoint=m_curPoint->forward;
		m_curPoint->imageId=i;
		m_curPoint->left=NULL;
		m_curPoint->right=NULL;
	}
	for (i=273;i<=269;i++)
	{
		m_curPoint->forward=(ImagePoint *)malloc(sizeof(ImagePoint));
		m_curPoint->forward->back=m_curPoint;
		m_curPoint=m_curPoint->forward;
		m_curPoint->imageId=i;
		m_curPoint->left=NULL;
		m_curPoint->right=NULL;
	}
	for (i=267;i>=262;i--)
	{
		m_curPoint->forward=(ImagePoint *)malloc(sizeof(ImagePoint));
		m_curPoint->forward->back=m_curPoint;
		m_curPoint=m_curPoint->forward;
		m_curPoint->imageId=i;
		m_curPoint->left=NULL;
		m_curPoint->right=NULL;
	}
	for (i=276;i>=275;i--)
	{
		m_curPoint->forward=(ImagePoint *)malloc(sizeof(ImagePoint));
		m_curPoint->forward->back=m_curPoint;
		m_curPoint=m_curPoint->forward;
		m_curPoint->imageId=i;
		m_curPoint->left=NULL;
		m_curPoint->right=NULL;
	}
m_curPoint->forward=NULL;

m_curPoint=m_thirdPoint;
for (i=242;i<=244;i++)
{
	m_curPoint->forward=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->forward->back=m_curPoint;
	m_curPoint=m_curPoint->forward;
	m_curPoint->imageId=i;
	m_curPoint->left=NULL;
	m_curPoint->right=NULL;
}
for (i=250;i<=254;i++)
{
	m_curPoint->forward=(ImagePoint *)malloc(sizeof(ImagePoint));
	m_curPoint->forward->back=m_curPoint;
	m_curPoint=m_curPoint->forward;
	m_curPoint->imageId=i;
	m_curPoint->left=NULL;
	m_curPoint->right=NULL;
}
m_curPoint->forward=NULL;

m_curPoint=m_startPoint;

}

