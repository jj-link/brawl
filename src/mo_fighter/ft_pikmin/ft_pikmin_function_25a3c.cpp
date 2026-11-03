#pragma force_active on

struct Vec3 {
    float x, y, z;
};

typedef float Mtx34[3][4];

struct Base8 {
    int a;
    int b;
};

struct Base3C {
    char pad[0x3C];
};

struct ObjA {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void* d4(unsigned int);
    virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15(); virtual void d16(); virtual void d17();
    virtual void d18(unsigned int);
};

struct Obj0 {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(int, void*);
    virtual void d5(Vec3*);
    virtual void d6();
    virtual void d7(int);
    virtual void d8(int);
    virtual unsigned int d9(int);
    virtual void d10(float);
    virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18();
    virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23(); virtual void d24(); virtual void d25(); virtual void d26(); virtual void d27(); virtual void d28(); virtual void d29();
    virtual void d30(); virtual void d31(); virtual void d32(); virtual void d33(); virtual void d34(); virtual void d35(); virtual void d36(); virtual void d37(); virtual void d38(); virtual void d39();
    virtual void d40(); virtual void d41(); virtual void d42(); virtual void d43(); virtual void d44(); virtual void d45(); virtual void d46(); virtual void d47(); virtual void d48(); virtual void d49();
    virtual void d50(); virtual void d51(); virtual void d52(); virtual void d53(); virtual void d54(); virtual void d55(); virtual void d56(); virtual void d57(); virtual void d58(); virtual void d59();
    virtual void d60(); virtual void d61(); virtual void d62(); virtual void d63(); virtual void d64(); virtual void d65(); virtual void d66(); virtual void d67(); virtual void d68(); virtual void d69();
    virtual void d70(); virtual void d71(); virtual void d72(); virtual void d73(); virtual void d74(); virtual void d75(); virtual void d76(); virtual void d77(); virtual void d78(); virtual void d79();
    virtual void d80(); virtual void d81(); virtual void d82(); virtual void d83(); virtual void d84(); virtual void d85(); virtual void d86();
    virtual void d87(int);
    virtual unsigned int d88();
};

struct Obj8 : Base8 {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9();
    virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23(); virtual void d24(); virtual void d25(); virtual void d26(); virtual void d27(); virtual void d28(); virtual void d29();
    virtual void d30(); virtual void d31(); virtual void d32(); virtual void d33(); virtual void d34(); virtual void d35(); virtual void d36(); virtual void d37(); virtual void d38(); virtual void d39();
    virtual void d40(int, void*, int);
    virtual void d41(); virtual void d42(); virtual void d43(); virtual void d44(); virtual void d45(); virtual void d46(); virtual void d47(); virtual void d48(); virtual void d49();
    virtual void d50(); virtual void d51(); virtual void d52(); virtual void d53(); virtual void d54(); virtual void d55(); virtual void d56(); virtual void d57(); virtual void d58(); virtual void d59();
    virtual void d60(); virtual void d61(); virtual void d62(); virtual void d63(); virtual void d64(); virtual void d65(); virtual void d66(); virtual void d67(); virtual void d68(); virtual void d69();
    virtual void d70(); virtual void d71(); virtual void d72(); virtual void d73(); virtual void d74(); virtual void d75(); virtual void d76(); virtual void d77(); virtual void d78(); virtual void d79();
    virtual void d80(); virtual void d81(); virtual void d82(); virtual void d83(); virtual void d84(); virtual void d85(); virtual void d86(); virtual void d87(); virtual void d88(); virtual void d89();
    virtual void d90(); virtual void d91(); virtual void d92(); virtual void d93(); virtual void d94(); virtual void d95(); virtual void d96(); virtual void d97(); virtual void d98(); virtual void d99();
    virtual void d100(); virtual void d101(); virtual void d102(); virtual void d103(); virtual void d104(); virtual void d105(); virtual void d106(); virtual void d107(); virtual void d108(); virtual void d109();
    virtual void d110();
    virtual float d111();
};

struct Obj3C : Base3C {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9();
    virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23(); virtual void d24(); virtual void d25(); virtual void d26(); virtual void d27(); virtual void d28(); virtual void d29();
    virtual void d30(); virtual void d31(); virtual void d32(); virtual void d33(); virtual void d34(); virtual void d35(); virtual void d36(); virtual void d37(); virtual void d38(); virtual void d39();
    virtual void d40(); virtual void d41(); virtual void d42();
    virtual void d43();
};

struct Modules {
    char pad0[4];
    Obj8* m4;
    char pad8[4];
    Obj0* m0c;
    Obj8* m10;
    char pad14[0x40];
    Obj0* m54;
    Obj0* m58;
    char pad5c[8];
    ObjA* m64;
};

struct Fighter {
    char pad0[8];
    Obj3C* f8;
    char padc[0xCC];
    Modules* mods;
};

extern "C" {
extern const float lbl_113_rodata_100[];
Vec3* fn_113_A1D0(Vec3* v, float x, float y, float z);
void fn_8003E3BC(Mtx34 m, Vec3* in, Vec3* out);
float fn_27_8EBA4(float value);
double atan2(double y, double x);

void fn_113_25A3C(void*, Fighter* self) {
    const float* c = lbl_113_rodata_100;
    Mtx34 mtx;
    Vec3 pos;
    Vec3 dir;

    self->mods->m64->d18(0x22000000);

    if (self->mods->m54->d88() == 1U) {
        self->mods->m4->d40(4, mtx, 0);
        fn_113_A1D0(&pos, c[0], c[0], c[0]);
        float tz = mtx[2][3];
        float ty = mtx[1][3];
        float tx = mtx[0][3];
        pos.x = tx;
        pos.y = ty;
        pos.z = tz;
        self->mods->m54->d87(1);
        pos.z = self->mods->m10->d111();
        self->mods->m0c->d5(&pos);
        fn_113_A1D0(&dir, c[0], c[0], c[1]);
        fn_8003E3BC(mtx, &dir, &dir);
        float ax = dir.x;
        float az = dir.z;
        float a = fn_27_8EBA4((float)atan2(az, ax));
        if (a >= c[0] && a < c[2]) {
            self->mods->m0c->d10(c[1]);
        } else {
            self->mods->m0c->d10(c[3]);
        }
        self->mods->m0c->d19();
        self->f8->d43();
    }

    if (self->mods->m54->d9(3) == 1U) {
        self->mods->m54->d8(3);
    }

    Obj0* b = self->mods->m54;
    void* r = self->mods->m64->d4(0x10000000);
    b->d4(3, r);
    self->mods->m58->d7(1);
}
}
