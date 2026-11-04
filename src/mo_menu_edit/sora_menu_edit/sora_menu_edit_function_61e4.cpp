#pragma force_active on
typedef unsigned int u32;

struct PadSt {
    u32 w[3];
    u32 w3;
    u32 w4;
    u32 w5;
    char pad[0x33 - 0x18];
    unsigned char stickY;
    char rest[0x40 - 0x34];
};

struct VObj {
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
    virtual void v11();
    virtual void v12();
    virtual void v13(int);
};

struct Ptr0C {
    char pad[0xC];
    int v;
};

struct Menu {
    char p0[0x40];
    int state;
    char p1[0x7D500 - 0x44];
    float cur;
    char p2[0x7D518 - 0x7D504];
    float step;
    float maxv;
    bool flag;
    float newv;
    int done;
    char p3[0x7D560 - 0x7D52C];
    Ptr0C* sel;
    char p4[0x7D580 - 0x7D564];
    int obj580;
    char p5[0x7D64C - 0x7D584];
    void* muObj;
    char p6[0x7D688 - 0x7D650];
    VObj* vobj;
    char p7[0xC4500 - 0x7D68C];
    int mode;
};

extern "C" {
extern void* g_gfPadSystem;
extern void* g_sndSystem;
extern const float lbl_5_rodata_C;
extern const float lbl_5_rodata_1E4;

void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(void*, int, PadSt*);
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
void setFrameVisible__8MuObjectFf(void*, float);
void fn_5_11924(Menu*, PadSt*, int);
void fn_5_6500(Menu*);
void fn_5_CBE8(Menu*, int, int);
void fn_800B5854(int, int, int, int, int);

void fn_5_61E4(Menu* self) {
    PadSt st;
    float v = self->cur;
    getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, 0xF0, &st);
    fn_5_11924(self, &st, 0);
    float old = self->newv;
    if (st.w5 & 8) {
        v -= self->step;
        if (v < lbl_5_rodata_C) v = lbl_5_rodata_C;
        self->newv = v;
        self->flag = true;
    } else if (st.w5 & 4) {
        v += self->step;
        if (v + self->step > self->maxv) v = self->maxv - self->step;
        self->newv = v;
        self->flag = true;
    } else if (st.w5 & 1) {
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
        self->state = 1;
        fn_5_6500(self);
    } else if (st.w3 & 0x800) {
        if (self->mode != 3) {
            self->state = 0x13;
        } else {
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 3, -1, 0, 0, -1);
        }
    }
    int y = (signed char)st.stickY;
    if (y < -0x1E) {
        v -= (float)(y - 0x1E) / lbl_5_rodata_1E4;
        if (v + self->step > self->maxv) v = self->maxv - self->step;
        self->newv = v;
        self->flag = true;
    } else if (y > 0x1E) {
        v -= (float)(y + 0x1E) / lbl_5_rodata_1E4;
        if (v < lbl_5_rodata_C) v = lbl_5_rodata_C;
        self->newv = v;
        self->flag = true;
    } else if (st.w3 & 0x1000) {
        setFrameVisible__8MuObjectFf(self->muObj, lbl_5_rodata_C);
        self->vobj->v13(self->sel->v);
        fn_5_CBE8(self, 0, 0);
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 1, -1, 0, 0, -1);
        self->state = 10;
        fn_800B5854(self->obj580, 1, 0x11, 1, 0);
        self->done = 1;
    }
    if (old != self->newv) {
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 7, -1, 0, 0, -1);
    }
}
}
