#include <ft/ft_common_data_accesser.h>
#pragma force_active on

struct Accesser;
struct Energy;

struct Speed {
    float x, y;
    Speed() {}
    Speed(float a, float b) : x(a), y(b) {}
};

class Work {
public:
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
    virtual float v18();
};

class Kinetic {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Energy* getEnergy(int);
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
    virtual void v23(int, Accesser*);
};

struct Modules {
    char pad0[0x5c];
    Work* work;
    char pad1[0x1c];
    Kinetic* kinetic;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Params {
    char pad[8];
    float a;
    float y;
};

struct Energy {
    char pad[8];
    Speed speed;
};

extern "C" {
extern const char lbl_94_data_9934[];
extern const char lbl_94_data_98E4[];
extern const char lbl_94_data_4570[];
extern const float lbl_94_rodata_70;

void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_94_1A428(void*, Accesser* a) {
    Modules* m = a->modules;
    Work* work = m->work;
    Kinetic* kinetic = m->kinetic;
    Params* p = *reinterpret_cast<Params**>(
        reinterpret_cast<char*>(g_ftCommonDataAccesser.getData((ftKind)0x18)) + 0x84);

    kinetic->v23(1, a);
    float f31 = p->a * work->v18();
    float f30 = p->y;

    Energy* e = static_cast<Energy*>(__dynamic_cast(
        kinetic->getEnergy(2), 0, lbl_94_data_9934, lbl_94_data_4570, 1));
    Speed s(f31, lbl_94_rodata_70);
    e->speed = s;

    static_cast<Energy*>(__dynamic_cast(
        kinetic->getEnergy(1), 0, lbl_94_data_98E4, lbl_94_data_4570, 1))->speed.y = f30;
}
