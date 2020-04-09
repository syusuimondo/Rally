#include "DxLib.h"
#include "map.h"
#include"player.h"
#include"music.h"
static int map[13][15] ={//マップの初期配列
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
static int image[3];
void map_init(){//マップの初期設定
	LoadDivGraph( "画像/マップ.png",3,3,1,32,32,image);
}
int map_kensa(int x,int y){//マップの検査
			if(map[x][y] == 1)//マップが壁だった場合
				return 1;
			if(map[x][y] == 2)//マップが地雷だった場合
				return 2;
}
void map_henka(int bx,int by){//マップを地雷に変える
		map[bx][by] = 2;
}
void map_atari(int mx,int my){//マップを平地にする
	map[mx][my] = 0;
	music_draw(0);
}
void map_draw(){//マップを描画する
	for(int y = 0;y<15;y++){
		for(int x = 0;x<13;x++){
			switch(map[x][y]){
			case 0://マップが平地の場合
				 DrawGraph( x*32, y*32, image[0], TRUE );
				 break;
			case 1://マップが壁の場合
				DrawGraph( x*32, y*32, image[1], TRUE );
				 break;
			case 2://マップが地雷の場合
				 DrawGraph( x*32, y*32, image[2], TRUE );
				 break;
			}
		}
	}
}
void map_fin(){
for(int y = 0;y<15;y++){
		for(int x = 0;x<13;x++){
			switch(map[x][y]){
			case 2://地雷を平地にする
				 map[x][y] = 0;
				 break;
			}
		}
	}
}