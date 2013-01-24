/********************************************************************
	created:	2012/09/14 
	filename: 	MemoryStream.h
	author:		reedhong 
	
	purpose:	�ڴ�Stream����д����
*********************************************************************/

#ifndef __Lotus2d_MemoryStream_H__
#define __Lotus2d_MemoryStream_H__

#include "Base/Prerequisites.h"
#include "Stream.h"

namespace Lotus2d {
	class MemoryStream: public Stream
	{
	public:
		MemoryStream();
		MemoryStream(const uint8 *buffer, size_t len, bool freeOnClose=FALSE);
		virtual ~MemoryStream();
	public:
		virtual size_t read(void* buf, size_t count);
		virtual size_t write(const void* buf, size_t count);
		virtual void skip(long count);
		virtual void seek( size_t pos );
		virtual size_t tell(void);
		virtual bool eof(void) const ;
		virtual void close(void);
		void setFreeOnClose(bool b) { m_freeOnClose = b;}

		const uint8* getBuffer() { return m_buffer;}
		
		/*
		 * �����µ�size��Ĭ��m_size = m_length
		 */
		void setSize(size_t size);

	protected:
		uint8*		m_buffer;
		uint8*		m_bufferStart;
		uint8*		m_bufferEnd;
		bool		m_freeOnClose;
		size_t		m_length;			// buffer�ĳ���
	};
}

#endif