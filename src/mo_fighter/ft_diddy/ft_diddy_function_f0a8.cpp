#pragma force_active on

struct Pair {
    float x, y;
};

struct Speed {
    float x, y;
    Speed() {}
    Speed(float x_, float y_) : x(x_), y(y_) {}
};

struct Vector {
    float x, y, z;
};

struct Params {
    char pad[0x64];
    float accel, limit, brake, terminal;
    char rest[0x270];
};

struct Accesser;

class Energy {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void reset(int, Speed*, Vector*, Accesser*);

    unsigned char state;
    unsigned char flags;
    char pad[10];
    float accel, limit, brake, terminal;
};

class Kinetic {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual Energy* getEnergy(int);
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual Pair getSum(const unsigned short&);
};

struct Modules {
    char pad[0x7c];
    Kinetic* kinetic;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
    extern char g_ftCommonDataAccesser;
    Params* getParam__20ftCommonDataAccesserCF6ftKind(const void*, int);
    extern const char lbl_115_data_7524[];
    extern const char lbl_115_data_2760[];
    extern const char lbl_115_data_7444[];
    extern const float lbl_115_rodata_5C;

    void* __dynamic_cast(void*, long, const void*, const void*, short);
    Vector* fn_115_8EF8(Vector*, float, float, float);
    void fn_27_89DAC(int, Accesser*);
}

extern "C" void fn_115_F0A8(Accesser* accesser) {
    unsigned short mask = 1;
    Speed speed;
    Pair sum = accesser->modules->kinetic->getSum(mask);
    __memcpy(&speed, &sum, sizeof(speed));

    Params params = *getParam__20ftCommonDataAccesserCF6ftKind(
        &g_ftCommonDataAccesser, 0x1b);

    Energy* gravity = static_cast<Energy*>(__dynamic_cast(
        accesser->modules->kinetic->getEnergy(1), 0,
        lbl_115_data_7524, lbl_115_data_2760, 1));

    Speed vertical(lbl_115_rodata_5C, speed.y);
    Vector rotation;
    gravity->reset(0, &vertical,
        fn_115_8EF8(&rotation, lbl_115_rodata_5C,
            lbl_115_rodata_5C, lbl_115_rodata_5C),
        accesser);

    gravity->flags |= 0x80;
    gravity->accel = -params.accel;
    gravity->limit = params.limit;
    gravity->brake = params.brake;
    gravity->terminal = params.terminal;

    Energy* stop = static_cast<Energy*>(__dynamic_cast(
        accesser->modules->kinetic->getEnergy(3), 0,
        lbl_115_data_7444, lbl_115_data_2760, 1));

    Speed horizontal(speed.x, lbl_115_rodata_5C);
    Vector rotation2;
    stop->reset(6, &horizontal,
        fn_115_8EF8(&rotation2, lbl_115_rodata_5C,
            lbl_115_rodata_5C, lbl_115_rodata_5C),
        accesser);

    stop->flags |= 0x80;
    fn_27_89DAC(2, accesser);
    fn_27_89DAC(0, accesser);
}
