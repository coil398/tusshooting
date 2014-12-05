#define PLAYER_MAX_SHOT1 11
#define PLAYER_MAX_SHOT2 15

int counter = 0, color_white;
char Key[256];

int img_background[2];
int img_player[4];

int ShotLevel = 11;

typedef struct
{
	double x, y;
	int status, counter; int shot[11][15];
} BODY_player_t;

BODY_player_t Player;

int img_player_shot[2];
typedef struct
{
	double x, y;
	int flag;
}SHOT_t;

SHOT_t PlayerShot[PLAYER_MAX_SHOT1][PLAYER_MAX_SHOT2];