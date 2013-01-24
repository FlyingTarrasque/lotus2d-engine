/********************************************************************
	created:	2012/09/17
	filename: 	UString.h
	author:		reedhong
	
	purpose:	utf8�ַ�������ַ��������Ի�ȡ��Unicode����
*********************************************************************/

#ifndef __Lotus2d_UString_H__
#define __Lotus2d_UString_H__

#include "Base/Prerequisites.h"

namespace Lotus2d {
	class UString 
	{
	public:
		UString();
		UString(const char* buf);
		UString(const char* data, size_t len);
		UString(const UString& str);
		UString(char c, size_t count);
		~UString();
		UString& operator= (const UString& str);
		UString& operator= (const char* str);

		/*
		 * һ�������ַ�Ϊ1
		 */
		size_t length() const;

		/*
		 * ����buf�Ĵ�С
		 */
		size_t size() const;

		bool empty() const;

		UString substr(size_t startIndex, size_t endIndex) const;
		
		void append(char c);
		void append(const char* str);
		void append(const char* buffer, size_t len);
	

		int get(size_t index) const;
		
		const char* c_str() const;
		/*
		 * ����ѭ�������ַ�������ȡ���ڵ�unicode����, ��int���棬Ϊ�˷����ж�
		 */
		int getUnicodeFromIterator();
	private:
		void init(const char* buf, size_t len);
		int _utf_string_len(const char* buf, size_t len);
	private:
		size_t m_iter;
		char 	m_localBuffer[LocalFixStringSize+1];
		char	*	m_mallocBuffer;		// stream data width utf-8 format.
		size_t   m_mallocBufferLen;	// len of stream data.
		size_t   m_strLen;		// len of string.

	};
}

#endif
