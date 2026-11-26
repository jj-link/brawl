#pragma force_active on

#include <types.h>
#include <gm/gm_global.h>
#include <mt/mt_prng.h>
#include <mt/mt_vector.h>

struct CrollObject {
    float f00;
    float f04;
    unsigned char pad08[0x0C];
    Vec3f v14;
    Vec3f v20;
    unsigned char sub2C[0x30];
    unsigned char sub5C[0x30];
    void* p8C;
    void* p90;
    float f94;
    float f98;
    float f9C;
    u32 unkA0;
    u32 unkA4;
    unsigned char padA8[0x1C];
    Vec3f vC4;
    float fD0;
    float fD4;
    unsigned char padD8[0x04];
    float fDC;
    s32 unkE0;
    float fE4;
    float fE8;
    float fEC;
    float fF0;
};

struct CrollArg3 {
    unsigned char pad[0x10];
    u16 v10;
};

struct CrollArg4 {
    unsigned char pad[0x08];
    u16 v8;
};

struct CrollTableEntry {
    s32 count;
    float base;
    float scale;
    float unused0C;
    float v10;
    float v14;
};

extern "C" {
void fn_801EC158(void*);

extern const float lbl_90_rodata_0;
extern const float lbl_90_rodata_C;
extern const float lbl_90_rodata_10;
extern const float lbl_90_rodata_14;
extern const float lbl_90_rodata_24;
extern const float lbl_90_rodata_30;
extern const float lbl_90_rodata_44;
extern const float lbl_90_rodata_60;
extern const float lbl_90_rodata_E0;
extern const float lbl_90_rodata_134;
extern const float lbl_90_rodata_138;
extern const float lbl_90_rodata_13C;
extern const float lbl_90_rodata_140;
extern const float lbl_90_rodata_144;
extern const float lbl_90_rodata_148;
extern const float lbl_90_rodata_14C;
extern CrollTableEntry lbl_90_data_2690[];
}

extern "C" void fn_90_7E5C(
    CrollObject* self,
    s32 arg1,
    s32 arg2,
    CrollArg3* arg3,
    CrollArg4* arg4,
    float farg0
) {
    self->unkE0 = arg1;
    self->p90 = arg4;
    self->p8C = arg3;
    fn_801EC158(self->sub2C);
    fn_801EC158(self->sub5C);

    Vec3f zero(lbl_90_rodata_0, lbl_90_rodata_0, lbl_90_rodata_0);
    self->v20 = zero;
    self->v14 = zero;
    self->f9C = lbl_90_rodata_10;
    self->f98 = lbl_90_rodata_10;
    self->f94 = lbl_90_rodata_10;
    self->unkA4 = 0;

    Vec3f axis(lbl_90_rodata_0, lbl_90_rodata_0, lbl_90_rodata_10);
    self->vC4 = axis;
    self->fDC = lbl_90_rodata_0;
    self->fD0 = lbl_90_rodata_0;
    self->fD4 = lbl_90_rodata_0;

    if (arg4 != 0 && (arg2 == -1 || arg1 == 0)) {
        int t = arg4->v8;
        if ((float)t > lbl_90_rodata_134) {
            self->f9C = lbl_90_rodata_134 / (float)t;
        }
    }

    if (arg2 < 0) {
        switch (arg2) {
        case -2:
            self->f94 = lbl_90_rodata_60;
            self->f98 = lbl_90_rodata_E0;
            self->f00 = lbl_90_rodata_0;
            self->f04 = farg0;
            break;
        case -1:
            self->f94 = lbl_90_rodata_E0;
            self->f98 = lbl_90_rodata_E0;
            self->f00 = lbl_90_rodata_0;
            self->f04 = farg0;
            break;
        }
    } else {
        CrollTableEntry* e = &lbl_90_data_2690[arg1];
        self->f94 = e->v10;
        self->f98 = e->v14;
        self->f00 = e->base + e->scale * (float)(arg2 % e->count);
        self->f04 = farg0;
    }

    if (arg2 >= -1) {
        unsigned int height3 = arg3->v10;
        unsigned int height4 = arg4->v8;
        self->v20.m_x += lbl_90_rodata_44 +
                         (self->f94 * (lbl_90_rodata_C * height3) +
                          (self->f98 * self->f9C) *
                              (lbl_90_rodata_C * (float)height4));
        self->unkA4 |= 0x30;

        if (arg1 == 4) {
            self->unkA4 = self->unkA4 | 0x100;
            self->fE4 = lbl_90_rodata_138 * randf();
            self->fE8 = lbl_90_rodata_10 /
                        (lbl_90_rodata_24 *
                         (lbl_90_rodata_13C +
                          lbl_90_rodata_140 * randf()));
            self->fEC = lbl_90_rodata_30 +
                        lbl_90_rodata_144 *
                            (randf() - lbl_90_rodata_C);
            self->fF0 = lbl_90_rodata_144 +
                        lbl_90_rodata_144 *
                            (randf() - lbl_90_rodata_C);

            float random = randf();
            float var31 = lbl_90_rodata_148;
            float var30 = lbl_90_rodata_14C;

            self->f00 += lbl_90_rodata_24 *
                         (random - lbl_90_rodata_C);

            if (!((((u8*)g_GameGlobal->getGlobalRecordMenuDatap())[0x28] >>
                   7) & 1)) {
                var31 *= lbl_90_rodata_14;
                var30 *= lbl_90_rodata_14;
            }

            if ((self->f00 - self->fEC) < var31) {
                self->f00 = var31 + self->fEC;
            } else if ((self->f00 + self->fEC) > var30) {
                self->f00 = var30 - self->fEC;
            }
        }
    }

    self->unkA0 = self->unkA4;
}
