#include <mu/mu_msg.h>
#include <mu/mu_object.h>
#include <gf/gf_model.h>

#pragma force_active on

extern "C" {
extern u16 lbl_2_rodata_9A8[];
extern double lbl_2_rodata_AA8;
extern float lbl_2_rodata_A98;
void setFrameVisible__8MuObjectFf(void*, float);
void setUpdateRate__16gfModelAnimationFf(void*, float);
}

extern "C" void fn_2_234F8(void* self, u8 start)
{
    int i = 0;
    int current = start;

    while (i < 9 && current < *(u8*)((char*)self + 0x678)) {
        u32 index = *(u32*)(*(u32**)((char*)self + 0x674) + current);
        u16 msgIndex = *(u16*)((char*)lbl_2_rodata_9A8 + index * 2 - 10);
        (*(MuMsg**)((char*)self + 0x67C))->printIndex((u32)i, (u32)msgIndex, 0);
        ++i;
        ++current;
    }

    int flags = 0;
    if (start != 0)
        flags |= 1;
    if ((int)start + 9 <= (int)*(u8*)((char*)self + 0x678) - 1)
        flags |= 2;

    setFrameVisible__8MuObjectFf(
        *(void**)((char*)*(void**)((char*)self + 0x64C) + 0x218),
        (float)flags);

    setUpdateRate__16gfModelAnimationFf(
        *(void**)((char*)*(void**)((char*)*(void**)((char*)self + 0x64C) + 0x218) + 0x14),
        lbl_2_rodata_A98);
}
