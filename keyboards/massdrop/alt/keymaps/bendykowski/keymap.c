#include QMK_KEYBOARD_H

enum alt_keycodes {
    L_BRI = SAFE_RANGE, //LED Brightness Increase                                   //Working
    L_BRD,              //LED Brightness Decrease                                   //Working
    L_PTN,              //LED Pattern Select Next                                   //Working
    L_PTP,              //LED Pattern Select Previous                               //Working
    L_PSI,              //LED Pattern Speed Increase                                //Working
    L_PSD,              //LED Pattern Speed Decrease                                //Working
    L_T_MD,             //LED Toggle Mode                                           //Working
    L_T_ONF,            //LED Toggle On / Off                                       //Broken
    L_ON,               //LED On                                                    //Broken
    L_OFF,              //LED Off                                                   //Broken
    L_T_BR,             //LED Toggle Breath Effect                                  //Working
    L_T_PTD,            //LED Toggle Scrolling Pattern Direction                    //Working
    U_T_AGCR,           //USB Toggle Automatic GCR control                          //Working
    DBG_TOG,            //DEBUG Toggle On / Off                                     //
    DBG_MTRX,           //DEBUG Toggle Matrix Prints                                //
    DBG_KBD,            //DEBUG Toggle Keyboard Prints                              //
    DBG_MOU,            //DEBUG Toggle Mouse Prints                                 //
    MD_BOOT             //Restart into bootloader after hold timeout                //Working
};

// Custom layouts
enum custom_layouts {
    _QTY = 0,           // Default QWERTY layout
    _COL,               // Default Colemak Mod-DH layout
    _EDT,               // Editor layout
    _COD,               // Coder layout
    _NAV,               // Navigator layout
    _FUN,               // Function layout
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

keymap_config_t keymap_config;
rgb_config_t rgb_matrix_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QTY] = LAYOUT(
        KC_ESC,               KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,           KC_EQL,  KC_BSPC, KC_DEL,  \
        LT(_COD, KC_TAB),     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    LT(_COD, KC_LBRC), KC_RBRC, KC_BSLS, KC_MUTE, \
        MT(MOD_LSFT, KC_GRV), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LT(_NAV, KC_QUOT),          KC_ENT,  KC_VOLU, \
        KC_Z,                 KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM(MOD_RSFT),              KC_UP,   KC_VOLD, \
        KC_LGUI,              KC_LALT, KC_LCTL,                            LT(_EDT, KC_SPC),                   KC_RALT, MO(_FUN),          KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [_COL] = LAYOUT(
        KC_ESC,               KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,           KC_EQL,  KC_BSPC, KC_DEL,  \
        LT(_COD, KC_TAB),     KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, LT(_COD, KC_LBRC), KC_RBRC, KC_BSLS, KC_MUTE, \
        MT(MOD_LSFT, KC_GRV), KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    LT(_NAV, KC_QUOT),          KC_ENT,  KC_VOLU, \
        KC_Z,                 KC_X,    KC_C,    KC_D,    KC_V,    XXXXXXX, KC_K ,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, OSM(MOD_RSFT),              KC_UP,   KC_VOLD, \
        KC_LGUI,              KC_LALT, KC_LCTL,                            LT(_EDT, KC_SPC),                   KC_RALT, MO(_FUN),          KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [_EDT] = LAYOUT(
        TG(_EDT), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, \
        KC_TAB,   KC_ESC,  KC_BTN2, KC_MS_U, KC_BTN3, XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_WH_U, KC_ESC,  KC_INS,  KC_CAPS, XXXXXXX, \
        KC_BTN1,  XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  XXXXXXX,          KC_PSCR, XXXXXXX, \
        XXXXXXX,  KC_LALT, KC_LSFT, KC_LCTL, KC_LGUI, XXXXXXX, KC_PGDN, KC_BSPC, KC_WH_L, KC_WH_R, KC_WH_D, KC_MENU,          XXXXXXX, XXXXXXX, \
        XXXXXXX,  XXXXXXX, XXXXXXX,                            TG(_EDT),                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
    ),
    [_COD] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, KC_AT,   KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC, KC_EXLM, KC_LABK, KC_RABK, KC_EQL,  KC_AMPR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, KC_BSLS, KC_SLSH, KC_LCBR, KC_RCBR, KC_ASTR, KC_QUES, KC_LPRN, KC_RPRN, KC_MINS, KC_COLN,  XXXXXXX,          XXXXXXX, XXXXXXX, \
        XXXXXXX, KC_HASH, KC_DLR,  KC_PIPE, KC_TILD, KC_GRV,  KC_PLUS, KC_PERC, KC_DQUO, KC_QUOT, KC_SCLN,  XXXXXXX,          XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX,                            TG(_EDT),                           TG(_NAV), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
    ),
    [_NAV] = LAYOUT(
        TG(_NAV), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX,  XXXXXXX, KC_HOME, KC_UP,   KC_END,  XXXXXXX, XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, \
        TG(_NAV), XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,  TG(_NAV),          XXXXXXX, XXXXXXX, \
        XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_WH_D, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX,  XXXXXXX,           XXXXXXX, XXXXXXX, \
        XXXXXXX,  XXXXXXX, XXXXXXX,                            KC_BTN1,                            TG(_NAV), XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX  \
    ),
    [_FUN] = LAYOUT(
        XXXXXXX, L_PTP,    L_PTN,    L_PSD,   L_PSI,   L_BRD,   L_BRI,   XXXXXXX, XXXXXXX, L_T_BR,  L_T_PTD,  L_T_MD,  L_T_ONF, TG_NKRO, MD_BOOT, \
        XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, \
        KC_CAPS, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,          KC_PSCR, KC_MPRV, \
        XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,          XXXXXXX, KC_MNXT, \
        CG_TOGG, DF(_QTY), DF(_COL),                            TG(_EDT),                           TG(_NAV), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    */
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    led_animation_id = 1;
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case L_BRI:
            if (record->event.pressed) {
                if (LED_GCR_STEP > LED_GCR_MAX - gcr_desired) gcr_desired = LED_GCR_MAX;
                else gcr_desired += LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_BRD:
            if (record->event.pressed) {
                if (LED_GCR_STEP > gcr_desired) gcr_desired = 0;
                else gcr_desired -= LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_PTN:
            if (record->event.pressed) {
                if (led_animation_id == led_setups_count - 1) led_animation_id = 0;
                else led_animation_id++;
            }
            return false;
        case L_PTP:
            if (record->event.pressed) {
                if (led_animation_id == 0) led_animation_id = led_setups_count - 1;
                else led_animation_id--;
            }
            return false;
        case L_PSI:
            if (record->event.pressed) {
                led_animation_speed += ANIMATION_SPEED_STEP;
            }
            return false;
        case L_PSD:
            if (record->event.pressed) {
                led_animation_speed -= ANIMATION_SPEED_STEP;
                if (led_animation_speed < 0) led_animation_speed = 0;
            }
            return false;
        case L_T_MD:
            if (record->event.pressed) {
                led_lighting_mode++;
                if (led_lighting_mode > LED_MODE_MAX_INDEX) led_lighting_mode = LED_MODE_NORMAL;
            }
            return false;
        case L_T_ONF:
            if (record->event.pressed) {
                led_enabled = !led_enabled;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_ON:
            if (record->event.pressed) {
                led_enabled = 1;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_OFF:
            if (record->event.pressed) {
                led_enabled = 0;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_T_BR:
            if (record->event.pressed) {
                led_animation_breathing = !led_animation_breathing;
                if (led_animation_breathing) {
                    gcr_breathe = gcr_desired;
                    led_animation_breathe_cur = BREATHE_MIN_STEP;
                    breathe_dir = 1;
                }
            }
            return false;
        case L_T_PTD:
            if (record->event.pressed) {
                led_animation_direction = !led_animation_direction;
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

led_instruction_t led_instructions[] = {
    //LEDs are normally inactive, no processing is performed on them
    //Flags are used in matching criteria for an LED to be active and indicate how to color it
    //Flags can be found in tmk_core/protocol/arm_atsam/led_matrix.h (prefixed with LED_FLAG_)
    //LED IDs can be found in config_led.h in the keyboard's directory
    //Examples are below
    // { .flags = LED_FLAG_USE_PATTERN | LED_FLAG_USE_ROTATE_PATTERN, .pattern_id = 1 },

    // ==========[ RGB led matrix programs ]==========
    // tmk_core/protocol/arm_atsam/led_matrix_programs.c
    // 0 - leds_rainbow_s
    // 1 - leds_rainbow_ns
    // 2 - leds_teal_salmon
    // 3 - leds_yellow
    // 4 - leds_red
    // 5 - leds_green
    // 6 - leds_blue
    // 7 - leds_white
    // 8 - leds_white_with_red_stripe
    // 9 - leds_black_with_red_stripe
    // 10 - leds_off

    //All LEDs use the user's selected pattern (this is the factory default)
     { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_USE_ROTATE_PATTERN, .layer = 0 },
     { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_USE_PATTERN, .pattern_id = 8, .layer = 2 }, // Editor Layer
     { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_USE_PATTERN, .pattern_id = 5, .layer = 3 }, // Coder Layer
     { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_USE_PATTERN, .pattern_id = 6, .layer = 4 }, // Mouse Layer
     { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_USE_PATTERN, .pattern_id = 4, .layer = 5 }, // Function Layer
     { .end = 1 }
};
