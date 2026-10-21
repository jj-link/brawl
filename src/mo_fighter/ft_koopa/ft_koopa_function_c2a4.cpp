#pragma force_active on
namespace {
struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(float a, float b) : x(a), y(b) {}
};

inline Vec2* temporaryVector(const Vec2& v) {
    return const_cast<Vec2*>(&v);
}
}

struct Vec3 {
    float x, y, z;
};

struct Flag {
    unsigned short mask;
};

struct Accesser;

class Situation {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int getKind();
};

class Work {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setInt(int, unsigned int);
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
    virtual void onFlag(unsigned int);
    virtual void offFlag(unsigned int);
    virtual void v20();
    virtual void v21();
    virtual void clear(int);
};

class Energy {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void resetEnergy(int, Vec2*, Vec3*, Accesser*);
};

class Kinetic {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Energy* getEnergy(int);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual Vec2 getSumSpeed(const Flag&);
};

struct Modules {
    char pad0[0x14];
    Situation* situation;
    char pad1[0x4C];
    Work* work;
    char pad2[0x14];
    Kinetic* kinetic;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

extern "C" {
extern char g_ftCommonDataAccesser[];
extern const char lbl_102_data_5E6C[];
extern const char lbl_102_data_5EBC[];
extern const char lbl_102_data_14F4[];
extern const float lbl_102_rodata_10;

void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_102_C1DC(Accesser*);
Vec3* fn_102_C5B8(Vec3*, float, float, float);
void fn_102_C5AC(Vec2*, float, float);
void fn_102_B024(Vec2*, const Vec2*);
}

static inline void apply(Vec2* dst, const float* a, const float* b, const Vec2& t) {
    fn_102_C5AC(const_cast<Vec2*>(&t), *a, *b);
    fn_102_B024(dst, &t);
}

extern "C" void fn_102_C2A4(Accesser* accesser) {
    Work* work = accesser->modules->work;
    int situation = accesser->modules->situation->getKind();

    work->clear(2);
    work->offFlag(0x22000010);
    work->offFlag(0x22000011);
    work->offFlag(0x22000012);
    work->offFlag(0x22000013);
    work->offFlag(0x22000014);
    work->onFlag(0x22000015);
    work->setInt(0, 0x20000000);
    work->offFlag(0x1200003F);

    if (situation == 2) {
        float* data = *reinterpret_cast<float**>(
            static_cast<char*>(getData__20ftCommonDataAccesserCF6ftKind(
                g_ftCommonDataAccesser, 11)) + 0x80);

        Flag flag;
        flag.mask = 1;
        Vec2 speed;
        __memcpy(&speed, &accesser->modules->kinetic->getSumSpeed(flag),
                 sizeof(Vec2));
        speed.y = data[1];

        fn_102_C1DC(accesser);

        Energy* gravity = static_cast<Energy*>(__dynamic_cast(
            accesser->modules->kinetic->getEnergy(1), 0,
            lbl_102_data_5E6C, lbl_102_data_14F4, 1));

        Vec3 rotation;
        gravity->resetEnergy(
            0, temporaryVector(Vec2(lbl_102_rodata_10, speed.y)),
            fn_102_C5B8(&rotation, lbl_102_rodata_10,
                        lbl_102_rodata_10, lbl_102_rodata_10),
            accesser);

        reinterpret_cast<float*>(gravity)[4] = -data[2];
        reinterpret_cast<float*>(gravity)[5] = data[3];
        reinterpret_cast<float*>(gravity)[7] = data[3];
        reinterpret_cast<unsigned char*>(gravity)[5] |= 0x80;

        Energy* control = static_cast<Energy*>(__dynamic_cast(
            accesser->modules->kinetic->getEnergy(2), 0,
            lbl_102_data_5EBC, lbl_102_data_14F4, 1));

        Vec3 rotation2;
        control->resetEnergy(
            0, temporaryVector(Vec2(speed.x, lbl_102_rodata_10)),
            fn_102_C5B8(&rotation2, lbl_102_rodata_10,
                        lbl_102_rodata_10, lbl_102_rodata_10),
            accesser);

        reinterpret_cast<float*>(control)[15] = data[7];

        apply(reinterpret_cast<Vec2*>(reinterpret_cast<char*>(control) + 0x18),
              &data[5], &reinterpret_cast<float*>(control)[7], Vec2());
        apply(reinterpret_cast<Vec2*>(reinterpret_cast<char*>(control) + 0x28),
              &data[5], &reinterpret_cast<float*>(control)[11], Vec2());

        reinterpret_cast<unsigned char*>(control)[5] |= 0x80;
    }
}
