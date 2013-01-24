/********************************************************************
	created:	2012/12/02
	filename: 	Resource.cpp
	author:		reedhong
	
	purpose:	
*********************************************************************/

#include "Resource.h"
#include "ResManagerBase.h"

namespace Lotus2d {
	Resource::Resource()
	{
		m_refCount = 1;

	}

	Resource::~Resource()
	{
		
	}

	void Resource::release()
	{
		m_refCount--;
		// ͨ�����ķ�ʽ�ͷ���Դ
		if(m_refCount == 0){
			ResourceManagerBase::getInstance()->releaseResouce(this);
			delete this;
		}
	}

	void Resource::addRef()
	{
		m_refCount++;
	}
}
