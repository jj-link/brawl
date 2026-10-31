#include <types.h>
#pragma force_active on
#pragma optimization_level 2
#pragma use_lmw_stmw on

struct SoHeapAllocator {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void* alloc(u32 size, s32 type);
};

extern SoHeapAllocator* lbl_805A0EB8;
extern "C" char lbl_80486F38[];

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

extern "C" void __ct__14Class_802C0D2CFiiii(void*, int, int, int, int);

struct Vtable_Class_802C0D2C {
    void* vtable;
    Vtable_Class_802C0D2C() {}
};

class Class_802C0D2C : public Vtable_Class_802C0D2C,
                       public Class_802A1FD4 {
public:
    Class_802C0D2C(int a, int b, int c, int d) {
        __ct__14Class_802C0D2CFiiii(this, b, a, c, d);
        vtable = lbl_80486F38;
    }
    char pad[0x34];
};

extern "C" Class_802C0D2C* fn_802C0B80(
    int arg0, int arg1, int arg2, int arg3) {
    return new Class_802C0D2C(arg0, arg1, arg2, arg3);
}
