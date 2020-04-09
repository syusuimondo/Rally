#include "DxLib.h"
#include "music.h"
#include"player.h"
static int music_bomb;
static int music_title;
static int music_victory;
static int music_lose;
static int music_select;
extern int player_f;
void music_init(){//���y�̏����ݒ�
	music_bomb = LoadSoundMem("�T�E���h/bomb.mp3");
	music_title = LoadSoundMem("�T�E���h/title.mp3");
	music_victory = LoadSoundMem("�T�E���h/victory.mp3");
	music_lose = LoadSoundMem("�T�E���h/lose.mp3");

}
void music_draw(int i){//���y�̑I��
	switch(i){
	case 0://�n����
		 PlaySoundMem( music_bomb, DX_PLAYTYPE_BACK );
		 break;
	case 1://�^�C�g����
		if(music_select == 0) PlaySoundMem( music_title,DX_PLAYTYPE_BACK);
		music_select = 1;
		 break;
	case 2://�X�e�[�W��
		if(music_select == 1)
		music_select = 2;
		break;
	case 3://�Q�[���I�[�o�|��
		if(music_select == 2)PlaySoundMem(music_lose,DX_PLAYTYPE_BACK);
		music_select = 0;
		break;
	case 4://�Q�[���[�N���A��
		if(music_select == 2)PlaySoundMem(music_victory,DX_PLAYTYPE_BACK);
		music_select = 0;
		break;
	case 5:
		PlaySoundMem( music_title,DX_PLAYTYPE_BACK);
		break;
	}
}
void music_fin(){//���y�̍Đ����Ƃ߂�
	StopSoundMem(music_title);
	StopSoundMem(music_victory);
	StopSoundMem(music_lose);
}