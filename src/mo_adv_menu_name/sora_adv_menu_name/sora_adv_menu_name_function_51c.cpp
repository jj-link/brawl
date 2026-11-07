#include <mu/mu_msg.h>
#include <gf/gf_file_io_handle.h>
#pragma force_active on

struct ModelHolder {
    char pad[0x10];
    nw4r::g3d::ScnMdlSimple* model;
};
struct State {
    char pad[0x12c];
    MuMsg* msg;
    char pad130[4];
    ModelHolder* m134;
    ModelHolder* m138;
    ModelHolder* m13c;
    ModelHolder* m140;
    char pad144[4];
    ModelHolder* m148;
    char pad14c[0x1f8];
    gfFileIOHandle handle;
};
extern "C" {
MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(unsigned long, HeapType, unsigned long);
extern float lbl_28_rodata_84;
extern float lbl_28_rodata_88;
void fn_28_51C(State* self) {
    self->msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(3, (HeapType)42, 43);
    self->msg->allocMsgBuf(0x100, 15);
    self->msg->setMsgData(self->handle.getBuffer());
    self->msg->attachScnMdlSimple(12, self->m148->model, 0, lbl_28_rodata_84);
    self->msg->setAlignMode(12, MuMsg::Align_Center);
    self->msg->setFontColor(12, 0, 0, 0, 255);
    self->msg->attachScnMdlSimple(13, self->m148->model, 1, lbl_28_rodata_88);
    self->msg->setFontColor(13, 0, 0, 0, 255);
    self->msg->attachScnMdlSimple(0, self->m140->model, 0, lbl_28_rodata_84);
    self->msg->setFontColor(0, 255, 0, 0, 255);
    self->msg->attachScnMdlSimple(1, self->m140->model, 1, lbl_28_rodata_84);
    self->msg->setFontColor(1, 0, 0, 0, 255);
    self->msg->attachScnMdlSimple(2, self->m140->model, 2, lbl_28_rodata_84);
    self->msg->setFontColor(2, 0, 0, 0, 255);
    self->msg->attachScnMdlSimple(3, self->m140->model, 3, lbl_28_rodata_84);
    self->msg->setFontColor(3, 0, 0, 0, 255);
    self->msg->attachScnMdlSimple(4, self->m140->model, 4, lbl_28_rodata_84);
    self->msg->setFontColor(4, 0, 0, 0, 255);
    self->msg->attachScnMdlSimple(5, self->m13c->model, 0, lbl_28_rodata_84);
    self->msg->setFontColor(5, 0, 0, 255, 255);
    self->msg->attachScnMdlSimple(6, self->m13c->model, 1, lbl_28_rodata_84);
    self->msg->setFontColor(6, 0, 0, 0, 255);
    self->msg->attachScnMdlSimple(7, self->m13c->model, 2, lbl_28_rodata_84);
    self->msg->setFontColor(7, 0, 0, 0, 255);
    self->msg->attachScnMdlSimple(8, self->m13c->model, 3, lbl_28_rodata_84);
    self->msg->setFontColor(8, 0, 0, 0, 255);
    self->msg->attachScnMdlSimple(9, self->m13c->model, 4, lbl_28_rodata_84);
    self->msg->setFontColor(9, 0, 0, 0, 255);
    self->msg->attachScnMdlSimple(10, self->m138->model, 0, lbl_28_rodata_84);
    self->msg->attachScnMdlSimple(11, self->m134->model, 0, lbl_28_rodata_84);
}
}