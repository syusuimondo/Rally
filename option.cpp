#include"DxLib.h"
#include "option.h"
#include "player.h"
static int starttime;
int score;
void time_init(){//���ԂƃX�R�A�̏����ݒ�
	starttime = GetNowCount();
	score = 0;
}
void time_updata(int i){//�X�R�A���Z
	score = score + i;
	
}
void time_draw(){//���ԂƃX�R�A�̕`��
	DrawFormatString(450,100,GetColor(255,255,255),"%d�b",30-(GetNowCount()-starttime)/1000);
	DrawFormatString(450,150,GetColor(255,255,255),"SCORE");
	DrawFormatString(450,200,GetColor(255,255,255),"%d",score);
}
void time_fin(){
	// 40�b��ɃQ�[�����I�����܂��B
// 1�b=1000 40�b=40000
// �J�n���Ԃ���4000�̍�������΃��[�v���Ȃ��Ȃ�܂��B
	if(GetNowCount()-starttime >30000) player_scean(3);
}
int score_fin(){//�X�R�A�̃����N��ݒ肷��
	if(score >= 2400) return 2;
	else if(score >= 1200) return 1;
	else return 0;
}