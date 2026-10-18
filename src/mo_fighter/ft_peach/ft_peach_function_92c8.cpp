#include <types.h>
#pragma force_active on

class PeachObj {
public:
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual PeachObj* method6(s32 a, void* b, void* c);
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual void pad17();
    virtual void pad18();
    virtual PeachObj* method19(u32 a);
};

struct PeachInner {
    u8 pad[0x64];
    PeachObj* target;
};

struct PeachContainer {
    u8 pad[0xd8];
    PeachInner* inner;
};

extern "C" {
PeachObj* fn_103_9190(PeachObj* self);
void* fn_27_131CD0(void*, s32, void*, void*);

void fn_103_92C8(PeachObj* self, s32 type, void* a3, void* a4) {
    PeachObj* obj = self;
    if (type != 2 && type != 1) {
        PeachContainer* container = (PeachContainer*)a4;
        PeachInner* inner = (PeachInner*)container->inner;
        obj = inner->target;
        obj = obj->method19(0x1200003e);
    }
    obj = fn_103_9190(obj);
    obj->method6(type, a3, a4);
    fn_27_131CD0(self, type, a3, a4);
}
}
