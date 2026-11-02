#include <types.h>
#pragma force_active on

#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)

void *OSGetStackPointer(void) {
    BLOCK {
        mr r3, r1
    }
}
