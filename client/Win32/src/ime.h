#include <windows.h>
#include <imm.h>
#include "Platform/textfield.h"

class CIme{
	bool g_bIme;//ime�����־
	char g_szCompStr[ MAX_PATH ];//�洢ת����Ĵ�
	char g_szCompReadStr[ MAX_PATH ];//�洢����Ĵ�
	char g_szCandList[ MAX_PATH ];//�洢������ַ���ѡ�ֱ�
	int g_nImeCursor;//�洢ת����Ĵ��еĹ��λ��
	CANDIDATELIST *g_lpCandList;//�洢��׼��ѡ�ֱ�
	char g_szImeName[ 64 ];//�洢���뷨������
	bool g_bImeSharp;//ȫ�Ǳ�־
	bool g_bImeSymbol;//���ı���־
	void ConvertCandList( CANDIDATELIST *pCandList, char *pszCandList );//��ѡ�ֱ�����ɴ�
public:
	CIme() : g_lpCandList( NULL ){ DisableIme(); }//ͨ��DisableIme��ʼ��һЩ����
	~CIme(){
		DisableIme();
		if( g_lpCandList ){
			GlobalFree( (HANDLE)g_lpCandList );
			g_lpCandList = NULL;
		}
	}
	//���ƺ���
	void DisableIme();//�رղ���ֹ���뷨����ime�Ѿ�����رգ��˺���Ҳ������ȼ�����ime
	void EnableIme();//�������뷨���˺���ҿ������ȼ�����ime
	void NextIme();//�л�����һ�����뷨������EnableIme�����Ч
	void SharpIme( HWND hWnd );//�л�ȫ��/���
	void SymbolIme( HWND hWnd );//�л���/Ӣ�ı��

	//״̬����
	char* GetImeName();//�õ����뷨���֣������ǰ��Ӣ���򷵻�NULL
	bool IfImeSharp();//�Ƿ�ȫ��
	bool IfImeSymbol();//�Ƿ����ı��
	void GetImeInput( char **pszCompStr, char **pszCompReadStr, int *pnImeCursor, char **pszCandList );
		//�õ����뷨״̬���ĸ�ָ�������ΪNULL���״̬���ط���
		//��pszCompStr�з���ת����Ĵ�
		//��pszCompReadStr�з��ؼ���ֱ������Ĵ�
		//��pnImeCursor�з���szCompStr�Ĺ��λ��
		//��pszCandList�з���ѡ�ֱ�ÿ��֮����\t�ָ�

	//��������Ϣ�е��õĺ��������������true���򴰿ں���Ӧֱ�ӷ���0������Ӧ���ݸ�DefWindowProc
	bool OnWM_INPUTLANGCHANGEREQUEST();
	bool OnWM_INPUTLANGCHANGE( HWND hWnd );
	bool OnWM_IME_SETCONTEXT(){ return true; }
	bool OnWM_IME_STARTCOMPOSITION(){ return true; }
	bool OnWM_IME_ENDCOMPOSITION(){ return true; }
	bool OnWM_IME_NOTIFY( HWND hWnd, WPARAM wParam );
	bool OnWM_IME_COMPOSITION( HWND hWnd, LPARAM lParam );
};

void CIme::DisableIme(){
	// win7 ���������ѭ��
	//while( ImmIsIME( GetKeyboardLayout( 0 ))) 
	if( ImmIsIME( GetKeyboardLayout( 0 )))
		ActivateKeyboardLayout(( HKL )HKL_NEXT, 0 );//���ime��ͨ��ѭ���л�����һ���ر�
	g_bIme = false;
	g_szImeName[ 0 ] = 0;
	g_szCompStr[ 0 ] = 0;
	g_szCompReadStr[ 0 ] = 0;
	g_szCandList[ 0 ] = 0;
	g_nImeCursor = 0;
}

void CIme::EnableIme(){
	g_bIme = true;
}

void CIme::NextIme(){
	if( g_bIme )ActivateKeyboardLayout(( HKL )HKL_NEXT, 0 );
}

void CIme::SharpIme( HWND hWnd ){
	ImmSimulateHotKey( hWnd, IME_CHOTKEY_SHAPE_TOGGLE );
}

void CIme::SymbolIme( HWND hWnd ){
	ImmSimulateHotKey( hWnd, IME_CHOTKEY_SYMBOL_TOGGLE );
}

void CIme::ConvertCandList( CANDIDATELIST *pCandList, char *pszCandList ){//ת��CandidateList��һ������\t�ָ�ÿһ��
	unsigned int i;
	if( pCandList->dwCount < pCandList->dwSelection ){
		pszCandList[ 0 ] = 0;
		return;
	}
		//��ѡ����ų���������΢��ƴ���ڶ��ε�ѡ�ֱ����һҳ���ٰ�PageDown�����������������һ��˳�ѡ��״̬����ʼһ���µ�����
		//��΢��ƴ���Լ���ime���ڿ��Խ��������⣬����΢��ƴ��ʵ���˸���Ľӿڣ�����ʹ�������ֲ�̫��׼������
		//�������޷����������⣬����ʵ��ʹ����Ҳ�������������£�����������׼���뷨������������bug
		//�Ǳ�׼���뷨����ʵ�ֵĽӿڱȽ��٣�����Ӧ��Ҳ������������bug
	for( i = 0; ( i < pCandList->dwCount - pCandList->dwSelection )&&( i < pCandList->dwPageSize ); i++ ){
		*pszCandList++ = ( i % 10 != 9 )? i % 10 + '1' : '0';//ÿ���Ӧ�����ּ�
		*pszCandList++ = '.';//��'.'�ָ�
		strncpy( pszCandList, (char*)pCandList
			+ pCandList->dwOffset[ pCandList->dwSelection + i ] ,259);//ÿ��ʵ�ʵ�����
		pszCandList += strlen( pszCandList );
		*pszCandList++ = '\t';//��֮����'\t'�ָ�
	}
	*( pszCandList - 1 )= 0;//��β�����������һ��'\t'
}

bool CIme::OnWM_INPUTLANGCHANGEREQUEST(){
	return !g_bIme;//�����ֹime�򷵻�false����ʱ���ں���Ӧ����0������DefWindowProc������뷨
}

bool CIme::OnWM_INPUTLANGCHANGE( HWND hWnd ){
	//ime�ı�
	HKL hKL = GetKeyboardLayout( 0 );
	if( ImmIsIME( hKL )){
		HIMC hIMC = ImmGetContext( hWnd );
		ImmEscape( hKL, hIMC, IME_ESC_IME_NAME, g_szImeName );//ȡ�������뷨����
		DWORD dwConversion, dwSentence;
		ImmGetConversionStatus( hIMC, &dwConversion, &dwSentence );
		g_bImeSharp = ( dwConversion & IME_CMODE_FULLSHAPE )? true : false;//ȡ��ȫ�Ǳ�־
		g_bImeSymbol = ( dwConversion & IME_CMODE_SYMBOL )? true : false;//ȡ�����ı���־
		ImmReleaseContext( hWnd, hIMC );
	}
	else//Ӣ������
		g_szImeName[ 0 ] = 0;
	return false;//���Ƿ���false����Ϊ��Ҫ���ں�������DefWindowProc��������
}

bool CIme::OnWM_IME_NOTIFY( HWND hWnd, WPARAM wParam ){
	HIMC hIMC;
	DWORD dwSize;
	DWORD dwConversion, dwSentence;
	switch( wParam ){
		case IMN_SETCONVERSIONMODE://ȫ��/��ǣ���/Ӣ�ı��ı�
			hIMC = ImmGetContext( hWnd );
			ImmGetConversionStatus( hIMC, &dwConversion, &dwSentence );
			g_bImeSharp = ( dwConversion & IME_CMODE_FULLSHAPE )? true : false;
			g_bImeSymbol = ( dwConversion & IME_CMODE_SYMBOL )? true : false;
			ImmReleaseContext( hWnd, hIMC );
			break;
		case IMN_OPENCANDIDATE://����ѡ��״̬
		case IMN_CHANGECANDIDATE://ѡ�ֱ�ҳ
			hIMC = ImmGetContext( hWnd );
			if( g_lpCandList ){
				GlobalFree( (HANDLE)g_lpCandList );
				g_lpCandList = NULL;
			}//�ͷ���ǰ��ѡ�ֱ�
			if( dwSize = ImmGetCandidateList( hIMC, 0, NULL, 0 )){
				g_lpCandList = (LPCANDIDATELIST)GlobalAlloc( GPTR, dwSize );
				if( g_lpCandList )
					ImmGetCandidateList( hIMC, 0, g_lpCandList, dwSize );
			}//�õ��µ�ѡ�ֱ�
			ImmReleaseContext( hWnd, hIMC );
			if( g_lpCandList )ConvertCandList( g_lpCandList, g_szCandList );//ѡ�ֱ�����ɴ�
			break;
		case IMN_CLOSECANDIDATE://�ر�ѡ�ֱ�
			if( g_lpCandList ){
				GlobalFree( (HANDLE)g_lpCandList );
				g_lpCandList = NULL;
			}//�ͷ�
			g_szCandList[ 0 ] = 0;
			break;
	}
	return true;//���Ƿ���true����ֹime���ڴ�
}
char* ucs_to_utf8(const wchar_t* pucs)
{
	static char tmpbuf[1024];
	memset(tmpbuf, 0, sizeof(tmpbuf));
	WideCharToMultiByte(CP_UTF8, 0, pucs, (int)wcslen(pucs), tmpbuf, 1023,0,0);
	return tmpbuf;

}

bool CIme::OnWM_IME_COMPOSITION( HWND hWnd, LPARAM lParam ){//����ı�
	HIMC hIMC;
	DWORD dwSize;
	hIMC = ImmGetContext( hWnd );
	if( lParam & GCS_COMPSTR ){
		dwSize = ImmGetCompositionString( hIMC, GCS_COMPSTR, (void*)g_szCompStr, sizeof( g_szCompStr ));
		g_szCompStr[ dwSize ] = 0;
	}//ȡ��szCompStr
	if( lParam & GCS_COMPREADSTR ){
		dwSize = ImmGetCompositionString( hIMC, GCS_COMPREADSTR, (void*)g_szCompReadStr, sizeof( g_szCompReadStr ));
		g_szCompReadStr[ dwSize ] = 0;
	}//ȡ��szCompReadStr
	if( lParam & GCS_CURSORPOS ){
		g_nImeCursor = 0xffff & ImmGetCompositionString( hIMC, GCS_CURSORPOS, NULL, 0 );
	}//ȡ��nImeCursor
	if( lParam & GCS_RESULTSTR ){
		static wchar_t str[ MAX_PATH ];
		wchar_t* pStr = str;
		LONG buflen = ImmGetCompositionStringW(hIMC, GCS_RESULTSTR,NULL,0);
		if(buflen>0)
		{
			buflen += sizeof(wchar_t);
			if(buflen>MAX_PATH)
			{
				pStr = new wchar_t[buflen];
			}
			else
			{
				buflen = MAX_PATH;
			}
			memset(pStr,0,buflen*sizeof(wchar_t));
			ImmGetCompositionStringW( hIMC, GCS_RESULTSTR, (void*)pStr, buflen);//ȡ�ú������봮
			wchar_t *p = str;
			lotus2d_inpututf8(ucs_to_utf8((const wchar_t*)p));

			if(buflen>MAX_PATH)
				delete[] pStr;
			
		}
		
		//dwSize = ImmGetCompositionString( hIMC, GCS_RESULTSTR, (void*)str, sizeof( str ));//ȡ�ú������봮
		//str[ dwSize ] = 0;
		//unsigned char *p = str;
		//ge_inpututf8(ucs_to_utf8((const wchar_t*)p));
		//while( *p )PostMessage( hWnd, WM_CHAR, (WPARAM)(*p++), 1 );//ת��WM_CHAR��Ϣ
	}
	ImmReleaseContext( hWnd, hIMC );
	return true;//���Ƿ���true����ֹime���ڴ�
}

char* CIme::GetImeName(){
	return g_szImeName[ 0 ]? g_szImeName : NULL;
}

bool CIme::IfImeSharp(){//�Ƿ�ȫ��
	return g_bImeSharp;
}

bool CIme::IfImeSymbol(){//�Ƿ����ı��
	return g_bImeSymbol;
}

void CIme::GetImeInput( char **pszCompStr, char **pszCompReadStr, int *pnImeCursor, char **pszCandList ){
	if( pszCompStr )*pszCompStr = g_szCompStr;
	if( pszCompReadStr )*pszCompReadStr = g_szCompReadStr;
	if( pnImeCursor )*pnImeCursor = g_nImeCursor;
	if( pszCandList )*pszCandList = g_szCandList;
}

//����΢��ƴ��ʵ���˺ܶ��Լ��Ķ�����CIme�����ļ�������Щ����
//1���ں���ConvertCandList����˵��ѡ�ֱ������
//2������GetImeInput���ص�szCompReadStr��Ȼ�����˼ӹ�����������ļ�������
//   ����ÿ������ϵ�����ռ�Կո����8byte�����µĲ�����ϵ������Ϊ0xa1
//   ���ǿ��������뷨���������Ӵ�"΢��ƴ��"ʱ��ֻ��ʾĩβ��һ��8byte�������0xa1��ʲô������ʾ��Ҳ����ֱ����TextOut��ʾ���е�
