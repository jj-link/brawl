#pragma force_active on
typedef struct {
    char pad[4];
    float end, start, value, step;
    int active, mode;
    unsigned char reverse;
} State;

void fn_80278C54(State *s) {
    float bound;
    if (s->active == 1) {
        switch (s->mode) {
        case 0:
            bound = s->end - 1.0f;
            s->value += s->step;
            if (s->value >= bound) {
                s->value = bound;
                s->active = 0;
            }
            break;
        case 1:
            s->value -= s->step;
            if (s->value <= s->start) {
                s->value = s->start;
                s->active = 0;
            }
            break;
        case 2:
            s->value += s->step;
            if (s->value >= s->end) {
                s->value -= s->end - s->start;
            }
            break;
        case 3:
            if (!s->reverse) {
                bound = s->end - 1.0f;
                s->value += s->step;
                if (s->value >= bound) {
                    s->value = bound;
                    s->reverse = 1;
                }
            } else {
                s->value -= s->step;
                if (s->value <= s->start) {
                    s->value = s->start;
                    s->reverse = 0;
                }
            }
            break;
        }
    }
}