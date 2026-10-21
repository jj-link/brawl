#include <types.h>
#pragma force_active on

struct Sub {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual s32 v9();
};

struct Arr {
    s32 a;
    s32 b;
    void* p;
    void* c;
};

extern "C" {
    extern u8 lbl_41_data_B20C[];
    extern u8 lbl_41_data_3E50[];
    void fn_41_2D038(void* self, s32 zero, s32 val, void* arr, void* tbl);
}

extern "C" u8* fn_41_3CCC8(u8* self, u8* arg) {
    *(void**)self = lbl_41_data_B20C;
    void* c = *(void**)(*(u8**)(arg + 0xd8) + 0xc0);
    Arr arr;
    arr.a = 1;
    arr.b = 9;
    arr.p = &arr;
    arr.c = c;
    s32 val = ((Sub*)(*(u8**)(*(u8**)(arg + 0xd8) + 0x80) + 8))->v9();
    fn_41_2D038(self + 4, 0, (s16)val, &arr.p, lbl_41_data_3E50);
    return self;
}
