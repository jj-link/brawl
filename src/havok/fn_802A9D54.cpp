#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void* alloc(s32 size, s32 align);
};

extern SoHeapAllocator* lbl_805A0EB8;
extern "C" char lbl_804868E8[];

extern "C" void __ct__14Class_802A99B0Fiiii(void*, int, int, int, int);

class Class_802A1FD4 {
public:
    static void operator delete(void* p);
    static void* operator new(u32 size) {
        void* p = lbl_805A0EB8->alloc(size, 0x1d);
        ((u16*)p)[2] = size;
        return p;
    }
};

class Class_802A0DC4 {
public:
    Class_802A0DC4() {}
    ~Class_802A0DC4() {}
};

class Class_802A9A5C {
public:
    u32 m_00;
};

class Class_802A99B0 : public Class_802A1FD4 {
public:
    void* vtable;
    u16 m_04;
    u8 pad[0x28];

    Class_802A99B0(int a, int b, int c, int d) {
        __ct__14Class_802A99B0Fiiii(this, b, a, c, d);
        vtable = lbl_804868E8;
    }

    Class_802A9A5C m_30;
    u8 pad_34[0xC];

    static void* operator new(u32 size) {
        Class_802A99B0* p = (Class_802A99B0*)lbl_805A0EB8->alloc(size, 0x1d);
        p->m_04 = size;
        return p;
    }
};

extern "C" Class_802A99B0* fn_802A9D54(
    int arg0, int arg1, int arg2, int arg3) {
    Class_802A99B0* object0 = new Class_802A99B0(arg0, arg1, arg2, arg3);
    return object0;
}
