#pragma force_active on
#pragma fp_contract off

#include <nw4r/math/math_arithmetic.h>
#include <mt/mt_common.h>

typedef unsigned long long u64;

struct Vec2 {
    float x, y;

    Vec2 operator*(float s) const {
        Vec2 r = {x * s, y * s};
        return r;
    }

    Vec2 operator-(const Vec2& v) const {
        Vec2 r = {x - v.x, y - v.y};
        return r;
    }

    float dot(const Vec2& v) const {
        return x * v.x + y * v.y;
    }
};

struct Vec2c {
    float x, y;
    Vec2c(const Vec2& o) {
        float ty = o.y;
        float tx = o.x;
        x = tx;
        y = ty;
    }
};

struct Pr {
    int a;
    int b;
};

inline void reflect(Vec2& v, const Vec2& n, const float* k) {
    v = v - (n * k[5]) * n.dot(v);
}

inline void reflect2(Vec2& v, const Vec2& n, const float* k) {
    reflect(v, n, k);
}

struct Cmd {
    virtual void v0();
    virtual signed char group();
    virtual signed char type();
};

struct Dst {
    virtual void d0();
    virtual void d1();
    virtual u64 get();
    char pad[4];
    Vec2 speed;
    float setSpeed(Vec2c s) {
        speed.x = s.x;
        speed.y = s.y;
        return s.x;
    }
};

struct Energy {
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
    virtual void e4();
    virtual void e5();
    virtual void* get(int);
};

struct PostureBase {
    char pad[8];
};

struct Posture : PostureBase {
    virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3();
    virtual void p4(); virtual void p5(); virtual void p6(); virtual void p7();
    virtual void p8(); virtual void p9(); virtual void p10(); virtual void p11();
    virtual void p12(); virtual void p13(); virtual void p14(); virtual void p15();
    virtual void p16(); virtual void p17(); virtual void p18(); virtual void p19();
    virtual void p20(); virtual void p21(); virtual void p22(); virtual void p23();
    virtual void p24(); virtual void p25(); virtual void p26(); virtual void p27();
    virtual void p28(); virtual void p29(); virtual void p30(); virtual void p31();
    virtual void p32(); virtual void p33(); virtual void p34(); virtual void p35();
    virtual void p36(); virtual void p37(); virtual void p38(); virtual void p39();
    virtual void p40(); virtual void p41(); virtual void p42(); virtual void p43();
    virtual void p44(); virtual void p45(); virtual void p46(); virtual void p47();
    virtual void p48(); virtual void p49(); virtual void p50(); virtual void p51();
    virtual void p52(); virtual void p53(); virtual void p54(); virtual void p55();
    virtual void p56();
    virtual u64 get(int, int);
};

struct Facing {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void set(float);
};

struct Modules {
    char pad[0xc];
    Facing* facing;
    Posture* posture;
    char pad2[0x68];
    Energy* energy;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct Params {
    char pad[8];
    float scale;
    char pad2[0xc];
    float limit;
};

struct SelfBase {
    char pad[0x3c];
};

struct Self : SelfBase {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43();
    virtual void s44(); virtual void s45(); virtual void s46();
    virtual int valid(signed char);
    virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51();
    virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55();
    virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59();
    virtual void s60(); virtual void s61(); virtual void s62(); virtual void s63();
    virtual void s64(); virtual void s65(); virtual void s66(); virtual void s67();
    virtual void s68(); virtual void s69(); virtual void s70(); virtual void s71();
    virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75();
    virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79();
    virtual void s80(); virtual void s81(); virtual void s82(); virtual void s83();
    virtual void s84(); virtual void s85(); virtual void s86(); virtual void s87();
    virtual void s88(); virtual void s89(); virtual void s90(); virtual void s91();
    virtual void s92(); virtual void s93(); virtual void s94(); virtual void s95();
    virtual void s96(); virtual void s97(); virtual void s98(); virtual void s99();
    virtual void s100(); virtual void s101(); virtual void s102(); virtual void s103();
    virtual void s104(); virtual void s105(); virtual void s106(); virtual void s107();
    virtual void s108(); virtual void s109(); virtual void s110(); virtual void s111();
    virtual void s112(); virtual void s113(); virtual void s114(); virtual void s115();
    virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119();
    virtual void s120(); virtual void s121(); virtual void s122(); virtual void s123();
    virtual void s124(); virtual void s125(); virtual void s126(); virtual void s127();
    virtual void s128(); virtual void s129(); virtual void s130(); virtual void s131();
    virtual void s132(); virtual void s133(); virtual void s134(); virtual void s135();
    virtual void s136(); virtual void s137();
    virtual void reset(int);

    char pad2[0x1f00];
    Params* params;
};

extern "C" {
extern char lbl_27_data_457C0[], lbl_27_data_CDF8[];
extern const float lbl_27_rodata_6370[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_1DA24C(Self*);

bool fn_27_2DD888(Self* self, Cmd* cmd, Access* access) {
    const float* k = lbl_27_rodata_6370;

    if (fn_27_1DA24C(self))
        return true;

    if (!self->valid(cmd->group()))
        return false;

    if (cmd->type() <= -1 || cmd->type() >= 11)
        return false;

    switch (cmd->type()) {
    case 6: {
        Dst* dst = (Dst*)__dynamic_cast(
            access->modules->energy->get(0),
            0,
            lbl_27_data_457C0,
            lbl_27_data_CDF8,
            1);

        Pr pv;
        Pr pn;
        u64 bits;
        u64 bits2;
        bits = dst->get();
        pv = *(Pr*)&bits;
        bits2 = access->modules->posture->get(255, 0);
        pn = *(Pr*)&bits2;
        Vec2& v = *(Vec2*)&pv;
        Vec2& n = *(Vec2*)&pn;

        reflect2(v, n, k);
        v = v * self->params->scale;

        float sum = v.dot(v);
        float mag;
        if ((float)(double)nw4r::math::FAbs(sum) <= k[6])
            mag = k[1];
        else
            mag = sum * rsqrtf(sum);

        if (mag < self->params->limit) {
            self->reset(0);
            return true;
        }

        float vx = dst->setSpeed(v);
        float facing = k[0];
        if (vx > k[1])
            facing = k[2];
        access->modules->facing->set(facing);
        return true;
    }
    }

    return false;
}
}
