#pragma force_active on
#include <ft/ft_manager.h>
#include <snd/snd_system.h>

struct Thresholds {
    float values[3];
    char pad0C[0xC];
    float repeatTime;
    char pad1C[8];
    int start;
    int end;
};
struct Owner {
    char pad0[0x44];
    Thresholds* thresholds;
    int previous;
    int time;
    float value;
    int selected;
    char pad58[8];
    int frame;
    char pad64[4];
    int sound;
    int secondSound;
    char pad70[8];
    int arg;
    char pad7C;
    bool flag;
};
struct SoundEntry { SndID a, b, c; };

extern "C" {
extern const SoundEntry lbl_27_rodata_F18[3];
float fn_27_14D5C0(Fighter*);
int fn_27_110340(Owner*, int, float);
unsigned int fn_80077DA0(sndSystem*, int);
void fn_80075F1C(sndSystem*, int, int);
}

#define TIER(out, x) \
    if ((x) >= self->thresholds->values[2]) out = 2; \
    else if ((x) >= self->thresholds->values[1]) out = 1; \
    else out = -!((x) >= self->thresholds->values[0])

#define STOP(field) \
    if (self->field != -1 && fn_80077DA0(g_sndSystem, self->field) == 1U) \
        fn_80075F1C(g_sndSystem, self->field, 0); \
    self->field = -1

#define FLAG() \
    if (entry != -1 && self->selected == entry) { \
        Thresholds* t = self->thresholds; \
        int frame = self->frame; \
        if (frame < t->end && frame >= t->start) self->flag = true; \
    }

extern "C" void fn_27_110698(Owner* self, int entry, int other) {
    float value = fn_27_14D5C0(g_ftManager->getFighter(other, -1));
    int tier;
    TIER(tier, value);
    if (tier != -1) {
        if (g_ftManager->isFighterActivate(entry, -1) == true) {
            float current = fn_27_14D5C0(g_ftManager->getFighter(entry, -1));
            int currentTier;
            TIER(currentTier, current);
            if (currentTier >= 2) {
                int index;
                TIER(index, value);
                if (index >= 1 && fn_27_110340(self, entry, value) != 0) {
                    STOP(sound);
                } else {
                    STOP(secondSound);
                    self->secondSound = g_sndSystem->playSE(lbl_27_rodata_F18[index].b, self->arg, 0, 0, -1);
                    FLAG();
                }
                goto done;
            }
        }
        if (self->previous == entry && (float)self->time < self->thresholds->repeatTime) {
            float current = self->value;
            if (value > current) current = value;
            int index;
            TIER(index, current);
            if (index >= 1 && fn_27_110340(self, entry, current) != 0) {
                STOP(sound);
            } else {
                STOP(secondSound);
                self->secondSound = g_sndSystem->playSE(lbl_27_rodata_F18[index].b, self->arg, 0, 0, -1);
                FLAG();
            }
        } else {
            STOP(sound);
            self->sound = g_sndSystem->playSE(lbl_27_rodata_F18[tier].a, self->arg, 0, 0, -1);
            if (tier == 2 || (tier == 1 && self->selected == other)) {
                Thresholds* t = self->thresholds;
                int frame = self->frame;
                if (frame < t->end && frame >= t->start) self->flag = true;
            }
        }
done:
        self->previous = entry;
        self->time = 0;
        self->value = value;
    }
}
