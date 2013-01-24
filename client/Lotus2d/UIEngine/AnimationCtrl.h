/********************************************************************
	created:	2012/11/08
	filename: 	AnimationCtrl.h
	author:		reedhong
	
	purpose:	
*********************************************************************/

#ifndef __Lotus2d_AnimationCtrl_H__
#define __Lotus2d_AnimationCtrl_H__

#include "Control.h"
#include "RenderSystem/Sprite.h"

namespace Lotus2d {
	class AnimationCtrl: public Control
	{
	public:
		AnimationCtrl();
		virtual ~AnimationCtrl();
		virtual AnimationCtrl* copy();

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
	
		void setSprite(Sprite* sprite);
	protected:
		void gotoNextFrame();
	public:
		int	m_spriteKey;
		int	m_action;	
		bool m_disable;		// ��ɫ
		int	m_frameIndex;
		int	m_frameDuration;
		
	private:
		Sprite*	m_sprite;


	};
}

#endif
