#include <types.h>
#pragma force_active on

typedef struct {
    char pad[0x28];
    s32 unk28;
} Struct_802793CC;

void fn_802793CC(Struct_802793CC* arg0, s32 arg1) {
    arg0->unk28 = arg1;
}