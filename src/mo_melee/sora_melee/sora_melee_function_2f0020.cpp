#pragma force_active on

struct Vec3 {
    float x, y, z;
};

class T70 {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual int s16(void*);
};

class TC {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual Vec3 s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8();
    virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12();
    virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16();
    virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20();
    virtual void s21(); virtual float s22();
};

class TD {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual float s12(unsigned int, void*);
};

struct Pad {
    char pad[8];
};

class TE : public Pad {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21();
    virtual void s22(int, Vec3*, Vec3*, const Vec3*, float);
};

struct Mods {
    char p0[4];
    TE* te;
    char p8[4];
    TC* tc;
    char p10[0x54];
    TD* td;
    char p68[8];
    T70* t70;
};

struct Obj {
    char pad[0xd8];
    Mods* mods;
};

struct Self {
    char pad[0x60];
    Obj* obj;
};

extern "C" void fn_27_492C(void*);
extern "C" float lbl_27_rodata_6488[];

extern "C" void fn_27_2F0020(Self* self) {
    float* lbl = lbl_27_rodata_6488;

    switch (self->obj->mods->t70->s16(self->obj)) {
    case 0: {
        float f31 = self->obj->mods->tc->s22();
        const Vec3& v20 = self->obj->mods->tc->s4();
        self->obj->mods->tc->s9();

        float product = lbl[5] *
            self->obj->mods->td->s12(0x11000001, self->obj);

        Vec3 v14;
        v14.y = lbl[6];
        v14.x = product;
        v14.z = lbl[1];

        Vec3 v8;
        v8.x = f31;
        v8.y = f31;
        v8.z = f31;

        self->obj->mods->te->s22(0, &v8, &v14, &v20, product);
        break;
    }
    default:
        fn_27_492C(self);
        break;
    }
}
