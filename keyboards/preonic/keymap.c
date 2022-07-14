#include QMK_KEYBOARD_H

// Key Aliases
#define MT_LAPO MT(MOD_LALT, KC_LBRC)
#define MT_RAPC MT(MOD_RALT, KC_RBRC)

enum preonic_layers {
    _L_BASE,
    _L_LOWER,
    _L_RAISE,
    _L_MEDIA
};

enum preonic_keycodes {
    L_BASE = SAFE_RANGE,
    L_LOWER,
    L_RAISE,
    L_MEDIA
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base Layer
    *   ╔══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╗
    *   ║   `  ~   │   1  !   │   2  @   │   3  #   │   4  $   │   5  %   │   6  ^   │   7  &   │   8  *   │   9  (   │   0  )   │   Bksp   ║
    *   ╟──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────╢
    *   ║   Tab    │   Q      │   W      │   E      │   R      │   T      │   Y      │   U      │   I      │   O      │   P      │   Enter  ║
    *   ╟──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────╢
    *   ║   Esc    │   A      │   S      │   D      │   F      │   G      │   H      │   J      │   K      │   L      │   ;  :   │   '  "   ║
    *   ╟──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────╢
    *   ║   Shift  │   Z      │   X      │   C      │   V      │   B      │   N      │   M      │   ,  <   │   .  >   │   /  ?   │   Shift  ║
    *   ╟──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────╢
    *   ║   Ctrl   │   MEDIA  │   Alt    │   Super  │   LOWER  │  Space   │  Space   │   RAISE  │   Super  │   Alt    │   MEDIA  │   Ctrl   ║
    *   ╚══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╝
    */
    [_L_BASE] = LAYOUT_ortho_5x12(
        KC_GRV,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_BSPC,
        KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_ENT,
        KC_ESC,    KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,
        KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSFT,
        KC_LCTL,   MO(3),     KC_LALT,   KC_LGUI,   MO(1),     KC_SPC,    KC_SPC,    MO(2),     KC_LGUI,   KC_RALT,    MO(3),    KC_RCTL
    ),
    /* Lower Layer
    *   ╔══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╗
    *   ║   F11    │   F1     │   F2     │   F3     │   F4     │   F5     │   F6     │   F7     │   F8     │   F9     │   F10    │   Bksp   ║
    *   ╟──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────╢
    *   ║   F12    │          │          │          │          │  PrntScr │  PrntScr │    +     │   7      │   8      │   9      │    *     ║
    *   ╟──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────╢
    *   ║          │          │          │          │          │   Home   │   End    │    -     │   4      │   5      │   6      │    /     ║
    *   ╟──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────╢
    *   ║          │          │          │          │  Insert  │   PgUp   │  PgDwn   │  Delete  │   1      │   2      │   3      │          ║
    *   ╟──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────╢
    *   ║          │    ▼     │          │          │    ▼     │  Space   │  Space   │    ▼     │          │   0      │   .  >   │   Enter  ║
    *   ╚══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╝
    */
    [_L_LOWER] = LAYOUT_ortho_5x12(
        KC_F11,    KC_F1,      KC_F2,    KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_BSPC,
        KC_F12,    XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,   KC_PSCR,   KC_PSCR,   KC_PLUS,   KC_P7,     KC_P8,     KC_P9,     KC_ASTR,
        XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,   KC_HOME,   KC_END,    KC_MINS,   KC_P4,     KC_P5,     KC_P6,     KC_SLSH,
        XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,   KC_INS,    KC_PGUP,   KC_PGDN,   KC_DEL,    KC_P1,     KC_P2,     KC_P3,     XXXXXXX,
        XXXXXXX,   _______,    XXXXXXX,  XXXXXXX,   _______,   KC_SPC,    KC_SPC,    _______,   XXXXXXX,   KC_P0,     KC_DOT,    KC_ENT
    ),
    /* Raise Layer
    *   ╔══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╗
    *   ║          │          │          │          │          │          │          │          │          │          │          │  Delete  ║
    *   ╟──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────╢
    *   ║          │          │          │          │          │          │          │    +     │   Up     │    -     │          │          ║
    *   ╟──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────╢
    *   ║          │          │    [     │    {     │    (     │    /     │    :     │   Left   │   Down   │   Right  │          │          ║
    *   ╟──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────╢
    *   ║    ▼     │          │    ]     │    }     │    )     │    \     │    |     │    _     │          │    =     │          │    ▼     ║
    *   ╟──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────╢
    *   ║    ▼     │    ▼     │    ▼     │    ▼     │    ▼     │  Space   │  Space   │    ▼     │    ▼     │    ▼     │    ▼     │    ▼     ║
    *   ╚══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╝
    */
    [_L_RAISE] = LAYOUT_ortho_5x12(
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_DEL,
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_PLUS,   KC_UP,     KC_MINS,   XXXXXXX,   XXXXXXX,
        XXXXXXX,  XXXXXXX,    KC_LBRC,   KC_LCBR,   KC_LPRN,   KC_SLSH,   KC_COLN,   KC_LEFT,   KC_DOWN,   KC_RGHT,   XXXXXXX,   XXXXXXX,
        _______,  XXXXXXX,    KC_RBRC,   KC_RCBR,   KC_RPRN,   KC_BSLS,   KC_PIPE,   KC_UNDS,   XXXXXXX,   KC_EQL,    XXXXXXX,   _______,
        _______,  _______,    _______,   _______,   _______,   KC_SPC,    KC_SPC,    _______,   _______,   _______,   _______,   _______
    ),
    /* Media Layer
    *   ╔══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╤══════════╗
    *   ║          │          │          │          │          │   Prev   │   Next   │          │ RGB Mode-│ RGB Mode-│   Plain  │  Breathe ║
    *   ╟──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────╢
    *   ║          │          │          │          │          │   Mute   │   Play   │          │  Effect- │  Effect+ │  Rainbow │   Swirl  ║
    *   ╟──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────╢
    *   ║          │          │          │          │          │   Vol-   │   Vol+   │          │   Hue-   │   Hue+   │   Snake  │Knight Rid║
    *   ╟──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────╢
    *   ║          │          │          │          │          │ Bright-  │ Bright+  │          │   Sat-   │   Sat+   │ Christmas│ Gradient ║
    *   ╟──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────╢
    *   ║          │    ▼     │          │          │    ▼     │RGB Toggle│RGB Toggle│    ▼     │  Value-  │  Value+  │   Test   │RGB Toggle║
    *   ╚══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╧══════════╝
    */
    [_L_MEDIA] = LAYOUT_ortho_5x12(
        XXXXXXX,  XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,   KC_MPRV,   KC_MNXT,   XXXXXXX,   RGB_RMOD,  RGB_MOD,   RGB_M_P,   RGB_M_B,
        XXXXXXX,  XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,   KC_MUTE,   KC_MPLY,   XXXXXXX,   RGB_SPD,   RGB_SPI,   RGB_M_R,   RGB_M_SW,
        XXXXXXX,  XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,   KC_VOLD,   KC_VOLU,   XXXXXXX,   RGB_HUD,   RGB_HUI,   RGB_M_SN,  RGB_M_K,
        XXXXXXX,  XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,   KC_BRID,   KC_BRIU,   XXXXXXX,   RGB_SAD,   RGB_SAI,   RGB_M_X,   RGB_M_G,
        XXXXXXX,  _______,   XXXXXXX,    XXXXXXX,   _______,   RGB_TOG,   RGB_TOG,   _______,   RGB_VAD,   RGB_VAI,   RGB_M_T,   RGB_TOG
    ),
};

