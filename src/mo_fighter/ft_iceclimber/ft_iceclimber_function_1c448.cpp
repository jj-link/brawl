#include <types.h>
#pragma force_active on

// Preserve the constructor-style destination return in r3.
extern "C" s16* fn_105_1C448(s16* destination, const s16* source) {
    *destination = *source;
    return destination;
}
