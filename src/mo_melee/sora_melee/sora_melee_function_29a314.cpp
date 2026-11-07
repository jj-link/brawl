#include <types.h>
#pragma force_active on

struct ItMgr {
    char pad[0x14B8];
    u32 field14B8;
};

extern "C" ItMgr* getInstance__9itManagerFv();
extern "C" int fn_27_2C0E10(u32 mgr, u32 id);
extern "C" void fn_27_2C12F4(u32 a, u32 b, u32 c);

class VObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual int v17(u32 id, void* owner);
};

struct Mid {
    char pad[0x64];
    VObj* obj;
};

struct Ent {
    char pad[0xD8];
    Mid* mid;
};

struct Self {
    char pad0[0x60];
    Ent* ent;
    char pad1[0x8C4 - 0x64];
    u32 id;
};

extern "C" void fn_27_29A314(void* unused, Self* arg) {
    u32 r30;
    u32 r29 = getInstance__9itManagerFv()->field14B8;
    r30 = arg->id;
    u32 var = (fn_27_2C0E10(getInstance__9itManagerFv()->field14B8, r30) != 0) ? r30 : 1;
    Ent* e = arg->ent;
    VObj* o = e->mid->obj;
    if (o->v17(0x12000003, e) != 0) {
        fn_27_2C12F4(r29, var, 1);
    }
}
