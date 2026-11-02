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

struct AllocationHeader {
    void* vtable;
    u16 m_04;
};

class Class_802A1FD4 {
public:
    static void operator delete(void* p);

    static void* operator new(u32 size) {
        AllocationHeader* p =
            (AllocationHeader*)lbl_805A0EB8->alloc(size, 0x1d);
        p->m_04 = size;
        return p;
    }
};

class Class_802A0DC4 {
public:
    Class_802A0DC4() {}
    ~Class_802A0DC4() {}
};

extern "C" char lbl_80486EF8[];

struct Vtable_Class_802C0718 {
    void* vtable;

    Vtable_Class_802C0718() : vtable(lbl_80486EF8) {}
};

struct Node;

class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4();
    virtual void fn_801B269C();
    virtual void fn_801B26E4();
    virtual void fn_801AAFDC(Node*, Node*, int);
};

struct Node {
    Class_8042B6D0* owner;
    char pad[8];
    Node* next;
};

class Class_802C0718 : public Vtable_Class_802C0718,
                       public Class_802A0DC4,
                       public Class_802A1FD4 {
public:
    Class_802C0718(int, int, int);

    char pad[0x10];
    Class_8042B6D0* owner1;
    Class_8042B6D0* owner2;
    int type1;
    int type2;
};

extern "C" Class_802C0718* fn_802C07D0(
    Node* a, Node* b, int c, int d) {
    Class_802C0718* obj = new Class_802C0718((int)a, (int)b, d);

    if (obj->type1 == 0x1a) {
        Class_8042B6D0* owner = a->owner;
        Node* x = a;
        while (x->next)
            x = x->next;
        Node* y = b;
        while (y->next)
            y = y->next;
        owner->fn_801AAFDC(x, y, c);
        obj->owner1 = owner;
    }

    if (obj->type2 == 0x1a) {
        Class_8042B6D0* owner = b->owner;
        while (b->next)
            b = b->next;
        while (a->next)
            a = a->next;
        owner->fn_801AAFDC(b, a, c);
        obj->owner2 = owner;
    }

    return obj;
}
