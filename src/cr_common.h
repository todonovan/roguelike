#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

// So, VSCode intellisense is refusing to recognize ncurses functions from either the shared
// library or from /usr/include. I spent a solid four hours trying to find a workaround.
// So yes, I copy/pasted the contents of ncurses.h into the project so I can use intellisense.
// Sue me.
#include "ncurses.h"

// Really going for the "mid-80s-C" flavor here. Exceptions? Huh?
typedef enum
{
    SUCCESS = 0,
    ERR_FATAL = -1,
} CRResultCode;

// This nifty macro will print out the message you give it along with file name and line info.
// It's slightly awkward as it will just slam it into the ncurses window, but it'll have to do
// until I have an actual UI system.
// Not to be used for general messaging or logging because, again, it just slams the msg in ncurses...
// At some point, I can at the very least spend a few minutes making sure this writes in a fixed location
#define CR_ERROR(msg) (printw("CR_ERROR: %s\n\tin file %s\n\tat line %d\n", ((char *)msg), __FILE__, __LINE__))