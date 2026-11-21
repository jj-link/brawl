#include <mu/mu_msg.h>

#pragma force_active on

extern "C" {
extern const float lbl_2_rodata_8F0;
extern const float lbl_2_rodata_8F4[];
MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
}

struct ModelHolder {
    char pad[0x10];
    nw4r::g3d::ScnMdlSimple* model;
};

struct Layout {
    char pad[0x1d4];
    ModelHolder* main;
    ModelHolder* items[7];
};

struct Self {
    char pad[0x64c];
    Layout* layout;
    char pad2[0x680 - 0x650];
    MuMsg* msg;
    void* data;
};

extern "C" void fn_2_1D67C(Self* self) {
    self->msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, 0x2a, 0x2b);
    self->msg->allocMsgBuf(0x100, 0xf);
    self->msg->setMsgData(self->data);

    int next;
    int i;
    for (i = 0; i < 7; i++) {
        int id = i + i;
        next = id + 1;
        self->msg->attachScnMdlSimple(id, self->layout->items[i]->model, 0, lbl_2_rodata_8F0);
        self->msg->setAlignMode(id, MuMsg::Align_Left);
        self->msg->setWScale(id, lbl_2_rodata_8F4[0]);
        self->msg->attachScnMdlSimple(next, self->layout->items[i]->model, 1, lbl_2_rodata_8F0);
        self->msg->setFontColor(next, 0xc4, 0xce, 0xff, 0xff);
    }

    self->msg->attachScnMdlSimple(
        0xe, self->layout->main->model, 0,
        lbl_2_rodata_8F0);
}
