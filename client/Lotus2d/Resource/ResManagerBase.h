/********************************************************************
	created:	2012/12/03
	filename: 	ResManagerBase.h
	author:		reedhong
	
	purpose:	������Ϸ��Դ����Ľӿڣ���Ҫ�Ƿ����������Դ�ķ��ʣ���Ҫʵ�������ӿ�
						
*********************************************************************/

#ifndef __Lotus2d_ResManagerBase_H__
#define __Lotus2d_ResManagerBase_H__

#include "Base/Prerequisites.h"
#include "Resource.h"
#include "Base/Stream.h"

namespace Lotus2d {
	class ResourceManagerBase
	{
	protected:
		ResourceManagerBase();
		virtual ~ResourceManagerBase();
	public:
		static ResourceManagerBase* getInstance();
		static void setInstance(ResourceManagerBase* rmb);
	protected:
		static ResourceManagerBase* s_instance;
	public:
		// ������Դ��key��������Դ
		virtual Resource* loadResouce(unsigned int key, eResType type) = 0;
		// ������Դ��·����������Դ
		virtual Resource* loadResouce(const string& path, eResType type) = 0;
		virtual void releaseResouce(Resource*  resource) {}

	};
}

#endif
