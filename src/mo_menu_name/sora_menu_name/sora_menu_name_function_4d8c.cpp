#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern void* g_sndSystem;
extern void* g_gfPadSystem;
extern float lbl_16_rodata_268;

class Sub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11(void* a, void* b);
    virtual void v12();
    virtual void v13();
    char pad[0xE0];
    void* f_e4;
};

struct Self {
    char p0[0x70];
    void* obj70;
    char p1[0x94 - 0x74];
    void* f94;
    char p2[0xA8 - 0x98];
    Sub* subA8;
    char p3[0x154 - 0xAC];
    void* f154;
    char p4[0x3F0 - 0x158];
    s32 f3f0;
    char p5[0x400 - 0x3F4];
    s32 f400;
    char p6[0x458 - 0x404];
    void* f458;
    char p7[0x478 - 0x45C];
    s32 f478;
};

extern "C" {
void playSE__9sndSystemF5SndIDiiii(void* self, int id, int a, int b, int c, int d);
void fn_800B5854(void* obj, int a, int b, int c, int d);
void printIndex__5MuMsgFUlUlPv(void* msg, u32 a, u32 b, void* c);
void setFrameVisible__8MuObjectFf(void* obj, float f);
void disconectWiiControler__11gfPadSystemFv(void* self);

void fn_16_4D8C(Self* self) {
    void* obj = self->obj70;
    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x22, -1, 0, 0, -1);
    Sub* s = self->subA8;
    s->v11(s->f_e4, self->f94);
    fn_800B5854(obj, 0, 0x11, 1, 0);
    printIndex__5MuMsgFUlUlPv(self->f154, 6, 0, self->f458);
    setFrameVisible__8MuObjectFf(self->obj70, lbl_16_rodata_268);
    disconectWiiControler__11gfPadSystemFv(g_gfPadSystem);
    self->f400 = 4;
    self->f478 = -1;
    self->f3f0 = 5;
}
}
