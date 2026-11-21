#include <snd/snd_system.h>
#pragma force_active on
#pragma optimization_level 1
struct Data {
    char a[0x1b40]; int count;
    char b[0x1bfc-0x1b44]; int state;
    char c[0x1d40-0x1c00]; int d40,d44,d48,d4c;
    char d[0x1d68-0x1d50]; int d68;
};
struct Menu { char pad[0x1ac]; Data* data; };
extern "C" void fn_5_13258(Menu* self, int value) {
    if (self->data->count > 0) {
        self->data->d4c = 0;
        self->data->state = 0x17;
    } else {
        self->data->d68 = value;
        self->data->d40 = -1;
        self->data->d44 = 0x1b;
        self->data->d48 = 0;
        self->data->state = 0x19;
    }
    g_sndSystem->playSE(static_cast<SndID>(1), -1, 0, 0, -1);
}