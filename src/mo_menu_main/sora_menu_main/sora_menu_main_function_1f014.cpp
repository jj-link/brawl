#include <types.h>
#include <mu/mu_msg.h>
#include <gf/gf_archive.h>
#include <ut/ut_relocate.h>

#pragma force_active on

extern "C" {
extern char lbl_2_data_2AF8[];
extern char lbl_2_data_294C[];
extern const float lbl_2_rodata_920[];

void fn_18_11C4(void*);
MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, HeapType, u32);
}

extern "C" void* fn_2_1F014(void* self, u32 a1, u32 a2,
                            void* arg6, void* arg7, gfArchive* archive) {
    u8* s = (u8*)self;
    const float* w = lbl_2_rodata_920;
    int size;
    u32 zero;

    fn_18_11C4(self);
    *(void**)(s + 0x668) = lbl_2_data_2AF8;
    *(MuMsg**)(s + 0x66c) =
        create__5MuMsgFUlQ25Heaps8HeapTypeUl(5, (HeapType)42, 43);
    (*(MuMsg**)(s + 0x66c))->allocMsgBuf(0x400, 7);
    *(void**)(s + 0x694) = arg6;
    *(void**)(s + 0x698) = arg7;
    *(void**)(s + 0x69c) = archive->getData(Data_Type_Misc, 8, 0xfffe);
    *(void**)(s + 0x6a0) = archive->getData(Data_Type_Misc, 4, 0xfffe);
    *(void**)(s + 0x6a4) = archive->getData(Data_Type_Misc, 5, 0xfffe);
    *(void**)(s + 0x6a8) = archive->getData(Data_Type_Misc, 6, 0xfffe);

    u8* dat = (u8*)archive->getData(Data_Type_Misc, 7, &size, 0xfffe);
    utRelocate rel(dat, size);
    *(void**)(s + 0x6ac) = rel.getPublicAddress(lbl_2_data_294C);
    zero = 0;
    *(u32*)(s + 0x6b0) = zero;
    goto outer_check;

outer_body:
    {
        u32 i = *(u32*)(s + 0x6b0);
        u8* base = *(u8**)(s + 0x6ac);
        u8* rec = base + i * 0x300;
        *(u32*)(s + 0x6b4 + i * 4) = zero;
        s32 j = 0;
        goto inner_check;

inner_body:
        {
            u8* base2 = *(u8**)(s + 0x6ac);
            s32 i2 = *(u32*)(s + 0x6b0);
            u32 off = (u32)(j * 8);
            u8* elem = (u8*)(off + (u32)base2) + i2 * 0x300 + 0x100;
            *(u32*)(s + i2 * 4 + 0x6b4) +=
                *(s32*)(elem + 4) - *(s32*)elem + 1;
            ++j;
        }

inner_check:
        {
            u32 index = *(u32*)(s + 0x6b0);
            u8* data = *(u8**)(s + 0x6ac);
            if (j < (*(u32*)(data + index * 0x300 + 0xfc) >> 1))
                goto inner_body;
        }
        *(u32*)(s + 0x6b0) = *(u32*)(s + 0x6b0) + 1;
    }

outer_check:
    if ((*(u32*)(*(u8**)(s + 0x6ac) +
                 *(u32*)(s + 0x6b0) * 0x300) + 0x10000) != 0xffff)
        goto outer_body;

    for (s32 i = 0; i < 7; ++i)
        (*(MuMsg**)(s + 0x66c))->setFontWidthModeAuto(i);

    (*(MuMsg**)(s + 0x66c))->attachScnMdlSimple(
        0, *(nw4r::g3d::ScnMdlSimple**)(*(u8**)(*(u8**)(s + 0x64c) + 0x1a4) + 0x10), 0, w[0]);
    (*(MuMsg**)(s + 0x66c))->setAlignMode(0, MuMsg::Align_Center);
    (*(MuMsg**)(s + 0x66c))->setFontColor(0, 240, 240, 240, 255);

    (*(MuMsg**)(s + 0x66c))->attachScnMdlSimple(
        1, *(nw4r::g3d::ScnMdlSimple**)(*(u8**)(*(u8**)(s + 0x64c) + 0x1a4) + 0x10), 1, w[0]);
    (*(MuMsg**)(s + 0x66c))->setAlignMode(1, MuMsg::Align_Center);
    (*(MuMsg**)(s + 0x66c))->setFontColor(1, 3, 53, 102, 255);

    (*(MuMsg**)(s + 0x66c))->attachScnMdlSimple(
        2, *(nw4r::g3d::ScnMdlSimple**)(*(u8**)(*(u8**)(s + 0x64c) + 0x1a4) + 0x10), 2, w[1]);
    (*(MuMsg**)(s + 0x66c))->setAlignMode(2, MuMsg::Align_Left);
    (*(MuMsg**)(s + 0x66c))->setFontColor(2, 233, 233, 233, 255);
    (*(MuMsg**)(s + 0x66c))->getWScale(2, w[2]);

    (*(MuMsg**)(s + 0x66c))->attachScnMdlSimple(
        3, *(nw4r::g3d::ScnMdlSimple**)(*(u8**)(*(u8**)(s + 0x64c) + 0x1a4) + 0x10), 3, w[0]);
    (*(MuMsg**)(s + 0x66c))->setAlignMode(3, MuMsg::Align_Center);
    (*(MuMsg**)(s + 0x66c))->setFontColor(3, 240, 240, 240, 255);

    (*(MuMsg**)(s + 0x66c))->attachScnMdlSimple(
        4, *(nw4r::g3d::ScnMdlSimple**)(*(u8**)(*(u8**)(s + 0x64c) + 0x1a4) + 0x10), 4, w[0]);
    (*(MuMsg**)(s + 0x66c))->setAlignMode(4, MuMsg::Align_Center);
    (*(MuMsg**)(s + 0x66c))->setFontColor(4, 3, 53, 102, 255);

    (*(MuMsg**)(s + 0x66c))->attachScnMdlSimple(
        5, *(nw4r::g3d::ScnMdlSimple**)(*(u8**)(*(u8**)(s + 0x64c) + 0x1a8) + 0x10), 0, w[0]);
    (*(MuMsg**)(s + 0x66c))->setAlignMode(5, MuMsg::Align_Center);
    (*(MuMsg**)(s + 0x66c))->setFontColor(5, 240, 240, 240, 255);

    (*(MuMsg**)(s + 0x66c))->attachScnMdlSimple(
        6, *(nw4r::g3d::ScnMdlSimple**)(*(u8**)(*(u8**)(s + 0x64c) + 0x1a8) + 0x10), 1, w[3]);
    (*(MuMsg**)(s + 0x66c))->setAlignMode(6, MuMsg::Align_Center);
    (*(MuMsg**)(s + 0x66c))->setFontColor(6, 240, 240, 240, 255);

    return self;
}
