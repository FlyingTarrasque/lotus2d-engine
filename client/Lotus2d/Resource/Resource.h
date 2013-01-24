/********************************************************************
	created:	2012/12/02
	filename: 	Resource.h
	author:		reedhong
	
	purpose:	��Դ, ϵͳ�е���Դ�̳��ڴˣ���Դ���ͷŵ���release�ӿ�
						��Դͨ��ָ����ʣ��ҽӵ���ͬ�Ķ�����ȥ���ҽӵ��µĶ���ʱ
						�ǵ��ͷ�
*********************************************************************/

#ifndef __Lotus2d_Resource_H__
#define __Lotus2d_Resource_H__

#include "Base/ObjectBase.h"

namespace Lotus2d {

	enum eResType{
		eResSprite = 0,
		eResPatchSprite,
		eResTexture,
	};

	class Resource: public ObjectBase
	{
	protected:
		Resource();
		virtual ~Resource();
	public:
		void release();
		void addRef();
		void resetRef() { m_refCount = 1;}
	private:
		int	m_refCount;
	};

}

#endif