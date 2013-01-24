/********************************************************************
	created:	2012/12/13
	filename: 	UICommandHander.h
	author:		reedhong
	
	purpose:	��ӦUI MainEvent
*********************************************************************/

#ifndef __UIManager_H__
#define __UIManager_H__

#include "Base/Prerequisites.h"
#include "UIEngine/Control.h"
using namespace Lotus2d;

typedef void (*UICommandFunc )(Control* control );

class UIManager
{
public:
	UIManager();
	~UIManager();
	static UIManager* Instance();
	void initHandlers();
	void registerHandler(int command, UICommandFunc func);
	void handleCommand(int command, Control* control);

	/*
	 * ��ӦUI�¼��ӿ�, ���õ�UIEngine��ȥ
	 */
	static void s_handleCommandCallback(int command, Control* control);
private:
	map<int, UICommandFunc>		m_handlers;
};


#endif
