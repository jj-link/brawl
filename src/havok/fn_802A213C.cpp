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
extern "C" char lbl_80486780[];
extern "C" char lbl_804867BC[];

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

struct Vtable_Class_802A1ED4 {
    void* vtable;
    u16 m_04;
    u8 pad[14];

    Vtable_Class_802A1ED4() : vtable(lbl_804867BC) {}
};

class Class_802A1ED4 : public Vtable_Class_802A1ED4,
                       public Class_802A0DC4,
                       public Class_802A1FD4 {
public:
    Class_802A1ED4(int, int, int, int);
};

extern "C" void __ct__14Class_802A1ED4Fiiii(void*, int, int, int, int);

struct Bar : public Class_802A1FD4 {
    void* m_00;
    u16 m_04;
    u8 pad[14];

    Bar(int a, int b, int c, int d) {
        __ct__14Class_802A1ED4Fiiii(this, b, a, c, d);
        m_00 = lbl_80486780;
    }

    static void* operator new(u32 size) {
        Bar* p = (Bar*)lbl_805A0EB8->alloc(size, 0x1d);
        p->m_04 = size;
        return p;
    }
};

extern "C" Bar* fn_802A213C(int a, int b, int c, int d) {
    Bar* object0 = new Bar(a, b, c, d);
    return object0;
}
