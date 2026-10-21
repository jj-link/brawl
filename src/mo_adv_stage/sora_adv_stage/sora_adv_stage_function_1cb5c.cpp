#include <types.h>
#pragma force_active on

extern "C" u64 fn_803F1798(u64, u32);

struct Base {
    u8 pad[0x3c];
};

#define SLOT(n) virtual void slot##n();
#define TEN(p) \
    SLOT(p##0) SLOT(p##1) SLOT(p##2) SLOT(p##3) SLOT(p##4) \
    SLOT(p##5) SLOT(p##6) SLOT(p##7) SLOT(p##8) SLOT(p##9)

struct Elem : Base {
    TEN(a)
    TEN(b)
    TEN(c)
    TEN(d)
    TEN(e)
    TEN(f)
    TEN(g)
    TEN(h)
    TEN(i)
    SLOT(j0)
    virtual void invoke();
};

struct Stage : Base {
    TEN(a)
    TEN(b)
    TEN(c)
    TEN(d)
    TEN(e)
    TEN(f)
    TEN(g)
    TEN(h)
    TEN(i)
    TEN(j)
    TEN(k)
    SLOT(l0)
    SLOT(l1)
    SLOT(l2)
    SLOT(l3)
    virtual void invoke(u8);

    u8 pad2[0x110];
    u32 count;
    Elem** elems;
};

#undef TEN
#undef SLOT

extern "C" void fn_40_1CB5C(Stage* self, u32* arg1, void*) {
    if ((s32)arg1[0] == 0x30) {
        u32 hi = arg1[2];
        u32 lo = arg1[3];
        u32 i = 0;

        while (i < self->count) {
            u64 ret = fn_803F1798(1ULL, i);
            if (((lo & (u32)ret) | (hi & (u32)(ret >> 32))) != 0) {
                self->elems[i]->invoke();
                self->invoke((u8)i);
            }
            ++i;
        }
    }
}
