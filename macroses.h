#ifndef MACROSES_H
#define MACROSES_H

enum custom_keycodes {
    NEXTSEN = USER00,
    PREDL,
    BRACES,
    PARENTH,

    TMUX,

    LANG0,
    LANG1,
    LANG2,
    LANG3,
    LANG4,

    CUT,
    COPY,
    PASTE,

    PERSISTENT_LEFT,
    PERSISTENT_RIGHT,
    PERSISTENT_DOWN,
    PERSISTENT_UP,

    H_PERSISTENT,
    J_PERSISTENT,
    K_PERSISTENT,
    L_PERSISTENT,
};

extern bool persistent_nav_is_active;
#endif
