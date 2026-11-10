#pragma force_active on
#include <types.h>
#include <snd/snd_system.h>

struct Object_vptr_3c_base {
    char pad[0x3c];
};

class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void processDefault();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void processPreMapCorrection();
    virtual void slot5();
    virtual void slot6();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void slot12();
    virtual void processEffect();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual int slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual float slot76();
    virtual float slot77();
};

class Fn27Self {
public:
    char pad0[0x40];
    unsigned char m40;
    char pad41[0x23];
    int m64;
    float m68;
    float m6C;
};

extern Object_vptr_3c* lbl_27_bss_5668;
extern sndSystem* g_sndSystem;
extern char lbl_27_data_4E160[];
extern char lbl_27_data_4E184[];

extern "C" int fn_80074018(sndSystem*, int, int);
extern "C" void fn_80073F84(sndSystem*, int);
extern "C" void fn_27_23B36C(...);
extern "C" void setBGMVol__9sndSystemFbf(sndSystem*, bool, float);

extern "C" void fn_27_2424D8(Fn27Self* self) {
    sndSystem* snd = g_sndSystem;
    Object_vptr_3c* const obj = lbl_27_bss_5668;
    if ((u32)obj == 0) {
        return;
    }

    self->m64 = obj->slot71();
    self->m68 = obj->slot76();
    self->m6C = obj->slot77();
    if (self->m64 != -1) {
        if (fn_80074018(snd, self->m64, 1) == 0) {
            fn_27_23B36C(lbl_27_data_4E160, self->m64);
            self->m40 = 0;
            return;
        }
        setBGMVol__9sndSystemFbf(snd, false, self->m68);
        self->m40 = 2;
        return;
    }
    fn_27_23B36C(lbl_27_data_4E184);
    fn_80073F84(snd, 0);
    self->m40 = 0;
}
