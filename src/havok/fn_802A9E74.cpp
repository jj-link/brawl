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

class Class_802A1FD4 {
public:
    static void operator delete(void* p);
};

class Class_802A99B0 : public Class_802A1FD4 {
public:
    Class_802A99B0(int, int, int, int);
    u8 pad[0x40];

    static void* operator new(u32 size) {
        void* p = lbl_805A0EB8->alloc(size, 0x1d);
        *(u16*)((u8*)p + 4) = size;
        return p;
    }
};

extern "C" void* fn_802A9E74(int arg0, int arg1, int arg2, int arg3) {
    Class_802A99B0* result = new Class_802A99B0(arg0, arg1, arg2, arg3);
    return result;
}
