#include <types.h>
#pragma force_active on

extern "C" const f32 lbl_27_rodata_6588;

struct Self;

struct FloatPair {
    f32 a, b;
};

struct Vt70 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(u32, void*);
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
    virtual u32 v16();
};

struct Vt7C {
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void* w6(u32);
};

struct VtResult {
    virtual void r0();
    virtual void r1();
    virtual FloatPair r2();
    f32 pad, field8, fieldC;
};

struct Class_90D8_base {
    char pad[8];
};

class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();
    virtual void fn_27_7B22C();
    virtual void fn_27_7AC38();
    virtual void fn_27_7ADE8();
    virtual void fn_27_7AF98();
    virtual void fn_27_7B0B0();
    virtual u32 fn_27_7ABD8();
};

struct Inner {
    char pad[0x70];
    Vt70* ptr70;
    char pad2[8];
    Vt7C* ptr7C;
    char pad3[0x3C];
    Class_90D8* ptrBC;
};

struct Mid {
    char pad[0xD8];
    Inner* ptrD8;
};

struct SelfBase {
    char pad[0x3C];
};

struct Self : SelfBase {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84();
    virtual void s85();
    virtual void s86();
    virtual void s87();
    virtual void s88();
    virtual void s89();
    virtual void s90();
    virtual void s91();
    virtual void s92();
    virtual void s93();
    virtual void s94();
    virtual void s95();
    virtual void s96();
    virtual void s97();
    virtual void s98();
    virtual void s99();
    virtual void s100();
    virtual void s101();
    virtual void s102();
    virtual void s103();
    virtual void s104();
    virtual void s105();
    virtual void s106();
    virtual void s107();
    virtual void s108();
    virtual void s109();
    virtual void s110();
    virtual void s111();
    virtual void s112();
    virtual void s113();
    virtual void s114();
    virtual void s115();
    virtual void s116();
    virtual void s117();
    virtual void s118();
    virtual void s119();
    virtual void s120();
    virtual void s121();
    virtual void s122();
    virtual void s123();
    virtual void s124();
    virtual void s125();
    virtual void s126();
    virtual void s127();
    virtual void s128();
    virtual void s129();
    virtual void s130();
    virtual void s131();
    virtual void s132();
    virtual void s133();
    virtual void s134();
    virtual u32 f135();
    virtual u32 f136();
    virtual void f137();

    char pad2[0x20];
    Mid* ptr60;
    char pad3[0x40];
    u8 byteA4;
};

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_457C0[], lbl_27_data_CDF8[];
extern "C" f32 lbl_27_rodata_658C;

inline u32 helper(u32 arg, Self* self) {
    if (self->ptr60->ptrD8->ptr70->v16() == 0) {
        if (arg & 3) {
            self->ptr60->ptrD8->ptr70->v3(1, self->ptr60);
            return 0;
        }
        if (arg & 0x10)
            return 0;
        if (arg & 4) {
            if (((u32)self->byteA4 >> 7 & 1) == 1)
                return self->f136();
            self->ptr60->ptrD8->ptr70->v3(1, self->ptr60);
            return 0;
        }
        if (arg & 8) {
            if (self->ptr60->ptrD8->ptrBC->fn_27_7ABD8() == 1) {
                self->f137();
                VtResult* result = (VtResult*)__dynamic_cast(
                    self->ptr60->ptrD8->ptr7C->w6(0), 0,
                    lbl_27_data_457C0, lbl_27_data_CDF8, 1);
                FloatPair pair = result->r2();
                FloatPair copy = pair;
                if (copy.b < lbl_27_rodata_658C) {
                    f32 scaled = copy.b * lbl_27_rodata_6588;
                    copy.b = scaled;
                    result->field8 = copy.a;
                    result->fieldC = copy.b;
                }
                return self->f135();
            }
        }
    }
    return 0;
}

extern "C" u32 fn_27_30B3D8(Self* self, u32 arg) {
    return helper(arg, self);
}
