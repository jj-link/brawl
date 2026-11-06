#include <st/st_melee.h>
#include <gr/gr_madein.h>
#include <gr/gr_tengan_event.h>
#include <ec/ec_mgr.h>
#include <mt/mt_prng.h>
#pragma force_active on

extern "C" {
extern const float lbl_60_rodata_0[];
extern const char lbl_60_data_450[];

int fn_60_420C(stMelee* self) {
    const float* rd = lbl_60_rodata_0;
    u8* b = (u8*)self;
    switch (((grTenganEvent*)(b + 0xc30))->getPhase()) {
    case 0: {
        u32 random = randi(3);
        if (random >= 2) random = 2;
        b[0xef0] = random;
        ((grMadein*)self->getGround(0x1f))->setMotion(b[0xef0]);
        ((grMadein*)self->getGround(0x1f))->startEntity();
        self->zoomOutCamera(rd[0x44/4], rd[0xbc/4]);
        *(int*)(b + 0xee4) = self->playSeBasic((SndID)0x1c64, rd[0]);
        ((grTenganEvent*)(b + 0xc30))->setPhase(1);
        *(u32*)(b + 0xedc) = g_ecMgr->setEffect((EfID)0x460008);
        g_ecMgr->setParent(*(u32*)(b + 0xedc), *self->getGround(0x1f)->m_sceneModels, lbl_60_data_450, false);
        break;
    }
    case 1:
        switch (b[0xef0]) {
        case 0:
            if (self->getGround(0x1f)->getMotionFrame(0) > rd[0xc0/4]) {
                self->stopSeBasic(*(int*)(b + 0xee4), rd[0x24/4]);
                *(int*)(b + 0xee4) = -1;
                ((grTenganEvent*)(b + 0xc30))->setPhase(2);
            }
            break;
        case 1:
        case 2:
            if (self->getGround(0x1f)->getMotionFrame(0) > rd[0x3c/4]) {
                self->stopSeBasic(*(int*)(b + 0xee4), rd[0x24/4]);
                *(int*)(b + 0xee4) = -1;
                ((grTenganEvent*)(b + 0xc30))->setPhase(2);
            }
            break;
        }
        break;
    case 2:
        if (((grMadein*)self->getGround(0x1f))->isEndEntity()) {
            ((grMadein*)self->getGround(0x1f))->endEntity();
            g_ecMgr->endEffect(*(u32*)(b + 0xedc));
            ((grTenganEvent*)(b + 0xc30))->end();
            self->zoomInCamera();
            if (*(int*)(b + 0xee4) != -1) {
                self->stopSeBasic(*(int*)(b + 0xee4), rd[0x24/4]);
                *(int*)(b + 0xee4) = -1;
            }
        }
        break;
    }
    return 0;
}
}