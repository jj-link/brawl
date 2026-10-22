#pragma force_active on

typedef unsigned char u8;
typedef int s32;
typedef short s16;

extern char lbl_41_data_179E4[];
extern char lbl_41_data_3E50[];

extern "C" void fn_41_30254(void*, s32, s32, void*, void*);

struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual s32 v7();
};

extern "C" void* fn_41_5927C(u8* self, u8* obj) {
    *(void**)self = lbl_41_data_179E4;
    void* v = *(void**)(*(u8**)(obj + 0xd8) + 0xc0);

    struct Args {
        s32 a;
        s32 b;
        s32* p;
        void* q;
    } args;

    args.a = 1;
    args.b = 0x2e;
    args.p = &args.a;
    args.q = v;

    VObj* sub = (VObj*)(*(u8**)(*(u8**)(obj + 0xd8) + 0x80) + 8);
    s32 r = sub->v7();

    fn_41_30254(self + 4, 0, (s16)r, &args.p, lbl_41_data_3E50);
    return self;
}
