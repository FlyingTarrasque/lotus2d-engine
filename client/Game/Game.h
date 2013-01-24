/********************************************************************
	created:	2012/09/11
	filename: 	Game.h
	author:		reedhong
	
	purpose:	
*********************************************************************/

#ifndef __Game_H__
#define __Game_H__

#include "RenderSystem/Texture.h"
#include "RenderSystem/Sprite.h"
#include "Base/Types.h"

#include "Framework/Framework.h"
using namespace Lotus2d;

enum eGameState
{
	GS_START,		// ���������أ��汾��֤����Դ���µ�
	GS_LOGIN,    // ��¼ע���
	GS_LOADING,	// ��������
	GS_ACTION,	// ������
	GS_BATTLE,	// ս��
};



class Game: public Framework
{
public:
	Game();
	~Game();
	static Game * Instance(void);
public:
	virtual void gameStartup(int width,int height,float scale=1.0);
	virtual void gameFrame();
	virtual void gamePause();
	virtual void gameResume();
	virtual void gameEnd();
	virtual void addAction(eRawActionEventType event, int x, int y);
	virtual void addKey(unsigned char key);

	void setState(eGameState status);
	eGameState getState();
	void setProcess(int process){ m_progress = process;}
protected:
	void logic();
	void paint();
	/*
	 * ��Ϸ�������� 
	 */
	void gameStartProcedure();
	/*
	 * ��Ϸ�г����ļ�������
	 */
	void loadingSceneProcedure();
	
private:
	uint64 m_tick;
	eGameState	m_state;
	int m_progress;		// �����ͳ������ص�ʱ����Ҫ

};

#endif 
