#include QMK_KEYBOARD_H
#include "animation.c"

enum layer_number {
  _QWERTY = 0,
  _NAV,
  _SYM,
  _ADJUST,
  _MEDIA
};

#define VS_BACK LCTL(KC_MINS)     // VSCode navigate Back
#define SPC_NAV LT(_NAV, KC_SPC)  //  
#define MOD_NAV MO(_NAV)         
#define MOD_SYM MO(_SYM)    
#define ENT_SYM LT(_SYM, KC_ENT)     
#define MOD_MED MO(_MEDIA)                

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |Delete|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCtrl |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  F12  |    |   _   |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                  | LAlt | LGUI | Space | /  SYM  /       \Enter\   |Enter |Media | RGUI |
 *                  |      |      | (NAV) |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_QWERTY] = LAYOUT( \
  KC_GESC, KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_DEL,  \
  KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC, \
  KC_LSFT, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT, \
  KC_LCTL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_F12, KC_UNDS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                   KC_LALT, KC_LGUI, SPC_NAV, MOD_SYM, KC_ENT, MOD_SYM, MOD_SYM, MOD_MED \
),
/* NAV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |Shift |      |-------.    ,-------|      | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|CODE_B |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI | NAV  | /       /       \Enter \  |Enter |Media | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_NAV] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, KC_UP  ,_______, _______, _______, \
  _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,                   _______, KC_LEFT, KC_DOWN,KC_RGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______, VS_BACK, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
                             _______, _______, _______, _______, _______, _______, _______, _______\
),
/* SYM
 * ,-----------------------------------------.                    ,-----------------------------------------. 
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  | 
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------| 
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |      |  -   |   _  |  +   |  =   | F12  | 
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------| 
 * |      |  -   |  _   |  =   |  +   |      |-------.    ,-------|      |  [   |  ]   |  {   |  }   |      | 
 * |------+------+------+------+------+------|CODE_B |    |       |------+------+------+------+------+------| 
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      | 
 * `-----------------------------------------/       /     \      \-----------------------------------------' 
 *                   | LAlt | LGUI | NAV  | /       /       \Enter \  |Enter |Media | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SYM] = LAYOUT( \
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_MINS, KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       _______, KC_MINS, KC_UNDS, KC_PLUS, KC_EQL,  KC_F12,  \
  _______, KC_MINS, KC_UNDS, KC_PLUS, KC_EQL,  _______,                    _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______, \
  _______, _______, _______, _______, _______, _______, VS_BACK, _______,  _______, _______, _______, _______, KC_BSLS, _______, \
                             _______, _______, _______, _______,  _______, _______, _______, _______ \
),

/* Media
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      | VOL+ |      | Play |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | Prev | VOL- | Next |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | MUTE |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI | NAV  | /Space  /       \Enter \  |Enter |Media | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_MEDIA] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, KC_VOLU, _______, KC_MPLY, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, _______, _______, _______, _______,\
                             _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NAV, _SYM, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    // oled_write_ln(read_layer_state(), false);
    // oled_write_ln(read_keylog(), false);
    // oled_write_ln(read_keylogs(), false);
    // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    // oled_write_ln(read_host_led_state(), false);
    // oled_write_ln(read_timelog(), false);
    render_anim();
    oled_set_cursor(0,6);
    sprintf(wpm_str, "       WPM: %03d", get_current_wpm());
    oled_write(wpm_str, false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
