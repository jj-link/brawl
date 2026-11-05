#pragma force_active on
#include <snd/snd_system.h>

struct Entry {
    char pad[0x98];
    u8 unk98;
    u8 unk99;
};

struct Owner {
    char pad[0x44];
    Entry* unk44;
};

extern "C" void fn_27_249B14(void* self, int a, int b, int c);

extern "C" void fn_27_253560(Owner* self, int a, int b, int c) {
    Entry* e = (Entry*)((char*)self->unk44 + b * 0x5C);
    if (e->unk99 == 1 && e->unk98 < 0x2E) {
        g_sndSystem->playSE((SndID)0x1B, -1, 0, 0, -1);
    }
    fn_27_249B14(self, a, b, c);
}
