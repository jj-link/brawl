#include <mu/mu_msg.h>
#pragma force_active on

struct Inner {
    char pad[0x10];
    nw4r::g3d::ScnMdlSimple* model;
};

struct Self {
    char pad[0x40];
    Inner* inner;
    char pad2[0x0c];
    MuMsg* msg;
};

extern "C" {
extern const float lbl_12_rodata_0[];

MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(
    unsigned long, unsigned long, unsigned long);
void fn_800B9488(MuMsg*, unsigned long, unsigned long);
void fn_800B9428(MuMsg*, unsigned long, float);
void FUN_800b9448__5MuMsgFUlb(MuMsg*, unsigned long, bool);
void FUN_800b9460__5MuMsgFUlUcUcUcf(
    MuMsg*, unsigned long, unsigned char, unsigned char, unsigned char, float);

void fn_12_34C(Self* self, void* data) {
    const float* const ro = lbl_12_rodata_0;
    Inner* p;
    MuMsg* msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(3, 0x2a, 0x2b);
    self->msg = msg;
    msg->setMsgData(data);
    msg->allocMsgBuf(0x100, 4);

    p = self->inner;

    msg->attachScnMdlSimple(0, p->model, 0, ro[0x44 / 4]);
    fn_800B9488(msg, 0, 1);
    msg->setFontColor(0, 0xff, 0x76, 0x76, 0xff);
    msg->setAlignMode(0, MuMsg::Align_Right);
    msg->getHScale(0, ro[0x48 / 4]);
    fn_800B9428(msg, 0, ro[0x4c / 4]);

    msg->attachScnMdlSimple(1, p->model, 1, ro[0x44 / 4]);
    fn_800B9488(msg, 1, 1);
    msg->setFontColor(1, 0x9d, 0x9e, 0xa7, 0xff);
    msg->setAlignMode(1, MuMsg::Align_Right);
    msg->getHScale(1, ro[0x48 / 4]);
    fn_800B9428(msg, 1, ro[0x4c / 4]);

    msg->attachScnMdlSimple(2, p->model, 2, ro[0x44 / 4]);
    fn_800B9488(msg, 2, 1);
    msg->setFontColor(2, 0xff, 0x76, 0x76, 0xff);
    msg->setAlignMode(2, MuMsg::Align_Right);
    msg->getHScale(2, ro[0x48 / 4]);
    fn_800B9428(msg, 2, ro[0x4c / 4]);

    msg->attachScnMdlSimple(3, p->model, 3, ro[0x44 / 4]);
    msg->setFontColor(3, 0xff, 0xff, 0xff, 0xff);
    FUN_800b9448__5MuMsgFUlb(msg, 3, true);
    FUN_800b9460__5MuMsgFUlUcUcUcf(msg, 3, 0, 0, 0, ro[0x50 / 4]);
}
}
