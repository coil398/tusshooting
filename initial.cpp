#include "DxLib.h"
#include "ExternGV.h"


void initialization(){
	Player.x = 200.0;
	Player.y = 400.0;
	Player.counter = 0;
	Player.status = 0;
	for (int i = 0; i < PLAYER_MAX_SHOT1; i++)
		for (int j = 0; j < PLAYER_MAX_SHOT2; j++)
			PlayerShot[i][j].flag = 0;
}

void SetColor(){
	color_white = GetColor(255, 255, 255);                   //”’Fƒnƒ“ƒhƒ‹‚ðŽæ“¾
}
