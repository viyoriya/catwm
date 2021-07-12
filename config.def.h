
#ifndef CONFIG_H
#define CONFIG_H

/* 
  Mod1 == alt
  Mod4 == Super
*/
#define MOD4            Mod4Mask
#define DESKTOPS        10  
#define MASTER_SIZE     0.55
#define PANEL_HEIGHT    22
#define BORDER_WIDTH    0.5
#define ATTACH_ASIDE    1 /* 0=TRUE, 1=New window is master */
#define DEFAULT_MODE    2 /* 0 = Horizontal, 1 = Fullscreen, 2 = Vertical */

#define FOCUS           "#956671" // pinkish
#define UNFOCUS         "#5e81ac" // blueish

static const char dmenufont[]      = "Iosevka:style=Bold:size=11"; 
static const char col_gray1[]      = "#2E3440";
static const char col_gray3[]      = "#929496";
static const char col_cyan[]       = "#7d7f82"; 
static const char col_gray4[]      = "#010b13";

static char dmenumon[2]            =   "0"; 
static const char *dmenucmd[]	   = { "dmenu_run", "-p", "Find", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char* termcmd[]       = { "st",NULL};
static const char* nvimcmd[]       = { "st", "-e", "nvim", NULL };
static const char* rangercmd[]     = { "st","-e","ranger", NULL };
static const char* vscodecmd[]     = { "codium", NULL };
static const char* firefoxcmd[]    = { "firefox",NULL};

//static const char* rofiwindowcmd[] = { "rofi","-show","window", NULL };
static const char* volumeUp[]      = { "amixer","sset","Master","5%+",NULL};
static const char* volumeDown[]    = { "amixer","sset","Master","5%-",NULL};

#define DESKTOPCHANGE(K,N) \
    {  MOD4,             K,     change_desktop,     {.i = N}}, \
    {  MOD4|ShiftMask,   K,     client_to_desktop,  {.i = N}},

#define CMD(cmd) { .com = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static struct key keys[] = {
    // MOD               KEY              FUNCTION       	 ARGS
    {  MOD4,             XK_i,            increase,       	 {NULL}},
    {  MOD4,             XK_d,            decrease,       	 {NULL}},
    {  MOD4,   		     XK_v,            switch_vertical,	 {NULL}},
    {  MOD4,   			 XK_h,            switch_horizontal, {NULL}},    
    {  MOD4,             XK_f,            toggle_fullscreen, {NULL}},
    {  MOD4,   			 XK_q,            kill_client,    	 {NULL}},
    {  MOD4,   			 XK_k,            move_up,        	 {NULL}},
    {  MOD4,   			 XK_j,            move_down,      	 {NULL}},
    {  MOD4,   			 XK_m,            swap_master,    	 {NULL}},
    {  MOD4,             XK_Tab,          next_win,       	 {NULL}},
    {  MOD4,             XK_Right,        rotate_desktop,    {.i = 1}},
    {  MOD4,             XK_Left,         rotate_desktop,    {.i = -1}},     
    {  MOD4,             XK_F2,           spawn,          	 {.com = nvimcmd}},
    {  MOD4,             XK_F3,           spawn,          	 {.com = rangercmd}},   
    {  MOD4,             XK_F4,           spawn,          	 {.com = vscodecmd}},       
    {  MOD4,             XK_F5,           spawn,          	 {.com = firefoxcmd}},    
    {  MOD4,             XK_Return,       spawn,          	 {.com = termcmd}},
    {  MOD4,             XK_r,            spawn,          	 CMD("~/.config/catwm/util/xmenu-apps")},
  //{  MOD4,             XK_w,            spawn,          	 {.com = rofiwindowcmd}},
    {  MOD4,             XK_p,            spawn,             {.com = dmenucmd}},  
    {  MOD4,             XK_0,            spawn,          	 CMD("~/.config/catwm/util/dwm_power_menu.sh")},
    {  MOD4,             XK_F1,           spawn,          	 {.com = volumeUp}},
    {  MOD4|ShiftMask,   XK_F1,           spawn,         	 {.com = volumeDown}},            
	{  MOD4,             XK_Print,  	  spawn,          	 CMD("~/.config/catwm/util/screenshot.sh")},
	{  MOD4|ShiftMask,   XK_Print,  	  spawn,          	 CMD("~/.config/catwm/util/screenshot_w.sh")},	       
    {  MOD4|ShiftMask,	 XK_q,            catkill,        	 {NULL}},    
    DESKTOPCHANGE(  XK_1,   0)
    DESKTOPCHANGE(  XK_2,   1)
    DESKTOPCHANGE(  XK_3,   2)
    DESKTOPCHANGE(  XK_4,   3)
    DESKTOPCHANGE(  XK_5,   4)
    DESKTOPCHANGE(  XK_6,   5)
    DESKTOPCHANGE(  XK_7,   6)
    DESKTOPCHANGE(  XK_8,   7)
    DESKTOPCHANGE(  XK_9,   8)
};

#endif
