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
};

extern bool persistent_nav_is_active;
#endif
