#include <ft/ft_manager.h>
#pragma force_active on

struct Rules {
    char pad[9];
    unsigned char mode;
    char padA;
    unsigned char flags;
    char padC;
    unsigned char enabled;
    char padE[0x8d];
    unsigned char index;
    char rest[0x5b];
};

struct Score {
    char pad[0x2e];
    signed char stock;
    char pad2[0x1d];
    int value;
    char pad3[0x22c];
    int other;
    char pad4[0x2c];
};

struct State {
    char pad[0x44];
    Rules* rules;
    char pad48[0x30];
    int mask;
    int values[4];
    float current[4];
    float target[4];
};

extern "C" void fn_27_1120C0(void*, float);

extern "C" void fn_27_24814C(State* self, Score* scores, float delta) {
            float divisor;
    if ((self->rules->enabled >> 5) & 1) {
        if (0.0f < delta) {
            self->mask = 0;
            int max, min;
            int count = 0;

            for (int i = 0; i < 4; i++) {
                if (g_ftManager->isValidEntryId(g_ftManager->getEntryId(i))) {
                    Rules* rules = self->rules;
                    Score* score =
                        &scores[((unsigned char*)rules)[0x9b + i * 0x5c]];
                    int value;

                    if ((rules->flags >> 5) & 1)
                        value = 0;
                    else {
                        unsigned mode = (rules->mode >> 5) & 7;
                        if (mode == 2)
                            value = score->value;
                        else if (mode == 1)
                            value = score->stock;
                        else
                            value = score->other;
                    }

                    if (self->mask == 0) {
                        max = value;
                        min = value;
                    } else {
                        max = max > value ? max : value;
                        min = min < value ? min : value;
                    }

                    self->values[i] = value;
                    count++;
                    self->mask |= 1 << i;
                }
            }

            int range = max - min;
            float scale = 0.5f;
            divisor = scale * (float)range;
            unsigned mode = (self->rules->mode >> 5) & 7;

            if (mode == 0) {
                scale = range < 5 ? scale : 1.0f;
            } else if (mode == 1) {
                scale = range < 2 ? scale : 1.0f;
            } else {
                scale = 1.0f;
            }

            scale *= (float)count / 4.0f;
            float step = 0.04f * delta / 60.0f;

            for (int i = 0; i < 4; i++) {
                if (self->mask & (1 << i)) {
                    float target;
                    if (0.0f == divisor)
                        target = 0.0f;
                    else
                        target = scale *
                                 ((float)(self->values[i] - min) / divisor -
                                  1.0f);

                    self->target[i] = target;
                    float current = self->current[i];

                    if (current != target) {
                        if (current < target) {
                            current += step;
                            if (current > target)
                                current = target;
                        } else {
                            current -= step;
                            if (current < target)
                                current = target;
                        }
                        self->current[i] = current;
                    }
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            if (self->mask & (1 << i)) {
                int id = g_ftManager->getEntryId(i);
                if (g_ftManager->isValidEntryId(id))
                    fn_27_1120C0(g_ftManager->getOwner(id), self->current[i]);
            }
        }
    }
}
