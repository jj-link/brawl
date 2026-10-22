#include <types.h>

#pragma force_active on

struct ListVt {
    virtual void v2();
    virtual void v3();
    virtual s32* at(s32 i);
    virtual s32 count();
};

struct SubVt {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(s32 j);
    virtual s32 v11(s32 j);
};

struct Mid {
    char pad0[0x54];
    SubVt* sub;
};

struct Arg1 {
    char pad0[8];
    void* p8;
    char pad1[0xD8 - 0xC];
    Mid* mid;
};

struct Self {
    char pad0[4];
    void* p4;
};

extern "C" {
void* fn_113_24550(void* self);
void fn_113_13958(void* self, s32 v);
void fn_113_1094C(void* self);
void fn_113_10DD0(void* p);
void fn_113_11D54(void* object, s16 deleting);
void fn_113_24D68(void* a, s32 b, s32 c);
void fn_113_25120(void* a, s32 b, s32 c);
}

extern "C" void fn_113_13714(Self* self, Arg1* arg1, s32 kind) {
    char sp8[0x60];
    ListVt* list = (ListVt*)fn_113_24550(self->p4);
    fn_113_13958(sp8, 0);
    s32 n = list->count();
    if (kind != 0xE && kind != 0 && kind != 0x7F && kind != 0x80) {
        for (s32 i = 0; i < n; i++) {
            s32 id = *list->at(i);
            fn_113_25120(self->p4, id, 0x12000004);
            fn_113_24D68(self->p4, id, 0xA);
        }
    }
    if (kind != 0x80) {
        fn_113_1094C(arg1);
        fn_113_10DD0(arg1->p8);
    }
    for (s32 j = 7; j < 0xD; j++) {
        if (arg1->mid->sub->v11(j) != 0) {
            arg1->mid->sub->v10(j);
        }
    }
    fn_113_11D54(sp8, 0);
}
