#include <types.h>
#pragma force_active on

struct SoObjEC8 {
    void* vtable;
    u32 m_04;
    u32 m_08;
    u32 m_0C;
    u32 m_10;
    u32 m_14;
    u32 m_18;
};

class Iface {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};

class SoHeapAllocator {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f(void* ptr, u32 size, s32 align);
};

extern SoObjEC8* lbl_805A0EC8;
extern SoHeapAllocator* lbl_805A0EB8;

extern "C" void* dtor_802B0C7C(void* arg0, s32 arg1) {
    if (arg0) {
        u32 val = *(u32*)arg0;
        SoObjEC8* obj = lbl_805A0EC8;
        obj->m_10 = val;
        if (val == obj->m_18) {
            ((Iface*)obj)->e();
        }
        if (arg1 > 0) {
            lbl_805A0EB8->f(arg0, 8, 0x15);
        }
    }
    return arg0;
}
