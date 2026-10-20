#include <types.h>
#pragma force_active on

// Bitfield write: reuses rlwimi to rotate the value into bits 24-30 of the
// word at offset 8 (a 7-bit : 7 bitfield), clearing the rest of the field.

struct S {
    unsigned int pad[2];
    unsigned int f : 7;
};

extern "C" void fn_48_B6F8(S* s, unsigned int v)
{
    s->f = v;
}
