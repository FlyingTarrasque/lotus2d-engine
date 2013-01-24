/********************************************************************
	created:	2012/09/11
	filename: 	Config.h
	author:		reedhong
	
	purpose:	�漰����ȫ���Ե���Ϣ��һЩ��ص����ã� follow ���ҵ���Ϸ��̸���
*********************************************************************/

#ifndef __Lotus2d_Config_H__
#define __Lotus2d_Config_H__


#define LOTUS2D_CONFIG_LITTLE_ENDIAN
#define LOTUS2D_PROFILING 1
#define ENABLE_GL_CHECK 1

// ���ڴ������Ժͼ�⿪��
#ifndef MEMORY_DEBUG 
	#define MEMORY_DEBUG 
#endif


#define LOTUS2D_RENDER_OPENGL 1
#define LOTUS2D_RENDER_OPENGLES1 2
#define LOTUS2D_RENDER_OPENGLES2 3


/* render config */
#if defined( __OPENGL__ )
#define LOTUS2D_RENDER LOTUS2D_RENDER_OPENGL
#elif defined( __OPENGLES1__)
#define LOTUS2D_RENDER LOTUS2D_RENDER_OPENGLES1
#elif defined(__OPENGLES2__)
#	define LOTUS2D_RENDER LOTUS2D_RENDER_OPENGLES2
#else
#	define LOTUS2D_RENDER LOTUS2D_RENDER_OPENGLES1
#endif


// Debug����
#   if defined(_DEBUG) || defined(DEBUG) || defined(__DEBUG) || defined(__DEBUG__)
#       define LOTUS2D_DEBUG 
#  endif

// profile
#define Lotus2d_PROFILING 0

// ��Ⱦ���ڲ��Ķ�������
#define MAX_ARRAY_SIZE 10*1000

// ����
enum FONT_ID
{
	LITTLE_FONT = 14,
	MIDDLE_FONT =18,
	LARGE_FONT =20,
};

enum FONT_CACHE_IMAGE_SIZE
{
	FONT_CACHE_IMAGE_64x64,		///< 64x64
	FONT_CACHE_IMAGE_128x128,	///< 128x128
	FONT_CACHE_IMAGE_256x256,	///< 256x256
	FONT_CACHE_IMAGE_512x512, 	///< 512x512
	FONT_CACHE_IMAGE_1024x1024	///< 1024x1024
};

/* The padding between glyphs on the texture(in pixel). */
#define TEX_FONT_GLYPH_PADDING	6

// UString���ػ������Ĵ�С
#define LocalFixStringSize 127

// ���绺��������
//��ʼ���Ľ��ջ��泤��
#define DEFAULTSOCKETINPUTBUFFERSIZE 64*1024
//����������Ļ��泤�ȣ������������ֵ����Ͽ�����
#define DISCONNECTSOCKETINPUTSIZE 96*1024

//��ʼ���ķ��ͻ��泤��
#define DEFAULTSOCKETOUTPUTBUFFERSIZE 8192
//����������Ļ��泤�ȣ������������ֵ����Ͽ�����
#define DISCONNECTSOCKETOUTPUTSIZE 100*1024

#define USES_VBO 1

#define FRAME_COUNT_PER_SECOND 15 // ÿ��֡��������������Ҫ�õ�
#define FRAME_TIME (1.0f/FRAME_COUNT_PER_SECOND)


// ui control
#define INPUT_COLOR 0xFF006600
#define INPUT_TICK_COLOR 0xFFFF0000
#define INPUT_CONTENT_GAP 2 // ����������ݵ�ͷβ���
#define INPUT_DEFAULT_MAX_LEN 128 // �����Ĭ�����������
#define INPUT_TICK_GAP 2	// ������й������ݵļ��


// socket
#define DEFAULT_CONNECT_TIMEOUT 3 // Ĭ�����ӳ�ʱʱ�䣬3��
#define DEFAULT_CONNECT_RETRY	3 // Ĭ���������Ӵ���

#endif