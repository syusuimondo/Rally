#include "DxLib.h"
#include "map.h"
#include"player.h"
#include"music.h"
static int map[13][15] ={//�}�b�v�̏����z��
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
void map_init(){//�}�b�v�̏����ݒ�
	LoadDivGraph( "�摜/�}�b�v.png",3,3,1,32,32,image);
}
int map_kensa(int x,int y){//�}�b�v�̌���
			if(map[x][y] == 1)//�}�b�v���ǂ������ꍇ
				return 1;
			if(map[x][y] == 2)//�}�b�v���n���������ꍇ
				return 2;
}
void map_henka(int bx,int by){//�}�b�v��n���ɕς���
		map[bx][by] = 2;
}
void map_atari(int mx,int my){//�}�b�v�𕽒n�ɂ���
	map[mx][my] = 0;
	music_draw(0);
}
void map_draw(){//�}�b�v��`�悷��
	for(int y = 0;y<15;y++){
		for(int x = 0;x<13;x++){
			switch(map[x][y]){
			case 0://�}�b�v�����n�̏ꍇ
				 DrawGraph( x*32, y*32, image[0], TRUE );
				 break;
			case 1://�}�b�v���ǂ̏ꍇ
				DrawGraph( x*32, y*32, image[1], TRUE );
				 break;
			case 2://�}�b�v���n���̏ꍇ
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
			case 2://�n���𕽒n�ɂ���
				 map[x][y] = 0;
				 break;
			}
		}
	}
}