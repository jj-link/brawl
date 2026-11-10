#include <types.h>
#include <mu/mu_msg.h>

#pragma force_active on

extern "C" {
extern const float lbl_2_rodata_E48[];
void fn_800B9488(MuMsg*, u32, u32);
void fn_800B9428(MuMsg*, u32, float);
void FUN_800b9448__5MuMsgFUlb(MuMsg*, u32, bool);
void FUN_800b9460__5MuMsgFUlUcUcUcf(MuMsg*, u32, u8, u8, u8, float);
}

#define MSG (*(MuMsg**)(s + 0x674))
#define MODEL1(off) (*(nw4r::g3d::ScnMdlSimple**)(*(u8**)(*(u8**)(s + 0x64c) + (off) + 0x238) + 0x10))
#define MODEL2(off) (*(nw4r::g3d::ScnMdlSimple**)(*(u8**)(*(u8**)(s + 0x64c) + (off) + 0x250) + 0x10))

extern "C" void fn_2_2777C(void* self) {
    const float* rod = lbl_2_rodata_E48;
    s32 r30;
    s32 r29;
    s32 k;
    u8* s = (u8*)self;
    u32 idt;
    s32 r25;

    k = 0;
    r30 = 0;
    r29 = 0xC;
    do {
        idt = *(u32*)(s + 0x66c) + k;
        MSG->attachScnMdlSimple(idt, MODEL1(r30), 0, rod[2]);
        fn_800B9488(MSG, idt, 1);
        MSG->setFontColor(idt, 0x60, 0x70, 0x85, 0xFF);
        MSG->setHScale(idt, rod[3]);
        FUN_800b9448__5MuMsgFUlb(MSG, idt, true);
        FUN_800b9460__5MuMsgFUlUcUcUcf(MSG, idt, 0xFF, 0xFF, 0xFF, rod[4]);

        idt = *(u32*)(s + 0x66c) + k + 6;
        MSG->attachScnMdlSimple(idt, MODEL1(r30), 1, rod[2]);
        MSG->setFontColor(idt, 0xFF, 0xFF, 0xFF, 0xFF);
        MSG->setHScale(idt, rod[3]);
        MSG->setAlignMode(idt, MuMsg::Align_Right);
        fn_800B9428(MSG, idt, rod[5]);

        s32 j = 0;
        r25 = 0;
        for (; j < 5; ++j, r25 += 4) {
            idt = *(u32*)(s + 0x66c) + (j + r29);
            MSG->attachScnMdlSimple(idt, MODEL2(r25), k, rod[2]);
            MSG->setFontColor(idt, 0xE5, 0xE5, 0xE5, 0xFF);
            MSG->setHScale(idt, rod[6]);
            MSG->getHScale(idt, rod[7]);
            MSG->setAlignMode(idt, MuMsg::Align_Right);
            fn_800B9428(MSG, idt, rod[8]);
        }
        k++;
        r30 += 4;
        r29 += 5;
    } while (k < 6);
}
