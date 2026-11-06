#include <snd/snd_system.h>
#pragma force_active on

struct BgmInfo {
    char pad[4];
    unsigned short frame;
};

struct Self {
    char pad0[0x170];
    BgmInfo* info;
    char pad174[4];
    int bgmId;
    unsigned int endFrame;
    unsigned int frame;
    char pad184[8];
    unsigned char enabled;
    char pad18D[0x1333];
    int state;
    char pad14C4[8];
    int ready1;
    char pad14D0[4];
    int ready2;
};

extern "C" void fn_80078768(Self*);
extern "C" void fn_80078990(Self*);
extern "C" void fn_800741EC(sndSystem*, int, unsigned int);

extern "C" void fn_80078648(Self* self) {
    switch (self->state) {
    case 0:
        self->state = 1;
        break;
    case 1:
        if (self->ready1 != 0 && self->ready2 != 0) {
            self->state = 2;
        }
        break;
    case 2:
        fn_80078768(self);
        fn_80078990(self);
        self->state = 3;
        break;
    case 3:
        self->frame++;
        if (self->info != 0 && self->info->frame != 0 &&
            self->info->frame != 0xFFFF && self->info->frame == self->frame) {
            fn_800741EC(g_sndSystem, self->bgmId, self->endFrame);
        } else if (self->enabled != 0 && self->frame == self->endFrame) {
            self->enabled = 0;
            g_sndSystem->playBGM(self->bgmId, 0, false);
        }
        break;
    case 4:
        break;
    }
}
