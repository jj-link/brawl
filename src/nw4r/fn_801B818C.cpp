#include <nw4r/ut/ut_LinkList.h>
#include <revolution/OS/OSInterrupt.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual int slot1();

    nw4r::ut::LinkListNode node;
};

class List : public nw4r::ut::detail::LinkListImpl {
public:
    using nw4r::ut::detail::LinkListImpl::Insert;
    using nw4r::ut::detail::LinkListImpl::GetEndIter;
};

extern "C" void fn_801B8458(void*, int);
extern "C" void fn_801B8540();
extern "C" void fn_801FFE28(void*, int);
extern "C" void fn_801FFE8C(void*, int);
extern "C" void fn_801FFEF0(void*, int);
extern "C" void fn_80200A00(unsigned short);
extern "C" void fn_80200A08(unsigned short);
extern "C" void fn_80200A10(unsigned short);

extern const float lbl_805A3444;

struct Ent {
    char pad[0x54];
    float a;
    float b;
    int c;
    int d;
};

static inline float calc(char* self, int off) {
    Ent* p = (Ent*)(self + off);
    int c = p->c;
    int d = p->d;
    if (d >= c) {
        return ((Ent*)((int)self + off))->b;
    }
    Ent* r = (Ent*)((unsigned int)self + off);
    return r->a + ((float)d * (r->b - r->a)) / (float)c;
}

extern "C" int fn_801B818C(char* self, int idx, Object_vptr_0* cb) {
    int off = idx * 16;
    Ent* p = (Ent*)(self + off);
    if (p->d < p->c) {
        fn_801B8458(self, idx);
    }

    float f = calc(self, off);
    Ent* q = (Ent*)((int)self + off);
    q->a = f;
    q->b = lbl_805A3444;
    q->c = 0;
    q->d = 0;

    switch (idx) {
    case 0:
        fn_80200A00((unsigned short)0x8000);
        break;
    case 1:
        fn_80200A08((unsigned short)0x8000);
        break;
    case 2:
        fn_80200A10((unsigned short)0x8000);
        break;
    }

    if (cb->slot1() == 0) {
        return 0;
    }

    List* list;
    int intr = OSDisableInterrupts();
    list = (List*)((int)self + idx * 12 + 0xB4);
    if (list->IsEmpty()) {
        switch (idx) {
        case 0:
            fn_801FFE28((void*)fn_801B8540, idx);
            break;
        case 1:
            fn_801FFE8C((void*)fn_801B8540, idx);
            break;
        case 2:
            fn_801FFEF0((void*)fn_801B8540, idx);
            break;
        }
        *(unsigned char*)(self + idx + 0xF0) = 2;
    }

    list->Insert(list->GetEndIter(), &cb->node);
    OSRestoreInterrupts(intr);
    return 1;
}
