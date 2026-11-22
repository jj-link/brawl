#include <mu/mu_msg.h>
#pragma force_active on

extern "C" {
MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(unsigned long, HeapType, unsigned long);
extern const float lbl_11_rodata_18;
extern const float lbl_11_rodata_1C;
}

struct Obj {
    char pad[0x10];
    nw4r::g3d::ScnMdlSimple* mdl;
};

struct Self {
    char pad[0x80];
    Obj* a;
    char pad2[0x1c8 - 0x84];
    Obj* b[7];
    char pad3[0x6064 - 0x1e4];
    MuMsg* msg;
};

extern "C" void fn_11_C10(Self* self) {
    Obj* obj;
    unsigned long id1, id2, id3, id4;
    MuMsg* msg;
    int i;
    msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, (HeapType)42, 43);
    self->msg = msg;
    msg->allocMsgBuf(0x100, 0x1d);
    msg->attachScnMdlSimple(0, self->a->mdl, 0, lbl_11_rodata_18);
    msg->setFontColor(0, 255, 255, 255, 255);
    msg->setAlignMode(0, MuMsg::Align_Center);

    i = 0;
    while (i < 7) {
        obj = self->b[i];

        id1 = i + 1;
        msg->attachScnMdlSimple(id1, obj->mdl, 0, lbl_11_rodata_18);
        msg->setFontColor(id1, 0x71, 0x6b, 0x6c, 255);
        msg->setAlignMode(id1, MuMsg::Align_Left);
        msg->setHScale(id1, lbl_11_rodata_1C);
        msg->getHScale(id1, lbl_11_rodata_1C);

        id2 = i + 8;
        msg->attachScnMdlSimple(id2, obj->mdl, 1, lbl_11_rodata_18);
        msg->setFontColor(id2, 0x71, 0x6b, 0x6c, 255);
        msg->setAlignMode(id2, MuMsg::Align_Left);
        msg->setHScale(id2, lbl_11_rodata_1C);
        msg->getHScale(id2, lbl_11_rodata_1C);

        id3 = i + 15;
        msg->attachScnMdlSimple(id3, obj->mdl, 2, lbl_11_rodata_18);
        msg->setFontColor(id3, 0x71, 0x6b, 0x6c, 255);
        msg->setAlignMode(id3, MuMsg::Align_Left);
        msg->setHScale(id3, lbl_11_rodata_1C);
        msg->getHScale(id3, lbl_11_rodata_1C);

        id4 = i + 22;
        msg->attachScnMdlSimple(id4, obj->mdl, 3, lbl_11_rodata_18);
        msg->setFontColor(id4, 10, 6, 7, 255);
        msg->setAlignMode(id4, MuMsg::Align_Left);
        i++;
    }
}
