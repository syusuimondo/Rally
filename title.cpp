#include "DxLib.h"
#include "title.h"
static int juke;
void title_init(){
	juke= LoadGraph("�摜/title.png");
}
void title_draw(){
	DrawGraph(0,0,juke,TRUE);
	// ********** ��������ǂݍ��񂾃t�H���g�𗘗p�ł��� **********
	SetFontSize(24);	// ���₷���̂��߁A�t�H���g�T�C�Y��傫��
	DrawString( 130 , 280, "J��START", GetColor( 255 , 255 , 255 ) );
	DrawString( 130 , 330, "K��END", GetColor( 255 , 255 , 255 ) );
}