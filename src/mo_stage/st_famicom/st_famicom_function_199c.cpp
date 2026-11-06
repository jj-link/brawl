#pragma force_active on
extern const float lbl_68_rodata_0;
extern "C" float randf__Fv();

struct Params {
    char pad[0x4c];
    float delay, low, high;
    float pad58;
    float threshold, chance;
};
struct Famicom {
    char pad[0x9c];
    Params* params;
    char pad2[0x1f4 - 0xa0];
    float values[4];
    float totals[4];
    unsigned char flags[4];
    char pad3[0x3b0 - 0x218];
    unsigned char state;
    char pad4[3];
    float timer, limit;
    char pad5[0x3ec - 0x3bc];
    unsigned char a, b, c, d;
};
extern "C" void fn_68_199C(Famicom* self, float delta) {
    Params* p = self->params;
    if (p) {
        self->timer -= delta;
        if (self->timer < lbl_68_rodata_0)
            self->timer = lbl_68_rodata_0;
        switch (self->state) {
        case 0: {
            self->timer = p->delay;
            float t = p->low + (p->high - p->low) * randf__Fv();
            self->state = 1;
            self->limit = t;
            break;
        }
        case 1:
            if (!(self->timer > lbl_68_rodata_0)) {
                unsigned int i;
                unsigned int flag = 0;
                unsigned int count;
                i = 0;
                count = 4;
                for (; i < 4; i++) {
                    if (self->totals[i] > p->threshold) {
                        flag = 1;
                        break;
                    }
                }
                if (!flag) {
                    i = 0;
                    count = 4;
                    for (; i < 4; i++) {
                        if (self->values[i] > self->limit)
                            break;
                    }
                }
                if (i != count) {
                    switch (i) {
                    case 0: self->a = 9; break;
                    case 1: self->a = 10; break;
                    case 2: self->a = 11; break;
                    case 3: self->a = 12; break;
                    }
                    if (flag == 1 && randf__Fv() < p->chance) {
                        self->b = self->a;
                        self->c = 1;
                        self->d = 0;
                        self->totals[(unsigned char)i] = lbl_68_rodata_0;
                    } else {
                        if (self->flags[i] == 1)
                            self->c = 0;
                        else
                            self->c = 1;
                        if (flag == 1)
                            self->totals[(unsigned char)i] = self->values[(unsigned char)i];
                        else
                            self->totals[(unsigned char)i] += self->values[(unsigned char)i];
                    }
                    self->values[(unsigned char)i] = lbl_68_rodata_0;
                    self->state = 2;
                }
            }
            break;
        case 2:
            if (self->a == 13 && self->b == 13) {
                float t = p->low + (p->high - p->low) * randf__Fv();
                self->state = 1;
                self->limit = t;
            }
            break;
        }
    }
}