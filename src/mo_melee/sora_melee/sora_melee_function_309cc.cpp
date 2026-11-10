#pragma force_active on

extern "C" void fn_80133F24(void*);
extern "C" void fn_27_2F00C(void*, unsigned int, unsigned int);
extern float lbl_27_rodata_440;
extern float lbl_27_rodata_444;

struct Vec2 {
    float x;
    float y;
    float z;
};

class Q {
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
    virtual float get();
};

class P {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual Vec2 getPos();
    virtual void s5();
    virtual Vec2 getPrev();
};

struct Modules {
    char pad0[0x0C];
    P* posture;
    char pad10[0x5C - 0x10];
    Q* q;
};

struct M {
    char pad[0xD8];
    Modules* mods;
};

struct Inner {
    char pad0[8];
    int field8;
    union {
        int fieldC;
        struct {
            unsigned int fieldCTop : 8;
            unsigned int mode : 8;
            unsigned int fieldCBottom : 16;
        };
    };
    char pad10[0x58 - 0x10];
    int field58;
    char pad5C[0x71 - 0x5C];
    unsigned char field71;
    unsigned char field72;
};

struct Wrapper {
    char pad0[4];
    Inner* in;
    char pad8[0x39 - 8];
    unsigned char state;
};

extern "C" void fn_27_309CC(void* arg0, M* wArg, Wrapper* mArg) {
    Wrapper* w = (Wrapper*)wArg;

    if ((w->in->field8 >> 24) != 0) {
        fn_80133F24(w->in);
    }

    w->in->field71 = (unsigned char)(w->in->field71 & ~0x08);
    w->in->field72 = (unsigned char)(w->in->field72 & ~0x20);
    fn_27_2F00C(w, 0, 0);

    unsigned char state = w->state;
    switch (state) {
    case 1:
    case 2:
        if (state == 1) {
            w->in->field58 = 0;
        } else {
            if (((M*)mArg)->mods->q->get() > lbl_27_rodata_440) {
                w->in->mode = 1;
            } else if (((M*)mArg)->mods->q->get() < lbl_27_rodata_444) {
                w->in->mode = 0;
            } else {
                w->in->mode = 2;
            }
            w->in->field58 = 2;
        }

        w->in->field71 |= 8;
        break;

    case 3:
    case 4: {
        const Vec2& a = ((M*)mArg)->mods->posture->getPos();
        const Vec2& b = ((M*)mArg)->mods->posture->getPrev();

        if (a.y < b.y) {
            if (state == 3) {
                w->in->field58 = 0;
            } else {
                if (((M*)mArg)->mods->q->get() > lbl_27_rodata_440) {
                    w->in->mode = 1;
                } else if (((M*)mArg)->mods->q->get() < lbl_27_rodata_444) {
                    w->in->mode = 0;
                } else {
                    w->in->mode = 2;
                }
                w->in->field58 = 2;
            }

            w->in->field71 |= 8;
        }
        break;
    }
    }
}
