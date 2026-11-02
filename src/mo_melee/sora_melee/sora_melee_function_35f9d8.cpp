#pragma force_active on
#pragma fp_contract off

typedef unsigned long long u64;

struct Vec2 {
    float x;
    float y;
};

inline Vec2 unpack(u64 bits) {
    return *(Vec2*)&bits;
}

struct WorkModule {
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
    virtual float getFloat(unsigned long);
    virtual void setFloat(unsigned long, float);
};

struct Energy {
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
    virtual void e4();
    virtual void e5();
    virtual void* get(int);
    virtual void e7();
    virtual void e8();
    virtual void e9();
    virtual void e10();
    virtual void e11();
    virtual void e12();
    virtual u64 position(short*);
};

struct Dst {
    virtual void d0();
    virtual void d1();
    virtual u64 d2();
};

struct Modules {
    char pad0[0x64];
    WorkModule* work;
    char pad1[0x14];
    Energy* energy;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct Self {
    char pad[0x60];
    Access* access;
};

extern "C" {
extern char lbl_27_data_457C0[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_7A10[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_1DAE14(void*);
float rsqrtf__Ff(float);
double atan2(double, double);
double __fabs(double);

int fn_27_35F9D8(void* arg0) {
    Self* self = (Self*)arg0;
    const float* k = lbl_27_rodata_7A10;
    fn_27_1DAE14(arg0);

    Energy* energy = self->access->modules->energy;
    Dst* dst = (Dst*)__dynamic_cast(energy->get(0), 0, lbl_27_data_457C0, lbl_27_data_CDF8, 1);

    Vec2 v = unpack(dst->d2());
    float sum = v.x * v.x + v.y * v.y;
    float mag;
    if ((float)__fabs(sum) <= k[8]) {
        mag = k[1];
    } else {
        mag = sum * rsqrtf__Ff(sum);
    }

    if (mag > k[9]) {
        double x = v.x;
        double y = v.y;
        float angle = k[10] * (float)atan2(y, x);
        Modules* m = self->access->modules;
        m->work->setFloat(0x11000002, angle);
    }
    return 0;
}
}
