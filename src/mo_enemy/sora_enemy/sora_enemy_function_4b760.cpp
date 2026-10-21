#pragma force_active on
typedef unsigned char u8;
typedef int s32;
typedef short s16;

extern "C" u8 lbl_41_data_10F48[];
extern "C" u8 lbl_41_data_3E50[];
extern "C" void fn_41_2D038(void*, s32, s16, void*, void*);

struct Args {
    s32 a;
    s32 b;
    s32* p;
    void* c;
};

struct VObj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual s32 f7();
};

extern "C" void* fn_41_4B760(void* self, void* other) {
    u8* o = (u8*)other;
    *(u8**)self = lbl_41_data_10F48;
    u8* x = *(u8**)(o + 0xd8);
    void* y = *(void**)((u8*)x + 0xc0);
    Args args;
    args.a = 1;
    args.b = 0x13;
    args.p = &args.a;
    args.c = y;
    u8* z = *(u8**)(o + 0xd8);
    u8* base = *(u8**)(z + 0x80);
    VObj* v = (VObj*)(base + 8);
    s32 rr = v->f7();
    fn_41_2D038((u8*)self + 4, 0, (s16)rr, &args.p, lbl_41_data_3E50);
    return self;
}
