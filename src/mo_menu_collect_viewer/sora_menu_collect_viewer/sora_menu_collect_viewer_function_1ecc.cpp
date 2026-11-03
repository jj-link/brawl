#pragma force_active on
#include <mu/mu_msg.h>
#include <gf/gf_file_io_handle.h>
extern "C" {
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void FUN_800b9448__5MuMsgFUlb(void*, u32, bool);
void FUN_800b9460__5MuMsgFUlUcUcUcf(void*, u32, u8, u8, u8, float);
}
struct ViewerModel {
    char pad[0x10];
    nw4r::g3d::ScnMdlSimple* mdl;
};
struct ViewerData {
    char pad0[0x108];
    ViewerModel* a;
    ViewerModel* b;
    char pad1[0x11c - 0x110];
    ViewerModel* c;
    char pad2[0x1c7c - 0x120];
    MuMsg* msg;
    char pad3[0x1c90 - 0x1c80];
    gfFileIOHandle handle;
};
struct ViewerObj {
    char pad[0x1ac];
    ViewerData* data;
};
extern "C" void fn_6_1ECC(ViewerObj* self, u32 flags) {
    self->data->msg = (MuMsg*)create__5MuMsgFUlQ25Heaps8HeapTypeUl(flags, 0x2a, 0x2b);
    self->data->msg->allocMsgBuf(0x100, 0x16);
    self->data->msg->setMsgData(self->data->handle.getBuffer());

    ViewerModel* a = self->data->a;
    self->data->msg->attachScnMdlSimple(0, a->mdl, 0, 0.0625f);
    self->data->msg->setFontColor(0, 0xED, 0xED, 0xED, 0xFF);
    self->data->msg->attachScnMdlSimple(1, a->mdl, 1, 0.0625f);
    self->data->msg->setFontColor(1, 0, 0, 0, 0xFF);
    self->data->msg->attachScnMdlSimple(2, a->mdl, 0xA, 0.0625f);
    self->data->msg->setFontColor(2, 0xFF, 0xFF, 0xFF, 0xFF);

    ViewerModel* b;
    for (int i = 0; i < 7; i++) {
        u32 id = i + 3;
        self->data->msg->attachScnMdlSimple(id, a->mdl, i + 2, 0.0625f);
        self->data->msg->setFontColor(id, 0xB7, 0xB7, 0xB7, 0xFF);
        FUN_800b9448__5MuMsgFUlb(self->data->msg, id, true);
        FUN_800b9460__5MuMsgFUlUcUcUcf(self->data->msg, id, 0x20, 0x20, 0x20, 3.0f);
    }

    self->data->msg->attachScnMdlSimple(0xB, a->mdl, 9, 0.0625f);
    self->data->msg->setFontColor(0xB, 0x4D, 0x4D, 0x4D, 0xFF);

    b = self->data->b;
    self->data->msg->attachScnMdlSimple(0xC, b->mdl, 0, 0.0625f);
    self->data->msg->setFontColor(0xC, 0x4F, 0x1E, 0x20, 0xFF);
    self->data->msg->attachScnMdlSimple(0xD, b->mdl, 1, 0.0625f);
    self->data->msg->attachScnMdlSimple(0xE, b->mdl, 2, 0.0625f);
    self->data->msg->attachScnMdlSimple(0xF, b->mdl, 3, 0.0625f);
    self->data->msg->setFontColor(0xF, 0x4F, 0x1E, 0x20, 0xFF);

    self->data->msg->attachScnMdlSimple(0x10, self->data->c->mdl, 0, 0.0625f);
    self->data->msg->setFontColor(0x10, 0, 0, 0, 0xFF);
}
