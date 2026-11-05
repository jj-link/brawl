#include <snd/snd_system.h>
#include <gr/gr_gimmick.h>
#pragma force_active on
struct Data {
    char pad[0x37];
    unsigned char enabled;
    char pad38[0xc];
    unsigned char kind;
    char pad45[3];
    int sound;
};
struct Object {
    char pad[0x160];
    Data* data;
};
extern "C" void fn_40_2567C(Object* self) {
    Data* data = self->data;
    if (data->enabled) {
        if (data->sound > 0) {
            g_sndSystem->playSE((SndID)data->sound, -1, 0, 0, -1);
        } else {
            switch (data->kind) {
            case 0: g_sndSystem->playSE((SndID)0x2262, -1, 0, 0, -1); break;
            case 1: g_sndSystem->playSE((SndID)0x2289, -1, 0, 0, -1); break;
            case 2: g_sndSystem->playSE((SndID)0x228a, -1, 0, 0, -1); break;
            case 3: g_sndSystem->playSE((SndID)0x228b, -1, 0, 0, -1); break;
            case 4: g_sndSystem->playSE((SndID)0x228c, -1, 0, 0, -1); break;
            }
        }
    }
    switch (self->data->kind) {
    case 5:
        ((grGimmick*)self)->startGimmickEffect(0);
        break;
    }
}