#include "DxLib.h"
#include "original.h"
extern int Key[256];
extern int gpUpdateKey();
extern int player_fin();
extern int score;
static int set = 0;
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
		ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK ); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�
		SetMainWindowText("RALLY");
		music_init();
		title_init();
		player_scean(0);
        // while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A, �L�[�̏�ԍX�V)
        while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && gpUpdateKey()==0){
			//�Q�[���̏���
			if(player_fin() == 0){
				music_draw(1);
				title_draw();
				if( Key[ KEY_INPUT_J ]  == 1){
					map_init();
					player_init();
					enemy_init();
					time_init();
					music_fin();
					player_scean(1);
				}
				if(Key[ KEY_INPUT_K ]  == 1){
						DxLib_End(); // DX���C�u�����I������
						return 0;
				}
			}
			if(player_fin() == 1){
				music_draw(2);
				map_draw();
				player_draw();
				player_updata();
				enemy_draw();
				enemy_updata();
				enemy_return();
				time_draw();
				time_fin();
				if(player_fin() == 2 || player_fin() == 3) music_fin();
				}
			if(player_fin() == 2){
					music_draw(3);
					SetFontSize(36);
					DrawFormatString( 240,180, GetColor(255,255,255),"GAME OVER" );
					DrawFormatString( 240,260, GetColor(255,255,255),"J�Ń��g���C" );
					map_fin();
					if( Key[ KEY_INPUT_J ]  == 1){
						player_scean(0);
						music_fin();
					}
				}
			 if(player_fin() == 3){
				music_draw(4);
				SetFontSize(36);
				DrawFormatString( 220,180, GetColor(255,255,255),"GAME CREAR" );
				DrawFormatString( 220,220, GetColor(255,255,255),"SCORE %d",score );
				DrawFormatString( 220,260, GetColor(255,255,255),"J�Ń��g���C" );
				map_fin();
			 if( Key[ KEY_INPUT_J ]  == 1){
				 player_scean(0);
				 music_fin();
			 }
			}
        }
  return 0;      
} 
