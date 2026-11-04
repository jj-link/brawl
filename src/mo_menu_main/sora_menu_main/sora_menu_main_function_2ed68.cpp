#include <mu/mu_msg.h>

#pragma force_active on

extern "C" {
extern unsigned char lbl_2_data_3C20[];
extern const unsigned char lbl_2_rodata_F90[];

void fn_18_11C4(void*, void*, void*);
MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(unsigned long, HeapType, unsigned long);
void FUN_800b9448__5MuMsgFUlb(MuMsg*, unsigned long, bool);
void FUN_800b9460__5MuMsgFUlUcUcUcf(
    MuMsg*, unsigned long, unsigned char, unsigned char, unsigned char, float);
}

#define MSG (*reinterpret_cast<MuMsg**>(self + 0x678))
#define MODEL(o) \
    (*reinterpret_cast<nw4r::g3d::ScnMdlSimple**>( \
        *reinterpret_cast<char**>(*reinterpret_cast<char**>(self + 0x64c) + (o)) + 0x10))
#define F(o) (*reinterpret_cast<const float*>(ro + (o)))

extern "C" void* fn_2_2ED68(
    char* self, void* a, void* b, void* data, void* data2, void* arg)
{
    int off;
    const unsigned char* ro = lbl_2_rodata_F90;

    fn_18_11C4(self, a, b);

    *reinterpret_cast<void**>(self + 0x680) = arg;
    *reinterpret_cast<void**>(self + 0x668) = lbl_2_data_3C20;
    *reinterpret_cast<void**>(self + 0x66c) = lbl_2_data_3C20 + 0x28;
    *reinterpret_cast<int*>(self + 0x684) = 0;
    *reinterpret_cast<int*>(self + 0x688) = 0;

    MSG = create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, (HeapType)42, 43);
    MSG->allocMsgBuf(0x400, 9);
    MSG->setMsgData(data);

    *reinterpret_cast<MuMsg**>(self + 0x67c) =
        create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, (HeapType)42, 43);
    (*reinterpret_cast<MuMsg**>(self + 0x67c))->allocMsgBuf(0x400, 1);
    (*reinterpret_cast<MuMsg**>(self + 0x67c))->setMsgData(data2);

    {
        int off, i;
        for (i = 0, off = 0; i <= 2; ++i, off += 4) {
            MSG->attachScnMdlSimple(
                i,
                *reinterpret_cast<nw4r::g3d::ScnMdlSimple**>(
                    *reinterpret_cast<char**>(
                        (*reinterpret_cast<char**>(self + 0x64c) + off) + 0x34c) + 0x10),
                0, F(0));
            MSG->setAlignMode(i, MuMsg::Align_Left);
            MSG->setFontColor(i, 0, 0, 0, 255);
            MSG->setFontWidthModeAuto(i);
        }
    }

    for (int i = 2, off = 8; i < 4; ++i, off += 4) {
        MSG->attachScnMdlSimple(
            i,
            *reinterpret_cast<nw4r::g3d::ScnMdlSimple**>(
                *reinterpret_cast<char**>(
                    (*reinterpret_cast<char**>(self + 0x64c) + off) + 0x344) + 0x10),
            1, F(0));
        MSG->setAlignMode(i, MuMsg::Align_Center);
        MSG->setFontColor(i, 255, 255, 255, 255);
        MSG->setFontWidthModeAuto(i);
        FUN_800b9448__5MuMsgFUlb(MSG, i, true);
        FUN_800b9460__5MuMsgFUlUcUcUcf(MSG, i, 0x3f, 0x39, 0x4f, F(4));
    }

    for (int i = 4; i < 9; ++i) {
        MSG->printIndex(i, 12, 0);
        MSG->attachScnMdlSimple(i, MODEL(0x354), i - 4, F(8));
        MSG->setFontColor(i, 0, 0, 0, 255);
    }

    return self;
}
