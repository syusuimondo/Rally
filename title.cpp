#include "DxLib.h"
#include "title.h"
static int juke;
void title_init(){
	juke= LoadGraph("画像/title.png");
}
void title_draw(){
	DrawGraph(0,0,juke,TRUE);
	// ********** ここから読み込んだフォントを利用できる **********
	SetFontSize(24);	// 見やすさのため、フォントサイズを大きく
	DrawString( 130 , 280, "JでSTART", GetColor( 255 , 255 , 255 ) );
	DrawString( 130 , 330, "KでEND", GetColor( 255 , 255 , 255 ) );
}