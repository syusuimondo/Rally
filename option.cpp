#include"DxLib.h"
#include "option.h"
#include "player.h"
static int starttime;
int score;
void time_init(){//時間とスコアの初期設定
	starttime = GetNowCount();
	score = 0;
}
void time_updata(int i){//スコア加算
	score = score + i;
	
}
void time_draw(){//時間とスコアの描画
	DrawFormatString(450,100,GetColor(255,255,255),"%d秒",30-(GetNowCount()-starttime)/1000);
	DrawFormatString(450,150,GetColor(255,255,255),"SCORE");
	DrawFormatString(450,200,GetColor(255,255,255),"%d",score);
}
void time_fin(){
	// 40秒後にゲームを終了します。
// 1秒=1000 40秒=40000
// 開始時間から4000の差があればループしなくなります。
	if(GetNowCount()-starttime >30000) player_scean(3);
}
int score_fin(){//スコアのランクを設定する
	if(score >= 2400) return 2;
	else if(score >= 1200) return 1;
	else return 0;
}