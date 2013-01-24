/********************************************************************
	created:	2012/10/23
	filename: 	ResManager.h
	author:		reedhong
	
	purpose:	��ʱֱ�Ӷ�ȡ��Դ
*********************************************************************/

#include <string>
#include <vector>
#include <map>
using namespace std;

#include "RenderSystem/Sprite.h"
#include "RenderSystem/Texture.h"
#include "Resource/ResManagerBase.h"
#include "UIEngine/Page.h"
using namespace Lotus2d;


class ResManager: public ResourceManagerBase
{
public:
	static ResManager* Instance();
	/*
	 * @binaryPath: ��Դ�Ķ���������
	 * @xmlPath: ��Դ���ݵ�·��  
	 */
	bool init(const string& resPath);
	void clearSprite();


	// ������Դ��key��������Դ
	virtual Resource* loadResouce(unsigned int key, eResType type);
	// ������Դ��·����������Դ
	virtual Resource* loadResouce(const string& path, eResType type);
	virtual void releaseResouce(Resource*  resource);

	Sprite* loadSprite(const string& name);
	string getScenePath(const string& name);

	const UString& getString(size_t index) const;
	
	Page* getPage(unsigned int key);
protected:
	void loadStrings();
	const char* getTarget();

protected:
	ResManager();
	~ResManager();

public:

	map<string, Sprite*>	mSpritesCache;	// action map, ���ڷ���ͻ���
	vector<UString >			m_strings;
};
