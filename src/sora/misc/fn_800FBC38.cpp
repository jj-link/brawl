#pragma force_active on
#include <mu/mu_object.h>
#include <mu/mu_msg.h>
#include <string.h>

struct Cfg { const char* name; u8 a; u8 b; u8 c; };
extern Cfg lbl_805A26E8;
extern char lbl_8059E4C8;
extern const float lbl_805A26F0;
extern const float lbl_805A26F4;
extern "C" {
MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, HeapType, u32);
void fn_800B9488(void*, u32, u32);
void fn_8006B660(void*, u32, u32);
}
extern "C" void fn_800FBC38(void* arg0, nw4r::g3d::ResFile* arg1, void* arg2) {
    char* self = (char*)arg0;
    char buf[64];
    int count = 1;
    int i;
    MuMsg* msg;
    u32 cfgAddr = (u32)&lbl_805A26E8;
    *(int*)(self + 0) = 0;
    *(void**)(self + 4) = 0;
    *(void**)(self + 8) = 0;
    *(int*)(self + 0xC) = 0;
    *(int*)(self + 0x14) = 0;
    *(int*)(self + 0x18) = 0;
    *(u8*)(self + 0x1C) = 0;
    *(int*)(self + 0x20) = 0;
    if (((Cfg*)cfgAddr)->a < ((Cfg*)cfgAddr)->b) {
        count = ((Cfg*)cfgAddr)->b - ((Cfg*)cfgAddr)->a;
    }
    for (i = 0; i < count; i++) {
        *(MuObject**)(self + (((Cfg*)cfgAddr)->a + i) * 4 + 4) = MuObject::create(arg1, ((Cfg*)cfgAddr)->name, ((Cfg*)cfgAddr)->c, 0, (HeapType)0x2a);
        strcpy(buf, ((Cfg*)cfgAddr)->name);
        strcat(buf, &lbl_8059E4C8);
        (*(MuObject**)(self + (((Cfg*)cfgAddr)->a + i) * 4 + 4))->changeAnimN(buf);
        (*(MuObject**)(self + (((Cfg*)cfgAddr)->a + i) * 4 + 4))->m_modelAnim->setUpdateRate(lbl_805A26F0);
    }
    msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(8, (HeapType)0x2a, 0x2a);
    *(MuMsg**)(self + 8) = msg;
    msg->allocMsgBuf(0x100, 2);
    (*(MuMsg**)(self + 8))->setMsgData(arg2);
    msg->attachScnMdlSimple(0, (nw4r::g3d::ScnMdlSimple*)(*(MuObject**)(self + 4))->m_sceneModel, 0, lbl_805A26F4);
    fn_800B9488(msg, 0, 4);
    fn_8006B660(*(void**)((char*)msg + 8), 0, 7);
    msg->attachScnMdlSimple(1, (nw4r::g3d::ScnMdlSimple*)(*(MuObject**)(self + 4))->m_sceneModel, 1, lbl_805A26F4);
    fn_800B9488(msg, 1, 4);
    fn_8006B660(*(void**)((char*)msg + 8), 1, 7);
}