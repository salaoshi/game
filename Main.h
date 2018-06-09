//------------------------------------------------------
//  Файл:  MAIN.H
//  Описание:  Главный модуль приложения 
//------------------------------------------------------
//#define STRICT
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <math.h>
//#define NOMUSIC
//#define NOWORK
#define ClassName "DX_Window"
#define AppName "Program"
#define TIMER_RATE	992//
#define Q_WIDTH 30 //Р-Р квадрата
#define MAP_Q_WIDTH 6 //Р-Р квадрата карты
#define MAX_Q 83  //кол-во квадратов

#define SPLASH		100
#define BASE_MENU	101
#define GAME_MENU	99
#define DEATH		41
#define PEOPLE		98
#define PEOPLE_SAY	97
#define RELOAD		95
#define D_OBJ		94
#define D_OBJ_SAY	93
#define D_OBJ_SAY	93
#define S_OBJ		92
#define MAP_VIEW 		91

//----------------------
#define INFO_STATIC 200
#define INFO_DINAMIC 201
#define INFO_PEOPLE 202
#define INFO_FOOD	203
#define INFO_ITEMS	204
#define INFO_ITEMS2 205
#define INFO_PORTAL 206
#define INFO_SMALL	207
#define INFO_CHANGE 208
#define INFO_MONSTR 209
#define INFO_OBJ	 210
//--------------------------
#define OK 0
#define NOT_OK 1
#define NOT_NOT_OK 2
//--------------------------
#define MAX_LIFE 312
#define MAX_KARMA 112
#define MAX_ZASLUGA 112

#define MAX_FOOD 220
#define MAX_LIST MAX_FOOD+40

//#define MAX_POINT 4
#define FOOD_HEIGHT 560
#define FOOD_WIDTH 504
#define FOOD_F_WIDTH 28
#define FOOD_F_HEIGHT 28

#define MAX_X  (MAX_Q)*Q_WIDTH  //
#define MAX_Y   (MAX_Q)*Q_WIDTH //

#define MAX_WIDTH   640 //р-ры экрана
#define MAX_HEIGHT   480//р-ры экрана
//#define MAX_WIDTH   800 //р-ры экрана
//#define MAX_HEIGHT   600//р-ры экрана
//#define MAX_WIDTH   1024 //р-ры экрана
//#define MAX_HEIGHT   768//р-ры экрана


//#define SCREN_HEIGHT (MAX_HEIGHT-1-140)
#define COLOR_DEPTH  8//глубина цвета
#define TRASPARENT_COLOR 0xff//прозрачный цвет

#define PI 3.1415926535897932384626433832795//

#define MAP_WIDTH (MAX_X*cos(PI/6)*2+MAX_WIDTH)
#define MAP_HEIGHT (MAX_Y+MAX_HEIGHT)  //
#define MOUSE_HEIGHT 34//р-р курсора
#define MOUSE_WIDTH	 34//р-р курсора  
#define Surface_HEIGHT 30//р-р ленты пов-ти
#define Surface_WIDTH  768
#define Roof_HEIGHT 64//р-р крыши
#define Roof_WIDTH  768//
#define Obj_Change_HEIGHT 256
#define Obj_Change_WIDTH 424
#define Obj_HEIGHT 256
#define Obj_WIDTH  640//371+53+53+53//583 
#define Obj_ANIM_HEIGHT 640
#define Obj_ANIM_WIDTH 200
#define Obj3_HEIGHT 240
#define Obj3_WIDTH 477
#define Obj4_HEIGHT 270
#define Obj4_WIDTH 211*3
#define Obj5_HEIGHT 270
#define Obj5_WIDTH 265*3
#define Obj6_HEIGHT 300
#define Obj6_WIDTH 264+52
//#define Obj_small_F_WIDTH 14
#define Obj_Small_F_HEIGHT FOOD_F_HEIGHT/2
#define Obj_Small_F_WIDTH  FOOD_F_WIDTH/2
#define Obj_Small_HEIGHT   FOOD_HEIGHT/2
#define Obj_Small_WIDTH	   FOOD_WIDTH/2

#define Pers_HEIGHT 640
#define Pers_WIDTH 800*3+160

#define Monster0_HEIGHT 640
#define Monster0_WIDTH 800*3+80
#define MAX_MONSTER 17
#define MONSTER_ATAC 7 //4
#define MONSTER_LIFE 10
#define MONSTER_REPAIR 1000
#define MONSTER_F_HEIGHT 80
#define MONSTER_F_WIDTH 80
#define MONSRER1_Z_A 3//активация
#define MONSRER1_Z_DA 8//деактивация
#define MONSRER1_PAUSE 60
#define MONSRER1_ROT_TIME 30

#define SPLASH_HEIGHT 480
#define SPLASH_WIDTH 640
#define S_FRAME_HEIGHT 30//р-р кадра пов-ти
#define S_FRAME_WIDTH 53//(int)(2*Q_WIDTH*cos(PI/6)+2)//р-р кадра пов-ти
#define ROMB_F_HEIGHT 30
#define ROMB_F_WIDTH  64
#define ROOF_F_HEIGHT 64
#define ROOF_F_WIDTH  64

#define S_OBJ_F_HEIGHT 80
#define S_OBJ_F_WIDTH 40
#define OBJ_CHANGE_F_HEIGHT 88
#define OBJ_CHANGE_F_WIDTH 53
#define OBJ_F_HEIGHT 128
#define OBJ_F_WIDTH 32
#define OBJ_ANIM_F_HEIGHT 64
#define OBJ_ANIM_F_WIDTH 40 
#define OBJ3_F_HEIGHT 240
#define OBJ3_F_WIDTH 159 

#define OBJ5_F_HEIGHT 270
#define OBJ5_F_WIDTH 265 

#define Pers_F_HEIGHT 80//р-р героя
#define Pers_F_WIDTH 80//р-р героя

#define MAX_BRONYA 50

#define MAX_PEOPLE 20
#define MAX_OBJ_CHANGE 28
#define MAX_OBJ 20
#define MAX_S_OBJ 10
#define MAX_D_OBJ 20
#define MAX_PORTAL 6
#define S_Obj_HEIGHT 640
#define S_Obj_WIDTH 164

#define DEBUG_HEIGHT 220//
#define DEBUG_WIDTH  75//
#define DEBUG_HEIGHT2 220//
#define DEBUG_WIDTH2  70//
#define INFO_HEIGHT 80//
#define INFO_WIDTH 250//
#define Menu_HEIGHT 303//
#define Menu_WIDTH 270//
#define Menu2_HEIGHT 224//
#define Menu2_WIDTH 270-4//
#define Menu3_HEIGHT 352//
#define Menu3_WIDTH 320*7//
#define Menub_HEIGHT 303//
#define Menub_WIDTH 580//

//#define Menub_HEIGHT 480//
//#define Menub_WIDTH 640//
#define Panel_HEIGHT 480+14//140//
#define Panel_WIDTH 640//
#define FONT_WIDTH 4.7//ширина букв

//#define pMenuPeople1_WIDTH 160
//#define pMenuPeople1_HEIGHT MAX_HEIGHT-140+14
//#define pMenuPeople2_WIDTH (MAX_WIDTH-pMenuPeople1_WIDTH)
//#define pMenuPeople2_HEIGHT 100

#define FPS_HEIGHT   20
#define FPS_WIDTH    54
#define LIFE_HEIGHT	 11*4
#define LIFE_WIDTH   312
#define KARMA_HEIGHT	 112
#define KARMA_WIDTH		 77*2*2

#define BONUS_HEIGHT	 30
#define BONUS_WIDTH	     60

#define MAP_COUNT 3
//#define SCREN_COUNT	 1//
#define CURCOR_COUNT 1//
#define FRAMES_COUNT 10*3//
#define DIRECT_COUNT 8//кол-во направлений

//#define OBJ_COUNT 20

#define DXY 3//приращение расстояния на 1 шаге

#define TIME_BONUS	60

#define TIME_SPLASH 20

#define REPUTATION_MIN 2

//directions
#define D	0
#define D_L 1
#define L	2
#define U_L	3
#define U	4
#define U_R	5
#define R	6
#define D_R	7

#define DEC_PROTECT 0.02;
#define DEC_WEAROM 0.02;
#define DEC_ODEGDA 0.015;
#define DEC_SHAPKA 0.008;
#define DEC_LIFE 0.05;
#define INC_LIFE 0.01;
#define SAVE_SIZE 130;
void Set_Cursor(HWND hwnd);
BOOL InitGame(HWND hwnd);
//Функции инициализации и удаления объектов,
//связанных с DirectDraw
BOOL InitDirectDraw(HWND hwnd);
void RemoveDirectDraw (void);
void DrawFrame(void);
void NextTick( void );

//Функции инициализации и удаления объектов,
//связанных с DirectInput
BOOL	InitDirectInput (HWND hwnd);
void	RemoveDirectInput (void);
void	ProcessMouse();
void	AccessMouse(BOOL);

//Функции инициализации и удаления объектов,
//связанных с DirectSound
BOOL	InitDirectSound (HWND hwnd);
void	RemoveDirectSound ();
void PlaySoundBuffer(int numer);
void SetSoundVolume();
void DecSoundVolume();
void IncSoundVolume();

//Функции инициализации и удаления объектов,
//связанных с DirectMusic
BOOL	InitDirectMusic (HWND hwnd);
void	RemoveDirectMusic ();
void PlayMidi();
void StopMidi();
void DecMusicVolume();
void IncMusicVolume();

extern LONG lMasterVolume;
extern LONG SoundVolume;
extern MUSIC;
extern SOUND;
extern DS,DM;

extern PANEL_UPDATE;
extern INVENTORY;
extern QUEST;
extern MAGIA;
extern OPIT;
extern MAP;
extern MENU;
extern OPTIONS;

extern modeinfo;
extern nLife,nUstalost,nZasluga;
extern a,b;
extern MenuIndex;
extern nDEBUG;
extern  Vanim;

extern  mode,	level;

