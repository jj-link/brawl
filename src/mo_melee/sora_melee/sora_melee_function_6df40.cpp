#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_6F30C(void*);

struct InnerObj {
    virtual void unused();
    virtual void* get();
};

struct VObj {
    virtual u32 get();
};

struct Outer {
    char pad[0x48];
    InnerObj* inner;
};

extern "C" u32 fn_27_6DF40(Outer* self) {
    InnerObj* inner = self->inner;
    char* ptr = (char*)inner->get();
    u32 r = fn_27_6F30C((void*)(ptr + 0x1c));
    char* a = (char*)(*(u32*)(r + 0x44));
    char* b = (char*)(*(u32*)(a + 0xd8));
    char* c = (char*)(*(u32*)(b + 0x10));
    VObj* v = (VObj*)c;
    u32 result = v->get();
    return (result == 0);
}
