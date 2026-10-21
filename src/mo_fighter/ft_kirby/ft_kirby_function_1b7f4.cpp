#pragma force_active on

struct Vec2f {
    float m_x, m_y;

    Vec2f() {}
    Vec2f(float x, float y) : m_x(x), m_y(y) {}

    static void copy(Vec2f& dst, const Vec2f& src) {
        __memcpy(&dst, &src, 8);
    }
};

struct Vec3f {
    float x, y, z;
};

class soModuleAccesser;

class soKineticEnergy {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void resetEnergy(int, Vec2f*, Vec3f*, soModuleAccesser*);

    struct AttributeFlag {
        short mask;
        AttributeFlag(int n) : mask(n) {}
    };
};

class Kinetic {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual soKineticEnergy* getEnergy(int);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual Vec2f getSumSpeed(const soKineticEnergy::AttributeFlag&);
};

struct Enumeration {
    char pad[0x7c];
    Kinetic* k;
};

class soModuleAccesser {
public:
    char pad[0xd8];
    Enumeration* e;

    Kinetic& getKineticModule() {
        return *e->k;
    }
};

extern "C" {
extern const char lbl_96_data_AF64[];
extern const char lbl_96_data_5E00[];
extern const float lbl_96_rodata_A8;

void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_96_BC54(Vec3f*, float, float, float);
void fn_27_89DAC(int, soModuleAccesser*);
}

static inline Vec2f* temp(const Vec2f& v) {
    return const_cast<Vec2f*>(&v);
}

extern "C" void fn_96_1B7F4(void*, soModuleAccesser* a) {
    soKineticEnergy* stop = static_cast<soKineticEnergy*>(__dynamic_cast(
        a->getKineticModule().getEnergy(3), 0,
        lbl_96_data_AF64, lbl_96_data_5E00, 1));

    Vec2f speed;
    Vec2f::copy(speed, a->getKineticModule().getSumSpeed(
        soKineticEnergy::AttributeFlag(1)));

    Vec3f r1;
    stop->resetEnergy(
        0, temp(Vec2f(speed.m_x, lbl_96_rodata_A8)),
        fn_96_BC54(&r1, lbl_96_rodata_A8,
                   lbl_96_rodata_A8, lbl_96_rodata_A8),
        a);

    fn_27_89DAC(1, a);
}
