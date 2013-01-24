/********************************************************************
created:	2012/10/31
filename: 	ParticleEmitterQuad.h
author:		reedhong

purpose:	�ı������ӷ������������ڵ�����ϵͳ(GL_POINT_SPRITE_OES,GL_POINT_SIZE_ARRAY_OES)
					��cocos2d-x˵�����ߵ�Ч�����ϵĻ����ϸ����ı��Σ������µĻ����Ϸ����أ����ԣ�������ϵͳ
					����ʵ�֣�������Լ�cocos2d-x
*********************************************************************/

#ifndef __Lotus2d_PointParticleEmitter_H__
#define __Lotus2d_PointParticleEmitter_H__

#include "ParticleEmitter.h"

namespace Lotus2d {
	class ParticleEmitterQuad: public ParticleEmitter
	{
	public:
		ParticleEmitterQuad(){}
		virtual ~ParticleEmitterQuad();
		// super methods
		virtual bool initWithTotalParticles(unsigned int numberOfParticles);
		virtual void updateQuadWithParticle(Particle* particle, const Vector2f& newPosition);
		virtual void postStep();
		virtual void paintImp();
	private:
		void paintParticle(Particle* particle);
	};
}
#endif