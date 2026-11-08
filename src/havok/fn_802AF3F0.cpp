#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void* slot4(int, int);
};
extern Object_vptr_0* lbl_805A0EB8;

class Class_802A0DA4 {
public:
    static void operator delete(void* p);
    static void* operator new(u32 size) {
        void* p = lbl_805A0EB8->slot4(size, 0x1d);
        ((u16*)p)[2] = size;
        return p;
    }
};

class Class_802A1FD4 {
public:
    static void operator delete(void* p);
    static void* operator new(u32 size) {
        void* p = lbl_805A0EB8->slot4(size, 0x1d);
        ((u16*)p)[2] = size;
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
    Class_802AF338() {}
    ~Class_802AF338() {}
};

extern "C" char lbl_80486AE8[];
struct Vtable_Class_802AF148 {
    void* vtable;
    Vtable_Class_802AF148() : vtable(lbl_80486AE8) {}
};
class Class_802AF148 : public Vtable_Class_802AF148, public Class_802AF338, public Class_802A0DA4 {
public:
    Class_802AF148(int, int, int, int);
    static void* operator new(u32 size) {
        void* p = lbl_805A0EB8->slot4(0x80, 0x1d);
        ((u16*)p)[2] = 0x80;
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
    Class_802A9A5C() {}
    ~Class_802A9A5C() {}
};

extern "C" char lbl_80486CE8[];
struct Vtable_Class_802B87B8 {
    void* vtable;
    Vtable_Class_802B87B8() : vtable(lbl_80486CE8) {}
};
class Class_802B87B8 : public Vtable_Class_802B87B8, public Class_802A1FD4, public Class_802A0DC4 {
public:
    Class_802B87B8(int, int, int, int);
    Class_802A9A5C m_10;
    static void* operator new(u32 size) {
        void* p = lbl_805A0EB8->slot4(0x20, 0x1d);
        ((u16*)p)[2] = 0x20;
        return p;
    }
};

extern "C" void* fn_802AF3F0(int a, int b, int c, int d) {
    if (d) {
        Class_802AF148* object0 = new Class_802AF148(a, b, c, d);
        return object0;
    }
    Class_802B87B8* object1 = new Class_802B87B8(a, b, c, d);
    return object1;
}