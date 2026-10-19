#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Ctx;

struct Self {
    u8 pad0[0x1ac];
    Ctx* ctx;
};

struct Ctx {
    u8 pad0[0x1a0];
    u32 f1a0;
    u8 pad1[0x1b40 - 0x1a4];
    u32 f1b40;
    u8 pad2[0x1cee - 0x1b44];
    u8 f1cee;
    u8 pad3[0x1d0c - 0x1cef];
    u8* inner;
};

struct sndSystem {
    void playBGM(int, unsigned long, bool);
};

struct Global {
    u8 pad0[0x174];
    u32 f174;
};

extern "C" {
extern int fn_6_308C(Self* self, u8* p);
extern sndSystem* g_sndSystem;
extern Global* lbl_805A01D8;
}

extern "C" void fn_7_3E4(Self* self) {
    int ret = fn_6_308C(self, self->ctx->inner + 0x360);
    if (ret >= 0) {
        self->ctx->f1a0 = *(u32*)(self->ctx->inner + 0x360);
        self->ctx->f1b40 = self->ctx->f1cee + ret;
    }
    g_sndSystem->playBGM(0x270c, 0, true);
    lbl_805A01D8->f174 = 0x2d;
}
