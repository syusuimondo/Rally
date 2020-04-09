#include"DxLib.h"
#include "player.h"
#include"map.h"
#include "music.h"
#include "enemy.h"
#include "option.h"
enum{
	RIGHT,
	LEFT,
	DOWN,
	UP
};
#define STARTX 1
#define STARTY 1
static int player_x;
static int player_y;
static int player_imag[4];
static int player_i;
static int player_f;
static int player_re;
static int countp;
int Key[256];
int gpUpdateKey(){
        char tmpKey[256]; // 現在のキーの入力状態を格納する
        GetHitKeyStateAll( tmpKey ); // 全てのキーの入力状態を得る
        for( int i=0; i<256; i++ ){ 
                if( tmpKey[i] != 0 ){ // i番のキーコードに対応するキーが押されていたら
                        Key[i]++;     // 加算
                } else {              // 押されていなければ
                        Key[i] = 0;   // 0にする
                }
        }
        return 0;
}
extern int map_kensa();
extern int map_henka();
extern void music_draw();
void player_init(){//プレイヤーの初期設定
	LoadDivGraph( "画像/自キャラ.png",4,4,1,32,32,player_imag);
	player_x = STARTX;
	player_y = STARTY;
	player_i = RIGHT;
	player_f = 0;
	player_re = LoadGraph("画像/sousa.png");
}
void player_updata(){//プレイヤーの移動
	if( Key[ KEY_INPUT_D ]  == 1&& map_kensa(player_x+1,player_y) != 1 ){      //右移動
		player_x++;
		map_henka(player_x-1,player_y);
		player_i = RIGHT;
		music_draw(5);
	}
	if( Key[ KEY_INPUT_A ]  == 1&& map_kensa(player_x-1,player_y) != 1 ){      //左移動
		player_x--;
		map_henka(player_x+1,player_y);
		player_i = LEFT;
		music_draw(5);
	}
	if( Key[ KEY_INPUT_S ]  == 1&& map_kensa(player_x,player_y+1) != 1 ){      //下移動
		player_y++;
		map_henka(player_x,player_y-1);
		player_i = DOWN;
		music_draw(5);
	}
	if( Key[ KEY_INPUT_W ]  == 1&& map_kensa(player_x,player_y-1) != 1 ){      //上移動
		player_y--;
		map_henka(player_x,player_y+1);
		player_i = UP;
		music_draw(5);
	}
	if(map_kensa(player_x,player_y) == 2){//プレイヤーが地雷マスを踏んだ場合
		map_atari(player_x,player_y);
		player_f = 2;
	}
	if(enemy_atari(player_x,player_y) == 1){//プレイヤーが敵と衝突した場合
		player_f = 2;
	}
}
void player_draw(){//プレイヤーの描画
	switch(player_i){
	case RIGHT:
		 DrawGraph( player_x*32, player_y*32, player_imag[0], TRUE );
		 break;
	case LEFT:
		 DrawGraph( player_x*32, player_y*32, player_imag[1], TRUE );
		 break;
	case DOWN:
		 DrawGraph( player_x*32, player_y*32, player_imag[3], TRUE );
		 break;
	case UP:
		 DrawGraph( player_x*32, player_y*32, player_imag[2], TRUE );
		 break;
	}
	DrawGraph(430,220,player_re,TRUE);
}
void player_scean(int player_s){
	player_f = player_s;
}
int player_fin(){//プレイヤーの終了設定
	if(player_f == 0){//プレイヤーのタイトル
		return 0;
	}
	if(player_f == 1){//プレイヤーのステージ
		return 1;
	}
	if(player_f == 2){//プレイヤーのゲームオーバー
		return 2;
	}
	if(player_f == 3){//プレイヤーのゲームオーバー
		return 3;
	}
}