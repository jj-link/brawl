#pragma force_active on

typedef unsigned long long u64;

struct Vec2f {
    float m_x;
    float m_y;
};

struct Vec3f {
    float m_x;
    float m_y;
    float m_z;
};

struct Parameters {
    Vec2f p[4];
};

struct Posture {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual Vec3f getPos();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual float getLr();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual float getScale();
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

struct WorkModule {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual unsigned int getFloat(unsigned int);
};

struct Modules {
    char pad0[0x0c];
    Posture* posture;
    char pad1[0x54];
    WorkModule* work;
    char pad2[0x14];
    Kinetic* kinetic;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct DataContainer {
    char pad[0x88];
    float* data;
};

struct Object {
    char pad0[0x60];
    Accesser* accesser;
    char pad1[0x1860c];
    DataContainer* dataContainer;
};

extern "C" {
void fn_27_13CC24(void*);
void fn_104_A024(Parameters*);
void fn_27_13FE28(void*, const Vec3f&, float, float, const Vec2f&,
                   const Parameters&, const Parameters&, int);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    Accesser*, unsigned long, unsigned long);
extern const float lbl_104_rodata_8;
extern const float lbl_104_rodata_10;
}

extern "C" void fn_104_9E38(Object* object, void* output) {
    Posture* posture;
    fn_27_13CC24(object);

    Accesser* accesser = object->accesser;
    const float* data = object->dataContainer->data;

    Parameters b;
    fn_104_A024(&b);
    b.p[0].m_x = lbl_104_rodata_8;
    b.p[1].m_x =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xbd6, 0);
    b.p[2].m_x = lbl_104_rodata_8;
    b.p[3].m_x =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xbd8, 0);
    b.p[0].m_y = -data[2];
    b.p[1].m_y =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xbd1, 0);
    b.p[2].m_y = data[3];
    b.p[3].m_y = data[3];

    Parameters a;
    fn_104_A024(&a);
    a.p[0].m_x = lbl_104_rodata_8;
    a.p[1].m_x =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xbbc, 0);
    a.p[2].m_x = lbl_104_rodata_8;
    a.p[3].m_x = lbl_104_rodata_10;
    a.p[0].m_y = lbl_104_rodata_8;
    a.p[1].m_y = lbl_104_rodata_8;
    a.p[2].m_y = lbl_104_rodata_8;
    a.p[3].m_y = lbl_104_rodata_8;

    short flag = -1;
    Vec2f speed;
    *(u64*)&speed = accesser->modules->kinetic->getSpeed(&flag);

    posture = accesser->modules->posture;
    fn_27_13FE28(output, posture->getPos(), posture->getScale(),
                 posture->getLr(), speed, a, b, 0xe0013);

    *(unsigned int*)((char*)output + 0x100) =
        accesser->modules->work->getFloat(0x10000040);
}
