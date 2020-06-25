 /* config.h for catwm-0.0.5.c
 *
 *  ( o   o )  Made by cat...
 *  (  =^=  )
 *  (        )            ... for cat!
 *  (         )
 *  (          ))))))________________ Cute And Tiny Window Manager
 *  ______________________________________________________________________________
 *
 *  Copyright (c) 2014-2015, Dj_Dexter, Helmuth.Schmelzer@gmail.com
 *  Copyright (c) 2010, Rinaldini Julien, julien.rinaldini@heig-vd.ch
 *  Based in moetunes fork
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Some changes and additions by P. Newman 24.4.11
 *     - best not to email julien if you use this... :)
 *  Some changes and bugfixes by Dj_Dexter/djmasde 21.7.14
 *  Bug with desktop numbers:
 *  -before, only show 3 desktops
 *  -after, show to 9 desktops, configured with config.h
 *  -removed the next_desktop, and prev_desktop functions
 *  Now, numlock on, not affects the keyboard shortcuts
 *  Unmapnotify function for rare windows, Ex: thunderbird, firefox, etc...
 */

#ifndef CONFIG_H
#define CONFIG_H

#define DESKTOPS        10  // Added for rotate_desktop method - vj

/* Mod (Mod1 == alt) and master size
   and I added panel size and  the windows key (Mod4 == Super)
   added shortcuts for different tiling modes
   added shortcuts for moving the window to the next workspace and back
   */
//#define MOD1            Mod1Mask
#define MOD4            Mod4Mask
#define MASTER_SIZE     0.6
#define PANEL_HEIGHT    18
#define BORDER_WIDTH    3
#define ATTACH_ASIDE    1 /* 0=TRUE, 1=New window is master */
#define DEFAULT_MODE    2 /* 0 = Horizontal, 1 = Fullscreen, 2 = Vertical */

// Colors
#define FOCUS           "#956671" // pinkish
#define UNFOCUS         "#5e81ac" // blueish

static const char dmenufont[]      = "Iosevka:style=Bold:pixelsize=12"; 
static const char col_gray1[]      = "#2E3440";
static const char col_gray3[]      = "#929496";
static const char col_cyan[]       = "#7d7f82"; 
static const char col_gray4[]      = "#010b13";

static char dmenumon[2]            =   "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]      = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char* termcmd[]       = { "st",NULL};
static const char* chromecmd[]     = { "google-chrome-stable", NULL };
static const char* rangercmd[]     = { "st","-e","ranger", NULL };
static const char* sublcmd[]       = { "subl", NULL };
static const char* firefoxcmd[]    = { "firefox",NULL};
static const char* rofiruncmd[]    = { "rofi","-show","drun", NULL };
static const char* rofiwindowcmd[] = { "rofi","-show","window", NULL };
static const char* volumeUp[]      = { "amixer","sset","Master","5%+",NULL};
static const char* volumeDown[]    = { "amixer","sset","Master","5%-",NULL};

// Avoid multiple paste
#define DESKTOPCHANGE(K,N) \
    {  MOD4,             K,     change_desktop,     {.i = N}}, \
    {  MOD4|ShiftMask,   K,     client_to_desktop,  {.i = N}},

// Execute commands
#define CMD(cmd) { .com = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

// Shortcuts
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
    {  MOD4,             XK_F2,           spawn,          	 {.com = chromecmd}},
    {  MOD4,             XK_F3,           spawn,          	 {.com = rangercmd}},   
    {  MOD4,             XK_F4,           spawn,          	 {.com = sublcmd}},       
    {  MOD4,             XK_F5,           spawn,          	 {.com = firefoxcmd}},    
    {  MOD4,             XK_Return,       spawn,          	 {.com = termcmd}},
    {  MOD4,             XK_r,            spawn,          	 {.com = rofiruncmd}},
    {  MOD4,             XK_w,            spawn,          	 {.com = rofiwindowcmd}},
    {  MOD4,             XK_p,            spawn,             {.com = dmenucmd}},  
    {  MOD4,             XK_0,            spawn,          	 CMD("~/.config/catwm/power-menu.sh")},
    {  MOD4,             XK_F1,           spawn,          	 {.com = volumeUp}},
    // Windows Key + shift + shortcut
    {  MOD4|ShiftMask,   XK_F1,           spawn,         	 {.com = volumeDown}},            
    {  MOD4|ShiftMask,	 XK_q,            catkill,        	 {NULL}},
	{  MOD4,             XK_Print,  	  spawn,          	 CMD("~/.config/catwm/screenshot.sh")},
	{  MOD4|ShiftMask,   XK_Print,  	  spawn,          	 CMD("~/.config/catwm/screenshot-w.sh")},	       
       DESKTOPCHANGE(    XK_1,                               0)
       DESKTOPCHANGE(    XK_2,                               1)
       DESKTOPCHANGE(    XK_3,                               2)
       DESKTOPCHANGE(    XK_4,                               3)
       DESKTOPCHANGE(    XK_5,                               4)
       DESKTOPCHANGE(    XK_6,                               5)
       DESKTOPCHANGE(    XK_7,                               6)
       DESKTOPCHANGE(    XK_8,                               7)
       DESKTOPCHANGE(    XK_9,                               8)
       //DESKTOPCHANGE(   XK_0,                                  9)
};

#endif
