#pragma opt_propagation off
#include <mu/mu_msg.h>
#include <gf/gf_file_io_handle.h>
#include <stdio.h>
#pragma force_active on

extern "C" {
MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, HeapType, u32);
void fn_800B93DC(MuMsg*, u32, int);
void fn_800B9488(MuMsg*, u32, int);
void FUN_800b9448__5MuMsgFUlb(MuMsg*, u32, bool);
void FUN_800b9460__5MuMsgFUlUcUcUcf(MuMsg*, u32, u8, u8, u8, float);
extern const float lbl_21_rodata_0[];
extern const char lbl_21_data_150[];
}

#define MSG (*(MuMsg**)(self + 0x44))
#define MODEL (*(nw4r::g3d::ScnMdlSimple**)(object + 0x10))

extern "C" void fn_21_4B0(unsigned char* self) {
    const float* ro = lbl_21_rodata_0;
    char buffer[10] = {};

    MSG = create__5MuMsgFUlQ25Heaps8HeapTypeUl(3, (HeapType)0x2a, 0x2b);
    MSG->allocMsgBuf(0x100, 7);
    MSG->setMsgData(((gfFileIOHandle*)(self + 0x150))->getBuffer());

    unsigned char* object = *(unsigned char**)(self + 0x40);

    MSG->attachScnMdlSimple(0, MODEL, 0, ro[6]);
    MSG->setHScale(0, ro[7]);
    MSG->getHScale(0, ro[7]);
    MSG->setAlignMode(0, MuMsg::Align_Center);
    fn_800B93DC(MSG, 0, 1);
    MSG->setFontColor(0, 0xd0, 0xde, 0xe7, 0xff);
    MSG->printIndex(0, 0, 0);

    MSG->attachScnMdlSimple(1, MODEL, 1, ro[6]);
    MSG->getHScale(1, ro[8]);
    FUN_800b9448__5MuMsgFUlb(MSG, 1, true);
    FUN_800b9460__5MuMsgFUlUcUcUcf(MSG, 1, 0, 0, 0, ro[9]);
    MSG->setAlignMode(1, MuMsg::Align_Center);
    MSG->setFontColor(1, 0xd2, 0xb2, 0xb2, 0xff);
    fn_800B9488(MSG, 1, 1);
    sprintf(buffer, lbl_21_data_150, *(int*)(self + 0x60));
    MSG->printf(1, buffer);

    MSG->attachScnMdlSimple(2, MODEL, 2, ro[6]);
    MSG->setHScale(2, ro[7]);
    MSG->getHScale(2, ro[7]);
    MSG->setAlignMode(2, MuMsg::Align_Center);
    fn_800B93DC(MSG, 2, 1);
    MSG->setFontColor(2, 0xd0, 0xde, 0xe7, 0xff);
    MSG->printIndex(2, 1, 0);

    MSG->attachScnMdlSimple(3, MODEL, 3, ro[6]);
    MSG->getHScale(3, ro[8]);
    FUN_800b9448__5MuMsgFUlb(MSG, 3, true);
    FUN_800b9460__5MuMsgFUlUcUcUcf(MSG, 3, 0, 0, 0, ro[9]);
    MSG->setAlignMode(3, MuMsg::Align_Center);
    MSG->setFontColor(3, 0xd2, 0xb2, 0xb2, 0xff);
    fn_800B9488(MSG, 3, 1);
    sprintf(buffer, lbl_21_data_150, *(int*)(self + 0x64));
    MSG->printf(3, buffer);

    MSG->attachScnMdlSimple(4, MODEL, 4, ro[6]);
    MSG->setHScale(4, ro[7]);
    MSG->getHScale(4, ro[7]);
    MSG->setAlignMode(4, MuMsg::Align_Center);
    fn_800B93DC(MSG, 4, 1);
    MSG->setFontColor(4, 0xd0, 0xde, 0xe7, 0xff);
    MSG->printIndex(4, 2, 0);

    MSG->attachScnMdlSimple(5, MODEL, 5, ro[6]);
    MSG->getHScale(5, ro[8]);
    FUN_800b9448__5MuMsgFUlb(MSG, 5, true);
    FUN_800b9460__5MuMsgFUlUcUcUcf(MSG, 5, 0, 0, 0, ro[9]);
    MSG->setAlignMode(5, MuMsg::Align_Center);
    MSG->setFontColor(5, 0xd2, 0xb2, 0xb2, 0xff);
    fn_800B9488(MSG, 5, 1);
    sprintf(buffer, lbl_21_data_150, *(int*)(self + 0x68));
    MSG->printf(5, buffer);

    MSG->attachScnMdlSimple(6, MODEL, 6, ro[6]);
    MSG->getHScale(6, ro[10]);
    MSG->setAlignMode(6, MuMsg::Align_Right);
    MSG->setFontColor(6, 0x6b, 0x58, 0, 0xff);
    fn_800B9488(MSG, 6, 1);
    sprintf(buffer, lbl_21_data_150, *(int*)(self + 0x6c));
    MSG->printf(6, buffer);
}

#undef MODEL
#undef MSG
