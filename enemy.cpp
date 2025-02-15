#include"DxLib.h"
#include "enemy.h"
#include"map.h"
#include "music.h"
#include"option.h"
#include <stdlib.h>
enum{
	RIGHT,
	LEFT,
	DOWN,
	UP
};
static int enemy_x[12];
static int enemy_y[12];
static int enemy_i[12];
static int enemy[12];
static int enemy_imag[4];
static int enemy_count;
extern int map_kensa();
void enemy_init(){	//敵の初期設定
	LoadDivGraph( "画像/敵キャラ.png",4,4,1,32,32,enemy_imag);
	for(int i = 0;i < 12;i++){
		enemy_x[i] = enemy_raandom(3,11);
		enemy_y[i] = enemy_raandom(2,13);
		enemy_i[i] = RIGHT;
		enemy[i] = 1;
	}
}
void enemy_updata(){	//敵の移動
	enemy_count++;
	if(enemy_count >= 20){//敵が０．２秒で動く
		for(int i = 0;i < 12;i++){
			if(enemy[i] == 1){
			switch(enemy_raandom(0,3)){//敵が上下左右に動く
			case RIGHT:
				if(map_kensa(enemy_x[i]+1,enemy_y[i]) != 1){//敵右移動
					enemy_x[i]++;
					enemy_i[i] = RIGHT;
				}
				break;
			case LEFT:
				if(map_kensa(enemy_x[i]-1,enemy_y[i]) != 1){//左移動
					enemy_x[i]--;
					enemy_i[i] = LEFT;
				}
				break;
			case DOWN:
				if(map_kensa(enemy_x[i],enemy_y[i]+1) != 1){//下移動
					enemy_y[i]++;
					enemy_i[i] = DOWN;
				}
				break;
			case UP:
				if(map_kensa(enemy_x[i],enemy_y[i]-1) != 1){//上移動
					enemy_y[i]--;
					enemy_i[i] = UP;
				}
				break;
			}
			if(map_kensa(enemy_x[i],enemy_y[i] )==2){//敵が地雷を踏むかどうかの判定
				map_atari(enemy_x[i],enemy_y[i]);
				enemy[i] = 0;
				time_updata(100);
			}
			}
		}
		enemy_count = 0;
	}
}
int enemy_raandom(int min,int max){//乱数関数
	return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}
void enemy_return(){//敵の復活設定
	for(int i = 0;i < 12; i++){
		if(enemy[i] == 0){//敵が死亡していた場合
		enemy_x[i] = enemy_raandom(3,11);
		enemy_y[i] = enemy_raandom(2,13);
		enemy_i[i] = 0;
		enemy[i] = 1;
		}
	}
}
int enemy_atari(int ex,int ey){//敵の当たり判定
	for(int i = 0;i < 12; i++){
	if(ex == enemy_x[i] && ey == enemy_y[i]){
		return 1;
	}
	}
}
void enemy_draw(){//敵の描画
	for(int i = 0;i < 12; i++){
	if(enemy[i] == 1){
	switch(enemy_i[i]){
	case RIGHT:
		 DrawGraph( enemy_x[i]*32, enemy_y[i]*32,enemy_imag[0], TRUE );
		 break;
	case LEFT:
		 DrawGraph( enemy_x[i]*32, enemy_y[i]*32,enemy_imag[1], TRUE );
		 break;
	case DOWN:
		 DrawGraph( enemy_x[i]*32, enemy_y[i]*32,enemy_imag[3], TRUE );
		 break;
	case UP:
		 DrawGraph( enemy_x[i]*32, enemy_y[i]*32,enemy_imag[2], TRUE );
		 break;
	}
	}
	}
}