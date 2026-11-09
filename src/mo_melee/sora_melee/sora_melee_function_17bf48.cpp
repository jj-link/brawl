#pragma force_active on

extern float lbl_27_rodata_2378;
extern float lbl_27_rodata_237C;

class MotionModule {
public:
    virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3();
    virtual void p4(); virtual void p5(); virtual void p6(); virtual void p7();
    virtual void p8(); virtual void p9(); virtual void p10(); virtual void p11();
    virtual void p12(); virtual void p13(); virtual void p14(); virtual void p15();
    virtual void p16(); virtual void p17(); virtual void p18(); virtual void p19();
    virtual void p20(); virtual void p21(); virtual void p22(); virtual void p23();
    virtual void p24(); virtual void p25(); virtual void p26(); virtual void p27();
    virtual void p28(); virtual void p29();
    virtual void setParam(int*, float);
    virtual void p31(); virtual void p32(); virtual void p33(); virtual void p34();
    virtual void p35(); virtual void p36();
    virtual int query37(int);
    virtual void p38();
    virtual void play(int, int, int, int, int, float, float);
    virtual void p40(); virtual void p41(); virtual void p42(); virtual void p43();
    virtual void p44();
    virtual int query45(int);
};

class SoundModule {
public:
    virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3();
    virtual void p4();
    virtual void set(int, int, int, int);
    virtual void p6(); virtual void p7(); virtual void p8(); virtual void p9();
    virtual void p10(); virtual void p11(); virtual void p12(); virtual void p13();
    virtual void p14(); virtual void p15(); virtual void p16(); virtual void p17();
    virtual void p18();
    virtual void on(int, int);
};

class SubModule {
public:
    virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3();
    virtual void p4();
    virtual void setFlag(int, unsigned int);
};

struct Modules {
    char pad0[8];
    MotionModule* motion;
    char pad1[0x50 - 0x0c];
    SoundModule* sound;
    char pad2[0x64 - 0x54];
    SubModule* sub;
    char pad3[0xa8 - 0x68];
    MotionModule* work;
};

struct Owner {
    char pad0[8];
    void* object;
    char pad1[0xd8 - 0x0c];
    Modules* modules;
};

struct Param {
    int kind;
    float a;
    float b;
    char c0;
    char c1;
    char c2;
    char c3;
};

struct Pad12 { char pad[0xc]; };

class ObjC : public Pad12 {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12();
    virtual void call(int, int, int);
    virtual void s14();
};

#define V(n) virtual void f##n();
#define V10(n) V(n##0) V(n##1) V(n##2) V(n##3) V(n##4) V(n##5) V(n##6) V(n##7) V(n##8) V(n##9)

struct Pad3c { char pad[0x3c]; };

class Fighter : public Pad3c {
public:
    V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V10(6) V10(7) V10(8) V10(9)
    V10(10) V10(11) V10(12) V10(13) V10(14) V10(15) V10(16) V10(17)
    V(180) V(181) V(182) V(183) V(184)
    virtual ObjC* get185();
    V(186)
};

extern "C" {
    void* __dynamic_cast(void*, long, const void*, const void*, long);
    extern const char lbl_27_data_69C0[];
    extern const char lbl_27_data_248[];
    void fn_27_1D6434(int, int, int, int, Owner*);
}

extern "C" void fn_27_17BF48(void*, Owner* owner) {
    int result = owner->modules->work->query37(0);
    int ret = owner->modules->motion->query45(1);

    if (ret != -1) {
        MotionModule* motion = owner->modules->motion;
        int kind = result == 0 ? 0x16d : 0x165;
        motion->play(
            1, kind, 0x135, 0, 0,
            lbl_27_rodata_2378, lbl_27_rodata_237C);
    } else {
        Param p;
        int kind = 0x169;
        if (result == 0) {
            kind = 0x171;
        }
        p.kind = kind;
        p.a = lbl_27_rodata_2378;
        p.b = lbl_27_rodata_237C;
        p.c0 = 0;
        p.c1 = 0;
        p.c2 = 0;
        p.c3 = 0;
        owner->modules->motion->setParam((int*)&p, lbl_27_rodata_2378);
    }

    owner->modules->sound->on(0x1f93, 0);

    if (result == 0) {
        owner->modules->sound->set(0x1f9d, 0, 0, 0);
    }

    owner->modules->sub->setFlag(3, 0x2000000c);

    if (result > 0) {
        Fighter* f = (Fighter*)__dynamic_cast(owner->object, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1);
        ObjC* x = f->get185();
        x->call(1, 0x1d, 0);
    }

    Fighter* f2 = (Fighter*)__dynamic_cast(owner->object, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1);
    fn_27_1D6434(2, 0x66, 0, (int)f2->get185(), owner);
}
