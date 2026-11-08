#include <types.h>
#pragma force_active on

extern "C" {
void update__9grGimmickFf(void* self, float deltaFrame);
void updateCallback__9grGimmickFUl(void* self, unsigned long arg);
extern const float lbl_27_rodata_45B0;
}

struct GimPad {
    char pad[0x3c];
};

struct GimVec3 {
    f32 x;
    f32 y;
    f32 z;
};

struct BlkA {
    s32 a;
    s32 b;
    GimVec3 v;
    f32 d;
    f32 e;
};

struct BlkB {
    s32 a;
    s32 b;
    GimVec3 v;
    f32 p;
    f32 q;
};

class GimVt : public GimPad {
public:
    virtual void s08(); virtual void s0c(); virtual void s10(); virtual void s14(); virtual void s18(); virtual void s1c(); virtual void s20(); virtual void s24();
    virtual void s28(); virtual void s2c(); virtual void s30(); virtual void s34(); virtual void s38(); virtual void s3c(); virtual void s40(); virtual void s44();
    virtual void s48(); virtual void s4c(); virtual void s50(); virtual void s54(); virtual void s58(); virtual void s5c(); virtual void s60(); virtual void s64();
    virtual void s68(); virtual void s6c(); virtual void s70(); virtual void s74(); virtual void s78(); virtual void s7c(); virtual void s80(); virtual void s84();
    virtual void s88(); virtual void s8c(); virtual void s90(); virtual void s94(); virtual void s98(); virtual void s9c(); virtual void sa0(); virtual void sa4();
    virtual void sa8(); virtual void sac(); virtual void sb0(); virtual void sb4(); virtual void sb8(); virtual void sbc(); virtual void sc0(); virtual void sc4();
    virtual void sc8(); virtual void scc(); virtual void sd0(); virtual void sd4(); virtual void sd8(); virtual void sdc(); virtual void se0(); virtual void se4();
    virtual void se8(); virtual void sec(); virtual void sf0(); virtual void sf4(); virtual void sf8(); virtual void sfc(); virtual void s100(void*, int); virtual void s104();
    virtual void s108(); virtual void s10c(); virtual void s110(); virtual void s114(); virtual void s118(); virtual void s11c(); virtual void s120(); virtual void s124();
    virtual void s128(); virtual void s12c(); virtual void s130(); virtual void s134(); virtual void s138(); virtual void s13c(); virtual void s140(); virtual void s144();
    virtual void s148(); virtual void s14c(); virtual void s150(); virtual void s154(); virtual void s158(); virtual void s15c(); virtual void s160(); virtual void s164();
    virtual void s168(); virtual void s16c(); virtual void s170(); virtual void s174(); virtual void s178(); virtual void s17c(); virtual void s180(); virtual void s184();
    virtual void s188(); virtual void s18c(); virtual void s190(); virtual void s194(); virtual void s198(); virtual void s19c(); virtual void s1a0(); virtual void s1a4();
    virtual void s1a8(); virtual void s1ac(); virtual void s1b0(); virtual void s1b4(); virtual void s1b8(); virtual void s1bc(); virtual void s1c0(); virtual void s1c4();
    virtual void s1c8(); virtual void s1cc(); virtual void s1d0(void*);
};

extern "C" void fn_27_27C5D8(void* self, float deltaFrame) {
    BlkA sp24;
    BlkB sp8;
    char* s = (char*)self;

    update__9grGimmickFf(self, deltaFrame);
    switch (*(u8*)(s + 0x158)) {
    case 1:
        if (*(f32*)(s + 0x15c) > (f32)*(s32*)(s + 0x160)) {
            sp24.a = 0x18;
            sp24.b = 0;
            ((GimVt*)self)->s1d0(&sp24.v);
            sp24.d = *(f32*)(*(char**)(s + 0x150) + 0x3c);
            sp24.e = *(f32*)(*(char**)(s + 0x150) + 0x38);
            void* o = *(void**)(s + 0x14c);
            ((GimVt*)o)->s100(&sp24, -1);
            ((GimVt*)self)->s1cc();
        } else {
            sp8.a = 0x19;
            sp8.b = 0;
            ((GimVt*)self)->s1d0(&sp8.v);
            void* o = *(void**)(s + 0x14c);
            ((GimVt*)o)->s100(&sp8, -1);
        }
        break;
    case 2:
        if (*(f32*)(s + 0x15c) > (f32)*(s32*)(s + 0x164)) {
            *(u8*)(s + 0x158) = 0;
            *(f32*)(s + 0x15c) = lbl_27_rodata_45B0;
        }
        break;
    }
    *(f32*)(s + 0x15c) += deltaFrame;
    updateCallback__9grGimmickFUl(self, 0);
}
