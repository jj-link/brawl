#include <types.h>
#pragma force_active on

// Copy one signed halfword from source to destination.
extern "C" void fn_126_968C(s16* destination, const s16* source) {
    *destination = *source;
}
