#include <types.h>

// Preserve the constructor-style destination return in r3.
extern "C" s16* fn_114_10520(s16* destination, const s16* source) {
    *destination = *source;
    return destination;
}
