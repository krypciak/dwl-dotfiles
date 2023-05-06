#define SUPER WLR_MODIFIER_LOGO
#define ALT WLR_MODIFIER_ALT
#define SHIFT WLR_MODIFIER_SHIFT
#define CTRL WLR_MODIFIER_CTRL
#define CAPS WLR_MODIFIER_MOD3

/* appearance */
static const int sloppyfocus               = 0;  /* focus follows mouse */
static const int bypass_surface_visibility = 0;  /* 1 means idle inhibitors will disable idle tracking even if it's surface isn't visible  */
static const float rootcolor[]             = {0.3, 0.3, 0.3, 1.0};
static const float bordercolor[]           = {0.5, 0.5, 0.5, 1.0};
static const float focuscolor[]            = {1.0, 0.0, 0.0, 1.0};
/* To conform the xdg-protocol, set the alpha to zero to restore the old behavior */
static const float fullscreen_bg[]         = {0.1, 0.1, 0.1, 1.0};


static unsigned int borderpx         = 0;  /* border pixel of windows */
static const unsigned int default_borderpx = 1;  /* second state of borderpx */

static const unsigned int gappih    = 0;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 0;       /* vert inner gap between windows */
static const unsigned int gappoh    = 0;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 0;       /* vert outer gap between windows and screen edge */
static const unsigned int default_gapps = 0;  /* second state of gapp size */

static const int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const int monoclegaps        = 0;        /* 1 means outer gaps in monocle layout */
static const int smartborders       = 1;


static const int lockfullscreen     = 1;  /* 1 will force focus on the fullscreen window */

/* tagging - tagcount should be no greater than 31 */
#define tagcount 14

static const unsigned int tags_layouts[] = {
    0,
    2,   2,   2,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,
};

static const Rule rules[] = {
	/* app_id                 title   tags mask   iscentered  ismaximilized issticky
     *                                                isfloating  isterm        donthidecursor
     *                                                    isfullscreen noswallow    monitor */
    { "Alacritty",            NULL,   0,          0,  0,  0,  0,  1,   0,   0,  0,  -1 },
    
    { "cmus",                 NULL,   1 << 3,     0,  0,  0,  0,  0,   0,   0,  0,  -1 },
    { "discord",              NULL,   1 << 4,     1,  0,  0,  0,  0,   0,   0,  0,  -1 },

    { "LibreWolf",            NULL,   1 << 5,     0,  0,  0,  0,  0,   0,   0,  0,  -1 },
    { "chromium",             NULL,   1 << 6,     0,  0,  0,  0,  0,   0,   0,  0,  -1 },
    { "tutanota-desktop",     NULL,   1 << 7,     0,  0,  0,  0,  0,   0,   0,  0,  -1 },
    { "aerc",                 NULL,   1 << 7,     0,  0,  0,  0,  0,   0,   0,  0,  -1 },
    { "dialect",              NULL,   1 << 8,     0,  0,  0,  0,  0,   0,   0,  0,  -1 },
    { NULL,            "Invidious",   1 << 9,     0,  0,  0,  0,  0,   0,   0,  0,  -1 },
    { "LBRY",                 NULL,   1 << 9,     0,  0,  0,  0,  0,   0,   0,  0,  -1 },
    { "FreeTube",             NULL,   1 << 9,     0,  0,  0,  0,  0,   0,   0,  0,  -1 },
    { NULL,   "Picture in picture",   1 << 9,     0,  1,  0,  0,  0,   1,   1,  0,  -1 },
    { "prismlauncher",        NULL,   1 << 10,    0,  0,  0,  0,  0,   0,   0,  0,  -1 },
    { NULL,            "Minecraft",   1 << 10,    0,  0,  0,  1,  0,   0,   0,  1,  -1 },
    { "Minecraft* 1.19.3",    NULL,   1 << 10,    0,  0,  0,  1,  0,   0,   0,  1,  -1 },
    { "gamescope",            NULL,   1 << 12,    0,  0,  1,  0,  0,   0,   0,  1,  -1 },
    { "live.na.exe",          NULL,   1 << 12,    1,  1,  0,  0,  0,   0,   0,  1,  -1 },
    { "Steam",                NULL,   1 << 13,    0,  0,  0,  0,  0,   0,   0,  0,  -1 },
    { "Lutris",               NULL,   1 << 13,    0,  0,  0,  0,  0,   0,   0,  0,  -1 },
    { "steap_app_960090",     NULL,   1 << 13,    0,  0,  0,  0,  0,   0,   0,  0,  -1 },
    { NULL,            "CrossCode",   1 << 13,    0,  0,  1,  0,  0,   0,   0,  0,  -1 },
    { "MonkeyCity-Win.exe",   NULL,   1 << 13,    0,  0,  1,  0,  0,   0,   0,  0,  -1 },
    { NULL,   "Bloons Monkey City",   1 << 13,    0,  0,  1,  0,  0,   0,   0,  0,  -1 },

    { "Pinentry-gtk-2",      NULL,    0,          1,  1,  0,  0,  0,   1,   0,  0,  -1 },
    { "org.kde.krunner",     NULL,    0,          1,  1,  0,  0,  0,   1,   0,  0,  -1 },
    { "gcr-prompter",        NULL,    0,          1,  1,  0,  0,  0,   1,   0,  0,  -1 },
};

/* layout(s) */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "<>=",      list_show_wallpaper },
    { NULL,       NULL },
};

/* monitors */
static const MonitorRule monrules[] = {
	/* name       mfact nmaster scale layout       rotate/reflect             x     y    resx    resy rate adaptive custom*/
    { "DP-1",     0.5, 1,      1,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL, -1920, 380,  1920,  1080, 60,  0, 0},
    { "HDMI-A-1", 0.5, 1,      1,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL, 0,     0,    2560,  1440, 144, 0, 0},
	{ NULL,       0.5, 1,      1,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL, -1,     -1,  0,     0,    0,   0, 0},
};

/* keyboard layouts */
static const int default_keyboard_layout = 0;

static struct xkb_rule_names dvorak_layout = {
    //.layout = "us",
    .variant = "dvorak",
    .layout = "pl",
    // this is accually a workaround for using capslock as a modkey, caps:shiftlock is modified
    .options = "caps:shiftlock",
};

static struct xkb_rule_names qwerty_layout = {
    //.layout = "us",
    .layout = "pl,us",
    // this is accually a workaround for using capslock as a modkey, caps:shiftlock is modified
    .options = "caps:shiftlock",
};

typedef struct {
    char *name;
    struct xkb_rule_names *xkb_rule;
} KeyboardLayout;

/* The first index has to be a qwerty layout */
static const KeyboardLayout keyboard_layouts[2] = {
    { .name = "qwerty", .xkb_rule = &qwerty_layout },
    { .name = "dvorak", .xkb_rule = &dvorak_layout },
};

static const int repeat_rate = 25;
static const int repeat_delay = 600;

/* Trackpad */
static const int tap_to_click = 1;
static const int tap_and_drag = 1;
static const int drag_lock = 1;
static const int natural_scrolling = 0;
static const int disable_while_typing = 1;
static const int left_handed = 0;
static const int middle_button_emulation = 0;
/* You can choose between:
LIBINPUT_CONFIG_SCROLL_NO_SCROLL
LIBINPUT_CONFIG_SCROLL_2FG
LIBINPUT_CONFIG_SCROLL_EDGE
LIBINPUT_CONFIG_SCROLL_ON_BUTTON_DOWN
*/
static const enum libinput_config_scroll_method scroll_method = LIBINPUT_CONFIG_SCROLL_2FG;

/* You can choose between:
LIBINPUT_CONFIG_CLICK_METHOD_NONE       
LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS       
LIBINPUT_CONFIG_CLICK_METHOD_CLICKFINGER 
*/
static const enum libinput_config_click_method click_method = LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS;

/* You can choose between:
LIBINPUT_CONFIG_SEND_EVENTS_ENABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED_ON_EXTERNAL_MOUSE
*/
static const uint32_t send_events_mode = LIBINPUT_CONFIG_SEND_EVENTS_ENABLED;

/* You can choose between:
LIBINPUT_CONFIG_ACCEL_PROFILE_FLAT
LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE
*/
static const enum libinput_config_accel_profile accel_profile = LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE;
static const double accel_speed = 0.0;
static const int cursor_timeout = 2;

/* You can choose between:
LIBINPUT_CONFIG_TAP_MAP_LRM -- 1/2/3 finger tap maps to left/right/middle
LIBINPUT_CONFIG_TAP_MAP_LMR -- 1/2/3 finger tap maps to left/middle/right
*/
static const enum libinput_config_tap_button_map button_map = LIBINPUT_CONFIG_TAP_MAP_LRM;

#define TAGKEYS(KEY,TAG) \
	{ ALT,                KEY,           view,            {.ui = 1 << TAG} }, \
	{ ALT|CTRL,           KEY,           toggleview,      {.ui = 1 << TAG} }, \
	{ ALT|SHIFT,          KEY,           tag,             {.ui = 1 << TAG} }, \
	{ ALT|CTRL|SHIFT,     KEY,           toggletag,       {.ui = 1 << TAG} }



#define PLAYERCTL_SCRIPT "luajit $HOME/.config/dotfiles/scripts/playerctl.lua "
#define PLAYERCTL_KEY(KEY,ACTION) \
	{ CAPS,                    KEY,           simplespawn,     {.v = PLAYERCTL_SCRIPT "\"" ACTION "\" 1"} }, \
	{ CAPS|SHIFT,              KEY,           simplespawn,     {.v = PLAYERCTL_SCRIPT "\"" ACTION "\" 2"} }


/* Autostart */
static const char *autostart_simplespawn[] = {
    "$HOME/.config/dwl/someblocks/someblocks",
    "pulseaudio --start",
    "wl-paste --watch cliphist store",
    "amixer set Capture nocap", 
    "fnott",

    "[ \"$(pgrep keepassxc)\" == \"\" ] && keepassxc",
    "[ \"$(pgrep tutanota-deskop)\" == \"\" ] && tutanota-desktop --enable-features=UseOzonePlatform --ozone-platform=wayland",
    "blueman-applet",
    "alacritty --class cmus --title cmus -e cmus",
    "wlr-randr --output DP-1 --off",
};

#define WALLPAPER_SCRIPT "luajit $HOME/.config/wallpapers/wallpaper.lua "

static const char *autostart_execute[] = { 
    "swww init",
    WALLPAPER_SCRIPT "inc 0 0",
    "gammastep -r" 
};

static const char *const at_exit[] = {
    "swww kill",
    "gammastep -x",
    "pkill wl-paste",
    "pkill gammastep",
    "pkill swww",
    "pkill someblocks",
    "pkill gnome-keyring",
};

#include "keys.h"
static const Key keys[] = {
	/* Note that Shift changes certain key codes: c -> C, 2 -> at, etc. */
	/* modifier                  key                 function        argument */
    { SUPER|CTRL,               Key_Return,     zoom,           {0} },
	
    // monitor
	{ ALT,                      Key_comma,      focusmon,       {.i = WLR_DIRECTION_LEFT} },
	{ ALT,                      Key_period,     focusmon,       {.i = WLR_DIRECTION_RIGHT} },
	{ ALT|SHIFT,                Key_comma,      tagmon,         {.i = WLR_DIRECTION_LEFT} },
	{ ALT|SHIFT,                Key_period,     tagmon,         {.i = WLR_DIRECTION_RIGHT} },

	{ SUPER,                    Key_comma,      focusmon,       {.i = WLR_DIRECTION_LEFT} },
	{ SUPER,                    Key_period,     focusmon,       {.i = WLR_DIRECTION_RIGHT} },
	{ SUPER|SHIFT,              Key_comma,      tagmon,         {.i = WLR_DIRECTION_LEFT} },
	{ SUPER|SHIFT,              Key_period,     tagmon,         {.i = WLR_DIRECTION_RIGHT} },


    // tags
	TAGKEYS(                    Key_Tab,        0),
	TAGKEYS(                    Key_q,          1),
	TAGKEYS(                    Key_w,          2),
    
	TAGKEYS(                    Key_n,          3),
	TAGKEYS(                    Key_d,          4),
	TAGKEYS(                    Key_s,          5),
	TAGKEYS(                    Key_a,          6),
	TAGKEYS(                    Key_z,          7),
	TAGKEYS(                    Key_t,          8),
	TAGKEYS(                    Key_f,          9),
	TAGKEYS(                    Key_c,          10),
	TAGKEYS(                    Key_g,          11),
	TAGKEYS(                    Key_v,          12),
	TAGKEYS(                    Key_h,          13),


    // view all tags at once
	{ SUPER,                    Key_0,          view,           {.ui = ~0} },


    // media
    PLAYERCTL_KEY(Key_Tab, "play-pause"),
    PLAYERCTL_KEY(Key_q,   "next"),
    PLAYERCTL_KEY(Key_a,   "previous"),
    PLAYERCTL_KEY(Key_w,   "volume 0.02%+"),
    PLAYERCTL_KEY(Key_s,   "volume 0.02%-"), 
	
    { CAPS|CTRL,                Key_Tab,        simplespawn,     {.v = PLAYERCTL_SCRIPT "swap -1"} },


    { CAPS,                     Key_e,          simplespawn,    {.v = "amixer set Master 5%+" } },
    { CAPS,                     Key_d,          simplespawn,    {.v = "amixer set Master 5%-" } },

    { CAPS|SHIFT,               Key_e,          simplespawn,    {.v = "amixer set Capture 5%+" } },
    { CAPS|SHIFT,               Key_d,          simplespawn,    {.v = "amixer set Capture 5%-" } },
    { CAPS|CTRL,                Key_e,          simplespawn,    {.v = "amixer set Capture cap" } },
    { CAPS|CTRL,                Key_d,          simplespawn,    {.v = "amixer set Capture nocap" } },

    // select audio output
    { CAPS|CTRL,                Key_q,          simplespawn,    {.v = "pacmd set-default-sink \"$(pactl list sinks short | awk '{print $1 \" <> \" substr($2,13) }' | tr '-' ' ' | tr '_' ' ' | fuzzel -d --log-level=none --width 50 | awk '{print $1}')\"" } },


    // gaps
    { CAPS,                     Key_y,          incgaps,        {.i = +1} },
    { CAPS,                     Key_h,          incgaps,        {.i = -1} },
    
    { CAPS|SHIFT,               Key_y,          setgaps_single, {.i = default_gapps } },
    { CAPS|SHIFT,               Key_h,          setgaps_single, {.i = 0 } },

    { CAPS|CTRL,                Key_y,          setborder,      {.ui = default_gapps } },
    { CAPS|CTRL,                Key_h,          setborder,      {.ui = 0 } },


    // walpaper
    { CAPS,                     Key_t,          simplespawn,    {.v = WALLPAPER_SCRIPT "wayland-gui" } },
    
    // launcher
	{ ALT,                      Key_r,          simplespawn,    {.v = "fuzzel --width 30 --log-level=none" } },
	{ ALT,                      Key_Return,     simplespawn,    {.v = "alacritty" } },
    // clipboard history view
    { CAPS,                     Key_1,          simplespawn,    {.v = "cliphist list | fuzzel --width 100 -d --log-level=none | cliphist decode | wl-copy" } },
    // clear the clipboard history
    { CAPS|CTRL,                Key_1,          simplespawn,    {.v = "rm $HOME/.cache/cliphist/db" } },

    { SUPER|ALT,                Key_s,          simplespawn,    {.v = "pkill steam" } },
    { SUPER|ALT,                Key_v,          simplespawn,    {.v = "pkill -9 gamescope; pkill Riot; pkill League; pkill lutris; pkill wine; pkill wine-preloader; pkill wine-device; pkill plugplay; pkill services.exe; pkill rpcss.exe; pkill svchost.exe; pkill gamescope" } },
    { SUPER|ALT,                Key_y,          simplespawn,    {.v = "pkill lbry" } },
    { SUPER|ALT,                Key_z,          simplespawn,    {.v = "pkill tutanota" } },
    { SUPER|ALT,                Key_u,          simplespawn,    {.v = "pkill gammastep" } },
    { SUPER|ALT,                Key_k,          simplespawn,    {.v = "pkill keepassxc" } },
    { SUPER|ALT,                Key_d,          simplespawn,    {.v = "pkill discord" } },

	{ CAPS,                     Key_b,          getclientinfo,  {0} },
	{ CAPS,                     Key_3,          simplespawn,    {.v = "$HOME/.config/dwl/dwl-dotfiles/scripts/togglemonitors.sh" } },
	{ CAPS,                     Key_3,          simplespawn,    {.v = "$HOME/.config/dotfiles/scripts/wayland/togglemonitors.sh" } },
	{ CAPS,                     Key_4,          simplespawn,    {.v = "$HOME/.config/dotfiles/scripts/wayland/change-res.sh" } },


    // layout 
    // master count
	{ SUPER|SHIFT,              Key_l,          incnmaster,     {.i = -1} },
	{ SUPER|SHIFT,              Key_h,          incnmaster,     {.i = +1} },
    // master width
	{ SUPER,                    Key_h,          setmfact,       {.f = -0.05} },
	{ SUPER,                    Key_l,          setmfact,       {.f = +0.05} },
    // layout switching
    { CAPS,                    Key_r,           cyclelayout,    {.i = +1} },
	{ CAPS,                    Key_f,           cyclelayout,    {.i = -1} },
    

    // change focused client 
	{ SUPER,                    Key_j,          focusstack,     {.i = +1} },
	{ SUPER,                    Key_k,          focusstack,     {.i = -1} },
    
    // move clients in stack
    { SUPER|SHIFT,              Key_j,          movestack,      {.i = +1} },
    { SUPER|SHIFT,              Key_k,          movestack,      {.i = -1} },

    // client keys
	{ SUPER,                    Key_f,          togglefullscreen, {0} },
	{ SUPER|SHIFT,              Key_c,          killclient,     {0} },
    { SUPER|SHIFT,              Key_space,      togglefloating, {0} },
    //{SUPER,                     Key_t,          always on top
	{ SUPER,                    Key_s,          togglesticky,   {0} },
    { SUPER,                    Key_m,          togglemaximilized, {0} },
    
    // screenshot
    { CAPS,                     Key_z,          simplespawn,    {.v = "grim - | wl-copy" } },
    { CAPS,                     Key_c,          simplespawn,    {.v = "grim -g \"$(slurp)\" - | wl-copy" } },


    // power
	{ SUPER|CTRL|SHIFT,         Key_p,          simplespawn,    {.v = "loginctl poweroff" } },
	{ SUPER|CTRL|SHIFT,         Key_r,          simplespawn,    {.v = "loginctl reboot" } },
	{ SUPER|CTRL|SHIFT,         Key_s,          simplespawn,    {.v = "playerctl pause -a; loginctl suspend && swaylock" } },
	{ SUPER|CTRL|SHIFT,         Key_h,          simplespawn,    {.v = "loginctl hibernate" } },


    // turn off screens
	{ CAPS,                     Key_v,          simplespawn,    {.v = "$HOME/.config/dwl/dpms-off/target/release/dpms-off" } },

    // dwl
	{ SUPER|CTRL|SHIFT,         Key_q,          quit,           {0} },
	{ SUPER|CTRL|SHIFT,         Key_n,          simplespawn,    {.v = "alacritty -e $HOME/.config/dwl/dwl-dotfiles/scripts/makeandexit.sh" } },
	{ SUPER|CTRL|SHIFT,         Key_m,          restartdwl,     {0} },

    // locking
	{ SUPER|CTRL|SHIFT,         Key_l,          simplespawn,    {.v = "playerctl pause -a; swaylock" } },
	{ SUPER|CTRL|SHIFT,         Key_k,          simplespawn,    {.v = "playerctl pause -a; $HOME/.config/dwl/dpms-off/target/release/dpms-off && swaylock" } },

    { CAPS,                     Key_2,          togglekeyboardlayout, {0} },


#define CHVT(n) { CTRL|ALT,XKB_KEY_XF86Switch_VT_##n, chvt, {.ui = (n)} }
	CHVT(1), CHVT(2), CHVT(3), CHVT(4), CHVT(5), CHVT(6),
	CHVT(7), CHVT(8), CHVT(9), CHVT(10), CHVT(11), CHVT(12),
};

static const Button buttons[] = {
	{ SUPER, BTN_LEFT,   moveresize,     {.ui = CurMove} },
	{ SUPER, BTN_MIDDLE, togglefloating, {0} },
	{ SUPER, BTN_RIGHT,  moveresize,     {.ui = CurResize} },
};
