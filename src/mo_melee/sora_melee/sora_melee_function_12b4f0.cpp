#pragma force_active on
#pragma fp_contract off

typedef unsigned int u32;
typedef int s32;

struct D8 {
    char pad00[0x0C];
    void* p0C;
    void* p10;
    void* p14;
    char pad18[8];
    void* p20;
    char pad24[0x14];
    void* p38;
    char pad3C[0x14];
    void* p50;
    char pad54[8];
    void* p5C;
    void* p60;
    void* p64;
    char pad68[8];
    void* p70;
    char pad74[0x14];
    void* p88;
    char pad8C[0x1C];
    void* pA8;
};

struct FighterBase {
    char pad[0x3C];
};

#define V8(p) \
    virtual void p##0(); virtual void p##1(); \
    virtual void p##2(); virtual void p##3(); \
    virtual void p##4(); virtual void p##5(); \
    virtual void p##6(); virtual void p##7();
#define V5(p) \
    virtual void p##0(); virtual void p##1(); \
    virtual void p##2(); virtual void p##3(); \
    virtual void p##4();
#define V16(p) V8(p##a) V8(p##b)
#define V24(p) V8(p##a) V8(p##b) V8(p##c)
#define V30(p) \
    virtual void p##0(); virtual void p##1(); \
    virtual void p##2(); virtual void p##3(); \
    virtual void p##4(); virtual void p##5(); \
    virtual void p##6(); virtual void p##7(); \
    virtual void p##8(); virtual void p##9(); \
    virtual void p##10(); virtual void p##11(); \
    virtual void p##12(); virtual void p##13(); \
    virtual void p##14(); virtual void p##15(); \
    virtual void p##16(); virtual void p##17(); \
    virtual void p##18(); virtual void p##19(); \
    virtual void p##20(); virtual void p##21(); \
    virtual void p##22(); virtual void p##23(); \
    virtual void p##24(); virtual void p##25(); \
    virtual void p##26(); virtual void p##27(); \
    virtual void p##28(); virtual void p##29();
#define V32(p) V8(p##a) V8(p##b) V8(p##c) V8(p##d)
#define V2(p) virtual void p##0(); virtual void p##1();
#define V1(p) virtual void p##0();

class FighterView : public FighterBase {
public:
    V32(a)
    V5(b)
    virtual void* slot37(void*);
    V32(c)
    V32(d)
    V32(e)
    V30(f)
    virtual void slot164();
    virtual void slot165(int);
    virtual void slot166(int, bool);
    virtual void slot167(int);
    virtual void slot168(int);
    V16(g)
    virtual void* slot185();
    char pad40[0x20];
    void* accesser;
};

class P0C {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
};

class P14 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6(int, int);
};

class P20 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5(int, int, int, int);
    V24(a)
    virtual void s30(int, int, int);
};

class P38_base {
public:
    char pad[8];
};

class P38 : public P38_base {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8(float);
};

class P10_base {
public:
    char pad[8];
};

class P10 : public P10_base {
public:
    V32(h)
    V32(i)
    V32(j)
    V16(k)
    virtual u32 s112(int);
};

class P64 {
public:
    V16(l)
    V1(m)
    virtual u32 s17(u32);
};

class P70 {
public:
    V32(n)
    V2(o)
    virtual void event(int, void*);
};

class P5C {
public:
    V8(p)
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void q3();
    virtual void q4();
    virtual void set(void*, int);
};

class P88 {
public:
    V8(q)
    virtual void call(int, int, float*, float*, float*, float*, int, float, int);
};

class POwner_base {
public:
    char pad[0x0C];
};

class POwner : public POwner_base {
public:
    virtual void s0();
    virtual int s1();
};

class PA8 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6(int, int, int, int);
};

extern "C" void fn_27_15A018(void*);
extern "C" u32 fn_27_111F4C(void*);
extern "C" s32 fn_27_112AF0(void*);
extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);
extern "C" const float lbl_27_rodata_1048;
extern "C" const float lbl_27_rodata_104C;

#define D (*(*(D8**)((char*)moduleAccesser + 0xD8)))

extern "C" void start__7FighterFP5Vec3fffib(
    FighterView* self, void*, float, float arg2, int arg3, bool arg4
) {
    void* moduleAccesser = self->accesser;

    ((P0C*)D.p0C)->s2();
    ((P38*)D.p38)->s8(arg2);
    self->slot165(arg3);

    switch (arg3) {
    case 0:
        if (((P10*)D.p10)->s112(0) == 1) {
            ((P14*)D.p14)->s6(0, 0);
            ((P70*)D.p70)->event(0x10E, moduleAccesser);
        } else {
            ((P14*)D.p14)->s6(2, 0);
            ((P70*)D.p70)->event(0xE, moduleAccesser);
            fn_27_15A018((char*)self + 0x13C);
        }
        break;

    case 1:
    case 2:
        if (((P64*)D.p64)->s17(0x12000023) == 1) {
            ((P14*)D.p14)->s6(2, 0);
            ((P70*)D.p70)->event(0xBE, moduleAccesser);
        } else {
            self->slot167(1);
            self->slot168(1);

            if (((P10*)D.p10)->s112(0) == 1) {
                ((P14*)D.p14)->s6(0, 0);
                ((P70*)D.p70)->event(0, moduleAccesser);
            } else {
                ((P14*)D.p14)->s6(2, 0);
                ((P70*)D.p70)->event(0xE, moduleAccesser);
            }
        }

        fn_27_15A018((char*)self + 0x13C);

        if (arg4 == 1) {
            void* owner = self->slot185();
            float values[12];
            values[0] = lbl_27_rodata_1048;
            values[1] = lbl_27_rodata_1048;
            values[2] = lbl_27_rodata_1048;
            values[3] = lbl_27_rodata_1048;
            values[4] = lbl_27_rodata_1048;
            values[5] = lbl_27_rodata_1048;
            values[6] = lbl_27_rodata_1048;
            values[7] = lbl_27_rodata_1048;
            values[8] = lbl_27_rodata_1048;
            values[9] = lbl_27_rodata_1048;
            values[10] = lbl_27_rodata_1048;
            values[11] = lbl_27_rodata_1048;
            int local = 0;

            ((P88*)D.p88)->call(0x1030017, 0x12E, &values[9], &values[6],
                                &values[3], &values[0], 0, lbl_27_rodata_104C, 0);

            ((P20*)D.p50)->s5(0x2288, 0, 0, 0);

            if (fn_27_111F4C(owner) == 1) {
                int value = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
                    moduleAccesser, 0x5A3E, 0
                );
                ((P20*)D.p20)->s30(value, 0, 0);
            }

            if (((POwner*)owner)->s1() == 0) {
                int value = fn_27_112AF0(owner);
                if (value != -1) {
                    ((PA8*)D.pA8)->s6(value, 0, 0, 0);
                }
            }
            (void)local;
        }
        break;

    case 3:
        break;

    case 4: {
        D8* d8 = *(D8**)((char*)moduleAccesser + 0xD8);
        P5C* module = (P5C*)d8->p5C;
        void* old = self->slot37(d8);
        module->set(old, 1);
        ((P70*)D.p70)->event(0x10F, moduleAccesser);
        break;
    }

    case 5: {
        D8* d8 = *(D8**)((char*)moduleAccesser + 0xD8);
        P5C* module = (P5C*)d8->p5C;
        void* old = self->slot37(d8);
        module->set(old, 1);
        ((P70*)D.p70)->event(0x110, moduleAccesser);
        break;
    }

    default:
        break;
    }

    self->slot166(arg3, arg4);
}

#undef D
#undef V8
#undef V16
#undef V24
#undef V30
#undef V32
#undef V5
#undef V2
#undef V1
