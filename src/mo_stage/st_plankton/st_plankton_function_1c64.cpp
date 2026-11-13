#pragma force_active on

extern "C" const float lbl_74_rodata_0[];

struct Wave {
    float velocity;
    float current;
    float next;
};

struct Obj {
    char pad[0x590];
    Wave wave[192];
};

extern "C" void fn_74_1C64(Obj* self)
{
    const float div = lbl_74_rodata_0[20];
    float v;
    int base = (int)self;
    int off;
    Wave* p = self->wave;
    unsigned int i;

    for (i = 0, off = 0; i < 192; ++p, off += 12, ++i) {
        if (i == 0) {
            v = p->velocity +
                (*(float*)(off + base + 0x5a0) + (p->current + p->current)) / div;
        } else if (i == 191) {
            v = p->velocity +
                (*(float*)(off + base + 0x588) + (p->current + p->current)) / div;
        } else {
            v = p->velocity +
                (*(float*)(off + base + 0x588) +
                 (p->current + *(float*)(off + base + 0x5a0))) / div;
        }

        v -= v / lbl_74_rodata_0[21];
        p->velocity = v - p->current;

        if (v > lbl_74_rodata_0[22])
            p->next = lbl_74_rodata_0[22];
        else
            p->next = v;
    }

    for (int i = 0; i < 192; ++i)
        self->wave[i].current = self->wave[i].next;
}
