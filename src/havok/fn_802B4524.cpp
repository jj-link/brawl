#include <types.h>
#pragma force_active on

extern "C" void fn_8027CD94(void*, s32, s32);
extern "C" char lbl_80486C34[];
extern "C" u16 lbl_8059EF78;

class Class_802A0DC4 {
public:
    Class_802A0DC4() {}
    ~Class_802A0DC4() {}
};

class Class_802B4774 {
public:
    Class_802B4774() : data(0), size(0), cap((s32)0x80000000) {}
    ~Class_802B4774() {}
    u16* data;
    s32 size;
    s32 cap;
    void resize(s32 n);
};

struct Vtable_Class_802B4524 {
    void* vtable;
    char pad4[2];
    s16 unk6;
    s32 unk8;
    Vtable_Class_802B4524(int a3) {
        unk6 = 1;
        unk8 = a3;
        vtable = lbl_80486C34;
    }
};

class Class_802A1FD4 {
public:
    static void operator delete(void* p);
};

class Class_802B4524 : public Class_802A0DC4, public Vtable_Class_802B4524, public Class_802A1FD4 {
public:
    Class_802B4524(int, int, int, int);
    Class_802B4774 m_C;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(s32*);
};

inline void Class_802B4774::resize(s32 n) {
    s32 oldSize = size;
    if (n > oldSize) {
        s32 capacity = cap & 0x3fffffff;
        if (capacity < n) {
            s32 doubled = capacity * 2;
            fn_8027CD94(this, n < doubled ? doubled : n, 2);
        }
        for (s32 i = oldSize; i < n; i++)
            data[i] = lbl_8059EF78;
    }
    size = n;
}

Class_802B4524::Class_802B4524(int a0, int a1, int a2, int a3) : Vtable_Class_802B4524(a3) {
    if (a3 != 0) {
        s32 n;
        Object_vptr_0* obj = *(Object_vptr_0**)a0;
        obj->slot8(&n);
        m_C.resize(n);
    }
}