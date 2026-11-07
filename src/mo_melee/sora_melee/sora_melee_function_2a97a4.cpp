#include <gm/gm_global.h>
#include <mt/mt_prng.h>
#pragma force_active on
struct ModeView {
    char pad[9];
    unsigned char flags;
    char pad2[0x16];
    unsigned int time;
    unsigned int count;
};
struct Object {
    char pad[0x50];
    int state;
    char pad54[0x20];
    float rate;
    float rate2;
    float rate1;
    char pad80[0x2c];
    unsigned int a;
    unsigned int b;
    unsigned int c;
    char padb8[0x10e4];
    char data[0x2f8];
    unsigned int flags;
    unsigned int timer;
    unsigned char forced;
    unsigned char pad149d;
    unsigned char enabled;
};
extern "C" int fn_800526E4();
extern "C" void fn_80052694();
extern "C" float fn_27_2A91CC(Object*, int, void*);
extern const float lbl_27_rodata_5D80;
extern "C" void fn_27_2A97A4(Object* self, int force, int arg) {
    ModeView* mode = (ModeView*)g_GameGlobal->m_modeMelee;
    if (mode) {
        self->timer = 0;
        self->flags = 0;
        self->forced = 0;
        if (self->state != 4 && arg == 0 && (force || !fn_800526E4())) {
            float chance = self->rate;
            unsigned int time = mode->time;
            switch ((mode->flags >> 5) & 7) {
            case 1:
                chance = self->rate1;
                time = mode->count * (self->a * 60);
                if (time < self->b * 60)
                    time = self->b * 60;
                break;
            case 2:
                chance = self->rate2;
                break;
            }
            if (force) {
                time /= 3;
                self->forced = 1;
            }
            unsigned int max = self->c * 3600;
            if (time == 0 || time > max)
                time = max;
            float factor = lbl_27_rodata_5D80;
            if (self->enabled)
                factor = fn_27_2A91CC(self, 20, self->data);
            chance = factor * chance;
            if (force || randf() < chance) {
                self->timer = time;
                self->flags |= 1;
                fn_80052694();
            }
        }
    }
}