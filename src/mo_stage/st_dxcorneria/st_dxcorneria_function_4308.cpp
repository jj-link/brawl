#pragma force_active on
typedef signed char s8;
typedef unsigned char u8;
typedef int s32;
typedef float f32;

struct Yakumono;

extern "C" s32 getTeam__8YakumonoFv(Yakumono*);
extern "C" void setTeam__8YakumonoFi(Yakumono*, s32);
extern "C" void OSReport(const char*, ...);
extern f32 lbl_82_rodata_C8;
extern char lbl_82_data_6B0[];

struct Self {
    char pad0[0x14C];
    Yakumono* yk;
    char pad1[0x1A4 - 0x150];
    f32 scale;
    char pad2[0x1AC - 0x1A8];
    u8 flagA;
    u8 flagB;
    u8 flagC;
};

struct Other {
    char pad[0x20];
    s8 team;
};

extern "C" void fn_82_4308(Self* self, Other* other, s32 flags) {
    Yakumono* yk = self->yk;
    if (yk != 0) {
        if (flags & 8) {
            s32 oldTeam = getTeam__8YakumonoFv(yk);
            setTeam__8YakumonoFi(yk, (s32)other->team);
            f32 k = lbl_82_rodata_C8;
            s8 team = other->team;
            self->flagA = 1;
            f32 s = self->scale;
            self->scale = s * k;
            OSReport(lbl_82_data_6B0, oldTeam, (s32)team, self->scale);
            return;
        }
        if (self->flagC != 0) {
            self->flagB = 1;
        }
    }
}
