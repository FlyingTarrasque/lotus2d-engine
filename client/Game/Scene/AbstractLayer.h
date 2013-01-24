/********************************************************************
	created:	2012/10/22
	filename: 	AbstractLayer.h
	author:		reedhong
	
	purpose:	����㣬���������кܶ����ɵ�
*********************************************************************/

#ifndef __AbstractLayer_H__
#define __AbstractLayer_H__

#include "Event/Event.h"
#include "Base/Types.h"
#include "Base/ObjectBase.h"

using namespace  Lotus2d;

class AbstractLayer : public ObjectBase
{
public:
	AbstractLayer();
	virtual ~AbstractLayer();
	virtual void enter()=0;
	virtual void leave()=0;
	virtual void step()=0;
	virtual void drawImp()=0;

	/*
	 * �¼�������ɷ���0�����򽻸���һ�㴦��
	 */
	virtual int handleEvent(eActionEventType event, int x, int y) = 0;

	void draw();

	void setVisible(BOOL b){ m_visible = b;}
private:
	BOOL		m_visible;

};

#endif
