#include <types.h>
#pragma force_active on

typedef struct Unk {
    char pad[0x7D8];
    s32 unk7D8;
} Unk;

void fn_803900E4(Unk* arg0, s32 arg1) {
    arg0->unk7D8 = arg1;
}
