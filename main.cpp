/* main.cpp */

#include "DxLib.h"
#include "GlobalVariable.h"


int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

	extern void img_sound_load();
	extern void initialization();
	extern void SetColor();
	extern void Background();
	extern void PlayerShotCalc();
	extern void PlayerShotDisp();
	extern void PlayerControl();
	extern void Background2();
	extern void FpsTimeFanction();
	int RefreshTime = 0;

	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) return -1;

	SetDrawScreen(DX_SCREEN_BACK);                  //����ʂ��g�p����B

	img_sound_load();
	initialization();
	SetColor();

	while (ProcessMessage() == 0 && GetHitKeyStateAll(Key) == 0){
		RefreshTime = GetNowCount();              //���̎��Ԃ��擾
		ClearDrawScreen();                                        //����ʂ̃f�[�^��S�č폜

		Background();

		PlayerShotCalc();

		PlayerShotDisp();

		PlayerControl();

		Background2();

		FpsTimeFanction();

		ScreenFlip();                                            //����ʃf�[�^��\��ʂ֔��f

		counter++;

		if (Key[KEY_INPUT_ESCAPE] == 1)    break;  //Escape�������ꂽ��I��
		while (GetNowCount() - RefreshTime < 17);//1���̏�����17�~���b�ɂȂ�܂ő҂�
	}

	DxLib_End();
	return 0;
}