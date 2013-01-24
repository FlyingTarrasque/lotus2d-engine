/********************************************************************
	created:	2012/11/09
	filename: 	PatchCtrl.h
	author:		reedhong
	
	purpose:	����һ���þŹ���֮��ķ�ʽȥ���ƣ����Ը��ݴ�С���ж�̬��Ӧ
*********************************************************************/

#ifndef __Lotus2d_PatchCtrl_H__
#define __Lotus2d_PatchCtrl_H__

#include "Control.h"
#include "ControlDef.h"
#include "RenderSystem/PatchSprite.h"

namespace Lotus2d {

	class PatchCtrl: public Control
	{
	public:
		PatchCtrl();
		virtual ~PatchCtrl();
		virtual PatchCtrl* copy();
		/* 
		 * ��stream�м��ؿؼ���Ϣ
		 */
		virtual void loadImp(Stream* stream) ;
		/*
		 * ���ƿؼ�
		 */
		virtual void drawImp(int offsetX = 0, int offsetY = 0);
		virtual bool handleEventImp(eActionEventType event, int posX, int posY, int offsetX=0,int offsetY=0);
		virtual bool hasChild() { return false;}
		void setPatchSprite(PatchSprite* sprite);
	public:
		int	m_patchSpriteKey;
		int	m_index;	
	private:
		PatchSprite*	m_patchSprite;
	};
}


#endif