#pragma force_active on

#include <ec/ec_mgr.h>
#include <revolution/OS.h>

extern "C" {
extern unsigned char lbl_27_data_547E4;
extern const float lbl_27_rodata_4388;
extern char lbl_27_data_56744[];

int fn_80060F3C(ecMgr*, int);
void fn_27_26D35C(void*, unsigned int);
}

struct Pair {
    float x, y;

    Pair(float a, float b) : x(a), y(b) {}
};

struct GimmickEffect {
    unsigned short state;
    unsigned char pad02[2];
    float timer;
    int handle;
    int effectID;
    int duration;
    int unk14;
    unsigned char pad18[2];
    unsigned short unk1A;
    Pair offset;
    unsigned char pad24[4];
};

struct Gimmick {
    void* unk00;
    unsigned char pad04[0xA8];
    unsigned int effectCount;
    GimmickEffect* effects;
};

extern "C" void updataGimmickEffect__9grGimmickFf(Gimmick* self, float dt) {
    if (lbl_27_data_547E4 == 0)
        return;

    int offset;
    unsigned int i = 0;
    offset = 0;

#define EFFECT ((GimmickEffect*)((char*)self->effects + offset))

    while (i < self->effectCount) {
        if (EFFECT->effectID != 0) {
            if (EFFECT->state == 1 &&
                (float)EFFECT->duration <= EFFECT->timer) {
                EFFECT->handle = g_ecMgr->setEffect((EfID)EFFECT->effectID);

                if (EFFECT->handle == 0)
                    OSReport(lbl_27_data_56744, self->unk00, EFFECT->effectID);

                EFFECT->state = 2;
                EFFECT->timer = lbl_27_rodata_4388;
            }

            if (EFFECT->handle >= 0 && EFFECT->state == 2) {
                fn_27_26D35C(self, i);

                if (fn_80060F3C(g_ecMgr, EFFECT->handle) == 0 &&
                    EFFECT->handle >= 0) {
                    g_ecMgr->endEffect(EFFECT->handle);
                    GimmickEffect& effect = *EFFECT;
                    effect.state = 0;
                    effect.timer = lbl_27_rodata_4388;
                    effect.handle = -1;
                    effect.unk1A = 0;
                    effect.offset = Pair(lbl_27_rodata_4388, lbl_27_rodata_4388);
                }

                if (EFFECT->unk14 != 0 &&
                    (float)EFFECT->unk14 <= EFFECT->timer &&
                    EFFECT->handle >= 0) {
                    g_ecMgr->endEffect(EFFECT->handle);
                    GimmickEffect& effect = *EFFECT;
                    effect.state = 0;
                    effect.timer = lbl_27_rodata_4388;
                    effect.handle = -1;
                    effect.unk1A = 0;
                    effect.offset = Pair(lbl_27_rodata_4388, lbl_27_rodata_4388);
                }
            }

            EFFECT->timer += dt;
        }

        offset += 0x28;
        ++i;
    }

#undef EFFECT
}
