#include <types.h>
#pragma force_active on

// Reads the word at offset 0x8 of the object pointed to by r3 and
// arithmetic-shifts it right by 29 (extracting the two top bits plus sign).
extern "C" s32 fn_27_295F04(s32* arg0) {
    return arg0[2] >> 29;
}
