#pragma force_active on

extern const float lbl_72_rodata_0[];
extern "C" float randf__Fv();

inline unsigned char minimum(unsigned int a, unsigned int b) {
    return (unsigned char)a < b ? a : b;
}

struct Params {
    char pad[0x34];
    float initial;
    float low;
    float high;
    char pad2[8];
    float chance;
    unsigned int count;
};

struct Entry {
    unsigned char state;
    char pad[0x33];
    float timer;
};

struct Greenhill {
    char pad[0x9c];
    Params* params;
    char pad2[0x1de - 0xa0];
    unsigned char state;
    char pad3;
    float timer;
    unsigned char count;
    unsigned char first;
    unsigned char second;
    unsigned char third;
    Entry entries[3];
};

extern "C" void fn_72_B9C(Greenhill* self, float delta) {
    const float* data = lbl_72_rodata_0;
    Params* p = self->params;

    if (p) {
        self->timer -= delta;
        if (self->timer < data[0])
            self->timer = data[0];

        switch (self->state) {
        case 0:
            self->timer = p->initial;
            self->state = 1;
        case 1:
            if (data[0] == self->timer) {
                if (self->count >= p->count) {
                    self->count = 0;
                    self->state = 3;
                    return;
                }

                if (randf__Fv() < p->chance) {
                    self->count = 0;
                    self->state = 3;
                    return;
                }

                float random = randf__Fv();
                int raw = (int)(data[6] * random);
                unsigned int n = (unsigned char)raw > 0 ? raw : 0;
                unsigned char index = minimum(n, 2);

                self->entries[index].state = 3;
                self->entries[index].timer = data[7] + data[8] * randf__Fv();
                self->state = 2;
                self->count++;
                return;
            }
            break;

        case 2:
            if (self->entries[0].state == 5 &&
                self->entries[1].state == 5 &&
                self->entries[2].state == 5)
                self->state = 5;
            break;

        case 3:
            if (randf__Fv() < data[9]) {
                self->first = 0;
                if (randf__Fv() < data[7]) {
                    self->second = 1;
                    self->third = 2;
                } else {
                    self->second = 2;
                    self->third = 1;
                }
            } else if (randf__Fv() < data[10]) {
                self->first = 1;
                if (randf__Fv() < data[7]) {
                    self->second = 0;
                    self->third = 2;
                } else {
                    self->second = 2;
                    self->third = 0;
                }
            } else {
                self->first = 2;
                if (randf__Fv() < data[7]) {
                    self->second = 0;
                    self->third = 1;
                } else {
                    self->second = 1;
                    self->third = 0;
                }
            }
            self->state = 4;
            self->timer = data[11];

        case 4:
            if (data[0] == self->timer) {
                if (self->first == 0xff) {
                    if (self->entries[0].state == 5 &&
                        self->entries[1].state == 5 &&
                        self->entries[2].state == 5)
                        self->state = 5;
                } else {
                    self->entries[self->first].state = 3;
                    self->first = self->second;
                    self->second = self->third;
                    self->third = 0xff;
                    self->timer = data[12] + data[13] * randf__Fv();
                    return;
                }
            }
            break;

        case 5:
            float t = p->low + (p->high - p->low) * randf__Fv();
            self->state = 1;
            self->timer = t;
            break;
        }
    }
}
