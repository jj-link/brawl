#pragma force_active on
struct Vec2 {
    float x, y;
    Vec2(float a, float b) : x(a), y(b) {}
};

struct Vec3 {
    float x, y, z;
};

struct Accesser;

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
};

class Work {
public:
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
    virtual void onFlag(unsigned int);
};

struct Modules {
    char pad0[0x64];
    Work* work;
    char pad1[0x14];
    Kinetic* kinetic;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

extern "C" {
extern char g_ftCommonDataAccesser[];
extern const char lbl_102_data_5E6C[], lbl_102_data_14F4[];
extern const float lbl_102_rodata_2C;

void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_102_E124(Accesser*);
Vec3* fn_102_C5B8(Vec3*, float, float, float);
}

inline Vec2* temporaryVector(const Vec2& v) {
    return const_cast<Vec2*>(&v);
}

extern "C" void fn_102_EA98(void*, Accesser* accesser) {
    float* data = *reinterpret_cast<float**>(
        static_cast<char*>(getData__20ftCommonDataAccesserCF6ftKind(
            g_ftCommonDataAccesser, 11)) + 0x88);

    fn_102_E124(accesser);

    Energy* energy = static_cast<Energy*>(__dynamic_cast(
        accesser->modules->kinetic->getEnergy(1), 0,
        lbl_102_data_5E6C, lbl_102_data_14F4, 1));

    Vec3 rotation;
    energy->resetEnergy(
        0, temporaryVector(Vec2(lbl_102_rodata_2C, -data[10])),
        fn_102_C5B8(&rotation, lbl_102_rodata_2C,
                    lbl_102_rodata_2C, lbl_102_rodata_2C),
        accesser);

    reinterpret_cast<float*>(energy)[4] = lbl_102_rodata_2C;
    reinterpret_cast<unsigned char*>(energy)[5] |= 0x80;
    accesser->modules->work->onFlag(0x12000001);
}
