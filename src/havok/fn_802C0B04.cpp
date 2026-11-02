#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void* alloc(int size, int align);
};

extern SoHeapAllocator* lbl_805A0EB8;
extern "C" void __ct__14Class_802C0D2CFiiii(void* self, int a, int b, int c, int d);

class Class_802A1FD4 {
public:
    static void operator delete(void* p);
    static void* operator new(u32 size) {
        void* p = lbl_805A0EB8->alloc(0x38, 0x1d);
        ((u16*)p)[2] = 0x38;
        return p;
    }
};

class Class_802C0D2C : public Class_802A1FD4 {
public:
    void* m_00;
    u16 m_04;
    char pad[0x32];

    Class_802C0D2C(int a, int b, int c, int d) {
        __ct__14Class_802C0D2CFiiii(this, a, b, c, d);
    }
};

extern "C" Class_802C0D2C* fn_802C0B04(int arg0, int arg1, int arg2, int arg3) {
    Class_802C0D2C* object0 = new Class_802C0D2C(arg0, arg1, arg2, arg3);
    return object0;
}
