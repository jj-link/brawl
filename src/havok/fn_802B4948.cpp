#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on

struct SoHeapAllocator {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void* alloc(u32 size, u32 type);
};

extern SoHeapAllocator* lbl_805A0EB8;

struct AllocationHeader {
    void* vtable;
    u16 m_04;
};

class Class_802A1FD4 {
public:
    static void operator delete(void* p);
    static void* operator new(unsigned long size) {
        AllocationHeader* p =
            (AllocationHeader*)lbl_805A0EB8->alloc(0x18, 0x1d);
        p->m_04 = 0x18;
        return p;
    }
};

class Class_802A0DC4 {
public:
    Class_802A0DC4() {}
    ~Class_802A0DC4() {}
};

class Class_802B4774 {
public:
    Class_802B4774() {}
    ~Class_802B4774() {}
};

extern "C" char lbl_80486C34[];

struct Vtable_Class_802B4524 {
    void* vtable;
    Vtable_Class_802B4524() : vtable(lbl_80486C34) {}
};

class Class_802B4524 : public Vtable_Class_802B4524,
                       public Class_802A0DC4,
                       public Class_802A1FD4 {
public:
    Class_802B4524(int, int, int, int);
    ~Class_802B4524();
    Class_802B4774 m_C;
};

extern "C" char lbl_80486BF8[];

class Class_802B4948 : public Class_802B4524 {
public:
    Class_802B4948(int a, int b, int c, int d)
        : Class_802B4524(a, b, c, d) {
        vtable = lbl_80486BF8;
    }
};

extern "C" Class_802B4524* fn_802B4948(
    int arg0, int arg1, int arg2, int arg3) {
    Class_802B4524* object0 =
        new Class_802B4948(arg1, arg0, arg2, arg3);
    return object0;
}
