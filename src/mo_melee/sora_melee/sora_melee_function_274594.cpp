#include <types.h>
#pragma force_active on

struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
};

struct soGimmickEventArgs {
    int unk0;
};

class grGimmickWarpZone {
public:
    void onGimmickEvent(soGimmickEventArgs* arg0, int* arg1);

    u8 pad0[0x150];
    u8* unk150;
    s8 unk154;
    u8 pad155[3];
    f32 unk158;
    Vec3f unk15C;
    u8 unk168;
};

extern "C" {
signed char getPlayerNumber__10grYakumonoFPi(void* self, int* arg);
void setTriggerFlag__12stTriggerMngFP13stTriggerData(void* self, void* data);
int getEntryId__9ftManagerFi(void* self, int id);
void setWarpFighter__9ftManagerFiP5Vec3ffUl(void* self, int id, Vec3f* pos, f32 f, unsigned long flag);
void startGimmickEffect__9grGimmickFUl(void* self, unsigned long flag);
extern void* g_ftManager;
extern void* g_stTriggerMng;
extern const f32 lbl_27_rodata_44D8;
extern const f32 lbl_27_rodata_4500;
}

void grGimmickWarpZone::onGimmickEvent(soGimmickEventArgs* arg0, int* arg1) {
    int temp = arg0->unk0;
    signed char playerNo = getPlayerNumber__10grYakumonoFPi(this, arg1);
    if (temp == 0x32) {
        setTriggerFlag__12stTriggerMngFP13stTriggerData(g_stTriggerMng, this->unk150 + 0x6C);
        if (this->unk168 == 7) {
            setWarpFighter__9ftManagerFiP5Vec3ffUl(g_ftManager,
                getEntryId__9ftManagerFi(g_ftManager, (int) playerNo),
                &this->unk15C, lbl_27_rodata_4500, 0);
            this->unk154 = 1;
            this->unk158 = lbl_27_rodata_44D8;
            startGimmickEffect__9grGimmickFUl(this, 0);
        }
    }
}
