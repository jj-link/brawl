#include <types.h>
#include <gf/gf_application.h>
#include <gf/gf_task.h>
#include <if/if_mngr.h>
#include <mu/mu_msg.h>
#include <snd/snd_system.h>
#pragma force_active on

struct Elem {
    s32 a;
    s32 b;
    s32 c;
};

class Task : public gfTask {
public:
    virtual void slot23();
    virtual void slot24();
    virtual void slot25(s32);
    virtual void slot26();
    virtual void slot27();
    virtual f32 slot28();
    virtual void slot29();
    virtual s32 slot30();
    virtual void slot31();
    virtual s32 slot32();
    virtual s32 slot33();

    char pad40[0x88 - 0x40];
    s32 state;
    s32 stateTimer;
    void* objA;
    char pad94[4];
    u8 flag98;
    u8 flag99;
    char pad9A[2];
    void* ptr9C;
    char padA0[0xE8 - 0xA0];
    MuMsg* msg;
    u8 flagEC;
    char padED[3];
    s32 valF0;
    char padF4[4];
    u8 flagF8;
    char padF9[3];
    s32 counterFC;
    char pad100[4];
    Elem elems[64];
    s32 count404;
    s32 idx408;
    f32 f40C;
    f32 f410;
    s32 h414;
    s32 h418;
    s32 h41C;
    f32 f420;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11(s32, void*);
    virtual void slot12();
    virtual void slot13(void*);

    char pad4[0xE4 - 4];
    s32 e4;
};

extern "C" {
extern const f32 lbl_805A2610;
extern const f32 lbl_805A2620;
void fn_800F57F0(Task*, s32, s32, s32, s32, s32);
s32 fn_800B61C0(void*);
void* fn_800B60A8(void*);
s32 fn_80077DA0(sndSystem*, s32);
}

extern "C" void fn_800F5344(Task* self) {
    if (self->flag99 == 0) {
        s32 advanceTimer = 1;
        void* objA = self->objA;
        s32 paused = (*reinterpret_cast<u32*>(reinterpret_cast<char*>(g_gfApplication) + 0xEC) >> 27) != 0;
        if (objA != 0) {
            if (paused != 0) {
                if (self->flag98 != 0) {
                    Object_vptr_0* sub = *reinterpret_cast<Object_vptr_0**>(reinterpret_cast<char*>(g_IfMngr) + 0x14);
                    if (sub != 0) {
                        sub->slot13(objA);
                    }
                    self->flag98 = 0;
                }
            } else if (self->flag98 == 0) {
                Object_vptr_0* sub = *reinterpret_cast<Object_vptr_0**>(reinterpret_cast<char*>(g_IfMngr) + 0x14);
                sub->slot11(sub->e4, objA);
                self->flag98 = 1;
            }
        }
        if (paused != 0 || ((reinterpret_cast<u8*>(g_gfApplication)[0xEE] >> 7) & 1)) {
            return;
        }

        if (self->count404 > 0) {
            if (self->state != 0 && self->state != 8) {
                f32 t = self->slot28();
                self->f410 = self->f410 + t;
            }
        }
        if (self->f420 > lbl_805A2610) {
            f32 t = self->slot28();
            f32 u = self->f420 - t;
            self->f420 = u;
            if (u < lbl_805A2610) {
                self->f420 = lbl_805A2610;
            }
        }
        if (self->state == 7) {
            if (self->count404 <= 0 || self->f410 >= self->f40C) {
                self->state = 8;
                self->stateTimer = 0;
            }
        }
        if (self->state == 1) {
            s32 ready;
            if (static_cast<u32>(self->h414) + 0x10000U == 0xFFFFU) {
                ready = 1;
            } else {
                ready = self->f420 <= lbl_805A2620;
            }
            if (ready != 0) {
                self->state = 2;
                self->stateTimer = 0;
                self->slot29();
            }
        }
        if (self->state == 2) {
            if (fn_800B61C0(self->ptr9C) != 0 || fn_800B60A8(self->ptr9C) == 0) {
                self->state = 3;
                self->stateTimer = 0;
                self->slot31();
            }
        }
        if (self->state == 3) {
            if (self->count404 > 0 && self->idx408 >= -1 && self->idx408 + 1 < self->count404) {
                if (self->slot32() != 0) {
                    ++self->idx408;
                    if (self->elems[self->idx408].a >= 0) {
                        fn_800F57F0(self, self->elems[self->idx408].a, self->elems[self->idx408].b, 0, 0, 0);
                        s32 c = self->elems[self->idx408].c;
                        if (c >= 0) {
                            self->h41C = g_sndSystem->playSE(static_cast<SndID>(c), -1, 0, 0, self->h414);
                        }
                        self->state = 4;
                        self->stateTimer = 0;
                    } else {
                        self->slot25(0);
                    }
                }
            } else {
                self->slot25(0);
            }
        }
        if (self->state == 4) {
            if (self->valF0 >= 0) {
                if (self->msg != 0 && self->flagF8 == 0 &&
                    (self->msg->isEndDelayPrint(0) || self->flagEC == 0) &&
                    (self->h41C < 0 || fn_80077DA0(g_sndSystem, self->h41C) == 0)) {
                    s32 t = self->counterFC - 1;
                    self->counterFC = t;
                    if (t < 0) {
                        self->counterFC = 0;
                        self->flagF8 = 1;
                        self->state = 5;
                        self->stateTimer = 0;
                    }
                }
            }
        }
        if (self->state == 5) {
            if (self->slot33() != 0) {
                self->state = 3;
                self->stateTimer = 0;
                advanceTimer = 0;
            }
        }
        if (self->state == 6) {
            if (fn_800B61C0(self->ptr9C) != 0) {
                self->state = 7;
                self->stateTimer = 0;
                self->slot25(0);
            }
        }
        if (advanceTimer != 0) {
            if (self->state != 0 && self->state != 8) {
                ++self->stateTimer;
            }
        }
    }
}
