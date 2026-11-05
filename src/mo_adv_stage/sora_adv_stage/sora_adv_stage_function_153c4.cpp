#pragma force_active on
#include <it/it_manager.h>
#include <mt/mt_prng.h>
#include <mt/mt_vector.h>

extern "C" void fn_27_226E2C(void*, Vec3f*);
extern "C" void* fn_80158BE0();
extern "C" int fn_801590F0(void*, int);
extern "C" void fn_27_2AA7AC(itManager*, void*, int, Vec3f*, int, int, int);
extern float lbl_40_rodata_218;

struct Pair {
    unsigned int x, y;
};

struct State {
    char pad[0x40];
    void* object;
    Pair pair;
    unsigned char active;
    unsigned char flag4D;
    unsigned char flag4E;
    unsigned char flag4F;
    unsigned int minimum;
    unsigned int maximum;
    unsigned int trigger;
    unsigned int timer;
    unsigned int delay;
};

extern "C" void fn_40_153C4(State* self) {
    if (self->delay < 120U) {
        self->delay++;
        return;
    }
    if (self->active) {
        if (self->timer == self->trigger) {
            if (self->object) {
                Vec3f pos;
                pos.m_x = pos.m_y = pos.m_z = lbl_40_rodata_218;
                fn_27_226E2C(self->object, &pos);
                int kind = (fn_801590F0(fn_80158BE0(), 1001) != 0) + 10001;
                Pair pair = self->pair;
                fn_27_2AA7AC(itManager::getInstance(), &pair, kind, &pos, -1, -1, -1);
            }
            self->timer++;
            return;
        }
        if (self->timer >= self->maximum) {
            self->active = 1;
            unsigned int a = self->minimum;
            self->flag4E = 1;
            self->timer = 0;
            float r = randf();
            unsigned int b = self->maximum;
            float diff = (float)(b - a);
            self->trigger = a + (unsigned int)(diff * r);
            return;
        }
        self->timer++;
    }
}
