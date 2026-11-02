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

extern "C" void __ct__14Class_802BAEB8Fiiii(void* self, int a, int b, int c, int d);

class Class_802A1FD4 {
public:
    static void operator delete(void* p);
    static void* operator new(u32 size) {
        void* p = lbl_805A0EB8->alloc(0x38, 0x1d);
        ((u16*)p)[2] = 0x38;
        return p;
    }
};

class Class_802A0DC4 {
public:
    Class_802A0DC4() {}
    ~Class_802A0DC4() {}
};

extern "C" char lbl_80486DEC[];

struct Vtable_Class_802BAEB8 {
    void* vtable;
    Vtable_Class_802BAEB8() : vtable(lbl_80486DEC) {}
};

class Class_802BAE28 {
public:
    Class_802BAE28() {}
    ~Class_802BAE28() {}
};

class Class_802BAEB8 : public Vtable_Class_802BAEB8, public Class_802A1FD4, public Class_802A0DC4 {
public:
    Class_802BAEB8(int, int, int, int);
    Class_802BAE28 m_C;
    unsigned char pad[0x30];
};

extern "C" void* fn_802BAC90(int arg0, int arg1, int arg2, int arg3) {
    Class_802BAEB8* object0 = new Class_802BAEB8(arg0, arg1, arg2, arg3);
    return object0;
}
