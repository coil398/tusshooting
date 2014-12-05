/* player.cpp */

#include "DxLib.h"
#include "ExternGV.h"


void PlayerControl(){
	if (Key[KEY_INPUT_LEFT]==1)
	{
		Player.x -= 4.0f;
		if (Player.x < 10.0)Player.x = 10.0;
	}
	if (Key[KEY_INPUT_RIGHT] == 1)
	{
		Player.x += 4.0f;
		if (Player.x > 409.0)Player.x = 409.0;
	}
	if (Key[KEY_INPUT_UP] == 1)
	{
		Player.y -= 4.0f;
		if (Player.y < 15.0)Player.y = 15.0;
	}
	if (Key[KEY_INPUT_DOWN] == 1)
	{
		Player.y += 4.0f;
		if (Player.y > 465.0)Player.y = 465.0;
	}

	DrawGraph((int)Player.x, (int)Player.y, img_player[0], TRUE);
}

void PlayerShotCalc()
{
	int i, j;
	int positionx[11] = { 0, -10, 10, -10, 10, -15, 15, -10, 10, -10, 10 }, positiony[11] = { -15, -2, -2, 6, 6, -6, -6, 2, 2, 10, 10 };
	if (Key[KEY_INPUT_Z] == 1 && counter % 5 == 0)
	{
		for (i = 0; i < ShotLevel; i++){
			for (j = 0; j < PLAYER_MAX_SHOT2; j++)
			{
				if (PlayerShot[i][j].flag == 0)
				{
					PlayerShot[i][j].flag = 1;
					PlayerShot[i][j].x = Player.x + (double)positionx[i];
					PlayerShot[i][j].y = Player.y + (double)positiony[i];
					break;
				}
			}
		}
	}

	int sab[11] = { 0, -1, 1, -3, 3, 0, 0, -2, 2, -5, 5 };
	for (i = 0; i < PLAYER_MAX_SHOT2; i++)
		for (j = 0; j < PLAYER_MAX_SHOT2; j++)
		{
			if (PlayerShot[i][j].flag == 1)
			{
				PlayerShot[i][j].x += (double)sab[i];
				PlayerShot[i][j].y -= 10.0;
				if (PlayerShot[i][j].y < -20)PlayerShot[i][j].flag = 0;
			}
		}
}


void PlayerShotDisp()
{
	int i, j;
	for (i = 0; i < PLAYER_MAX_SHOT1; i++)
	{
		for (j = 0; j < PLAYER_MAX_SHOT2; j++)
		{
			switch (i)
			{
			case 0:
			case 5:
			case 6:
				if (PlayerShot[i][j].flag == 1)
					DrawGraph(PlayerShot[i][j].x + 7, PlayerShot[i][j].y - 18, img_player_shot[0], true);
				break;
			default:
				DrawGraph((int)PlayerShot[i][j].x+8, (int)PlayerShot[i][j].y - 10, img_player_shot[1], true);
				break;
			}
		}
	}
}
