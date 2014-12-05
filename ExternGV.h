#define PLAYER_MAX_SHOT1 11
#define PLAYER_MAX_SHOT2 15

extern int counter, color_white;
extern char Key[256];


//画像ファイルハンドル
extern int img_background[2];
extern int img_player[4];

//弾
extern int img_player_shot[2];

extern int ShotLevel;

typedef struct{
	double x, y;
	int status, counter; int shot[11][15];
} BODY_player_t;

extern BODY_player_t Player;

typedef struct
{
	double x, y;
	int flag;
}SHOT_t;

extern SHOT_t PlayerShot[PLAYER_MAX_SHOT1][PLAYER_MAX_SHOT2];