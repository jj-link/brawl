#include <types.h>
#pragma force_active on

class Alloc {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(void* p, s32 a, s32 b);
};

class EcMgr {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    u32 pad[3];
    u32 unk10;
    u32 unk14;
    u32 unk18;
};

extern EcMgr* lbl_805A0EC8;
extern Alloc* lbl_805A0EB8;

class Class_8028050C {
public:
    ~Class_8028050C();
    void operator delete(void* p) { lbl_805A0EB8->v5(p, 8, 0x15); }
    u32 unk0;
};

Class_8028050C::~Class_8028050C() {
    u32 val = unk0;
    EcMgr* obj = lbl_805A0EC8;
    obj->unk10 = val;
    if (val == obj->unk18) {
        obj->v4();
    }
}
