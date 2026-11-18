#pragma force_active on
struct Item {
    int w0;
    char pad4[0x54];
    int f58;
};

struct Vt44 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual int s9();
};

struct Mid {
    int unk0;
    int unk4;
    char pad8[0x44 - 8];
    Vt44* f44;
};

struct Owner {
    char pad0[0xd8];
    Mid* fd8;
};

struct Seq {
    virtual void s0();
    virtual Item* s1(int i);
    virtual void s2();
    virtual int s3();
};

struct SeqB {
    virtual void s0();
    virtual void* s1(int i, Mid* d);
};

struct Counter {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual int s3();
};

struct Self {
    char pad0[0x28];
    Owner* f28;
    Seq* f2c;
    float f30;
    char pad34[0x84];
    char b8[0xdc - 0xb8];
    char dc[0xe8 - 0xdc];
    char e8[0xf4 - 0xe8];
    int fF4;
    int padF8;
    int fFC;
    int f100;
    unsigned char f104;
};

extern "C" {
void fn_27_3627C(void*, int);
void fn_27_37880(void*, int, float, float);
void fn_27_36768(void*, int, int);
int fn_27_36028(void*, int, int);
void fn_27_36A8C(void*);
unsigned int fn_27_4DA80(void*, int, int, void*, void*, float);
}

extern const float lbl_27_rodata_534;

extern "C" void fn_27_4E670(Self* self, float a, float b) {
    int i;
    self->f30 = b;
    int r27 = self->f28->fd8->f44->s9();
    int r29 = ((Counter*)((char*)self + 0x34))->s3();
    for (int i = 0; i < r29; i++) {
        fn_27_3627C(self->b8, i);
        fn_27_37880(self->b8, i, a, lbl_27_rodata_534);
        fn_27_36768(self->b8, r27, i);
    }
    if (self->fFC > 0) {
        if (self->f100 == 0) {
            self->f100 = self->fFC;
        } else {
            self->f100 = self->f100 - 1;
            return;
        }
    }
    unsigned int r26 = 0U;
    int r30 = self->f2c->s3();
    for (int j = 0; j < r30; j++) {
        if (self->f2c->s1(j)->w0 != 0) {
            int v;
            int dv;
            void* obj;
            int res;
            if (j == self->fF4) {
                obj = (void*)self->f2c->s1(j)->f58;
                dv = self->f28->fd8->unk4;
                v = (int)((SeqB*)self->f2c)->s1(j, self->f28->fd8);
                res = fn_27_36028(self->b8, j, (int)obj);
                if (fn_27_4DA80((void*)v, dv, res, self->dc, self->e8, self->f30) == 1U) {
                    r26 = 1U;
                }
            } else {
                v = self->f2c->s1(j)->f58;
                dv = self->f28->fd8->unk4;
                obj = ((SeqB*)self->f2c)->s1(j, self->f28->fd8);
                res = fn_27_36028(self->b8, j, v);
                if (fn_27_4DA80(obj, dv, res, 0, 0, self->f30) == 1U) {
                    r26 = 1U;
                }
            }
        }
    }
    if (r26 == 1U) {
        fn_27_36A8C(self->b8);
    }
    self->f104 = 1;
}
