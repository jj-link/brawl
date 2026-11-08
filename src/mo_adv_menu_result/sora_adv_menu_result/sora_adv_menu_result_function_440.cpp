#include <mu/mu_msg.h>
#include <stdio.h>
#pragma force_active on
extern "C" {
MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, HeapType, u32);
void* fn_80015DB4(void*, int, int, int, u16);
void fn_800B9488(MuMsg*, u32, int);
extern const float lbl_34_rodata_30;
extern const float lbl_34_rodata_34;
extern const char lbl_34_data_28[];
}
#define MSG (*(MuMsg**)(self + 0x1b8))
#define MODEL (*(nw4r::g3d::ScnMdlSimple**)(object + 0x10))
extern "C" void fn_34_440(unsigned char* self) {
    char buffer[10] = {};
    MSG = create__5MuMsgFUlQ25Heaps8HeapTypeUl(3, (HeapType)42, 43);
    MSG->allocMsgBuf(0x100, 8);
    *(void**)(self + 0x118) = fn_80015DB4(*(void**)(self + 0x5a8), 0, 1, 40, (u16)0xfffe);
    *(void**)(self + 0x120) = fn_80015DB4(*(void**)(self + 0x5a8), 0, 1, 50, (u16)0xfffe);
    MSG->setMsgData(fn_80015DB4(*(void**)(self + 0x5a8), 0, 1, 30, (u16)0xfffe));
    unsigned char* object = *(unsigned char**)(*(unsigned char**)(self + 0x59c) + 0x268);
    MSG->attachScnMdlSimple(1, MODEL, 0, lbl_34_rodata_30);
    MSG->setAlignMode(1, MuMsg::Align_Left);
    MSG->setFontColor(1, 0, 0, 0, 255);
    MSG->printIndex(1, 0, 0);
    MSG->attachScnMdlSimple(2, MODEL, 1, lbl_34_rodata_30);
    MSG->setAlignMode(2, MuMsg::Align_Left);
    MSG->setFontColor(2, 0, 0, 0, 255);
    sprintf(buffer, lbl_34_data_28, *(int*)(self + 0x100));
    MSG->printf(2, buffer);
    MSG->attachScnMdlSimple(3, MODEL, 2, lbl_34_rodata_30);
    MSG->setAlignMode(3, MuMsg::Align_Left);
    MSG->setFontColor(3, 0, 0, 0, 255);
    MSG->printIndex(3, 1, 0);
    MSG->attachScnMdlSimple(4, MODEL, 3, lbl_34_rodata_30);
    MSG->setAlignMode(4, MuMsg::Align_Left);
    MSG->setFontColor(4, 0, 0, 0, 255);
    sprintf(buffer, lbl_34_data_28, *(int*)(self + 0x104));
    MSG->printf(4, buffer);
    MSG->attachScnMdlSimple(7, MODEL, 6, lbl_34_rodata_34);
    MSG->setAlignMode(7, MuMsg::Align_Center);
    MSG->setFontColor(7, 0x6b, 0x58, 0, 255);
    fn_800B9488(MSG, 7, 1);
    sprintf(buffer, lbl_34_data_28, *(int*)(self + 0xfc));
    MSG->printf(7, buffer);
}