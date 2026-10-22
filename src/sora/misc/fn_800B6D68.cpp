#include <types.h>
#pragma force_active on

struct Vec {
    float x, y, z;
};

struct SrcBig {
    u32 flags;
    Vec v;
    char pad[0x40];
};

extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(void* self, const char* name);
extern "C" void fn_801956CC(SrcBig* src, Vec* dst);

struct Res {
    char pad[0xc];
    void* obj;   // 0xc
};

struct Obj14 {
    char pad[0xc];
    void* virt;   // 0xc
};

struct Arg1 {
    char pad[0x10];
    void* ptr10;   // 0x10
    Obj14* ptr14;  // 0x14
};

struct Big10 {
    char pad[0xe8];
    void* res;  // 0xe8
};

class Virt {
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
    virtual void m12(SrcBig* out, void* val);
};

extern "C" void fn_800B6D68(Vec* arg0, Arg1* arg1, const char* name) {
    Big10* b = (Big10*)arg1->ptr10;
    void* sp8 = b->res;
    Res* res = (Res*)GetResNode__Q34nw4r3g3d6ResMdlCFPCc(&sp8, name);
    SrcBig sp18;
    Vec spC;
    Virt* virt = (Virt*)(((Obj14*)arg1->ptr14)->virt);
    void* val = (res != 0) ? res->obj : 0;
    virt->m12(&sp18, val);
    fn_801956CC(&sp18, &spC);
    arg0->x = spC.x;
    arg0->y = spC.y;
    arg0->z = spC.z;
}
