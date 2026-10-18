#pragma force_active on
extern "C" {
extern const unsigned char lbl_121_data_7C34[];
extern const unsigned char lbl_121_data_3CF0[];
extern const unsigned char lbl_121_data_8EF0[];
extern const unsigned char lbl_121_data_31F4[];
extern const float lbl_121_rodata_A0;
extern const float lbl_121_rodata_A4;

void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct Vec2 {
    float x, y;
};

struct Vec3 {
    float x, y, z;
    Vec3();
    Vec3(const Vec3&);
};

extern "C" Vec2* fn_121_DAE8(Vec2*, const Vec2*);

class KineticModule {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void* getEnergy(int);
};

class WorkModule {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void setInt(int, unsigned int);
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual float getFloat(unsigned int);
    virtual void setFloat(float, unsigned int);
};

class ModelModule {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual Vec3 getPosition(int);
    virtual void setPosition(const Vec3&, int);
};

struct Modules {
    unsigned char unused0[0x0C];
    ModelModule* model;
    unsigned char unused1[0x54];
    WorkModule* work;
    unsigned char unused2[0x14];
    KineticModule* kinetic;
};

struct Accesser {
    unsigned char unused0[8];
    void* stageObject;
    unsigned char unused1[0xCC];
    Modules* modules;
};

struct Fighter {
    unsigned char unused[0x20E4];
    unsigned char* parameters;
};

extern "C" void fn_121_14C68(void*, Accesser* accesser)
{
    unsigned char* parameters = static_cast<Fighter*>(__dynamic_cast(
        accesser->stageObject, 0x3C,
        lbl_121_data_7C34, lbl_121_data_3CF0, 1))->parameters;

    unsigned char* energy = static_cast<unsigned char*>(__dynamic_cast(
        accesser->modules->kinetic->getEnergy(0), 0,
        lbl_121_data_8EF0, lbl_121_data_31F4, 1));

    Vec2 acceleration;
    acceleration.x = lbl_121_rodata_A0;
    acceleration.y = lbl_121_rodata_A0;
    fn_121_DAE8(reinterpret_cast<Vec2*>(energy + 0x10), &acceleration);

    float value = accesser->modules->work->getFloat(0x11000001);
    if (value <= lbl_121_rodata_A0) {
        value += lbl_121_rodata_A4;
    } else {
        value -= lbl_121_rodata_A4;
    }

    accesser->modules->work->setFloat(value, 0x11000001);
    accesser->modules->work->setInt(
        *reinterpret_cast<int*>(parameters + 0x34), 0x20000000);

    Vec3 position = accesser->modules->model->getPosition(1);
    position.y = *reinterpret_cast<float*>(parameters + 0x18);
    accesser->modules->model->setPosition(position, 1);
}
