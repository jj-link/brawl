#include <snd/snd_system.h>
#pragma force_active on

struct Inner {
    char pad[4];
    unsigned short value;
};
struct Obj {
    char pad[0x170];
    Inner* inner;
    char pad174[4];
    int id;
    unsigned int fade;
    int unk180;
    char pad184[0xC];
    int saved;
};
extern "C" int fn_8007923C(Obj*, int, int, int);
extern "C" int fn_80074018(sndSystem*, int, int);

extern "C" int fn_80078DAC(Obj* self, int arg1, int arg2, unsigned int arg3) {
    if ((unsigned int)(arg2 + 0x10000) != 0xffff) {
        int result = fn_8007923C(self, arg1, arg2, 0);
        if (result == -1) {
            self->id = 0;
            return -1;
        }
        self->id = result;
        if (arg1 == 0x2a) {
            if (arg2 == 0)
                self->id = self->saved;
            else
                self->saved = result;
        }
    }
    if (self->id == 0)
        return -1;
    if (self->inner->value == 0) {
        if (!g_sndSystem->playBGM(self->id, arg3, true))
            return -1;
    } else {
        self->fade = arg3;
        self->unk180 = 0;
        if (!fn_80074018(g_sndSystem, self->id, 1))
            return -1;
    }
    return self->id;
}