#pragma force_active on
typedef int s32;
typedef unsigned int u32;

struct VIface {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual float getVal();
    virtual void v7();
    virtual void setVal(float);
};

struct Node14 {
    char pad[0x0c];
    VIface* p0c;
    char pad2[0x08];
    VIface* p18;
};

struct Mu {
    char pad[0x14];
    Node14* n14;
};

struct O64 {
    char pad[0x1bc];
    Mu* m1bc;
    char pad2[0x1d4 - 0x1c0];
    Mu* m1d4;
};

struct Menu {
    char pad0[0x634];
    s32 s634;
    char pad1[0x64c - 0x638];
    O64* o64c;
    char pad2[0x664 - 0x650];
    s32 s664;
    char pad3[0x670 - 0x668];
    s32 s670;
    s32 s674;
};

extern "C" {
extern const float lbl_2_rodata_710[];
u32 fn_18_12E0(Menu* self);
s32 fn_2_1DD94(Menu* self, u32 flags);
void fn_2_1DA60(Menu* self, s32 arg);
void setFrameMatCol__8MuObjectFf(void* obj, float frame);
}

extern "C" s32 fn_2_1E034(Menu* self) {
    const float* c = lbl_2_rodata_710;
    s32 r = 0;

    switch (self->s664) {
    case 0: {
        if (self->s670 != 1) {
            self->s664 = 2;
        }
        u32 flags = fn_18_12E0(self);
        if (fn_2_1DD94(self, flags) != 0) {
            fn_2_1DA60(self, 2);
            r = 4;
            self->s664 = 2;
        }
        if (flags & 0x20) {
            fn_2_1DA60(self, 3);
            r = 1;
            self->s634 = 0x10;
        }
        break;
    }
    case 1:
        if (self->s670 != 1) {
            self->s664 = 2;
        }
        break;
    case 2: {
        u32 flags = fn_18_12E0(self);
        fn_2_1DD94(self, flags);
        if (flags & 0x20) {
            fn_2_1DA60(self, 3);
            self->s634 = 0x10;
            r = 1;
            self->s664 = 3;
        }
        break;
    }
    case 3:
        if (self->s670 == 0) {
            r = 3;
        }
        break;
    }

    switch (self->s670) {
    case 0:
    case 2:
        break;
    case 1:
        if (self->o64c->m1d4->n14->p0c->getVal() >= c[0x1EC / 4]) {
            if (self->o64c->m1bc->n14->p0c->getVal() >= c[0x1F8 / 4]) {
                fn_2_1DA60(self, 2);
            }
        }
        break;
    case 3:
        if (self->o64c->m1d4->n14->p0c->getVal() >= c[0x1F8 / 4]) {
            if (self->o64c->m1bc->n14->p0c->getVal() >= c[0x1FC / 4]) {
                fn_2_1DA60(self, 0);
            }
        }
        break;
    }

    switch (self->s674) {
    case 0:
        break;
    case 1:
        if (self->o64c->m1d4->n14->p18->getVal() >= c[0x200 / 4]) {
            if (self->s674 != 0) {
                setFrameMatCol__8MuObjectFf(self->o64c->m1d4, c[0x1D8 / 4]);
                self->o64c->m1d4->n14->p18->setVal(c[0x1D8 / 4]);
                self->s674 = 0;
            }
        }
        break;
    case 2:
        if (self->o64c->m1d4->n14->p18->getVal() >= c[0x204 / 4]) {
            if (self->s674 != 0) {
                setFrameMatCol__8MuObjectFf(self->o64c->m1d4, c[0x1D8 / 4]);
                self->o64c->m1d4->n14->p18->setVal(c[0x1D8 / 4]);
                self->s674 = 0;
            }
        }
        break;
    }

    return r;
}
