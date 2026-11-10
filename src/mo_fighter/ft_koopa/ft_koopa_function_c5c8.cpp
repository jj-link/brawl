#pragma force_active on
#include <ft/ft_common_data_accesser.h>
#include <so/so_value_accesser.h>

namespace {
struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(float a, float b) : x(a), y(b) {}
};
inline Vec2* tempVec(const Vec2& v) { return const_cast<Vec2*>(&v); }
inline Vec2& tempRef(const Vec2& v) { return const_cast<Vec2&>(v); }
}

struct Vec3 { float x, y, z; };
struct Flag { unsigned short mask; };
struct Params { float p0, p4, p8, pC, p10, p14, p18, p1C; };
struct MotionData {
    unsigned int value;
    float first, second;
    unsigned char byte0, byte1, byte2, byte3;
};

struct Accesser;

class Energy {
public:
    virtual void e1(); virtual void e2(); virtual void e3(); virtual void e4(); virtual void e5();
    virtual void reset(int, Vec2*, Vec3*, Accesser*);
    unsigned char state;
    unsigned char flags;
    char pad0[0x12];
    Vec2 v18;
    char pad1[8];
    Vec2 v28;
    char pad2[0x0C];
    float f3C;
};

class WorkModule {
public:
    virtual void w1(); virtual void w2(); virtual void w3(); virtual void w4(); virtual void w5();
    virtual void setInt(int, unsigned int);
    virtual void w7(); virtual void w8(); virtual void w9(); virtual void w10(); virtual void w11();
    virtual void w12(); virtual void w13(); virtual void w14(); virtual void w15(); virtual void w16();
    virtual void w17();
    virtual int isFlag(unsigned int);
    virtual void onFlag(unsigned int);
    virtual void offFlag(unsigned int);
};

class Kinetic {
public:
    virtual void k1(); virtual void k2(); virtual void k3(); virtual void k4(); virtual void k5(); virtual void k6();
    virtual Energy* getEnergy(int);
    virtual void k8(); virtual void k9(); virtual void k10(); virtual void k11(); virtual void k12(); virtual void k13();
    virtual Vec2 getSum(const Flag&);
};

class Visibility {
public:
    virtual void v1(); virtual void v2();
    virtual void set(int, int);
};

class Motion {
public:
    virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5();
    virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void setFrame(float);
    virtual float getFrame();
    virtual void m14(); virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18();
    virtual void m19(); virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28();
    virtual void m29(); virtual void m30();
    virtual void change(MotionData*);
};

class Sth {
public:
    virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5();
    virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10();
    virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
    virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19(); virtual void a20();
    virtual void a21(); virtual void a22(); virtual void a23(); virtual void a24(); virtual void a25();
    virtual void a26(); virtual void a27(); virtual void a28(); virtual void a29(); virtual void a30();
    virtual void a31(); virtual void a32(); virtual void a33(); virtual void a34(); virtual void a35();
    virtual void a36(); virtual void a37(); virtual void a38(); virtual void a39(); virtual void a40();
    virtual void a41();
    virtual void setA(unsigned int, int);
    virtual void b43(); virtual void b44(); virtual void b45(); virtual void b46(); virtual void b47();
    virtual void b48(); virtual void b49();
    virtual void setB(unsigned int, int);
};

struct Modules {
    char pad0[0x08];
    Motion* motion;
    char pad1[0x58 - 0x0C];
    Visibility* visibility;
    char pad2[0x64 - 0x5C];
    WorkModule* work;
    char pad3[0x7C - 0x68];
    Kinetic* kinetic;
    char pad4[0xA8 - 0x80];
    Sth* sth;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

extern "C" {
void fn_102_C1DC(Accesser*);
void fn_102_C2A4(Accesser*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3* fn_102_C5B8(Vec3*, float, float, float);
void fn_102_C5AC(Vec2*, float, float);
void fn_102_B024(void*, const void*);
void fn_102_CB90(MotionData*, unsigned int, float, float,
                 unsigned char, unsigned char, unsigned char, unsigned char);
extern const char lbl_102_data_5EBC[];
extern const char lbl_102_data_5D8C[];
extern const char lbl_102_data_14F4[];
extern const float lbl_102_rodata_10;
extern const float lbl_102_rodata_14;
}

static inline void apply(void* dst, const float* a, const float* b, const Vec2& t) {
    fn_102_C5AC(const_cast<Vec2*>(&t), *a, *b);
    fn_102_B024(dst, &t);
}

extern "C" void fn_102_C5C8(void*, Accesser* accesser) {
    WorkModule* work = accesser->modules->work;
    Motion* motion;

    if (work->isFlag(0x1200003D)) {
        fn_102_C2A4(accesser);
        work->offFlag(0x1200003D);
    }

    Sth* sth = accesser->modules->sth;
    unsigned int enabled = !work->isFlag(0x22000013);
    sth->setA(enabled, 0);
    sth->setB(enabled, 0xFF);

    int one = 1;
    Flag flag;
    flag.mask = one;
    Vec2 speed;
    __memcpy(&speed, &accesser->modules->kinetic->getSum(flag), sizeof(speed));

    Params* params = *reinterpret_cast<Params**>(
        reinterpret_cast<char*>(g_ftCommonDataAccesser.getData((ftKind)0xB)) + 0x80);

    work->setInt(0, 0x20000000);
    fn_102_C1DC(accesser);

    if (!work->isFlag(0x22000010)) {
        Energy* e = static_cast<Energy*>(__dynamic_cast(
            accesser->modules->kinetic->getEnergy(2), 0,
            lbl_102_data_5EBC, lbl_102_data_14F4, one));
        Vec3 rot;
        e->reset(0, tempVec(Vec2(speed.x, lbl_102_rodata_10)),
            fn_102_C5B8(&rot, lbl_102_rodata_10, lbl_102_rodata_10, lbl_102_rodata_10),
            accesser);
        e->f3C = params->p18;
        apply(reinterpret_cast<char*>(e) + 0x18, &params->p10, &e->v18.y, tempRef(Vec2()));
        apply(reinterpret_cast<char*>(e) + 0x28, &params->p10, &e->v28.y, tempRef(Vec2()));
        e->flags |= 0x80;
    } else {
        Energy* e = static_cast<Energy*>(__dynamic_cast(
            accesser->modules->kinetic->getEnergy(3), 0,
            lbl_102_data_5D8C, lbl_102_data_14F4, one));
        Vec3 rot;
        e->reset(0, tempVec(Vec2(speed.x, lbl_102_rodata_10)),
            fn_102_C5B8(&rot, lbl_102_rodata_10, lbl_102_rodata_10, lbl_102_rodata_10),
            accesser);
        e->flags |= 0x80;
    }

    if (work->isFlag(0x22000015)) {
        MotionData md;
        fn_102_CB90(&md, 0x1D4, lbl_102_rodata_10, lbl_102_rodata_14, 0, 0, 0, 0);
        accesser->modules->motion->change(&md);
        work->offFlag(0x22000015);
    } else if (work->isFlag(0x22000016)) {
        float frame;
        if (!work->isFlag(0x1200003F)) {
            work->onFlag(0x1200003F);
            motion = accesser->modules->motion;
            float k = (float)soValueAccesser::getConstantInt(
                reinterpret_cast<soModuleAccesser*>(accesser), 0x5DC5, 0);
            frame = motion->getFrame() - k;
        } else {
            frame = accesser->modules->motion->getFrame();
        }
        MotionData md;
        fn_102_CB90(&md, 0x1D4, lbl_102_rodata_14, lbl_102_rodata_14, 0, 0, 0, 0);
        accesser->modules->motion->change(&md);
        accesser->modules->motion->setFrame(frame);
        work->offFlag(0x22000016);
    } else {
        MotionData md;
        fn_102_CB90(&md, 0x1D4, lbl_102_rodata_10, lbl_102_rodata_14, 0, 0, 0, 0);
        accesser->modules->motion->change(&md);
    }

    if (work->isFlag(0x22000013)) {
        accesser->modules->visibility->set(1, 1);
        accesser->modules->visibility->set(0, -1);
    } else {
        accesser->modules->visibility->set(1, 0);
        if (work->isFlag(0x12000006)) {
            accesser->modules->visibility->set(0, 0);
        }
    }
}
