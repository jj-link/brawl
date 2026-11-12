#pragma force_active on
#define V1(n) virtual void f##n();
#define V10(n) V1(n##0) V1(n##1) V1(n##2) V1(n##3) V1(n##4) V1(n##5) V1(n##6) V1(n##7) V1(n##8) V1(n##9)

struct Vec3f { float x, y, z; };

struct Pad {
    char p[0x28];
    int taskId;
    char q[0x10];
};

struct Fighter : Pad {
    V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V10(6) V10(7) V10(8) V10(9)
    V10(10) V10(11) V10(12) V10(13) V10(14) V10(15) V10(16) V10(17)
    V1(180) V1(181) V1(182) V1(183) V1(184)
    virtual void* s187();
};

struct Pad8 {
    char p[8];
};

struct ObjB : Pad8 {
    V1(0) V1(1) V1(2) V1(3)
    virtual void* s6();
};

struct Obj12 {
    V10(0)
    virtual void* s12();
};

struct Posture {
    V1(0) V1(1) V1(2) V1(3) V1(4) V1(5) V1(6) V1(7) V1(8)
    virtual float s11();
};

struct ObjA {
    V10(0) V1(10) V1(11)
    virtual float s14(int);
};

struct Modules {
    ObjB* m0;
    char p4[8];
    Posture* mC;
    char p10[0x54];
    ObjA* m64;
};

struct Accesser {
    char p[8];
    void* m8;
    char q[0xcc];
    Modules* mD8;
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(void*);
Vec3f* fn_120_8718(Vec3f*, float, float, float);
void fn_120_13670(void*, int, void*, int, Vec3f*, float, float);
extern const char lbl_120_data_242C[], lbl_120_data_2CA8[];
extern const float lbl_120_rodata_8;
}

extern "C" int fn_120_85D4(void* arg0, Accesser* arg1) {
    float f31;
    Vec3f sp8;
    Fighter* fighter = (Fighter*)__dynamic_cast(arg1->m8, 0x3c, lbl_120_data_242C, lbl_120_data_2CA8, 1);
    Modules* mods = arg1->mD8;
    Posture* r30 = mods->mC;
    ObjB* r29 = mods->m0;
    int taskId = fighter->taskId;
    ObjA* objA = mods->m64;
    float f30 = (float)objA->s14(0x11000014);
    f31 = r30->s11();
    Vec3f* vec = fn_120_8718(&sp8, lbl_120_rodata_8, lbl_120_rodata_8, lbl_120_rodata_8);
    int owner = fn_27_111364(fighter->s187());
    Obj12* o = (Obj12*)r29->s6();
    void* r5 = o->s12();
    fn_120_13670(arg0, taskId, r5, owner, vec, f31, f30);
    return 1;
}
