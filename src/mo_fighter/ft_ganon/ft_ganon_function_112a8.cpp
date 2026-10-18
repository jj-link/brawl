#pragma force_active on
struct Vec {
    float x, y, z;
};

struct Param {
    unsigned task, a, b, c;
    int owner, team, f18, f1c;
    Vec pos;
    float lr;
    int value, f34, situation, status, f40, motion, f48;
    unsigned char active : 1;
    unsigned char bits1 : 3;
    unsigned char bit4 : 1;
    unsigned char bits5 : 3;
    unsigned char bits6 : 2;
    unsigned char reserved : 6;

    Param(unsigned t, unsigned r, int v, const Vec& p, float f)
        : task(t), a(r), b(r), c(r), owner(-1), team(-1),
          f18(0), f1c(0), pos(p), lr(f), value(v), f34(0),
          situation(2), status(128), f40(0), motion(0x35f),
          f48(0), active(1), bits1(0), bit4(1), bits5(0),
          bits6(0) {}
};

class Energy {
public:
    virtual void slot08();
    virtual void init(int);
    virtual void slot10();
    virtual void add(int, int, bool);
    virtual void finish();
};

class Kinetic {
public:
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2c();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3c();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4c();
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual void s5c();
    virtual void s60();
    virtual void s64();
    virtual void s68();
    virtual void s6c();
    virtual void s70();
    virtual void s74();
    virtual void s78();
    virtual void s7c();
    virtual void s80();
    virtual void s84();
    virtual void s88();
    virtual void s8c();
    virtual void change(int, void*);
};

struct Modules {
    char p[0x58];
    void* energy;
    char p2[0x14];
    Kinetic* kinetic;
};

struct Access {
    char p[0xd8];
    Modules* modules;
};

struct Object {
    char p[0x60];
    Access* access;
};

struct Common {
    char p[0x24];
    int value;
};

extern "C" {
extern char g_ftCommonDataAccesser[];
extern char lbl_109_data_6F6C[];
extern char lbl_109_data_6FC8[];

void fn_27_1D8370(void*, const Param*);
Common* fn_27_149964(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);

void fn_109_112A8(Object* object, unsigned task, unsigned resource,
                  int value, float lr, const Vec* pos) {
    Access* access = object->access;
    Param param(task, resource, value, *pos, lr);
    fn_27_1D8370(object, &param);

    int common = fn_27_149964(g_ftCommonDataAccesser)->value;
    access->modules->kinetic->change(0, access);

    Energy* energy = static_cast<Energy*>(__dynamic_cast(
        access->modules->energy, 0,
        lbl_109_data_6F6C, lbl_109_data_6FC8, 1));

    energy->init(common);
    for (int i = 0; i < 2; ++i)
        energy->add(0, 0, 0);
    energy->finish();
}
}
