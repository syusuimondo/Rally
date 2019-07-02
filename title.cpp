#include "DxLib.h"
#include "title.h"
static int juke;
void title_init(){
	juke= LoadGraph("画像/Jukebox.png");
		// ********** フォントのロード ********
	LPCSTR font_path = "misaki_mincho.ttf"; // 読み込むフォントファイルのパス
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
	} else {
		// フォント読込エラー処理
		MessageBox(NULL,"フォント読込失敗","",MB_OK);
	}
}
void title_draw(int ti){
	DrawGraph(0,0,juke,TRUE);
	// ********** ここから読み込んだフォントを利用できる **********
	SetFontSize(24);	// 見やすさのため、フォントサイズを大きく
	ChangeFont( "美咲明朝", DX_CHARSET_DEFAULT ) ;
	if(ti == 0) DrawString( 130 , 280, "START", GetColor( 255 , 255 , 255 ) );
	if(ti == 1) DrawString( 130 , 280, "END", GetColor( 255 , 255 , 255 ) );
	//WaitKey() ;		// キーの入力待ち(『WaitKey』を使用)
}