#include <types.h>
#include <mu/mu_msg.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#pragma force_active on

struct CollectViewer {
    char pad00[0x40];
    MuObject* objects[12];
    char pad70[8];
    MuMsg* msg;
};

extern "C" {
extern const float lbl_6_rodata_6E8[];
MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, HeapType, u32);
void fn_800B9428(MuMsg*, u32, float);
void fn_800B9488(MuMsg*, u32, u32);
}

extern "C" void fn_6_AC44(CollectViewer* self, void* data, HeapType heap, u32 heap2) {
    const float* const ro = lbl_6_rodata_6E8;
    MuObject* obj;
    MuMsg* msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(3, heap, heap2);
    self->msg = msg;
    msg->allocMsgBuf(0x100, 5);
    msg->setMsgData(data);

    obj = self->objects[0];
    msg->attachScnMdlSimple(0, obj->m_sceneModel, 0, ro[0x74 / 4]);
    msg->setAlignMode(0, MuMsg::Align_Left);
    msg->setFontColor(0, 0, 0, 0, 0xff);
    fn_800B9428(msg, 0, ro[0x78 / 4]);
    fn_800B9488(msg, 0, 1);

    msg->attachScnMdlSimple(1, obj->m_sceneModel, 1, ro[0x74 / 4]);
    msg->setAlignMode(1, MuMsg::Align_Left);
    msg->setFontColor(1, 0, 0, 0, 0xff);
    fn_800B9428(msg, 1, ro[0x78 / 4]);
    fn_800B9488(msg, 1, 1);

    msg->attachScnMdlSimple(2, obj->m_sceneModel, 2, ro[0x74 / 4]);
    msg->printIndex(2, 4);
    msg->attachScnMdlSimple(3, obj->m_sceneModel, 3, ro[0x74 / 4]);
    msg->printIndex(3, 5);

    msg->attachScnMdlSimple(4, self->objects[3]->m_sceneModel, 0, ro[0x74 / 4]);
    fn_800B9488(msg, 4, 1);
    msg->setAlignMode(4, MuMsg::Align_Left);
    fn_800B9428(msg, 4, ro[0x7c / 4]);
}
