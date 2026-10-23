#include <so/stageobject.h>
#pragma force_active on

struct LaunchFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};

struct LaunchParam {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    LaunchFlags flags;
};

extern "C" {
extern const float lbl_27_rodata_7B08;
void fn_27_1D8370(void*, const LaunchParam*);
void fn_27_1DA698(void*, int, int, int);
}

struct VBase {
    virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(int, void*);
    virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40();
    virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44();
    virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48();
    virtual void s49(); virtual void s50(); virtual void s51(); virtual void s52();
    virtual void s53(); virtual void s54(); virtual void s55(); virtual void s56();
    virtual void s57(); virtual void s58(); virtual void s59(); virtual void s60();
    virtual void s61(); virtual void s62(); virtual void s63(); virtual void s64();
    virtual void s65(); virtual void s66(); virtual void s67(); virtual void s68();
    virtual void s69(); virtual void s70(); virtual void s71(); virtual void s72();
    virtual void s73(); virtual void s74(); virtual void s75(); virtual void s76();
    virtual void s77(); virtual void s78(); virtual void s79(); virtual void s80();
    virtual void s81(int);
};

struct Holder {
    char pad0[0x54];
    VBase* m54;
    char pad1[0x70 - 0x58];
    VBase* m70;
};

struct Acc {
    char pad[0xd8];
    Holder* holder;
};

struct Obj {
    char pad[0x60];
    Acc* acc;
};

extern "C" void fn_27_3661DC(void* object, int resource, int team, int cond, int value)
{
    Obj* o = (Obj*)object;
    if (cond != 0) {
        LaunchParam initialize;
        Vec3f position(lbl_27_rodata_7B08, lbl_27_rodata_7B08, lbl_27_rodata_7B08);
        initialize.resource = resource;
        initialize.team = team;
        initialize.teamOwner = team;
        initialize.teamAnother = team;
        initialize.index = -1;
        initialize.owner = -1;
        initialize.reserved0 = 0;
        initialize.reserved1 = 0;
        __memcpy(&initialize.position, &position, sizeof(Vec3f));
        initialize.facing = lbl_27_rodata_7B08;
        initialize.parameter = -1;
        initialize.variant = 0;
        initialize.situation = 2;
        initialize.status = 0x80;
        initialize.reserved2 = 0;
        initialize.motion = 0x35f;
        initialize.reserved3 = 0;
        initialize.flags.first = 1;
        initialize.flags.second = 0;
        initialize.flags.third = 0;
        initialize.flags.fourth = 0;
        initialize.flags.fifth = 1;
        initialize.flags.sixth = 0;
        initialize.flags.seventh = 0;
        initialize.flags.eighth = 0;
        initialize.flags.ninth = 0;
        initialize.flags.tenth = 0;

        fn_27_1D8370(object, &initialize);
        fn_27_1DA698(object, resource, value, 1);
    } else {
        LaunchParam initialize;
        Vec3f position(lbl_27_rodata_7B08, lbl_27_rodata_7B08, lbl_27_rodata_7B08);
        initialize.resource = resource;
        initialize.team = team;
        initialize.teamOwner = team;
        initialize.teamAnother = team;
        initialize.index = -1;
        initialize.owner = -1;
        initialize.reserved0 = 0;
        initialize.reserved1 = 0;
        __memcpy(&initialize.position, &position, sizeof(Vec3f));
        initialize.facing = lbl_27_rodata_7B08;
        initialize.parameter = -1;
        initialize.variant = 0;
        initialize.situation = 2;
        initialize.status = 0x80;
        initialize.reserved2 = 0;
        initialize.motion = 0x35f;
        initialize.reserved3 = 0;
        initialize.flags.first = 1;
        initialize.flags.second = 1;
        initialize.flags.third = 0;
        initialize.flags.fourth = 0;
        initialize.flags.fifth = 1;
        initialize.flags.sixth = 0;
        initialize.flags.seventh = 0;
        initialize.flags.eighth = 0;
        initialize.flags.ninth = 0;
        initialize.flags.tenth = 0;

        fn_27_1D8370(object, &initialize);
        Acc* a = o->acc;
        a->holder->m70->s36(0, a);
    }
    o->acc->holder->m54->s81(8);
}
