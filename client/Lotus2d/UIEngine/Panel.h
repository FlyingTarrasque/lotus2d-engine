/********************************************************************
	created:	2012/10/17
	filename: 	Panel.h
	author:		reedhong
	
	purpose:	UI����, �䱳���Ļ����ǿ���Ӧ������,����������Ӧ����ȡ�Ź���ķ�ʽ
*********************************************************************/

#ifndef __Lotus2d_Panel_H__
#define __Lotus2d_Panel_H__

#include "Control.h"
#include "Base/Types.h"

namespace Lotus2d {

	class Panel: public Control
	{
	public:
		Panel();
		virtual ~Panel();
		virtual Panel* copy();

		virtual void loadImp(Stream* stream) ;
		virtual void drawImp(int posX = 0, int posY = 0);
		virtual bool handleEventImp(eActionEventType event, int posX, int posY, int offsetX=0,int offsetY=0);

		virtual bool hasChild() { return true;}
		virtual void addChild(Control* control);
		virtual void deleteChild(Control* control);
		virtual Control* getFirstChild();
		virtual Control* getNextChild();
		virtual void forwardControl(Control* control, bool isup);

	protected:
		vector<Control *>	m_childControls;
		vector<Control *>::iterator m_iter;
	};
}


#endif