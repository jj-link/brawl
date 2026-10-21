#pragma force_active on
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef short s16;

extern char lbl_41_data_A324[];
extern char lbl_41_data_3E50[];

extern "C" void fn_41_2D038(void* self, s32 p1, s32 p2, void* p3, void* p4);

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

extern "C" void* fn_41_3AA30(u8* self, u8* p2) {
    *(void**)self = lbl_41_data_A324;

    struct Args {
        s32 a;
        s32 b;
        s32* p;
        void* q;
    } args;

    u8* outer = *(u8**)(p2 + 0xd8);
    void* q = *(void**)(outer + 0xc0);

    args.a = 1;
    args.b = 6;
    args.p = &args.a;
    args.q = q;

    VObj* obj = (VObj*)(*(u8**)(*(u8**)(p2 + 0xd8) + 0x80) + 8);
    s32 r = obj->v7();

    fn_41_2D038(self + 4, 0, (s16)r, &args.p, lbl_41_data_3E50);
    return self;
}
