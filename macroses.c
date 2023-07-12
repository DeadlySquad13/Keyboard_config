#include QMK_KEYBOARD_H
#include "macroses.h"
#include "definitions.h"
#include "tap_dance.h"

bool persistent_nav_is_active = false;
uint16_t persistent_nav_timer = 0;

// Custom keycodes.
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        extern uint32_t tap_timer;
        tap_timer = timer_read32();
    }

    switch (keycode) {
        case NEXTSEN:  // Next sentence macro.
          if (record->event.pressed) {
            register_code16(C(A(G(KC_F21))));
            unregister_code16(C(A(G(KC_F21))));
            SEND_STRING(" ");
            add_oneshot_mods(MOD_BIT(KC_LSFT));  // Set one-shot mod for shift.
          }
          return false;

        case BRACES:
            if (record->event.pressed) {
                uint8_t shifted = get_mods() & (MOD_MASK_SHIFT);
                    if (shifted) {
                        unregister_code(KC_LSFT);
                        unregister_code(KC_RSFT);
                        SEND_STRING("{}"SS_TAP(X_LEFT));
                    }
                    else {
                        SEND_STRING("[]"SS_TAP(X_LEFT));
                    }
            }
            break;

        case PARENTH:
            if (record->event.pressed) {
                SEND_STRING("()");
                tap_code(KC_LEFT);
            }
            break;

        case TMUX:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_LCTL(SS_TAP(X_SPC))
                );
            }
            break;

        case LANG0:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_LALT(SS_LSFT(SS_TAP(X_6)))
                );
            }
            break;

        case LANG1:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_LALT(SS_LSFT(SS_TAP(X_7)))
                );
            }
            break;

        case LANG2:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_LALT(SS_LSFT(SS_TAP(X_8)))
                );
            }
            break;

        case LANG3:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_LALT(SS_LSFT(SS_TAP(X_9)))
                );
            }
            break;

        case LANG4:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_LALT(SS_LSFT(SS_TAP(X_0)))
                );
            }
            break;

        case CUT:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_LCTL(SS_TAP(X_X))
                );
            }
            break;

        case COPY:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_LCTL(SS_TAP(X_C))
                );
            }
            break;

        case PASTE:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_LCTL(SS_TAP(X_V))
                );
            }
            break;

        case PERSISTENT_LEFT:
            persistent_nav_timer = timer_read();

            if (record->event.pressed) {
                register_code(KC_LEFT);
                persistent_nav_is_active = true;
            } else {
                unregister_code(KC_LEFT);
            }
            break;

        case KC_H:
            if (persistent_nav_is_active) {
                persistent_nav_timer = timer_read();

                if (record->event.pressed) {
                    register_code(KC_LEFT);
                } else {
                    unregister_code(KC_LEFT);
                }

                return false;
            }

            if (!record->event.pressed) {
                unregister_code(KC_LEFT);
            }

            return true;

        case PERSISTENT_DOWN:
            persistent_nav_timer = timer_read();

            if (record->event.pressed) {
                register_code(KC_DOWN);
                persistent_nav_is_active = true;
            } else {
                unregister_code(KC_DOWN);
            }
            break;

        case KC_J:
            if (persistent_nav_is_active) {
                persistent_nav_timer = timer_read();

                if (record->event.pressed) {
                    register_code(KC_DOWN);
                } else {
                    unregister_code(KC_DOWN);
                }

                return false;
            }

            if (!record->event.pressed) {
                unregister_code(KC_DOWN);
            }

            return true;

        case PERSISTENT_UP:
            persistent_nav_timer = timer_read();

            if (record->event.pressed) {
                register_code(KC_UP);
                persistent_nav_is_active = true;
            } else {
                unregister_code(KC_UP);
            }
            break;

        case KC_K:
            if (persistent_nav_is_active) {
                persistent_nav_timer = timer_read();

                if (record->event.pressed) {
                    register_code(KC_UP);
                } else {
                    unregister_code(KC_UP);
                }
                
                return false;
            }

            if (!record->event.pressed) {
                unregister_code(KC_UP);
            }

            return true;

        case PERSISTENT_RIGHT:
            persistent_nav_timer = timer_read();

            if (record->event.pressed) {
                register_code(KC_RIGHT);
                persistent_nav_is_active = true;
            } else {
                unregister_code(KC_RIGHT);
           }
            break;

        case KC_L:
            if (persistent_nav_is_active) {
                persistent_nav_timer = timer_read();

                if (record->event.pressed) {
                    register_code(KC_RIGHT);
                } else {
                    unregister_code(KC_RIGHT);
                }
                return false;
            }

            if (!record->event.pressed) {
                unregister_code(KC_RIGHT);
            }
            return true;

        case KC_ESC:
            persistent_nav_is_active = false;
            break;
    }

    return true;
}

void matrix_scan_user(void) { // The very important timer.
  if (persistent_nav_is_active) {
        if (timer_elapsed(persistent_nav_timer) > 1500) {
            persistent_nav_is_active = false;
        }
    }
}
