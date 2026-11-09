#include <mu/mu_msg.h>
#pragma force_active on
struct Inner { char pad[0x10]; nw4r::g3d::ScnMdlSimple* model; };
struct Self { char pad[0x40]; Inner* inner; char pad2[4]; MuMsg* msg; void* data; };
extern "C" {
extern float lbl_805A22B4;
extern float lbl_805A22B8;
MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(unsigned long, HeapType, unsigned long);
void fn_800B9488(MuMsg*, unsigned long, unsigned long);
void fn_8006B660(void*, int, int);
void fn_800BF4BC(Self* self, HeapType heap, unsigned long heap2, int flag, int special) {
    Inner* p;
    MuMsg* msg;
    unsigned long type;
    unsigned long font;
    if (flag) { font = 8; type = 4; } else { font = 1; type = 0; }
    msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(font, heap, heap2);
    self->msg = msg;
    msg->allocMsgBuf(0x200, 6);
    msg->setMsgData(self->data);
    p = self->inner;
    msg->attachScnMdlSimple(0, p->model, 0, lbl_805A22B4);
    msg->getWScale(0, lbl_805A22B8);
    msg->setFontColor(0, 0, 0, 0, 255);
    fn_800B9488(msg, 0, type);
    if (special) fn_8006B660(*(void**)((char*)msg + 8), 0, 7);
    msg->attachScnMdlSimple(1, p->model, 1, lbl_805A22B4);
    msg->getWScale(1, lbl_805A22B8);
    msg->setFontColor(1, 0, 0, 0, 255);
    fn_800B9488(msg, 1, type);
    if (special) fn_8006B660(*(void**)((char*)msg + 8), 1, 7);
    msg->attachScnMdlSimple(2, p->model, 2, lbl_805A22B4);
    msg->setFontColor(2, 0, 0, 0, 255);
    fn_800B9488(msg, 2, type);
    if (special) fn_8006B660(*(void**)((char*)msg + 8), 2, 7);
    msg->attachScnMdlSimple(3, p->model, 3, lbl_805A22B4);
    msg->setFontColor(3, 0, 0, 0, 255);
    fn_800B9488(msg, 3, type);
    if (special) fn_8006B660(*(void**)((char*)msg + 8), 3, 7);
    msg->attachScnMdlSimple(4, p->model, 5, lbl_805A22B4);
    msg->setFontColor(4, 0, 0, 0, 255);
    fn_800B9488(msg, 4, type);
    if (special) fn_8006B660(*(void**)((char*)msg + 8), 4, 7);
    msg->attachScnMdlSimple(5, p->model, 4, lbl_805A22B4);
    msg->setFontColor(5, 0, 0, 0, 255);
    fn_800B9488(msg, 5, type);
    if (special) fn_8006B660(*(void**)((char*)msg + 8), 5, 7);
}
}