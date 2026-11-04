#include <types.h>
#pragma force_active on

class Serializer {
public:
    virtual void v0();
    virtual void v1(int a, int b, void* c);
    virtual void v2(char* name, int size, void* p, u32 count, u32 flag);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

struct Inner {
    u16 pad0;
    u16 count;
};

struct Arg0 {
    char pad0[0x1c];
    void* f1c;
    u32 f20;
    u32 f24;
    char pad28[0x14];
    Inner* f3c;
};

extern char lbl_80411050[];

extern "C" void fn_802D9350(void* arg0, void* arg1) {
    Serializer* obj = (Serializer*)arg1;
    Arg0* a = (Arg0*)arg0;
    obj->v1(0, 8, arg0);
    obj->v2(lbl_80411050, 8, a->f3c, a->f3c->count, 0);
    u32 f = a->f24;
    char* name = lbl_80411050 + 0xC;
    if (!(f & 0x80000000)) {
        obj->v2(name, 8, a->f1c, a->f20, f & 0x3FFFFFFF);
    }
    obj->v6();
}
