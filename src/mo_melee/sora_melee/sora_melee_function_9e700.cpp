#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" const float lbl_27_rodata_C5C;

struct Rec {
    char pad[0x28];
    u8 f28;
    char pad2;
    u8 f2a;
};

class Sub {
public:
    virtual void v0();
    virtual Rec* at(int i);
    virtual void v2();
    virtual int count();
};

class Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int a, void* b, int c, float d);
};

struct Ext {
    char pad[0x6c];
    Inner* p6c;
};

struct Mid {
    char pad[0xd8];
    Ext* ext;
};

struct Entry8 {
    char pad[6];
    u8 flag;
    char pad2;
};

struct Arg {
    char pad[0xc];
    u32 flags;
};

class Self {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24(int, int, int);
    virtual void s25();
    virtual void s26();
    virtual void s27(int, int);

    char pad0[0x44 - 4];
    Mid* f44;
    char pad1[0x4c - 0x48];
    Sub* f4c;
    char pad2[0x6c - 0x50];
    Entry8* f6c;
    int f70;
    int f74;
};

extern "C" void fn_27_9E700(Self* self, int a, int b, const Arg* arg) {
    if (!((arg->flags >> 5) & 1)) {
        self->s24(1, 0, 1);
        self->s27(1, 0);
        int n = self->f4c->count();
        for (int i = 0; i < n; i++) {
            if (self->f4c->at(i)->f28 == 1) {
                if (self->f4c->at(i)->f2a == 1) {
                    self->f4c->at(i)->f28 = 0;
                }
            }
        }
        int idx = self->f74;
        if (idx != -1 && self->f6c[idx].flag == 1) {
            Mid* m = self->f44;
            Inner* in = m->ext->p6c;
            in->v6(self->f70, m, -1, lbl_27_rodata_C5C);
            self->f74 = -1;
        }
    }
}
