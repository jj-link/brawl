#pragma force_active on

struct BD50Data {
    int value;
    float first;
    float second;
    unsigned char flags[4];
};

extern "C" void fn_105_BD50(BD50Data*, int, float, float, unsigned char, unsigned char, int, unsigned char);

extern float lbl_105_rodata_58;
extern float lbl_105_rodata_5C;

class Mod64 {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16();
    virtual unsigned long f17(unsigned long);
    virtual void s18();
    virtual void f19(unsigned long);
};

class Mod08 {
public:
    virtual void t0(); virtual void t1(); virtual void t2(); virtual void t3();
    virtual void t4(); virtual void t5(); virtual void t6(); virtual void t7();
    virtual void t8(); virtual void t9(); virtual void t10(); virtual void t11();
    virtual float f12();
    virtual void t13(); virtual void t14(); virtual void t15(); virtual void t16();
    virtual void t17(); virtual void t18(); virtual void t19(); virtual void t20();
    virtual int f21();
    virtual void t22(); virtual void t23(); virtual void t24(); virtual void t25();
    virtual void t26(); virtual void t27(); virtual void t28(); virtual void t29();
    virtual void f30(BD50Data*);
};

struct Mods {
    char p0[0x8];
    Mod08* mod08;
    char p1[0x58];
    Mod64* mod64;
};

struct Ic {
    char p[0xd8];
    Mods* mods;
};

extern "C" void fn_105_144E8(void*, Ic* self)
{
    if (self->mods->mod64->f17(0x22000014UL) == 1UL) {
        self->mods->mod64->f19(0x22000014UL);

        BD50Data data;
        float v = lbl_105_rodata_58;
        int flag = 0;
        unsigned char z = 0;

        if (self->mods->mod08->f21() == 0x1D7) {
            v = self->mods->mod08->f12();
            flag = 1;
        }
        fn_105_BD50(&data, 0x1DE, v, lbl_105_rodata_5C, z, z, flag, z);
        self->mods->mod08->f30(&data);
    } else {
        if (self->mods->mod64->f17(0x22000015UL) == 1UL) {
            self->mods->mod64->f19(0x22000015UL);

            BD50Data data;
            float v = lbl_105_rodata_58;
            int flag = 0;
            unsigned char z = 0;

            if (self->mods->mod08->f21() == 0x1D6) {
                v = self->mods->mod08->f12();
                flag = 1;
            }
            fn_105_BD50(&data, 0x1DF, v, lbl_105_rodata_5C, z, z, flag, z);
            self->mods->mod08->f30(&data);
        }
    }
}
