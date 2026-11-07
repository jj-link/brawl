#include <ft/ft_common_data_accesser.h>
#include <so/ground/so_ground_module_impl.h>
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

struct Flag {
    short mask;
    Flag(int n) : mask(n) {}
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
    unsigned char state, flags;
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
    virtual Pair getSum(const Flag&);
};

class Work {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int getInt(unsigned int);
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
    virtual int isFlag(unsigned int);
    virtual void onFlag(unsigned int);
    virtual void offFlag(unsigned int);
};

class Status {
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
    virtual int getStatus();
};

class Visibility {
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
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void extra();
    virtual void set(int, int);
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void set2(int, int);
};

class Situation {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void set(int, int);
};

struct Modules {
    char pad0[0x10];
    soGroundModule* other;
    Situation* situation;
    char pad18[0x4c];
    Work* work;
    char pad68[8];
    Status* status;
    char pad74[8];
    Kinetic* kinetic;
    char pad80[0x28];
    Visibility* visibility;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
extern const char lbl_94_data_9934[];
extern const char lbl_94_data_98E4[];
extern const char lbl_94_data_4570[];
extern const float lbl_94_rodata_30;

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_94_F63C(Accesser*);
void fn_94_F574(Accesser*);
Vector* fn_94_94E0(Vector*, float, float, float);
Speed* fn_94_F174(Speed*, float, float);
void fn_94_FABC(Energy*, const Speed*);
}

inline Speed* temporary(const Speed& s) {
    return const_cast<Speed*>(&s);
}

extern "C" void fn_94_1032C(void*, Accesser* a) {
    Work* work = a->modules->work;
    if (work->isFlag(0x1200003e)) {
        fn_94_F63C(a);
        work->offFlag(0x1200003e);
    }

    Visibility* visibility = a->modules->visibility;
    int index = work->getInt(0x10000043) != 2;
    visibility->set(index, 0);
    visibility->set2(index, 255);

    int status = a->modules->status->getStatus();
    Speed speed;
    Speed::copy(speed, a->modules->kinetic->getSum(Flag(1)));

    float* params = *reinterpret_cast<float**>(
        reinterpret_cast<char*>(g_ftCommonDataAccesser.getData((ftKind)3)) + 0x84);
    fn_94_F574(a);

    float f31, f30;
    switch (status) {
    case 0x121:
        f30 = params[0x10];
        f31 = f30;
        break;
    default:
        f31 = params[5];
        f30 = params[3];
        break;
    }

    Energy* e = static_cast<Energy*>(__dynamic_cast(
        a->modules->kinetic->getEnergy(2), 0,
        lbl_94_data_9934, lbl_94_data_4570, 1));

    Vector v;
    e->reset(0, temporary(Speed(speed.x, lbl_94_rodata_30)),
        fn_94_94E0(&v, lbl_94_rodata_30, lbl_94_rodata_30, lbl_94_rodata_30), a);
    e->value = f31;
    fn_94_FABC(e, fn_94_F174(temporary(Speed()),
        f30 * e->speed.x, e->speed.y));
    e->flags |= 0x80;

    e = static_cast<Energy*>(__dynamic_cast(
        a->modules->kinetic->getEnergy(1), 0,
        lbl_94_data_98E4, lbl_94_data_4570, 1));

    Vector v2;
    e->reset(0, temporary(Speed(lbl_94_rodata_30, speed.y)),
        fn_94_94E0(&v2, lbl_94_rodata_30, lbl_94_rodata_30, lbl_94_rodata_30), a);
    e->flags |= 0x80;

    a->modules->situation->set(2, 0);
    a->modules->other->setCorrect((soGroundShapeImpl::CorrectKind)5, 0);
}
