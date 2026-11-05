#pragma force_active on
#include <mt/mt_vector.h>

struct Flag {
    unsigned char value;
};

struct StatusModule {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual Vec2f v13(short* p);
};

struct WorkModule {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
};

struct PostureModule {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float v9();
};

struct Modules {
    char p0[0xc];
    PostureModule* posture;
    char p1[0x64 - 0x10];
    WorkModule* work;
    char p2[0x7c - 0x68];
    StatusModule* status;
};

struct Access {
    char pad[0xd8];
    Modules* mods;
};

struct PikminEnergy {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void activate();

    unsigned char m_isNull;
    unsigned char m_flags;
    unsigned char m_pad[2];
    Vec2f speed;
    Vec2f accel;
    Vec2f p18;
    Vec2f p20;
    Vec2f p28;
    unsigned char active;
};

extern "C" {
extern const float lbl_113_rodata_90;
void fn_113_BC00(Vec2f*, const Vec2f*);
float fn_113_22580(void*);
float fn_113_225F4(void*);
float fn_113_22668(void*);
float fn_113_226DC(void*);
}

extern "C" void fn_113_1E9F0(void*, unsigned char* energies, Access* access) {
    short spA = 1;
    Vec2f speed;
    Vec2f::copy(speed, access->mods->status->v13(&spA));
    access->mods->status->v12();
    access->mods->work->v23();
    Flag flag = {0};
    PikminEnergy* stop = reinterpret_cast<PikminEnergy*>(energies + 0x10);
    stop->active = 1;
    stop->activate();
    fn_113_BC00(&stop->speed, &speed);
    fn_113_BC00(&stop->p18, &Vec2f(fn_113_22580(access), lbl_113_rodata_90));
    fn_113_BC00(&stop->p20, &Vec2f(fn_113_225F4(access), lbl_113_rodata_90));
    fn_113_BC00(&stop->p28, &Vec2f(fn_113_22668(access), lbl_113_rodata_90));
    float a = fn_113_226DC(access);
    if (access->mods->posture->v9() > lbl_113_rodata_90) {
        a = -a;
    }
    fn_113_BC00(&stop->accel, &Vec2f(a, lbl_113_rodata_90));
    reinterpret_cast<unsigned char*>(stop)[5] |= 0x80;
}
