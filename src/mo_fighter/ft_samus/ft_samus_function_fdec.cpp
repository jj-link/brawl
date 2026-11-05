#include <ft/ft_common_data_accesser.h>
#pragma force_active on

struct Pair { float x, y; };
struct Speed {
    float x, y;
    Speed() {}
    Speed(float a, float b) : x(a), y(b) {}
    static void copy(Speed& dst, const Pair& src) {
        __memcpy(&dst, &src, 8);
    }
};
struct Vector { float x, y, z; };
struct AttributeFlag {
    short mask;
    AttributeFlag(int n) : mask(n) {}
};
struct Accesser;

class Energy {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void reset(int, Speed*, Vector*, Accesser*);
    unsigned char state;
    unsigned char flags;
    char pad[0x12];
    Speed speed;
    char pad20[0x1c];
    float value;
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
    virtual Pair getSum(const AttributeFlag&);
};

class Class_CF88 {
public:
    virtual void fn_94_6CF8();
    virtual void fn_94_1CAF0();
    virtual void fn_94_1DAE0();
    virtual void fn_94_1DAD8();
    virtual void fn_94_1DAD0();
    virtual void fn_94_1DAC8();
    virtual void fn_94_1DAC0();
    virtual void fn_94_1DAB8();
    virtual void fn_94_1DAB0();
    virtual void fn_94_1DAA8();
    virtual void fn_94_1DAA0();
    virtual void fn_94_1DA98();
    virtual void fn_94_1DA90();
    virtual void fn_94_1DA88();
    virtual void fn_94_1DA38();
    virtual void fn_94_1DA80();
    virtual void fn_94_1DA70();
    virtual int fn_94_1DA60(unsigned int);
    virtual void fn_94_1DA50(unsigned int);
    virtual void fn_94_1DA40(unsigned int);
};

class Status {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void change(int, Accesser*);
};

struct Modules {
    char pad0[0x64];
    Class_CF88* work;
    char pad68[8];
    Status* status;
    char pad74[8];
    Kinetic* kinetic;
};
struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
extern const char lbl_94_data_9804[];
extern const char lbl_94_data_98E4[];
extern const char lbl_94_data_9934[];
extern const char lbl_94_data_4570[];
extern const float lbl_94_rodata_30;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_94_F574(Accesser*);
Vector* fn_94_94E0(Vector*, float, float, float);
Speed* fn_94_F174(Speed*, float, float);
void fn_94_FABC(Energy*, const Speed*);
}

inline Speed* temporary(const Speed& s) {
    return const_cast<Speed*>(&s);
}

extern "C" void fn_94_FDEC(void*, Accesser* a) {
    Status* status;
    Class_CF88* work;
    struct { float* params; } data;
    data.params = *reinterpret_cast<float**>(
        reinterpret_cast<char*>(g_ftCommonDataAccesser.getData((ftKind)3)) + 0x84);
    status = a->modules->status;
    work = a->modules->work;
    if (!work->fn_94_1DA60(0x22000011) &&
        work->fn_94_1DA60(0x22000012)) {
        Energy* e = static_cast<Energy*>(__dynamic_cast(
            a->modules->kinetic->getEnergy(3), 0,
            lbl_94_data_9804, lbl_94_data_4570, 1));
        Speed speed;
        Speed::copy(speed, a->modules->kinetic->getSum(AttributeFlag(1)));
        fn_94_F574(a);
        Vector v;
        e->reset(0, temporary(Speed(speed.x, lbl_94_rodata_30)),
            fn_94_94E0(&v, lbl_94_rodata_30, lbl_94_rodata_30, lbl_94_rodata_30), a);
        e->flags |= 0x80;
        work->fn_94_1DA40(0x22000012);
    }
    if (work->fn_94_1DA60(0x22000010)) {
        Speed speed;
        Speed::copy(speed, a->modules->kinetic->getSum(AttributeFlag(1)));
        fn_94_F574(a);
        speed.y = data.params[0];
        Energy* e = static_cast<Energy*>(__dynamic_cast(
            a->modules->kinetic->getEnergy(2), 0,
            lbl_94_data_9934, lbl_94_data_4570, 1));
        Vector v;
        e->reset(10, temporary(Speed(speed.x, lbl_94_rodata_30)),
            fn_94_94E0(&v, lbl_94_rodata_30, lbl_94_rodata_30, lbl_94_rodata_30), a);
        e->value = data.params[4];
        fn_94_FABC(e, fn_94_F174(temporary(Speed()), data.params[2] * e->speed.x, e->speed.y));
        e->flags |= 0x80;
        e = static_cast<Energy*>(__dynamic_cast(
            a->modules->kinetic->getEnergy(1), 0,
            lbl_94_data_98E4, lbl_94_data_4570, 1));
        Vector v2;
        e->reset(0, temporary(Speed(lbl_94_rodata_30, speed.y)),
            fn_94_94E0(&v2, lbl_94_rodata_30, lbl_94_rodata_30, lbl_94_rodata_30), a);
        e->flags |= 0x80;
        status->change(0x11e, a);
        work->fn_94_1DA40(0x22000010);
    }
}
