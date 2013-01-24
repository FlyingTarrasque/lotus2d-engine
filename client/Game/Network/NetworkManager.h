/********************************************************************
	created:	2012/12/10
	filename: 	NetworkManager.h
	author:		reedhong
	
	purpose:	
*********************************************************************/
#include "Thread/Thread.h"
#include "Socket/ClientSocket.h"
using namespace Lotus2d;

class NetworkManager 
{
protected:
	NetworkManager();
public:
	~NetworkManager();
	static NetworkManager* Instance();
	int connectLoginServer(const char* szServerAddr,  unsigned short serverPort);
	void step();
	void init();
protected:
	void waitPacket();
protected:
	//�ɶ����
	fd_set					m_readFD;
	//��д���
	fd_set					m_writeFD;
	//�쳣���
	fd_set					m_exceptFD;
	
	bool					m_isStartConnectThread;
	vector<ClientSocket * > m_clientSockets;
};
