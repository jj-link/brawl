#include <types.h>
#pragma force_active on

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void* alloc(int size, int align);
};

extern SoHeapAllocator* lbl_805A0EB8;

class Class_802A0DA4 {
public:
    static void operator delete(void* p);
};

extern "C" char lbl_80486BA8[];
extern "C" void __ct__14Class_802AF338Fiii(void* self, int a, int b, int c);
extern "C" void __ct__14Class_802B193CFiii(void* self, int a, int b, int c);

class Class_802AF338 : public Class_802A0DA4 {
    void* vtable;
    char padding[0x7c];
public:
    Class_802AF338(int a, int b, int c) {
        __ct__14Class_802AF338Fiii(this, a, b, c);
        vtable = lbl_80486BA8;
    }
    static void* operator new(u32 size) {
        Class_802AF338* p = (Class_802AF338*)lbl_805A0EB8->alloc(0x80, 0x1d);
        ((u16*)p)[2] = 0x80;
        return p;
    }
};

class Class_802B193C : public Class_802A0DA4 {
    void* vtable;
    char padding[0x2c];
public:
    Class_802B193C(int a, int b, int c) {
        __ct__14Class_802B193CFiii(this, a, b, c);
    }
    static void* operator new(u32 size) {
        Class_802B193C* p = (Class_802B193C*)lbl_805A0EB8->alloc(0x30, 0x1d);
        ((u16*)p)[2] = 0x30;
        return p;
    }
};

extern "C" void* fn_802B3700(int a, int b, int unused, int c) {
    if (c) {
        return new Class_802AF338(a, b, c);
    }
    return new Class_802B193C(a, b, c);
}