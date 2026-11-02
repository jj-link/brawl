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

class Class_8030A6BC {
public:
    static void operator delete(void* p);
    static void* operator new(size_t) {
        void* p = lbl_805A0EB8->alloc(0xb0, 0x1f);
        ((s16*)p)[2] = 0xb0;
        return p;
    }
};

class Class_8008080C {
public:
    Class_8008080C() {}
    ~Class_8008080C() {}
};

extern "C" char lbl_80488988[];
struct Vtable_Class_80312FD8 {
    void* vtable;
    Vtable_Class_80312FD8() : vtable(lbl_80488988) {}
};
class Class_80312FD8 : public Vtable_Class_80312FD8, public Class_8008080C {
public:
    Class_80312FD8() {}
    ~Class_80312FD8() {}
};

class Class_8030A51C {
public:
    Class_8030A51C() {}
    ~Class_8030A51C() {}
};

class Class_8030A490 {
public:
    Class_8030A490() {}
    ~Class_8030A490() {}
};

extern "C" char lbl_804888F0[];
struct Vtable_Class_80309954 {
    void* vtable;
    Vtable_Class_80309954() : vtable(lbl_804888F0) {}
};
class Class_80309954 : public Vtable_Class_80309954, public Class_80312FD8, public Class_8030A6BC {
public:
    Class_80309954(int, int, int);
    Class_8030A490 m_70;
    Class_8030A51C m_7C[3];
};

extern "C" void* fn_80312EB4(int a, int b, int c) {
    Class_80309954* obj = new Class_80309954(a, b, c);
    return obj;
}
