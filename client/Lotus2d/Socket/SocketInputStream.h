/********************************************************************
	created:	2012/12/10
	filename: 	SocketInputStream.h
	author:		reedhong
	
	purpose:	����������, �ü�������
*********************************************************************/

#ifndef __Lotus2d_SocketInputStream_H__
#define __Lotus2d_SocketInputStream_H__


#include "Socket.h"

//��ʼ���Ľ��ջ��泤��
#define DEFAULTSOCKETINPUTBUFFERSIZE 64*1024
//����������Ļ��泤�ȣ������������ֵ����Ͽ�����
#define DISCONNECTSOCKETINPUTSIZE 96*1024


#include "Base/Stream.h"
#include "Socket.h"

namespace Lotus2d {
	class SocketInputStream:public Stream
	{
	public :
		SocketInputStream( Socket* sock, 
						   unsigned int BufferSize = DEFAULTSOCKETINPUTBUFFERSIZE,
						   unsigned int MaxBufferSize = DISCONNECTSOCKETINPUTSIZE ) ;
		virtual ~SocketInputStream( ) ;
	public :
		virtual size_t read(void* buf, size_t count);
		virtual size_t write(const void* buf, size_t count){ return 0;};
		virtual void skip(long count);
		virtual void seek( size_t pos ) {};
		virtual size_t tell(void) { return 0;};
		virtual bool eof(void) const;
		virtual void close(void) {};

		/*
		 * ֻ��ȡ���ݣ����ƶ�ָ��
		 */
		size_t peek(void* buf, size_t count) ;


		bool find( char* buf ) ;
	
		
		unsigned int	fill( ) ;

		void	initsize( ) ;
		bool	resize(int size ) ;
		
		unsigned int	capacity( )const { return m_bufferLen; }
		
		unsigned int	length( )const ;
		unsigned int	size( )const { return length(); }

		bool	empty( )const { return m_head==m_tail; }

		void	cleanUp( ) ;

		unsigned int		getHead(){return m_head;}
		unsigned int		getTail(){return m_tail;}
		unsigned int		getBuffLen(){return m_bufferLen;}
		const char*	getBuff(){return m_buffer;}
	private :
		Socket*		m_pSocket ;
		
		char*		m_buffer ;	// ѭ��buf
		
		unsigned int		m_bufferLen ;
		unsigned int		m_maxBufferLen ;
		
		unsigned int		m_head ;
		unsigned int		m_tail ;



	};

}




#endif
