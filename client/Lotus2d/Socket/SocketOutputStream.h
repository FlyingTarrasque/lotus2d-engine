/********************************************************************
	created:	2012/12/10
	filename: 	SocketOutputStream.h
	author:		reedhong
	
	purpose:	����������, �ü�������
*********************************************************************/

#ifndef __Lotus2d_SocketOutputStream_H__
#define __Lotus2d_SocketOutputStream_H__

#include "Base/Stream.h"
#include "Socket.h"

//��ʼ���ķ��ͻ��泤��
#define DEFAULTSOCKETOUTPUTBUFFERSIZE 8192
//����������Ļ��泤�ȣ������������ֵ����Ͽ�����
#define DISCONNECTSOCKETOUTPUTSIZE 100*1024

namespace Lotus2d {
	class SocketOutputStream :public Stream
	{
	public :
		SocketOutputStream( Socket* sock, 
							unsigned int BufferSize = DEFAULTSOCKETOUTPUTBUFFERSIZE,
							unsigned int MaxBufferSize = DISCONNECTSOCKETOUTPUTSIZE ) ;
		virtual ~SocketOutputStream( ) ;


	public :
		virtual size_t read(void* buf, size_t count) { return 0;};
		virtual size_t write(const void* buf, size_t count);
		virtual void skip(long count) {};
		virtual void seek( size_t pos ) {};
		virtual size_t tell(void) { return 0;};
		virtual bool eof(void) const { return true;};
		virtual void close(void) {};

		unsigned int						flush( ) ;

		void						initsize( ) ;
		bool						resize( int size ) ;

		int							capacity ()const { return m_bufferLen ; }
	 
		unsigned int			length( )const ;
		unsigned int			size( )const { return length( ) ; }

		const char*			getBuffer( )const { return m_buffer ; }

		char*						getTail( )const { return &(m_buffer[m_tail]) ; }
	 
		bool						empty ()const { return m_head==m_tail ; }

		void						cleanup( ) ;

		unsigned int			getHead(){return m_head;}
		unsigned int			getTail(){return m_tail;}
	private :
		
		Socket*		m_pSocket ;
		
		char*		m_buffer ;
		
		unsigned int		m_bufferLen ;
		unsigned int		m_maxBufferLen ;
		
		unsigned int		m_head ;
		unsigned int		m_tail ;
	};

}

#endif
