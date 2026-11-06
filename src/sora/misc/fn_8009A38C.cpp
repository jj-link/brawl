#pragma force_active on
typedef unsigned char u8;
class Object_vptr_0 {
public:
    virtual void* slot0(void*, int);
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18(int);
    char pad[8];
    int count;
};
struct Self {
    char pad[0x47];
    u8 flag;
    Object_vptr_0* obj;
    void* value;
};
struct State {
    char pad[0x40];
    u8 flag;
    u8 value;
};
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" Object_vptr_0* fn_8027ED0C(void*);
extern "C" Object_vptr_0* fn_8027E5A8(void*, Object_vptr_0*, int);
extern "C" void fn_8027B8D8(Object_vptr_0*, Object_vptr_0*, void (*)(int), int);
extern "C" void fn_8027B89C(Object_vptr_0*);
extern "C" void* fn_8009A4EC(int, int);
extern "C" void fn_8009A4FC();
extern "C" void fn_8009BA2C(int);
extern void* (*lbl_8059EF40)(int, int);
extern void (*lbl_8059EF44)();
extern Object_vptr_0* lbl_805A0EB8;
extern void* lbl_8059DC18;
extern State* lbl_8049DEC8[32];
extern u8 lbl_805A0270;
extern "C" void fn_8009A38C(Self* self) {
    if (!self->flag) {
        self->flag = 1;
        lbl_8059EF40 = fn_8009A4EC;
        lbl_8059EF44 = fn_8009A4FC;
        Object_vptr_0* p = (Object_vptr_0*)__nw__FUlQ25Heaps8HeapType(0xD34, 0xD);
        if (p) p = fn_8027ED0C(p);
        Object_vptr_0* q = (Object_vptr_0*)__nw__FUlQ25Heaps8HeapType(0x320, 0xD);
        if (q) q = fn_8027E5A8(q, p, 0x10);
        self->obj = q;
        fn_8027B8D8(p, q, fn_8009BA2C, 0);
        if (--p->count == 0 && p) p->slot18(1);
        self->value = lbl_805A0EB8->slot0(lbl_8059DC18, 1);
        self->obj->slot0(self->value, (int)lbl_8059DC18);
        fn_8027B89C(self->obj);
    }
    if (self->flag) {
        lbl_805A0270 = lbl_8049DEC8[0]->flag ? lbl_8049DEC8[0]->value : 0;
    }
}