#include QMK_KEYBOARD_H
#include "definitions.h"
#include "tap_dance.h"
#include "macroses.h"

// --- Layers. ---
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [_BASE] = LAYOUT_all( \
            KC_GRV,       KC_1,    KC_2,      KC_3,       KC_4,          KC_5,                                        KC_6,            KC_7,          KC_8,         KC_9,         KC_0,    SETS, \
            TD_CAPS_GAME, KC_Q,    KC_W,      KC_E,       KC_R,          KC_T,                                        KC_Y,            KC_U,          KC_I,         KC_O,         KC_P,    KC_LBRC, \
            KC_TAB,       KC_A,    TD_S_LGUI, TD_D_LALT,  TD_F_LCTL,     KC_G,                                        KC_H,            KC_J,          KC_K,         KC_L,         KC_SCLN, KC_QUOT, \
            MEDIA,        KC_Z,    KC_X,      KC_C,       KC_V,          KC_B,                                        KC_N,            TD_M_RCTL,     TD_COMM_RALT, TD_DOT_RGUI,  KC_SLSH, MEDIA, \
                                   BASE,      TD_DEL_NUM, OSM(MOD_LSFT), TD_SPACE_NAV, TD_TMUX_SYMB,    TD_TMUX_SYMB, TD_SPACE_NAV,    OSM(MOD_LSFT), KC_BSPC,      FUNC \
        ),

        [_NAV] = LAYOUT_all( \
            _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                            KC_F6,       KC_F7,       KC_F8,     KC_F9,        KC_F10, _______,
            QK_BOOT, _______, _______, _______, _______, _______,                          _______,     KC_HOME,     _______,   KC_END,       _______, _______,
            _______, _______, _______, _______, _______, _______,                          TD_LEFT_NAV, TD_DOWN_NAV, TD_UP_NAV, TD_RIGHT_NAV, KC_CAPS, _______,
            _______, _______, _______, _______, _______, _______,                          KC_PSCR,     PREVWRD,     NEXTSEN,   NEXTWRD,      _______, _______,
                              BASE,    _______, _______, _______, _______,        _______, _______,     _______,     _______,   _______\
        ),

        [_SYMB] = LAYOUT_all( \
            _______, _______,  KC_AT,    _______,  KC_DLR,   _______,                       _______,  _______,  _______,  _______,  _______,  QK_BOOT,
            _______, KC_TILD,  _KC_LT,   _KC_EXLM, _KC_EQL,  _KC_GT,                        _KC_CIRC,  _KC_LBRC, KC_UNDS,  _KC_RBRC, _______,  _______,
            _______, _KC_PLUS, _KC_RPRN, _KC_MINS, _KC_RCBR, _KC_BSLS,                      KC_PERC,  _KC_LCBR, _KC_QUOT, _KC_LPRN, _KC_EXLM, _______,
            KC_LSFT, _KC_SCLN, _KC_SLSH, _KC_DQUO, _KC_ASTR, KC_HASH,                       _KC_AMPR, _KC_QUES, _KC_COLN, _KC_PIPE,  _______, QK_RBT,
                               _______,  _______,  _______,  _______,  _______,    _______, _______,  _______,  _______,  _______ \
        ),

        [_MEDIA] = LAYOUT_all(
            _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, DM_PLY1, DM_REC1,
            RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,                           _______, KC_VOLD, KC_MUTE, KC_VOLU, DM_PLY2, DM_REC2,
            RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, CG_TOGG,                           _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, DM_RSTP,
                              _______, _______, _______, _______, _______,         _______, _______,  _______, _______, _______
        ),

        [_GAME] = LAYOUT_all( \
            _______, _______, _______, _______, _______, _______,                           _______, _______,  _______, _______, _______, _______,
            KC_ESC,  _______, KC_W,    _______, _______, _______,                           _______, _______,  _______, _______, _______, _______,
            KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    _______,                           _______, _______,  _______, _______, _______, _______,
            KC_LSFT, _______, _______, _______, _______, _______,                           _______, _______,  _______, _______, _______, KC_INS,
                              BASE,    _______, KC_LALT, KC_SPACE, KC_LCTL,        _______, _______, KC_ENTER, KC_BSPC, BASE \
        ),

        [_NUM] = LAYOUT_all( \
            _______, _______, _______, _______, _______, _______,                            _______,  KC_PSLS, KC_PAST,  _______, _______,  _______,
            _______, _______, _______, _______, _______, _______,                            _______,  KC_P7,   KC_P8,    KC_P9,   KC_PPLS,  _______,
            _______, _______, _______, _______, _______, KC_NUM,                             _______,  KC_P4,   KC_P5,    KC_P6,   KC_PPLS,  _______,
            _______, _______, _______, _______, _______, _______,                            _______,  KC_P1,   KC_P2,    KC_P3,   KC_PMNS,  _______,
                              _______, _______, _______, _______, _______,         KC_ENTER, KC_0,     KC_PDOT, _______,  _______ \
        ),

        [_FUNC] = LAYOUT_all( \
            _______, _______, _______, _______, _______, _______,                           _______,  _______,  _______, _______,  _______,  _______,
            _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   _______,                           _______,  _______,  _______, _______,  _______,  _______,
            _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   _______,                           _______,  _______,  _______, _______,  _______,  _______,
            _______, KC_F10,  KC_1,    KC_F2,   KC_F3,   _______,                           _______,  _______,  _______, _______,  _______,  _______,
                              _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______ \
        ),

        [_SETS] = LAYOUT_all( \
            _______, LANG4,   LANG3,   LANG2,   LANG1,   LANG0,                            LANG0,   LANG1,   LANG2,   LANG3,    LANG4,    _______,
            _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______,  _______,  _______,
            _______, _______, _______, _______, CG_SWAP, _______,                          _______, _______, _______, _______,  _______,  _______,
            _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______,  _______,  _______,
                              _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______ \
        ),
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//     if (get_highest_layer(default_layer_state) == _GAME) {
//         combo_disable();
//     }
//     else {
//         combo_enable();
//     }

//     return state;
// }

