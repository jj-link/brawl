#pragma force_active on
extern "C" const float lbl_68_rodata_D0;

struct Base {
    unsigned char padding[0x3c];
};

#define SLOT(n) virtual void unused##n();
#define SLOTS8(n) \
    SLOT(n##0) SLOT(n##1) SLOT(n##2) SLOT(n##3) \
    SLOT(n##4) SLOT(n##5) SLOT(n##6) SLOT(n##7)
#define SLOTS16(n) \
    SLOTS8(n) \
    SLOT(n##8) SLOT(n##9) SLOT(n##a) SLOT(n##b) \
    SLOT(n##c) SLOT(n##d) SLOT(n##e) SLOT(n##f)

struct Object : Base {
    SLOTS16(a)
    SLOTS16(b)
    SLOTS16(c)
    SLOTS16(d)
    SLOTS16(e)
    SLOTS16(f)
    SLOTS16(g)
    SLOTS16(h)
    SLOTS8(i)
    virtual unsigned int state();
    virtual int paused();

    unsigned char padding1[0x11c];
    float timer;
};

#undef SLOTS16
#undef SLOTS8
#undef SLOT

extern "C" void fn_68_BB4C(Object* self, float delta) {
    if (self->state() != 1 || self->paused() != 0) {
        self->timer -= delta;
        if (self->timer < lbl_68_rodata_D0) {
            self->timer = lbl_68_rodata_D0;
        }
    }
}
