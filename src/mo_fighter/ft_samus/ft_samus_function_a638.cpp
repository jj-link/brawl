#pragma force_active on
typedef unsigned long long u64;

struct Vec2f { float m_x, m_y; };
struct Vec3f { float m_x, m_y, m_z; };
struct Parameters { Vec2f p[4]; };

struct Status {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual int getKind();
};

struct Kinetic {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual u64 getSpeed(const short*);
};

struct Posture {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual Vec3f getPos();
    virtual void unusedB0();
    virtual void unusedB1();
    virtual void unusedB2();
    virtual void unusedB3();
    virtual float getLr();
    virtual void unusedC0();
    virtual void unusedC1();
    virtual void unusedC2();
    virtual void unusedC3();
    virtual void unusedC4();
    virtual void unusedC5();
    virtual void unusedC6();
    virtual void unusedC7();
    virtual void unusedC8();
    virtual void unusedC9();
    virtual void unusedC10();
    virtual void unusedC11();
    virtual float getScale();
};

struct Modules {
    char pad[0xc];
    Posture* posture;
    char pad1[0x60];
    Status* status;
    char pad2[8];
    Kinetic* kinetic;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Object {
    char pad[0x60];
    Accesser* accesser;
};

struct Data {
    char pad[0x8c];
    float* params;
};

extern "C" {
void fn_27_13CC24(void*);
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
extern unsigned char g_ftCommonDataAccesser;
void fn_94_A82C(Parameters*);
extern const float lbl_94_rodata_C;
extern const float lbl_94_rodata_20;

float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    Accesser*, unsigned long, unsigned long);

void fn_27_13FE28(
    void*, const Vec3f&, float, float, const Vec2f&,
    const Parameters&, const Parameters&, int);
}

extern "C" void fn_94_A638(Object* object, void* output) {
    fn_27_13CC24(object);

    Accesser* accesser = object->accesser;
    float* data = ((Data*)getData__20ftCommonDataAccesserCF6ftKind(
        &g_ftCommonDataAccesser, 3))->params;

    Parameters b;
    fn_94_A82C(&b);
    b.p[0].m_x = lbl_94_rodata_C;
    b.p[1].m_x =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xbd6, 0);
    b.p[2].m_x = lbl_94_rodata_C;
    b.p[3].m_x =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xbd8, 0);
    b.p[0].m_y = -data[1];
    b.p[1].m_y =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xbd1, 0);
    b.p[2].m_y = data[2];
    b.p[3].m_y = data[2];

    Parameters a;
    fn_94_A82C(&a);
    a.p[0].m_x = lbl_94_rodata_C;
    a.p[1].m_x =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xbbc, 0);
    a.p[2].m_x = lbl_94_rodata_C;
    a.p[3].m_x = lbl_94_rodata_20;
    a.p[0].m_y = lbl_94_rodata_C;
    a.p[1].m_y = lbl_94_rodata_C;
    a.p[2].m_y = lbl_94_rodata_C;
    a.p[3].m_y = lbl_94_rodata_C;

    int kind = 0;
    Status* status = accesser->modules->status;
    if (status->getKind() != 0x10b)
        kind = 0x84;

    short flag = -1;
    Kinetic* kinetic = accesser->modules->kinetic;
    Vec2f speed;
    *(u64*)&speed = kinetic->getSpeed(&flag);

    Posture* posture = accesser->modules->posture;
    fn_27_13FE28(
        output, posture->getPos(), posture->getScale(),
        posture->getLr(), speed, a, b, kind);
}
