#include QMK_KEYBOARD_H

#define _BASE 0
#define _NAV 1
#define _SYMB 2
#define _MEDIA 3
#define _GAME 4
#define _NUM  5
#define _FUNC 6
#define _SETS 7

#define _EIGHT 8
#define _NINE 9
#define _TEN 10
#define _ELEVEN 11
#define _TWELVE 12
#define _THIRTEEN 13
#define _FOURTEEN 14
#define _FIFTEEN 15
#define _SIXTEEN 16

#define BASE    DF(_BASE)
#define NAV     MO(_NAV)
#define SYMB    MO(_SYMB)
#define MEDIA   MO(_MEDIA)
#define GAME    DF(_GAME)
#define NUM     MO(_NUM)
#define FUNC    MO(_FUNC)
#define SETS    OSL(_SETS)

// Mappings for universal layout symbol layer. Should be synchronized with ahk.
#define _KC_EXLM LCAG(KC_1)

#define _KC_QUOT LCAG(KC_2)
#define _KC_DQUO HYPR(KC_2)

#define _KC_SCLN LCAG(KC_4)

#define _KC_COLN LCAG(KC_6)

#define _KC_QUES LCAG(KC_7)
#define _KC_AMPR HYPR(KC_7)

#define _KC_ASTR LCAG(KC_8)

#define _KC_LPRN LCAG(KC_9)

#define _KC_RPRN LCAG(KC_0)

#define _KC_MINS LCAG(KC_F13)

#define _KC_EQL LCAG(KC_F14)
#define _KC_PLUS HYPR(KC_F14)

#define _KC_LBRC LCAG(KC_F15)
#define _KC_LCBR HYPR(KC_F15)

#define _KC_RBRC LCAG(KC_F16)
#define _KC_RCBR HYPR(KC_F16)

#define _KC_LT LCAG(KC_F17)

#define _KC_GT LCAG(KC_F18)

#define _KC_BSLS LCAG(KC_F19)
#define _KC_PIPE HYPR(KC_F19)

#define _KC_SLSH LCAG(KC_F20)

#define PREVWRD   LCTL(KC_LEFT)
#define NEXTWRD   LCTL(KC_RIGHT)
