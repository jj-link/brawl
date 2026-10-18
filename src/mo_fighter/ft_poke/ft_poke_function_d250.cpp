#include <types.h>
#pragma force_active on

// Copy a single signed halfword from *source to *destination.
extern "C" void fn_116_D250(s16* destination, const s16* source) {
    *destination = *source;
}
