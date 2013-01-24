/********************************************************************
	created:	2012/09/14 
	filename: 	Stream.h
	author:		reedhong 
	
	purpose:	һ��Ķ�ȡ��д���Ϊbig endian������Ҳ�ṩlittle endian�Ľӿڣ��� le��β
					Big endian���������ֽڴ洢����ʼ��ַ
					Little endian���������ֽڴ洢����ʼ��ַ
					windows��linux�ı����ֽ����Ϊ le�� �����ֽ���Ϊbe
					�˴�������Ĭ�ϱ����ֽ����Ϊle���������Լ��ټ���ͷ�֧�ж�
					Ĭ�ϵ�read/write Ϊbeģʽ����Ϊ��д������������
*********************************************************************/

#ifndef __Lotus2d_Stream_H__
#define __Lotus2d_Stream_H__

#include "Base/Prerequisites.h"

namespace Lotus2d {
	class Stream 
	{
	protected:
		/// Size of the data in the stream (may be 0 if size cannot be determined)
		size_t mSize;
	public:
		Stream();
		virtual ~Stream();
		static void swapEndian(void* pData, size_t size);

		virtual size_t read(void* buf, size_t count) = 0;
		virtual size_t write(const void* buf, size_t count)=0;
		virtual void skip(long count) = 0;
		virtual void seek( size_t pos ) = 0;
		virtual size_t tell(void)  = 0;
		virtual bool eof(void) const = 0;
		virtual void close(void) = 0;

		size_t size(void) const { return mSize; }
		
		virtual BOOL readBool();
		virtual int8 read8();

		// BE �����ֽ���
		virtual int16 read16();
		virtual int32 read32();
		virtual int64 read64();
		virtual float readf();

		/*
		 * @ishort: �ַ��������Ƿ�Ϊ16λ�������ֽ��򣬻���8λ
		 */
		virtual UString readUString(bool isShort=true);


		/* ��le�ֽ������*/
		// win32/linux local
		virtual int16 read16le();
		virtual int32 read32le();
		virtual int64 read64le();


		virtual void writeBool(BOOL b);
		virtual void write8(int8 c);
		virtual void write16(int16 s);
		virtual void write32(int32 i);	
		virtual void write64(int64 l);	
		virtual void writef(float f);
		// �ַ���������big endian��ʽд��
		virtual void writeUString(const UString& str, bool isShort=true);
		
		/* ��le�ֽ���д�룬����ֱ��д�룬����ת��*/
		// win32/linux local 
		virtual void write16le(int16 s);
		virtual void write32le(int32 i);	
		virtual void write64le(int64 l);	
	};

}


#endif