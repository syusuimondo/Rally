#include "DxLib.h"
#include "title.h"
static int juke;
void title_init(){
	juke= LoadGraph("�摜/Jukebox.png");
		// ********** �t�H���g�̃��[�h ********
	LPCSTR font_path = "misaki_mincho.ttf"; // �ǂݍ��ރt�H���g�t�@�C���̃p�X
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
	} else {
		// �t�H���g�Ǎ��G���[����
		MessageBox(NULL,"�t�H���g�Ǎ����s","",MB_OK);
	}
}
void title_draw(int ti){
	DrawGraph(0,0,juke,TRUE);
	// ********** ��������ǂݍ��񂾃t�H���g�𗘗p�ł��� **********
	SetFontSize(24);	// ���₷���̂��߁A�t�H���g�T�C�Y��傫��
	ChangeFont( "���疾��", DX_CHARSET_DEFAULT ) ;
	if(ti == 0) DrawString( 130 , 280, "START", GetColor( 255 , 255 , 255 ) );
	if(ti == 1) DrawString( 130 , 280, "END", GetColor( 255 , 255 , 255 ) );
	//WaitKey() ;		// �L�[�̓��͑҂�(�wWaitKey�x���g�p)
}