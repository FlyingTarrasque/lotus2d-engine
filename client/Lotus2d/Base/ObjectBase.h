/********************************************************************
	created:	2012/09/19
	filename: 	ObjectBase.h
	author:		reedhong
	
	purpose:	������Ҫ��̬���ɵ���̳д�
*********************************************************************/

#ifndef __Lotus2d_ObjectBase_H__
#define __Lotus2d_ObjectBase_H__

#include <new>

namespace Lotus2d {

	class ObjectBase
	{
	public:
	   		
		inline void* operator new( size_t aSize );
	   		
		inline void operator delete( void* aPtr );

		inline void* operator new [] (size_t aSize );

		inline void operator delete [] ( void* aPtr );
		
		virtual ~ObjectBase()				{}
	protected:
	   
		ObjectBase()						{}
	
	private:
	};

}
// implementation
#include "ObjectBase.inl"


#endif