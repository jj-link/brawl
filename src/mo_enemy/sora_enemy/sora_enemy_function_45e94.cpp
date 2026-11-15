#include <types.h>
#include <mt/mt_vector.h>
#include <wn/wn_em_simple.h>
#include <em/wnem/wnem_proc_common.h>
#include <ft/ft_external_value_accesser.h>
#pragma force_active on

struct V2 { float x, y; };
struct StatusV {
    virtual void s08();
    virtual void s0C();
    virtual int s10();
};
struct ModuleV {
    virtual void s08();
    virtual void s0C();
    virtual StatusV* s10();
    virtual void s14();
    virtual Vec3f s18();
    virtual void s1C();
    virtual void s20(int, int);
};
class CounterArray {
public:
    virtual void s08();
    virtual void* get(int);
    char pad[0x10];
};
class ValueArray {
public:
    virtual void s08();
    virtual void* get(int);
};
struct Modules {
    char pad[0xC];
    ModuleV* unkC;
    char pad2[4];
    ModuleV* unk14;
    ModuleV* unk18;
};
union Vec2Bits {
    unsigned long long bits;
    V2 vec;
};
extern void* lbl_27_bss_F0;
extern char lbl_41_data_E8FC[];
extern const float lbl_41_rodata_FD8;
extern "C" {
float fn_41_33B6C(float*, void*);
float fn_41_10830(V2*);
void fn_41_1BEA8(V2*, const V2*);
Fighter* fn_41_2C7C4(Vec3f*, float);
void fn_41_5AC4(Vec3f*, float, float, float);
u32 fn_41_33AD0(void*, void*);
unsigned long long fn_41_441C8(Vec3f*, Vec3f*, float*, Vec3f*, bool*, float, float, float, float);
void fn_41_456D8(float*, float);
void fn_8003DBA8(V2*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
}
struct Wnem {
    char pad0[0x21f8];
    V2 pos;
    V2 acc;
    char pad2208[0xc];
    u8 entered;
    char pad2215[3];
    u8 unk2218;
    char pad2219[0x1b];
    void* params;
    CounterArray counters;
    ValueArray values;
};
extern "C" void fn_41_45E94(Wnem* wn, void* arg1) {
    void* params = 0;
    if (wn->params) params = wn->params;
    u8 entered = wn->entered;
    wn->entered = 0;
    if (entered) {
        wnemCommonProc::Report(lbl_41_data_E8FC);
        ((wnemSimple*)wn)->setProcFnc_TouchGround(0x15);
        ((wnemSimple*)wn)->setProcFnc_LifeZero(0x15);
        (*(Modules**)((char*)arg1 + 0xD8))->unk14->s20(2, 1);
        ((wnemSimple*)wn)->executeAnimCmd(7);
        ((wnemSimple*)wn)->executeAnimCmd(8);
        float f27a = fn_41_33B6C((float*)((char*)params + 0x10), arg1);
        *(float*)wn->values.get(0) = f27a;
        *(u32*)wn->counters.get(0) = 0;
        *(u32*)wn->counters.get(0) = 0;
        *(u32*)wn->counters.get(1) = 0;
    }
    if ((*(Modules**)((char*)arg1 + 0xD8))->unk18->s10()->s10() != 0x2710) {
        float f = fn_41_10830((V2*)&wn->acc.x);
        V2 v = wn->pos;
        fn_8003DBA8(&v);
        fn_41_456D8((float*)&v, f);
        fn_41_1BEA8((V2*)&wn->acc.x, &v);
        return;
    }
    if (wn->unk2218) {
        ((wnemSimple*)wn)->changeProcFnc(0x15, 1);
        return;
    }
    if (lbl_27_bss_F0 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
        if (p) p = fn_27_5BCD0(p);
        lbl_27_bss_F0 = p;
    }
    if (*((u8*)lbl_27_bss_F0 + 0x48) == 1) {
        ((wnemSimple*)wn)->changeProcFnc(0x15, 1);
        return;
    }
    u32 r28 = fn_41_33AD0((char*)params + 0x38, arg1);
    float f26 = fn_41_33B6C((float*)((char*)params + 0x40), arg1);
    float f27 = fn_41_33B6C((float*)((char*)params + 0x48), arg1);
    float f31 = fn_41_33B6C((float*)((char*)params + 0x50), arg1);
    float f25 = *(float*)((char*)params + 0x58);
    float f24 = *(float*)((char*)params + 0x5C);
    float factor = *(float*)((char*)params + 0x60);
    float f30 = *(float*)((char*)params + 0x64);
    float f29 = f27 * factor;
    fn_41_33B6C((float*)((char*)params + 0x10), arg1);
    if (((wnemSimple*)wn)->getFrameCounter(1) >= r28) {
        float f = fn_41_10830((V2*)&wn->acc.x);
        V2 v = wn->pos;
        fn_8003DBA8(&v);
        fn_41_456D8((float*)&v, f);
        fn_41_1BEA8((V2*)&wn->acc.x, &v);
        return;
    }
    {
        u32 cur;
        u32 r27 = *(u32*)((char*)params + 0x20);
        Vec3f target;
        fn_41_5AC4(&target, lbl_41_rodata_FD8, lbl_41_rodata_FD8, lbl_41_rodata_FD8);
        Vec3f pos = (*(Modules**)((char*)arg1 + 0xD8))->unkC->s18();
        Vec3f sp3C;
        if (((wnemSimple*)wn)->getFrameCounter(1) >= r27) {
            float range = *(float*)((char*)params + 4);
            Fighter* fighter = fn_41_2C7C4(&pos, range);
            if (fighter) {
                Vec3f hip = ftExternalValueAccesser::getHipPos(fighter);
                target.m_x = hip.m_x;
                target.m_y = hip.m_y;
                target.m_z = lbl_41_rodata_FD8;
            } else {
                target.m_x = pos.m_x + wn->pos.x;
                target.m_y = pos.m_y + wn->pos.y;
            }
            float f23 = fn_41_33B6C((float*)((char*)params + 8), arg1);
            float spC = *(float*)wn->values.get(0);
            fn_41_5AC4(&sp3C, wn->pos.x, wn->pos.y, lbl_41_rodata_FD8);
            float f28 = fn_41_10830((V2*)&wn->pos.x);
            bool sp8 = false;
            V2 sp18 = wn->pos;
            fn_8003DBA8(&sp18);
            cur = *(u32*)wn->counters.get(0);
            if (cur < *(u32*)((char*)params + 0x18)) {
                u32* counter = (u32*)wn->counters.get(0);
                *counter = cur + 1;
                if (*(int*)wn->counters.get(1) > 0) sp8 = true;
            } else {
                Vec2Bits result;
                result.bits = fn_41_441C8(&target, &pos, &spC, &sp3C, &sp8, f26, f25, f24, f30);
                sp18.x = result.vec.x;
                sp18.y = result.vec.y;
                *(float*)wn->values.get(0) = spC;
                *(u32*)wn->counters.get(0) = 0;
                cur = sp8;
                *(u32*)wn->counters.get(1) = cur;
            }
            float var_f1;
            if (!sp8) {
                var_f1 = f28 + f29;
                if (var_f1 >= f23) var_f1 = f23;
            } else {
                var_f1 = f28 - f27;
                if (var_f1 < f31) var_f1 = f31;
            }
            fn_41_456D8((float*)&sp18, var_f1);
            fn_41_1BEA8((V2*)&wn->pos.x, &sp18);
        }
    }
}
