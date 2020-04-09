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
        char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����
        GetHitKeyStateAll( tmpKey ); // �S�ẴL�[�̓��͏�Ԃ𓾂�
        for( int i=0; i<256; i++ ){ 
                if( tmpKey[i] != 0 ){ // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
                        Key[i]++;     // ���Z
                } else {              // ������Ă��Ȃ����
                        Key[i] = 0;   // 0�ɂ���
                }
        }
        return 0;
}
extern int map_kensa();
extern int map_henka();
extern void music_draw();
void player_init(){//�v���C���[�̏����ݒ�
	LoadDivGraph( "�摜/���L����.png",4,4,1,32,32,player_imag);
	player_x = STARTX;
	player_y = STARTY;
	player_i = RIGHT;
	player_f = 0;
	player_re = LoadGraph("�摜/sousa.png");
}
void player_updata(){//�v���C���[�̈ړ�
	if( Key[ KEY_INPUT_D ]  == 1&& map_kensa(player_x+1,player_y) != 1 ){      //�E�ړ�
		player_x++;
		map_henka(player_x-1,player_y);
		player_i = RIGHT;
		music_draw(5);
	}
	if( Key[ KEY_INPUT_A ]  == 1&& map_kensa(player_x-1,player_y) != 1 ){      //���ړ�
		player_x--;
		map_henka(player_x+1,player_y);
		player_i = LEFT;
		music_draw(5);
	}
	if( Key[ KEY_INPUT_S ]  == 1&& map_kensa(player_x,player_y+1) != 1 ){      //���ړ�
		player_y++;
		map_henka(player_x,player_y-1);
		player_i = DOWN;
		music_draw(5);
	}
	if( Key[ KEY_INPUT_W ]  == 1&& map_kensa(player_x,player_y-1) != 1 ){      //��ړ�
		player_y--;
		map_henka(player_x,player_y+1);
		player_i = UP;
		music_draw(5);
	}
	if(map_kensa(player_x,player_y) == 2){//�v���C���[���n���}�X�𓥂񂾏ꍇ
		map_atari(player_x,player_y);
		player_f = 2;
	}
	if(enemy_atari(player_x,player_y) == 1){//�v���C���[���G�ƏՓ˂����ꍇ
		player_f = 2;
	}
}
void player_draw(){//�v���C���[�̕`��
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
int player_fin(){//�v���C���[�̏I���ݒ�
	if(player_f == 0){//�v���C���[�̃^�C�g��
		return 0;
	}
	if(player_f == 1){//�v���C���[�̃X�e�[�W
		return 1;
	}
	if(player_f == 2){//�v���C���[�̃Q�[���I�[�o�[
		return 2;
	}
	if(player_f == 3){//�v���C���[�̃Q�[���I�[�o�[
		return 3;
	}
}