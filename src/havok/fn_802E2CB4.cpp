#include <types.h>
#pragma force_active on

class Class_80487F18 {
public:
    virtual void fn_802E2A9C();
    virtual void fn_802E13DC();
    virtual void fn_802E3058();
    virtual void* fn_802E2CA8();
    virtual void fn_802E1B10();

    u16 f4;
    u16 f6;
    char pad8[4];
    int fc;
    int f10;
    char pad14[0x10];
    void* f24;
    char pad28[0x24];
    struct Entry* data;
    int size;
    unsigned int capacity;
    char pad58[0x48];
    char block[0x100];
    struct Inner* inner;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void* slot4(unsigned int, int);
};

struct Pair {
    int a, b;
};

struct Entry {
    int a, b;
    Pair c;
};

struct Inner {
    void* vtable;
    u16 f4, f6;
    char pad8[0xf8];
    int f100;
};

struct Params {
    char data[0xc0];
} __attribute__((aligned(16)));

extern Object_vptr_0* lbl_805A0EB8;
extern void* lbl_805A0EC8;
extern char lbl_80487E28[];

extern "C" void fn_802E3604(Params*);
extern "C" void fn_802E2B0C(Class_80487F18*, Params*);
extern "C" Class_80487F18* fn_802E2840(Class_80487F18*, Params*);
extern "C" void fn_80281BC0(void*, void*, int);
extern "C" void* fn_8027EA20(void*, unsigned int, int);
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);

inline int getCapacity(const Class_80487F18* p) {
    return p->capacity & 0x3fffffff;
}

inline void copyArray(Class_80487F18* dest, int size,
                      const Class_80487F18* source) {
    dest->size = size;
    int i = 0;
    const Entry* src = source->data;
    Entry* dst = dest->data;
    for (; i < size; ++i) {
        dst[i] = src[i];
    }
}

extern "C" Class_80487F18* fn_802E2CB4(Class_80487F18* self) {
    Params p;
    fn_802E3604(&p);
    fn_802E2B0C(self, &p);

    Class_80487F18* result =
        (Class_80487F18*)lbl_805A0EB8->slot4(0x1f0, 0x2b);
    result->f4 = 0x1f0;
    if (result) {
        result = fn_802E2840(result, &p);
    }

    fn_80281BC0(result->block, self->block, 0x11);
    if (self->inner) {
        Inner* q = (Inner*)fn_8027EA20(lbl_805A0EC8, 0x110, 0x2c);
        q->f4 = 0x110;
        if (q) {
            q->f6 = 1;
            q->f100 = 0;
            q->vtable = lbl_80487E28;
        }
        result->inner = q;
        fn_80281BC0(q, self->inner, 0x11);
    }

    result->f24 = result->fn_802E2CA8();

    int cap = getCapacity(result);
    if (cap < self->size) {
        if (!(result->capacity & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, result->data, cap * 16, 0x15);
        }
        result->data =
            (Entry*)fn_8027EA20(lbl_805A0EC8, self->size * 16, 0x15);
        result->capacity = self->size | (result->capacity & 0x40000000);
    }

    copyArray(result, self->size, self);
    result->f10 = self->f10;
    result->fc = self->fc;
    return result;
}
