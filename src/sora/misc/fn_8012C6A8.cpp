#include <types.h>
#pragma force_active on

struct A {
    u8 pad[0xF];
    u8 flags;
};

struct B {
    u8 pad[0x54];
    u8 flags;
};

struct C {
    u8 pad[0x2C];
    u8 flags;
};

struct Bits {
    u8 hi : 1;
    u8 rest : 7;
};

struct Local {
    A* a;
    B* b;
    C* c;
    u8 byte;
    Bits bits;

    int enabled() const {
        int ok = 0;
        if (a && b && c)
            ok = 1;
        if (ok && ((b->flags >> 4) & 1) && ((c->flags >> 7) & 1))
            return 1;
        return 0;
    }
};

struct Arg1 {
    A* ptr0;
    void* ptr4;
    void* ptr8;
    u8 unkC;

    A* getFirst() const {
        return ptr0;
    }
};

struct Class_8045DA20_base {
    u32 pad0;
    u32 pad4;
    f32 f8;
    u8 padC[0x320];
};

class Class_8045DA20 : public Class_8045DA20_base {
public:
    virtual void fn_80125930();
    virtual void fn_80125E1C();
    virtual void fn_80125E30();
    virtual void fn_80126B48();
    virtual void fn_80126F40();
    virtual void fn_8012C32C();
    virtual void fn_8012C6A8();
    virtual void fn_80132000();
    virtual void fn_8012A8B8();
    virtual void fn_80126EA4();
    virtual void fn_80125E44();
    virtual void fn_8012CADC(const Arg1*, f32*);

    u8 pad_after[0x128];
    u16 field458;
};

typedef Class_8045DA20 Self;

extern "C" void fn_80111968(void*, void*, void*, int);
extern "C" s32 fn_8011A944(Self*, const Arg1*);
extern "C" s32 fn_8012B5A8(Self*, const Arg1*, f32*);
extern "C" s32 fn_8012BC68(Self*, const Arg1*, f32*);
extern "C" s32 fn_8012ACA0(Self*, const Arg1*, f32*);
extern "C" s32 fn_8012B120(Self*, const Arg1*, f32*);
extern "C" s32 fn_80113DF8(const Arg1*, Local*);
extern "C" s32 fn_80113EC0(const Arg1*, Local*);
extern "C" f32 lbl_805A29C8;

struct Output {
    u8 data[32];

    Output(void* const& second, A* first) {
        fn_80111968(second, this, first, 0);
    }
};

extern "C" s32 fn_8012C6A8(Self& selfr, const Arg1& arg1r) {
    Self* self = &selfr;
    const Arg1* arg1 = &arg1r;
    f32 value;
    Local local;
    Output scratch(arg1r.ptr8, arg1r.getFirst());

    if (fn_8011A944(self, arg1))
        return 0;

    local.a = 0;
    local.b = 0;
    local.c = 0;
    local.byte = 0;
    local.bits.hi = 0;
    Local* np = &local;

    self->fn_8012C32C();

    f32 initialValue = lbl_805A29C8;
    s32 counter = 0;
    A* first = arg1->ptr0;
    value = initialValue;
    self->field458 = 0;

    if (((first->flags >> 2) & 1) &&
        !(arg1->unkC & 1) &&
        fn_8012B5A8(self, arg1, &value))
        counter = 1;

    if (((arg1->ptr0->flags >> 3) & 1) &&
        !(arg1->unkC & 2) &&
        fn_8012BC68(self, arg1, &value))
        ++counter;

    if (((arg1->ptr0->flags >> 1) & 1) &&
        !(arg1->unkC & 4) &&
        fn_8012ACA0(self, arg1, &value))
        ++counter;

    if ((arg1->ptr0->flags & 1) &&
        !(arg1->unkC & 8) &&
        fn_8012B120(self, arg1, &value))
        ++counter;

    if (!((arg1->ptr0->flags >> 2) & 1) &&
        !((arg1->ptr0->flags >> 3) & 1)) {
        if (((arg1->ptr0->flags >> 1) & 1) &&
            fn_80113DF8(arg1, &local)) {
            if (local.enabled() && (np->a->flags & 1))
                goto dispatch;
        }

        if (fn_80113EC0(arg1, &local)) {
            if (local.enabled() && (np->a->flags & 1))
                goto dispatch;
        }

        if ((arg1->ptr0->flags & 1) &&
            fn_80113DF8(arg1, &local)) {
            if (local.enabled() && ((np->a->flags >> 1) & 1))
                goto dispatch;
        }

        if (fn_80113EC0(arg1, &local)) {
            if (local.enabled() && ((np->a->flags >> 1) & 1))
                goto dispatch;
        }
    } else {
    dispatch:
        self->fn_8012CADC(arg1, &value);
    }

    if (self->f8 > value)
        self->f8 = value;

    if (counter != 0)
        return 1;
    return 0;
}
