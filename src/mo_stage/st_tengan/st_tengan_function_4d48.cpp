#include <types.h>
#include <gr/gr_tengan_event.h>
#include <gr/gr_madein.h>
#include <st/stage.h>
#include <mt/mt_prng.h>
#include <ec/ec_mgr.h>
#pragma force_active on

extern "C" {
extern const float lbl_60_rodata_38;
extern const float lbl_60_rodata_54;
extern const char lbl_60_data_474[];
}

struct Tengan {
    char pad0[0x9c];
    char* params;
    char padA0[0x218 - 0xa0];
    int selectedEvent;
    char pad21C[0x2c8 - 0x21c];
    grTenganEvent cue;
    char pad374[0x420 - 0x374];
    grTenganEvent event420;
    grTenganEvent event4CC;
    grTenganEvent event578;
    grTenganEvent event624;
    grTenganEvent event6D0;
    grTenganEvent event77C;
    grTenganEvent event828;
    char pad8D4[0xe54 - 0x8d4];
    u8 eventStarted;
    char padE55[0xe68 - 0xe55];
    u8 flags[3];
    u8 cnt;
    char padE6C[0xea8 - 0xe6c];
    u8 flagEA8;
    char padEA9[0xee8 - 0xea9];
    int sound;
    float time;
};

extern "C" void fn_60_4D48(Tengan* self) {
    int i;
    char* p = self->params;
    if (p == 0) return;

    #define F(o) (*(float*)(p + (o)))
    #define G() ((grMadein*)((Stage*)self)->getGround(3))

    float m = lbl_60_rodata_38;
    i = 0;
    int r = randi((int)(F(0xac) * m + (F(0xa8) * m + (F(0xa4) * m + (F(0xa0) * m + (F(0x98) * m + F(0x9c) * m))))) + 1);
    int sum = 0;
    unsigned long done = 0;

    do {
        switch (i) {
        case 0: sum += (int)(F(0x98) * m); break;
        case 1: sum += (int)(F(0x9c) * m); break;
        case 2: sum += (int)(m * (F(0xa0) + F(0xa4))); break;
        case 3: sum += (int)(F(0xa8) * m); break;
        case 4: sum += (int)(F(0xac) * m); break;
        case 5: sum = r; break;
        }
        if (sum >= r) done = 1;
        if (sum < r) i++;
    } while (done != 1);

    unsigned long ok = 0;
    if (self->selectedEvent != i) {
        switch (i) {
        default:
            ok = self->event578.start();
            break;
        case 1:
            if (self->event77C.isEvent() == 0) {
                if (self->event6D0.isEvent() == 0) {
                    self->cnt = 0;
                    for (int k = 0; k < 3; k++) {
                        if (self->flags[k] == 1) self->cnt++;
                    }
                    if ((s8)self->cnt != 3) {
                        ok = self->event4CC.start();
                        self->event6D0.start();
                    }
                }
            }
            break;
        case 2:
            ok = self->event4CC.start();
            if (ok == 1) {
                ok = self->event420.start();
                if (ok == 0) self->event4CC.end();
                else self->flagEA8 = 1;
            }
            break;
        case 3:
            ok = self->event624.start();
            break;
        case 4:
            if (self->event77C.isEvent() == 0) {
                if (self->event6D0.isEvent() == 0) {
                    self->cnt = 0;
                    for (int k = 0; k < 3; k++) {
                        if (self->flags[k] == 1) self->cnt++;
                    }
                    if ((s8)self->cnt != 3) ok = self->event828.start();
                }
            }
            break;
        case 5:
            ok = 0;
            break;
        }
    }

    if (ok == 1) {
        self->selectedEvent = i;
        self->eventStarted = 1;
        G()->setMotion(1);
        G()->startEntity();
        self->cue.end();
        self->cue.start();
        self->sound = 0x1c4c;
        self->time = lbl_60_rodata_54;
        p = (char*)g_ecMgr->setEffect((EfID)0x104004c);
        g_ecMgr->setParent((unsigned long)p, G()->m_sceneModels[0], lbl_60_data_474, false);
    }
}