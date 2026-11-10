#include <types.h>
#include <string.h>
#include <mt/mt_vector.h>
#include <wn/wn_em_simple.h>
#include <em/wnem/wnem_proc_common.h>
#include <ft/ft_external_value_accesser.h>
#pragma force_active on

struct HitPair {
    unsigned long a, b;
};

struct HitInfo {
    HitPair first;
    unsigned long c;
    float d;
    unsigned long e_high : 16;
    unsigned long e_kind : 10;
    unsigned long e_low : 6;
    unsigned long f;
};

union Vec2Bits {
    unsigned long long bits;
    Vec2f vec;
};

class Inner {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Inner* slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
};

class Mod34 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(int, int, HitInfo*);
    virtual int slot7(int);
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual HitInfo* slot11(int);
};

class Mod1C {
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
    virtual void slot11();
};

class ModC {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3f slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
};

struct Mods {
    char pad0[0xC];
    ModC* c;
    char pad10[8];
    Object_vptr_0* m18;
    Mod1C* m1c;
    char pad20[0x14];
    Mod34* m34;
};

extern char lbl_41_data_E778[];
extern char lbl_41_data_E799[];
extern const float lbl_41_rodata_FB8;
extern const float lbl_41_rodata_FBC;

extern "C" {
    void fn_41_1BEA8(Vec2f*, const Vec2f*);
    Vec3f* fn_41_5AC4(Vec3f*, float, float, float);
    unsigned long long fn_41_43FB8(Vec3f*, Vec3f*, float, Vec3f*);
    void fn_41_456D8(float*, float);
    Fighter* fn_41_2C7C4(Vec3f*, float);
}

inline void clearAndCopy(Vec2f* dst, const Vec2f* src) {
    dst->m_y = lbl_41_rodata_FB8;
    dst->m_x = lbl_41_rodata_FB8;
    fn_41_1BEA8(dst, src);
}

extern "C" void fn_41_45388(wnemSimple* self, void* arg) {
    void* data = 0;
    if (self->unk2234)
        data = self->unk2234;

    bool entered = self->unk2214;
    self->unk2214 = 0;

    if (entered) {
        wnemCommonProc::Report(lbl_41_data_E778);
        self->setProcFnc_HitShell(26);
        self->setProcFnc_TouchGround(26);
        self->setProcFnc_LifeZero(27);
        self->executeAnimCmd(0);
    }

    if ((*(Mods**)((char*)arg + 0xD8))->m18->slot2()->slot2() != 0x2710) {
        if ((*(Mods**)((char*)arg + 0xD8))->m34->slot7(0)) {
            HitInfo* p = (*(Mods**)((char*)arg + 0xD8))->m34->slot11(0);
            HitInfo info;
            __memcpy(&info.first, &p->first, 8);
            info.c = p->c;
            info.d = p->d;
            *(unsigned long*)((char*)&info + 0x10) =
                *(unsigned long*)((char*)p + 0x10);
            info.f = p->f;
            info.e_kind = 2;
            (*(Mods**)((char*)arg + 0xD8))->m34->slot6(0, 0, &info);
        } else {
            wnemCommonProc::Report(lbl_41_data_E799);
        }

        clearAndCopy((Vec2f*)((char*)self + 0x2200), (Vec2f*)&self->unk21F8);
        fn_41_456D8(&self->unk2200, lbl_41_rodata_FBC);
        (*(Mods**)((char*)arg + 0xD8))->m1c->slot4();
    }

    if (self->unk2218) {
        (*(Mods**)((char*)arg + 0xD8))->m1c->slot4();
        self->changeProcFnc(26, 1);
        return;
    }

    if ((*(Mods**)((char*)arg + 0xD8))->m18->slot2()->slot2() == 0x2710) {
        unsigned long frame = *(unsigned long*)((char*)data + 0x18);
        Vec3f target;
        fn_41_5AC4(&target, lbl_41_rodata_FB8,
                   lbl_41_rodata_FB8, lbl_41_rodata_FB8);

        Vec3f pos = (*(Mods**)((char*)arg + 0xD8))->c->slot4();

        if (self->getFrameCounter(1) >= frame) {
            float range = *(float*)data;
            Fighter* fighter = fn_41_2C7C4(&pos, range);
            Vec3f motion;

            if (fighter) {
                Vec3f hip = ftExternalValueAccesser::getHipPos(fighter);
                target.m_x = hip.m_x;
                target.m_y = hip.m_y;
                target.m_z = lbl_41_rodata_FB8;
            } else {
                target.m_x = pos.m_x + self->unk21F8;
                target.m_y = pos.m_y + self->unk21FC;
            }

            float turn = *(float*)((char*)data + 8);
            float max = *(float*)((char*)data + 4);
            fn_41_5AC4(&motion, self->unk21F8, self->unk21FC,
                       lbl_41_rodata_FB8);

            Vec2f out;
            Vec2Bits result;
            result.bits = fn_41_43FB8(&target, &pos, turn, &motion);
            ((unsigned long*)&out)[0] = ((unsigned long*)&result)[0];
            ((unsigned long*)&out)[1] = ((unsigned long*)&result)[1];
            fn_41_456D8((float*)&out, max);
            fn_41_1BEA8((Vec2f*)&self->unk21F8, &out);
        }
    }
}
