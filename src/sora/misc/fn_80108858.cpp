#include <types.h>
#pragma force_active on

class MuSub {
public:
    virtual void v0(void);
    virtual void v1(void);
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void v5(void);
    virtual void v6(void);
    virtual void v7(void);
    virtual void v8(float f);
};

class MuObject {
public:
    void changeAnimN(const char* name);
    void setFrameNode(float f);
    void setFrameMatCol(float f);
};

struct MuHolder {
    char pad0[0xc];
    MuSub* a;
    char pad1[0x8];
    MuSub* b;
};

struct MuObj {
    char pad0[0x14];
    MuHolder* h;
};

struct MuSelf {
    char pad0[0x4];
    MuObj* o1;
    MuObj* o2;
};

extern char lbl_8045D170[];
extern char lbl_8045D188[];
extern float lbl_805A27F8;
extern float lbl_805A27FC;

extern "C" void fn_80108858(MuSelf* self, s32 arg1, s32 arg2) {
    MuObject* obj;
    if (arg2 == 0) {
        obj = (MuObject*)self->o1;
    } else {
        obj = (MuObject*)self->o2;
    }
    if (arg1 == 0) {
        obj->changeAnimN(lbl_8045D170);
    } else {
        obj->changeAnimN(lbl_8045D188);
    }
    obj->setFrameNode(lbl_805A27F8);
    ((MuObj*)obj)->h->a->v8(lbl_805A27FC);
    obj->setFrameMatCol(lbl_805A27F8);
    ((MuObj*)obj)->h->b->v8(lbl_805A27FC);
}
