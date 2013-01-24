/********************************************************************
	created:	2012/11/03
	filename: 	ParticleEmitterExamples.h
	author:		reedhong
	
	purpose:	���ӵ�һЩʾ�������������Ժͼ��
*********************************************************************/

#ifndef __Lotus2d_ParticleEmitterExamples_H__
#define __Lotus2d_ParticleEmitterExamples_H__

#include "ParticleEmitterQuad.h"

namespace Lotus2d {
	class ParticleEmitterSnow: public ParticleEmitterQuad
	{
	public:
		ParticleEmitterSnow();
		virtual ~ParticleEmitterSnow(){}
		virtual bool initWithTotalParticles(unsigned int numberOfParticles);
	};
}


#endif