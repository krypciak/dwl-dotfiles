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

static const int lockfullscreen     = 1;  /* 1 will force focus on the fullscreen window */
static const float rootcolor[]      = {0.3, 0.3, 0.3, 1.0};
static const float bordercolor[]    = {0.5, 0.5, 0.5, 1.0};
static const float focuscolor[]     = {1.0, 0.0, 0.0, 1.0};
/* To conform the xdg-protocol, set the alpha to zero to restore the old behavior */
static const float fullscreen_bg[]  = {0.1, 0.1, 0.1, 1.0};

/* tagging */
static const char *tags[] = { "1", "2", "3" };


static const Rule rules[] = {
	/* app_id     title       tags mask     isfloating  isterm  noswallow  monitor */
	/* examples:
	{ "Gimp",       NULL,       0,            1,          0,      1,         -1 },
	*/
    { "alacritty",  NULL,       0,            0,          1,      0,         -1 },
    { "imv",        NULL,       0,            0,          0,      0,         -1 },
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

/* keyboard */
static const struct xkb_rule_names xkb_rules = {
	/* can specify fields: rules, model, layout, variant, options */
    .layout = "pl,us",
    // this is accually a workaround for using capslock as a modkey, caps:shiftlock is modified
	.options = "caps:shiftlock",
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

#define WALLPAPER_SCRIPT "luajit @HOME/.config/dotfiles/scripts/wallpaper.lua "

/* Autostart */
static char *autostart[] = {
        "gammastep -r",
        WALLPAPER_SCRIPT "0 0",
        "wl-paste --watch cliphist store",
        "pulseaudio --start",
};

static const char *const pkill_at_exit[] = {
    "gammastep", 
};

/* If you want to use the windows key change this to WLR_MODIFIER_LOGO */
#define TAGKEYS(KEY,SKEY,TAG) \
	{ ALT,                KEY,            view,            {.ui = 1 << TAG} }, \
	{ ALT|CTRL,           KEY,            toggleview,      {.ui = 1 << TAG} }, \
	{ ALT|SHIFT,          SKEY,           tag,             {.ui = 1 << TAG} }, \
	{ ALT|CTRL|SHIFT,     SKEY,           toggletag,       {.ui = 1 << TAG} }


static const Key keys[] = {
	/* Note that Shift changes certain key codes: c -> C, 2 -> at, etc. */
	/* modifier                  key                 function        argument */
    { SUPER|CTRL,               XKB_KEY_Return,     zoom,           {0} },
	
    //{ SUPER,                    XKB_KEY_space,      setlayout,      {0} },
	
	{ SUPER|SHIFT,              XKB_KEY_parenright, tag,            {.ui = ~0} },
    // monitor
	{ SUPER,                    XKB_KEY_comma,      focusmon,       {.i = WLR_DIRECTION_LEFT} },
	{ SUPER,                    XKB_KEY_period,     focusmon,       {.i = WLR_DIRECTION_RIGHT} },
	{ SUPER|SHIFT,              XKB_KEY_less,       tagmon,         {.i = WLR_DIRECTION_LEFT} },
	{ SUPER|SHIFT,              XKB_KEY_greater,    tagmon,         {.i = WLR_DIRECTION_RIGHT} },

    // tags
	TAGKEYS(                    XKB_KEY_Tab,        XKB_KEY_ISO_Left_Tab,    0),
	TAGKEYS(                    XKB_KEY_q,          XKB_KEY_Q,      1),
	TAGKEYS(                    XKB_KEY_w,          XKB_KEY_W,      2),
    // view all tags at once
	{ SUPER,                    XKB_KEY_0,          view,           {.ui = ~0} },


    // media
    { CAPS,                     XKB_KEY_e,          simplespawn,    {.v = "amixer set Master 5%+" } },
    { CAPS,                     XKB_KEY_d,          simplespawn,    {.v = "amixer set Master 5%-" } },

    { CAPS|SHIFT,               XKB_KEY_E,          simplespawn,    {.v = "amixer set Capture 5%+" } },
    { CAPS|SHIFT,               XKB_KEY_D,          simplespawn,    {.v = "amixer set Capture 5%-" } },
    { CAPS|CTRL,                XKB_KEY_e,          simplespawn,    {.v = "amixer set Capture cap" } },
    { CAPS|CTRL,                XKB_KEY_d,          simplespawn,    {.v = "amixer set Capture nocap" } },


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
    { SUPER,                    XKB_KEY_c,          simplespawn,    {.v = "cliphist list | fuzzel -d --log-level=none | cliphist decode | wl-copy" } },
    // clear the clipboard history
    { SUPER|ALT,                XKB_KEY_c,          simplespawn,    {.v = "rm @HOME/.cache/cliphist/db" } },

    { SUPER|ALT,                XKB_KEY_s,          simplespawn,    {.v = "pkill steam" } },
    { SUPER|ALT,                XKB_KEY_v,          simplespawn,    {.v = "pkill League" } },
    { SUPER|ALT,                XKB_KEY_y,          simplespawn,    {.v = "pkill lbry" } },
    { SUPER|ALT,                XKB_KEY_z,          simplespawn,    {.v = "pkill tutanota" } },
    { SUPER|ALT,                XKB_KEY_u,          simplespawn,    {.v = "pkill gammastep" } },
    { SUPER|ALT,                XKB_KEY_k,          simplespawn,    {.v = "pkill keepassxc" } },
    { SUPER|ALT,                XKB_KEY_d,          simplespawn,    {.v = "pkill discord" } },

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
    //{SUPER,                     XKB_KEY_m,          maximalize
    


    // screen
    // next screen
    // prev screen
    //{ CAPS,                     XKB_KEY_v,          

    // power
	{ SUPER|CTRL|SHIFT,         XKB_KEY_P,          simplespawn,    {.v = "loginctl poweroff" } },
	{ SUPER|CTRL|SHIFT,         XKB_KEY_R,          simplespawn,    {.v = "loginctl reboot" } },
	{ SUPER|CTRL|SHIFT,         XKB_KEY_S,          simplespawn,    {.v = "playerctl pause -a; loginctl suspend && swaylock" } },
	{ SUPER|CTRL|SHIFT,         XKB_KEY_H,          simplespawn,    {.v = "loginctl hibernate" } },

    // turn off screens
	{ CAPS,                     XKB_KEY_v,          simplespawn,    {.v = "@HOME/.config/dwl/dpms-off/target/release/dpms-off" } },

    // dwl
	{ SUPER|CTRL|SHIFT,         XKB_KEY_Q,          quit,           {0} },
	{ SUPER|CTRL|SHIFT,         XKB_KEY_N,          simplespawn,    {.v = "alacritty -e @HOME/.config/dwl/dwl-dotfiles/scripts/makeandexit.sh" } },
	{ SUPER|CTRL|SHIFT,         XKB_KEY_M,          restartdwl,     {0} },

    // locking
	{ SUPER|CTRL|SHIFT,         XKB_KEY_L,          simplespawn,    {.v = "playerctl pause -a; swaylock" } },
	{ SUPER|CTRL|SHIFT,         XKB_KEY_K,          simplespawn,    {.v = "playerctl pause -a; @HOME/.config/dwl/dpms-off/target/release/dpms-off && swaylock" } },


#define CHVT(n) { CTRL|ALT,XKB_KEY_XF86Switch_VT_##n, chvt, {.ui = (n)} }
	CHVT(1), CHVT(2), CHVT(3), CHVT(4), CHVT(5), CHVT(6),
	CHVT(7), CHVT(8), CHVT(9), CHVT(10), CHVT(11), CHVT(12),
};

static const Button buttons[] = {
	{ SUPER, BTN_LEFT,   moveresize,     {.ui = CurMove} },
	{ SUPER, BTN_MIDDLE, togglefloating, {0} },
	{ SUPER, BTN_RIGHT,  moveresize,     {.ui = CurResize} },
};
