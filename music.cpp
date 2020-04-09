#include "DxLib.h"
#include "music.h"
#include"player.h"
static int music_bomb;
static int music_title;
static int music_victory;
static int music_lose;
static int music_select;
extern int player_f;
void music_init(){//音楽の初期設定
	music_bomb = LoadSoundMem("サウンド/bomb.mp3");
	music_title = LoadSoundMem("サウンド/title.mp3");
	music_victory = LoadSoundMem("サウンド/victory.mp3");
	music_lose = LoadSoundMem("サウンド/lose.mp3");

}
void music_draw(int i){//音楽の選択
	switch(i){
	case 0://地雷音
		 PlaySoundMem( music_bomb, DX_PLAYTYPE_BACK );
		 break;
	case 1://タイトル音
		if(music_select == 0) PlaySoundMem( music_title,DX_PLAYTYPE_BACK);
		music_select = 1;
		 break;
	case 2://ステージ音
		if(music_select == 1)
		music_select = 2;
		break;
	case 3://ゲームオーバ－音
		if(music_select == 2)PlaySoundMem(music_lose,DX_PLAYTYPE_BACK);
		music_select = 0;
		break;
	case 4://ゲームークリア音
		if(music_select == 2)PlaySoundMem(music_victory,DX_PLAYTYPE_BACK);
		music_select = 0;
		break;
	case 5:
		PlaySoundMem( music_title,DX_PLAYTYPE_BACK);
		break;
	}
}
void music_fin(){//音楽の再生をとめる
	StopSoundMem(music_title);
	StopSoundMem(music_victory);
	StopSoundMem(music_lose);
}