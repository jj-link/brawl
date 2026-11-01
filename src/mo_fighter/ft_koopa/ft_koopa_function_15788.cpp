#pragma force_active on
struct V2 { float x, y; };
struct V3 { float x, y, z; };
struct Fighter;

#define SLOT(n) virtual void unused##n();

struct Situation {
    SLOT(8) SLOT(12) SLOT(16)
    virtual int kind();
    SLOT(24) SLOT(28) SLOT(32) SLOT(36) SLOT(40)
    SLOT(44) SLOT(48) SLOT(52) SLOT(56) SLOT(60)
    SLOT(64) SLOT(68) SLOT(72) SLOT(76) SLOT(80)
    SLOT(84) SLOT(88) SLOT(92) SLOT(96)
};

struct Work {
    SLOT(8) SLOT(12) SLOT(16) SLOT(20) SLOT(24)
    virtual void set(int, int);
    SLOT(32) SLOT(36) SLOT(40) SLOT(44) SLOT(48)
    SLOT(52) SLOT(56) SLOT(60) SLOT(64) SLOT(68)
    SLOT(72) SLOT(76)
    virtual void on(int);
    virtual void off(int);
    SLOT(88) SLOT(92)
    virtual void clear(int);
};

struct Energy {
    SLOT(8) SLOT(12) SLOT(16) SLOT(20) SLOT(24)
    virtual void reset(int, V2*, V3*, Fighter*);
    SLOT(32) SLOT(36) SLOT(40) SLOT(44) SLOT(48)
    SLOT(52) SLOT(56) SLOT(60) SLOT(64) SLOT(68)
    SLOT(72) SLOT(76) SLOT(80) SLOT(84) SLOT(88)
    SLOT(92) SLOT(96)
};

struct Kinetic {
    SLOT(8) SLOT(12) SLOT(16) SLOT(20) SLOT(24) SLOT(28)
    virtual Energy* energy(int);
    SLOT(36) SLOT(40) SLOT(44) SLOT(48) SLOT(52) SLOT(56)
    virtual V2 sum(short*);
    SLOT(64) SLOT(68) SLOT(72) SLOT(76) SLOT(80)
    SLOT(84) SLOT(88) SLOT(92) SLOT(96)
};

#undef SLOT

struct Modules {
    char pad[0x14];
    Situation* situation;
    char pad2[0x4c];
    Work* work;
    char pad3[0x14];
    Kinetic* kinetic;
};

struct Fighter {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
extern char g_ftCommonDataAccesser[];
extern char lbl_102_data_5E6C[];
extern char lbl_102_data_5EBC[];
extern char lbl_102_data_14F4[];
extern float lbl_102_rodata_58;

void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_102_156C0(Fighter*);
V3* fn_102_C5B8(V3*, float, float, float);
V2* fn_102_C5AC(V2*, float, float);
void fn_102_B024(void*, const V2*);
}

extern "C" void fn_102_15788(Fighter* f) {
    Work* w = f->modules->work;
    Situation* s = f->modules->situation;
    int kind = s->kind();

    w->clear(2);
    w->off(0x22000010);
    w->off(0x22000011);
    w->off(0x22000012);
    w->off(0x22000013);
    w->off(0x22000014);
    w->on(0x22000015);
    w->set(0, 0x20000000);
    w->off(0x1200003f);

    if (kind == 2) {
        float* data = *(float**)((char*)
            getData__20ftCommonDataAccesserCF6ftKind(
                g_ftCommonDataAccesser, 0x30) + 0x84);

        short attr = 1;
        Kinetic* k = f->modules->kinetic;
        V2 speed;
        V2 sum = k->sum(&attr);
        __memcpy(&speed, &sum, 8);
        speed.y = data[1];

        fn_102_156C0(f);

        Energy* g = (Energy*)__dynamic_cast(
            f->modules->kinetic->energy(1), 0,
            lbl_102_data_5E6C, lbl_102_data_14F4, 1);

        float sy = speed.y;
        V2 gv = {lbl_102_rodata_58, sy};
        V3 gr;
        g->reset(0, &gv,
            fn_102_C5B8(&gr, lbl_102_rodata_58,
                lbl_102_rodata_58,
                lbl_102_rodata_58), f);

        ((float*)g)[4] = -data[2];
        ((float*)g)[5] = data[3];
        ((float*)g)[7] = data[3];
        ((unsigned char*)g)[5] |= 0x80;

        Energy* m = (Energy*)__dynamic_cast(
            f->modules->kinetic->energy(2), 0,
            lbl_102_data_5EBC, lbl_102_data_14F4, 1);

        V2 mv = {speed.x, lbl_102_rodata_58};
        V3 mr;
        m->reset(0, &mv,
            fn_102_C5B8(&mr, lbl_102_rodata_58,
                lbl_102_rodata_58,
                lbl_102_rodata_58), f);

        ((float*)m)[15] = data[7];

        V2 a;
        fn_102_C5AC(&a, data[5], ((float*)m)[7]);
        fn_102_B024((char*)m + 0x18, &a);

        V2 b;
        fn_102_C5AC(&b, data[5], ((float*)m)[11]);
        fn_102_B024((char*)m + 0x28, &b);

        ((unsigned char*)m)[5] |= 0x80;
    }
}
