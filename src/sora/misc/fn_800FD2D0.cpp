#pragma force_active on
#include <mu/mu_object.h>
#include <mu/mu_msg.h>

struct Lbl2708 {
    const char* name;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
};

extern Lbl2708 lbl_805A2708;
extern const char lbl_8059E4F0[6];
extern const float lbl_805A2710;

extern "C" {
int sprintf(char* s, const char* format, ...);
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void fn_800B9488(void*, u32, u32);
void fn_8006B660(void*, int, int);
}

extern "C" void fn_800FD2D0(void* arg0, nw4r::g3d::ResFile* arg1, s32 arg2) {
    char buf[0x40];
    s32 count;
    MuMsg* msg;
    s32 i;
    u32 cfgAddr;

    cfgAddr = (u32)&lbl_805A2708;
    count = 1;
    if (((Lbl2708*)cfgAddr)->unk4 < ((Lbl2708*)cfgAddr)->unk5) {
        count = ((Lbl2708*)cfgAddr)->unk5 - ((Lbl2708*)cfgAddr)->unk4;
    }
    sprintf(buf, lbl_8059E4F0, ((Lbl2708*)cfgAddr)->name);
    for (i = 0; i < count; i++) {
        ((MuObject**)arg0)[((Lbl2708*)cfgAddr)->unk4 + i] = MuObject::create(arg1, ((Lbl2708*)cfgAddr)->name, ((Lbl2708*)cfgAddr)->unk6, 0, (HeapType)0x28);
        ((MuObject**)arg0)[((Lbl2708*)cfgAddr)->unk4 + i]->changeAnimN(buf);
    }
    ((s32*)arg0)[2] = arg2;
    msg = (MuMsg*)create__5MuMsgFUlQ25Heaps8HeapTypeUl(8, 0x28, 0x2A);
    ((MuMsg**)arg0)[1] = msg;
    msg->allocMsgBuf(0x100, 2);
    msg->attachScnMdlSimple(0, (nw4r::g3d::ScnMdlSimple*)((MuObject**)arg0)[0]->m_sceneModel, 0, lbl_805A2710);
    msg->setFontColor(0, 0xF0, 0xF0, 0xF0, 0xFF);
    fn_800B9488(msg, 0, 4);
    fn_8006B660(((void**)msg)[2], 0, 7);
    msg->attachScnMdlSimple(1, (nw4r::g3d::ScnMdlSimple*)((MuObject**)arg0)[0]->m_sceneModel, 1, lbl_805A2710);
    fn_800B9488(msg, 1, 4);
    fn_8006B660(((void**)msg)[2], 1, 7);
}
