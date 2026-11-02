#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on

struct SoHeapAllocator {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void* alloc(u32 size, u32 align);
};

extern SoHeapAllocator* lbl_805A0EB8;
extern "C" char lbl_80486D28[];

class Class_802A0DA4 {
public:
    static void operator delete(void* p);
};

extern "C" void __ct__14Class_802B8F44Fiiii(void*, int, int, int, int);

class Class_802B8F44 : public Class_802A0DA4 {
public:
    void* m_00;
    u16 m_04;
    u8 pad[0x1A];

    static void* operator new(u32 size) {
        Class_802B8F44* p = (Class_802B8F44*)lbl_805A0EB8->alloc(size, 0x1d);
        p->m_04 = size;
        return p;
    }

    Class_802B8F44(int a, int b, int c, int d) {
        __ct__14Class_802B8F44Fiiii(this, b, a, c, d);
        m_00 = lbl_80486D28;
    }
};

extern "C" Class_802B8F44* fn_802B9168(int a, int b, int c, int d) {
    Class_802B8F44* object0 = new Class_802B8F44(a, b, c, d);
    return object0;
}