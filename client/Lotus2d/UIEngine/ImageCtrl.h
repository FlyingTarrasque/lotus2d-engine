/********************************************************************
	created:	2012/11/08
	filename: 	Image.h
	author:		reedhong
	
	purpose:	�󲿷��ܹ���AnimationCtrl�㶨�����ڸ���֤���ʱ���������Ҫ
*********************************************************************/

#ifndef __Lotsu2d_Image_H__
#define __Lotsu2d_Image_H__

#include "Control.h"
#include "RenderSystem/Image.h"

namespace Lotus2d {

	class ImageCtrl: public Control
	{
	public:
		ImageCtrl();
		virtual ~ImageCtrl();
		virtual ImageCtrl* copy();
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
		void setImage(const Image& image);
	protected:
		Image 	m_image;

	};

}


#endif
