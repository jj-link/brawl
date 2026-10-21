#pragma force_active on
typedef unsigned char u8;
typedef signed short s16;
typedef int s32;

extern char lbl_41_data_101F8[];
extern char lbl_41_data_3E50[];

extern "C" void fn_41_2D038(void* p, int a, s16 b, void* c, void* d);

struct Sub {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual s16 v7();
};

struct Mid {
    u8 pad[8];
    Sub sub;
};

struct Ctx {
    u8 pad[0x80];
    Mid* mid;
    u8 pad2[0x3c];
    void* x;
};

struct Owner {
    u8 pad[0xd8];
    Ctx* ctx;
};

struct Arg {
    s32 a;
    s32 b;
    void* c;
    void* d;
};

extern "C" void* fn_41_49EAC(void* self, Owner* o) {
    *reinterpret_cast<void**>(self) = static_cast<void*>(lbl_41_data_101F8);
    void* x = o->ctx->x;
    Arg arg;
    arg.a = 1;
    arg.b = 0xf;
    arg.c = &arg;
    arg.d = x;
    s16 v = o->ctx->mid->sub.v7();
    fn_41_2D038(static_cast<u8*>(self) + 4, 0, v, &arg.c, static_cast<void*>(lbl_41_data_3E50));
    return self;
}
