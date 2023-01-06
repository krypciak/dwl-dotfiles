#define SUPER WLR_MODIFIER_LOGO
#define ALT WLR_MODIFIER_ALT
#define SHIFT WLR_MODIFIER_SHIFT
#define CTRL WLR_MODIFIER_CTRL
#define CAPS WLR_MODIFIER_MOD3

/* appearance */
static const int sloppyfocus        = 0;  /* focus follows mouse */
static const unsigned int borderpx  = 1;  /* border pixel of windows */

static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int monoclegaps        = 0;        /* 1 means outer gaps in monocle layout */
static const int smartborders       = 1;

static const int lockfullscreen     = 1;  /* 1 will force focus on the fullscreen window */
static const float rootcolor[]      = {0.3, 0.3, 0.3, 1.0};
static const float bordercolor[]    = {0.5, 0.5, 0.5, 1.0};
static const float focuscolor[]     = {1.0, 0.0, 0.0, 1.0};
/* To conform the xdg-protocol, set the alpha to zero to restore the old behavior */
static const float fullscreen_bg[]  = {0.1, 0.1, 0.1, 0};

/* tagging */
static const char *tags[] = {
    "T", "q", "w", "n", "d", "s", "a", "z",
    "t", "f", "c", "g", "v", "h"
};


static const Rule rules[] = {
	/* app_id                 title   tags mask   iscentered isfloating isfullscreen ismaximilized isterm noswallow  monitor */
    { "Alacritty",            NULL,   0,          0,  0,  0,  0,  1,  0,  -1 },
    
    { "cmus",                 NULL,   1 << 3,     0,  0,  0,  0,  0,  0,  -1 },
    { "discord",              NULL,   1 << 4,     1,  0,  0,  0,  0,  0,  -1 },
    { "librewolf",            NULL,   1 << 5,     0,  0,  0,  0,  0,  0,  -1 },
    { "Chromium",             NULL,   1 << 6,     0,  0,  0,  0,  0,  0,  -1 },
    { "tutanota-desktop",     NULL,   1 << 7,     0,  0,  0,  0,  0,  0,  -1 },
    { "aerc",                 NULL,   1 << 7,     0,  0,  0,  0,  0,  0,  -1 },
    { "dialect",              NULL,   1 << 8,     0,  0,  0,  0,  0,  0,  -1 },
    { NULL,            "Invidious",   1 << 9,     0,  0,  0,  0,  0,  0,  -1 },
    { "LBRY",                 NULL,   1 << 9,     0,  0,  0,  0,  0,  0,  -1 },
    { "prismlauncher",        NULL,   1 << 10,    0,  0,  0,  0,  0,  0,  -1 },
    { NULL,            "Minecraft",   1 << 10,    0,  0,  0,  1,  0,  0,  -1 },
    { "gamescope",            NULL,   1 << 12,    0,  0,  1,  0,  0,  0,  -1 },
    //{ "virt-manager",         NULL,   1 << 11,    0,  0,  0,  0,  0,  0,  -1 },
    //{ "explorer.exe",         NULL,   1 << 12,    1,  1,  0,  0,  0,  0,  -1 },
    //{ "leagueclient.exe",     NULL,   1 << 12,    1,  1,  0,  0,  0,  0,  -1 },
    //{ "league of legends.exe",NULL,   1 << 12,    0,  0,  1,  0,  0,  0,  -1 },
    //{ "leagueclientux.exe"   ,NULL,   1 << 12,    1,  1,  0,  0,  0,  0,  -1 },
    //{ "riotclientux.exe"     ,NULL,   1 << 12,    1,  1,  0,  0,  0,  0,  -1 },
    { "live.na.exe",          NULL,   1 << 12,    1,  1,  0,  0,  0,  0,  -1 },
    { "Steam",                NULL,   1 << 13,    0,  0,  0,  0,  0,  0,  -1 },
    { "Lutris",               NULL,   1 << 13,    0,  0,  0,  0,  0,  0,  -1 },
    { "steap_app_960090",     NULL,   1 << 13,    0,  0,  0,  0,  0,  0,  -1 },
    { NULL,            "CrossCode",   1 << 13,    0,  0,  1,  0,  0,  0,  -1 },
    { "MonkeyCity-Win.exe",   NULL,   1 << 13,    0,  0,  1,  0,  0,  0,  -1 },
    { NULL,   "Bloons Monkey City",   1 << 13,    0,  0,  1,  0,  0,  0,  -1 },


};

/* layout(s) */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	//{ "[M]",      monocle },
    { NULL,       NULL },
};

/* monitors */
static const MonitorRule monrules[] = {
	/* name       mfact nmaster scale layout       rotate/reflect */
	/* example of a HiDPI laptop monitor:
	{ "eDP-1",    0.5,  1,      2,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL },
	*/
	/* defaults */
	{ NULL,       0.5, 1,      1,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL },
};

/* keyboard layouts */
static const int default_keyboard_layout = 1;

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

/* pointer constraints */
static const int allow_constrain      = 1;

/* Autostart */
static const char *autostart_simplespawn[] = {
    "wlr-randr --output HDMI-A-1 --mode 2560x1440@143.912003",
    "$HOME/.config/dwl/someblocks/someblocks",
    "pulseaudio --start",
    "wl-paste --watch cliphist store",
    "amixer set Capture nocap",
};

#define WALLPAPER_SCRIPT "luajit $HOME/.config/dotfiles/scripts/wallpaper.lua "

static const char *autostart_execute[] = { 
    "swww init",
    WALLPAPER_SCRIPT "0 0",
    "gammastep -r" 
};

static const char *autostart_simplespawn_2s[] = { 
    "[ \"$(pgrep keepassxc)\" == \"\" ] && keepassxc",
    "[ \"$(pgrep tutanota-deskop)\" == \"\" ] && tutanota-desktop --enable-features=UseOzonePlatform --ozone-platform=wayland",
    "blueman-applet",
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

#define TAGKEYS(KEY,SKEY,TAG) \
	{ ALT,                KEY,            view,            {.ui = 1 << TAG} }, \
	{ ALT|CTRL,           KEY,            toggleview,      {.ui = 1 << TAG} }, \
	{ ALT|SHIFT,          SKEY,           tag,             {.ui = 1 << TAG} }, \
	{ ALT|CTRL|SHIFT,     SKEY,           toggletag,       {.ui = 1 << TAG} }



#define PLAYERCTL_SCRIPT "luajit $HOME/.config/dotfiles/scripts/playerctl.lua "
#define PLAYERCTL_KEY(KEY,SHIFT_KEY,ACTION) \
	{ CAPS,                    KEY,                 simplespawn,     {.v = PLAYERCTL_SCRIPT "\"" ACTION "\" 1"} }, \
	{ CAPS|SHIFT,              SHIFT_KEY,           simplespawn,     {.v = PLAYERCTL_SCRIPT "\"" ACTION "\" 2"} }

static const Key keys[] = {
	/* Note that Shift changes certain key codes: c -> C, 2 -> at, etc. */
	/* modifier                  key                 function        argument */
    { SUPER|CTRL,               XKB_KEY_Return,     zoom,           {0} },
	
    //{ SUPER,                    XKB_KEY_space,      setlayout,      {0} },
	
	{ SUPER|SHIFT,              XKB_KEY_parenright, tag,            {.ui = ~0} },
    // monitor
	{ ALT,                      XKB_KEY_comma,      focusmon,       {.i = WLR_DIRECTION_LEFT} },
	{ ALT,                      XKB_KEY_period,     focusmon,       {.i = WLR_DIRECTION_RIGHT} },
	{ ALT|SHIFT,                XKB_KEY_less,       tagmon,         {.i = WLR_DIRECTION_LEFT} },
	{ ALT|SHIFT,                XKB_KEY_greater,    tagmon,         {.i = WLR_DIRECTION_RIGHT} },

	{ SUPER,                    XKB_KEY_comma,      focusmon,       {.i = WLR_DIRECTION_LEFT} },
	{ SUPER,                    XKB_KEY_period,     focusmon,       {.i = WLR_DIRECTION_RIGHT} },
	{ SUPER|SHIFT,              XKB_KEY_less,       tagmon,         {.i = WLR_DIRECTION_LEFT} },
	{ SUPER|SHIFT,              XKB_KEY_greater,    tagmon,         {.i = WLR_DIRECTION_RIGHT} },


    // tags
	TAGKEYS(                    XKB_KEY_Tab,        XKB_KEY_ISO_Left_Tab,    0),
	TAGKEYS(                    XKB_KEY_q,          XKB_KEY_Q,      1),
	TAGKEYS(                    XKB_KEY_w,          XKB_KEY_W,      2),
    
	TAGKEYS(                    XKB_KEY_n,          XKB_KEY_N,      3),
	TAGKEYS(                    XKB_KEY_d,          XKB_KEY_D,      4),
	TAGKEYS(                    XKB_KEY_s,          XKB_KEY_S,      5),
	TAGKEYS(                    XKB_KEY_a,          XKB_KEY_A,      6),
	TAGKEYS(                    XKB_KEY_z,          XKB_KEY_Z,      7),
	TAGKEYS(                    XKB_KEY_t,          XKB_KEY_T,      8),
	TAGKEYS(                    XKB_KEY_f,          XKB_KEY_F,      9),
	TAGKEYS(                    XKB_KEY_c,          XKB_KEY_C,      10),
	TAGKEYS(                    XKB_KEY_g,          XKB_KEY_G,      11),
	TAGKEYS(                    XKB_KEY_v,          XKB_KEY_V,      12),
	TAGKEYS(                    XKB_KEY_h,          XKB_KEY_H,      13),


    // view all tags at once
	{ SUPER,                    XKB_KEY_0,          view,           {.ui = ~0} },


    // media
    PLAYERCTL_KEY(XKB_KEY_Tab, XKB_KEY_ISO_Left_Tab, "play-pause"),
    PLAYERCTL_KEY(XKB_KEY_q,   XKB_KEY_Q,            "next"),
    PLAYERCTL_KEY(XKB_KEY_a,   XKB_KEY_A,            "previous"),
    PLAYERCTL_KEY(XKB_KEY_w,   XKB_KEY_W,            "volume 0.02%+"),
    PLAYERCTL_KEY(XKB_KEY_s,   XKB_KEY_S,            "volume 0.02%-"), 
	
    { CAPS|CTRL,                XKB_KEY_Tab,        simplespawn,     {.v = PLAYERCTL_SCRIPT "swap -1"} },


    { CAPS,                     XKB_KEY_e,          simplespawn,    {.v = "amixer set Master 5%+" } },
    { CAPS,                     XKB_KEY_d,          simplespawn,    {.v = "amixer set Master 5%-" } },

    { CAPS|SHIFT,               XKB_KEY_E,          simplespawn,    {.v = "amixer set Capture 5%+" } },
    { CAPS|SHIFT,               XKB_KEY_D,          simplespawn,    {.v = "amixer set Capture 5%-" } },
    { CAPS|CTRL,                XKB_KEY_e,          simplespawn,    {.v = "amixer set Capture cap" } },
    { CAPS|CTRL,                XKB_KEY_d,          simplespawn,    {.v = "amixer set Capture nocap" } },

    // select audio output
    { CAPS|CTRL,                XKB_KEY_q,          simplespawn,    {.v = "pacmd set-default-sink \"$(pactl list sinks short | awk '{print $1 \" <> \" substr($2,13) }' | tr '-' ' ' | tr '_' ' ' | fuzzel -d --log-level=none | awk '{print $1}')\"" } },


    // gaps
    { CAPS,                     XKB_KEY_y,          incgaps,        {.i = +1} },
    { CAPS,                     XKB_KEY_h,          incgaps,        {.i = -1} },

    // walpaper
    { CAPS,                     XKB_KEY_t,          simplespawn,    {.v = WALLPAPER_SCRIPT "1 0" } },
    { CAPS,                     XKB_KEY_g,          simplespawn,    {.v = WALLPAPER_SCRIPT "0 1" } },
    
    // launcher
	{ ALT,                      XKB_KEY_r,          simplespawn,    {.v = "fuzzel --log-level=warning" } },
	{ ALT,                      XKB_KEY_Return,     simplespawn,    {.v = "alacritty" } },
    // clipboard history view
    { CAPS,                     XKB_KEY_1,          simplespawn,    {.v = "cliphist list | fuzzel -d --log-level=none | cliphist decode | wl-copy" } },
    // clear the clipboard history
    { CAPS|CTRL,                XKB_KEY_1,          simplespawn,    {.v = "rm $HOME/.cache/cliphist/db" } },

    { SUPER|ALT,                XKB_KEY_s,          simplespawn,    {.v = "pkill steam" } },
    { SUPER|ALT,                XKB_KEY_v,          simplespawn,    {.v = "pkill -9 League && pkill -9 Riot" } },
    { SUPER|ALT,                XKB_KEY_y,          simplespawn,    {.v = "pkill lbry" } },
    { SUPER|ALT,                XKB_KEY_z,          simplespawn,    {.v = "pkill tutanota" } },
    { SUPER|ALT,                XKB_KEY_u,          simplespawn,    {.v = "pkill gammastep" } },
    { SUPER|ALT,                XKB_KEY_k,          simplespawn,    {.v = "pkill keepassxc" } },
    { SUPER|ALT,                XKB_KEY_d,          simplespawn,    {.v = "pkill discord" } },

	{ CAPS,                     XKB_KEY_b,          getclientinfo,  {0} },

    // layout 
    // master count
	{ SUPER|SHIFT,              XKB_KEY_L,          incnmaster,     {.i = -1} },
	{ SUPER|SHIFT,              XKB_KEY_H,          incnmaster,     {.i = +1} },
    // master width
	{ SUPER,                    XKB_KEY_h,          setmfact,       {.f = -0.05} },
	{ SUPER,                    XKB_KEY_l,          setmfact,       {.f = +0.05} },
    // layout switching
    { CAPS,                    XKB_KEY_r,           cyclelayout,    {.i = +1} },
	{ CAPS,                    XKB_KEY_f,           cyclelayout,    {.i = -1} },
    

    // change focused client 
	{ SUPER,                    XKB_KEY_j,          focusstack,     {.i = +1} },
	{ SUPER,                    XKB_KEY_k,          focusstack,     {.i = -1} },
    
    // move clients in stack
    { SUPER|SHIFT,              XKB_KEY_J,          movestack,      {.i = +1} },
    { SUPER|SHIFT,              XKB_KEY_K,          movestack,      {.i = -1} },

    // client keys
	{ SUPER,                    XKB_KEY_f,          togglefullscreen, {0} },
	{ SUPER|SHIFT,              XKB_KEY_C,          killclient,     {0} },
    { SUPER|SHIFT,              XKB_KEY_space,      togglefloating, {0} },
    //{SUPER,                     XKB_KEY_t,          always on top
	{ SUPER,                    XKB_KEY_s,          togglesticky,   {0} },
    { SUPER,                    XKB_KEY_m,          togglemaximilized, {0} },
    


    // screen
    // next screen
    // prev screen
    //{ CAPS,                     XKB_KEY_v,          
    
    // screenshot
    { CAPS,                     XKB_KEY_z,          simplespawn,    {.v = "grim - | wl-copy" } },
    { CAPS,                     XKB_KEY_c,          simplespawn,    {.v = "grim -g \"$(slurp)\" - | wl-copy" } },


    // power
	{ SUPER|CTRL|SHIFT,         XKB_KEY_P,          simplespawn,    {.v = "loginctl poweroff" } },
	{ SUPER|CTRL|SHIFT,         XKB_KEY_R,          simplespawn,    {.v = "loginctl reboot" } },
	{ SUPER|CTRL|SHIFT,         XKB_KEY_S,          simplespawn,    {.v = "playerctl pause -a; loginctl suspend && swaylock" } },
	{ SUPER|CTRL|SHIFT,         XKB_KEY_H,          simplespawn,    {.v = "loginctl hibernate" } },


    // turn off screens
	{ CAPS,                     XKB_KEY_v,          simplespawn,    {.v = "$HOME/.config/dwl/dpms-off/target/release/dpms-off" } },

    // dwl
	{ SUPER|CTRL|SHIFT,         XKB_KEY_Q,          quit,           {0} },
	{ SUPER|CTRL|SHIFT,         XKB_KEY_N,          simplespawn,    {.v = "alacritty -e $HOME/.config/dwl/dwl-dotfiles/scripts/makeandexit.sh" } },
	{ SUPER|CTRL|SHIFT,         XKB_KEY_M,          restartdwl,     {0} },

    // locking
	{ SUPER|CTRL|SHIFT,         XKB_KEY_L,          simplespawn,    {.v = "playerctl pause -a; swaylock" } },
	{ SUPER|CTRL|SHIFT,         XKB_KEY_K,          simplespawn,    {.v = "playerctl pause -a; $HOME/.config/dwl/dpms-off/target/release/dpms-off && swaylock" } },

    { CAPS,                     XKB_KEY_2,          togglekeyboardlayout, {0} },


#define CHVT(n) { CTRL|ALT,XKB_KEY_XF86Switch_VT_##n, chvt, {.ui = (n)} }
	CHVT(1), CHVT(2), CHVT(3), CHVT(4), CHVT(5), CHVT(6),
	CHVT(7), CHVT(8), CHVT(9), CHVT(10), CHVT(11), CHVT(12),
};

static const Button buttons[] = {
	{ SUPER, BTN_LEFT,   moveresize,     {.ui = CurMove} },
	{ SUPER, BTN_MIDDLE, togglefloating, {0} },
	{ SUPER, BTN_RIGHT,  moveresize,     {.ui = CurResize} },
};
