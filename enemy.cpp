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
void enemy_init(){	//“G‚Ì‰Šúİ’è
	LoadDivGraph( "‰æ‘œ/“GƒLƒƒƒ‰.png",4,4,1,32,32,enemy_imag);
	for(int i = 0;i < 12;i++){
		enemy_x[i] = enemy_raandom(3,11);
		enemy_y[i] = enemy_raandom(2,13);
		enemy_i[i] = RIGHT;
		enemy[i] = 1;
	}
}
void enemy_updata(){	//“G‚ÌˆÚ“®
	enemy_count++;
	if(enemy_count >= 20){//“G‚ª‚OD‚Q•b‚Å“®‚­
		for(int i = 0;i < 12;i++){
			if(enemy[i] == 1){
			switch(enemy_raandom(0,3)){//“G‚ªã‰º¶‰E‚É“®‚­
			case RIGHT:
				if(map_kensa(enemy_x[i]+1,enemy_y[i]) != 1){//“G‰EˆÚ“®
					enemy_x[i]++;
					enemy_i[i] = RIGHT;
				}
				break;
			case LEFT:
				if(map_kensa(enemy_x[i]-1,enemy_y[i]) != 1){//¶ˆÚ“®
					enemy_x[i]--;
					enemy_i[i] = LEFT;
				}
				break;
			case DOWN:
				if(map_kensa(enemy_x[i],enemy_y[i]+1) != 1){//‰ºˆÚ“®
					enemy_y[i]++;
					enemy_i[i] = DOWN;
				}
				break;
			case UP:
				if(map_kensa(enemy_x[i],enemy_y[i]-1) != 1){//ãˆÚ“®
					enemy_y[i]--;
					enemy_i[i] = UP;
				}
				break;
			}
			if(map_kensa(enemy_x[i],enemy_y[i] )==2){//“G‚ª’n—‹‚ğ“¥‚Ş‚©‚Ç‚¤‚©‚Ì”»’è
				map_atari(enemy_x[i],enemy_y[i]);
				enemy[i] = 0;
				time_updata(100);
			}
			}
		}
		enemy_count = 0;
	}
}
int enemy_raandom(int min,int max){//—”ŠÖ”
	return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}
void enemy_return(){//“G‚Ì•œŠˆİ’è
	for(int i = 0;i < 12; i++){
		if(enemy[i] == 0){//“G‚ª€–S‚µ‚Ä‚¢‚½ê‡
		enemy_x[i] = enemy_raandom(3,11);
		enemy_y[i] = enemy_raandom(2,13);
		enemy_i[i] = 0;
		enemy[i] = 1;
		}
	}
}
int enemy_atari(int ex,int ey){//“G‚Ì“–‚½‚è”»’è
	for(int i = 0;i < 12; i++){
	if(ex == enemy_x[i] && ey == enemy_y[i]){
		return 1;
	}
	}
}
void enemy_draw(){//“G‚Ì•`‰æ
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