#include <types.h>
#pragma force_active on
class SoHeapAllocator {
public:
    virtual ~SoHeapAllocator();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* alloc(u32 size, s32 align);
};
extern SoHeapAllocator* lbl_805A0EB8;
class Class_802A0DA4 {
public:
    static void operator delete(void* p);
    static void* operator new(size_t size) {
        void* p = lbl_805A0EB8->alloc(size, 0x1d);
        ((s16*)p)[2] = size;
        return p;
    }
};
extern "C" char lbl_80486B68[];
struct Vtable_Class_802AF338 {
    void* vtable;
    Vtable_Class_802AF338() : vtable(lbl_80486B68) {}
};
class Class_802AF338 : public Vtable_Class_802AF338, public Class_802A0DA4 {
public:
    Class_802AF338(int, int, int);
    ~Class_802AF338() {}
    char padding[0x7c];
};
class Class_802A0E20 {
public:
    Class_802A0E20() {}
    ~Class_802A0E20() {}
};
extern "C" char lbl_80486B28[];
struct Vtable_Class_802B193C {
    void* vtable;
    Vtable_Class_802B193C() : vtable(lbl_80486B28) {}
};
class Class_802B193C : public Vtable_Class_802B193C, public Class_802A0E20, public Class_802A0DA4 {
public:
    Class_802B193C(int, int, int);
    char padding[0x2c];
};
extern "C" void* fn_802B28B4(int a, int b, int unused, int c) {
    if (c) {
        return new Class_802AF338(a, b, c);
    }
    return new Class_802B193C(a, b, c);
}