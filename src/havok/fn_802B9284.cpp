#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on

extern "C" void __ct__14Class_802B8F44Fiiii(void* self, void* a, void* b, void* c, void* d);

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void* alloc(s32 size, s32 align);
};

extern SoHeapAllocator* lbl_805A0EB8;

class Class_802A0DA4 {
public:
    static void operator delete(void* p);
};

class Class_802B8F44 : public Class_802A0DA4 {
public:
    void* m_00;
    u16 m_04;
    u8 pad[0x18];

    Class_802B8F44(void* a, void* b, void* c, void* d) {
        __ct__14Class_802B8F44Fiiii(this, a, b, c, d);
    }

    static void* operator new(u32 size) {
        Class_802B8F44* p = (Class_802B8F44*)lbl_805A0EB8->alloc(size, 0x1d);
        p->m_04 = size;
        return p;
    }
};

extern "C" Class_802B8F44* fn_802B9284(void* arg0, void* arg1, void* arg2, void* arg3) {
    Class_802B8F44* object0 = new Class_802B8F44(arg0, arg1, arg2, arg3);
    return object0;
}
