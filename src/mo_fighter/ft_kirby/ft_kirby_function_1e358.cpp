#include <types.h>
#pragma force_active on

struct S {
    unsigned int flags;
    unsigned char pad[4];
    unsigned int word;
};

extern "C" void fn_96_1E358(S* arg)
{
    arg->word = arg->word | (0x8 << 0x10);
}
