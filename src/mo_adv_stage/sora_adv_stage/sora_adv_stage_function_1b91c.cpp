#include <types.h>
#include <gr/gr_gimmick.h>
#include <st/st_trigger.h>
#pragma force_active on

struct FnArg {
    s32 unk0;
    s32 unk4;
    f32 x;
    f32 y;
    f32 z;
    s32 unk14;
};

extern "C" s8 getPlayerNumber__10grYakumonoFPi(void* self, s32* taskId);
extern "C" s32 isSubFighter__10grYakumonoFPi(void* self, s32* taskId);
extern "C" void fn_40_1B804(void* self, s32 id, s8 playerNo);
extern "C" void fn_40_5780(void* a, s32 b, Vec3f* pos);

extern void* lbl_40_bss_15C;
extern const f32 lbl_40_rodata_280;

extern "C" void fn_40_1B91C(grGimmick* self, FnArg* arg, s32* taskId) {
    u8* base = (u8*)self;
    s32 type = arg->unk0;
    s32 val = arg->unk4;
    s8 playerNo = getPlayerNumber__10grYakumonoFPi(self, taskId);

    if (isSubFighter__10grYakumonoFPi(self, taskId) == 0 && playerNo == 0) {
        base[0x16D] = 1;
    }

    if (type == 0x33) {
        fn_40_1B804(self, val, playerNo);
        return;
    }

    if (type > 1 && type < 10) goto process;
    return;
process:
    {
        switch (type) {
        case 2: {
            Vec3f sp8 = self->getPos();
            *(u8*)(base + 0x16C) = 1;
            s32 idx;
            for (idx = 0; idx < 4; ++idx) {
                if (base[0x174 + idx * 12] == 0) break;
            }
            u8* e = base + idx * 12;
            e[0x174] = 1;
            e[0x175] = 1;
            *(s32*)(e + 0x178) = val;
            *(f32*)(e + 0x17C) = lbl_40_rodata_280;
            e[0x176] = playerNo;
            if (base[0x16D] != 0) {
                fn_40_5780(lbl_40_bss_15C, 1, &sp8);
                g_stTriggerMng->setTriggerFlag((stTriggerData*)(*(u8**)(base + 0x150) + 0xD8));
            }
            if (idx == 1) {
                u8 v = base[0x175];
                if (v != 4) {
                    base[0x181] = v;
                    *(f32*)(base + 0x188) = (f32)v;
                }
            }
            if ((s32)base[0x1A4] == 2) {
                self->grGimmick::changeNodeAnim(0, 0);
                base[0x1A4] = 0;
            }
            self->startGimmickSE(0);
            arg->unk14 = *(u16*)(*(u8**)(base + 0x150) + 0xCE);
            arg->x = sp8.m_x;
            arg->y = sp8.m_y;
            arg->z = sp8.m_z;
            break;
        }
        case 3:
            base[0x16C] = *(*(u8**)(base + 0x150) + 0xCB);
            for (int i = 0; i < 4; i++) {
                if (base[0x174 + i * 12] != 0 && base[0x175 + i * 12] != 4) {
                    base[0x175 + i * 12] = 3;
                }
            }
            self->grGimmick::changeNodeAnim(1, 0);
            base[0x1A4] = 1;
            break;
        }
    }
}
