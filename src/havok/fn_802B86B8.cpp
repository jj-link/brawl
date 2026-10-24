#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void* alloc(u32 size, s32 type);
};

extern SoHeapAllocator* lbl_805A0EB8;

class Class_802A1FD4 {
public:
    static void operator delete(void* p);
};

extern "C" char lbl_80486A30[];

extern "C" void __ct__14Class_802B87B8Fiiii(void*, int, int, int, int);

class Class_802B87B8 : public Class_802A1FD4 {
public:
    void* m_00;
    u16 m_04;
    u8 pad[0x1A];

    Class_802B87B8(int a, int b, int c, int d) {
        __ct__14Class_802B87B8Fiiii(this, b, a, c, d);
        m_00 = lbl_80486A30;
    }

    static void* operator new(u32 size) {
        Class_802B87B8* p = (Class_802B87B8*)lbl_805A0EB8->alloc(size, 0x1d);
        p->m_04 = size;
        return p;
    }
};

extern "C" Class_802B87B8* fn_802B86B8(int arg0, int arg1, int arg2, int arg3) {
    Class_802B87B8* object0 = new Class_802B87B8(arg0, arg1, arg2, arg3);
    return object0;
}
