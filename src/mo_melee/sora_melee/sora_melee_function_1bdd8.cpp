#include <types.h>
#pragma force_active on

struct Outer;

struct Inner {
    char pad[8];
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual unsigned int v8(Outer* arg) = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual int v14() = 0;
};

struct Middle {
    char pad[0xb8];
    Inner* inner;
};

struct Outer {
    char pad[0xd8];
    Middle* middle;
};

struct Self {
    char pad[0x165];
    u8 flags;
    char pad2[2];
    Outer* outer;
};

extern "C" void fn_27_1BF30(Self* self, s16* arg1, s32 arg2);
extern "C" void fn_27_1BFE4(Self* self, s16* arg1, s32 arg2);
extern "C" void fn_27_1C0F8(Self* self, s16* arg);
extern "C" void fn_27_1C1DC(Self* self, s16* arg);

struct Id {
    s16 value;
    char pad[2];
};

extern "C" void fn_27_1BDD8(Self* self) {
    Id a, b, c, d, e, f;
    unsigned int flag = 0;
    
    if (self->outer->middle->inner->v8(self->outer) == 1) {
        if (self->outer->middle->inner->v14() == 0) {
            flag = 1;
        }
    }
    
    unsigned int field1 = (unsigned int)(self->flags >> 4) & 3;
    if (field1 == 1) {
        a.value = 0x40;
        fn_27_1BF30(self, &a.value, 1);
    } else if (field1 == 2 || flag == 1) {
        b.value = 0x40;
        fn_27_1C0F8(self, &b.value);
    } else {
        c.value = 0x40;
        fn_27_1BF30(self, &c.value, 0);
    }
    
    unsigned int field2 = (unsigned int)(self->flags >> 2) & 3;
    if (field2 == 1) {
        d.value = 0x80;
        fn_27_1BFE4(self, &d.value, 1);
    } else if (field2 == 2 || flag == 1) {
        e.value = 0x80;
        fn_27_1C1DC(self, &e.value);
    } else {
        f.value = 0x80;
        fn_27_1BFE4(self, &f.value, 0);
    }
}