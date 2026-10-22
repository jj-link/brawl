#include <types.h>
#pragma force_active on

class MuMsg;
class MuObject;

extern "C" void printIndex__5MuMsgFUlUlPv(void* msg, u32 a, u32 b, void* c);
extern "C" void setFrameNode__8MuObjectFf(void* obj, f32 frame);

extern f32 lbl_805A2714;
extern f32 lbl_805A2718;

class MuSub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setFrame(f32 frame);
};

struct MuObjectHolder {
    u8 pad[0xC];
    MuSub* sub;
};

struct MuObject {
    u8 pad0[0x14];
    MuObjectHolder* holder;
};

struct MuMsgOwner {
    void* unk0;
    void* msg;
    void* unk8;
    u32 unkC;
};

extern "C" void fn_800FD470(MuMsgOwner* self, u32 arg) {
    printIndex__5MuMsgFUlUlPv(self->msg, 0, arg, self->unk8);
    MuObject* obj = (MuObject*)self->unk0;
    setFrameNode__8MuObjectFf(obj, lbl_805A2714);
    obj->holder->sub->setFrame(lbl_805A2718);
    self->unkC = arg;
}
