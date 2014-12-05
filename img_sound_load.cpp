/* img_sound_load.cpp */

#include "DxLib.h"
#include "ExternGV.h"

void img_sound_load(){
	img_background[0] = LoadGraph("Sh/img/back/background0.png");
	img_background[1] = LoadGraph("Sh/img/back/background1.png");
	img_player_shot[0] = LoadGraph("Sh/img/shot/player/1.png");
	img_player_shot[1] = LoadGraph("Sh/img/shot/player/2.png");
	LoadDivGraph("Sh/img/char/player.png", 4, 4, 1, 32, 48, img_player);
}