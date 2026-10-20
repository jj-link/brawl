#pragma force_active on
typedef unsigned char u8;

struct HalberdBase {
    char pad0[0x3C];

#define VIRTUAL_SLOTS(N) \
    virtual void unused##N##0(); \
    virtual void unused##N##1(); \
    virtual void unused##N##2(); \
    virtual void unused##N##3(); \
    virtual void unused##N##4(); \
    virtual void unused##N##5(); \
    virtual void unused##N##6(); \
    virtual void unused##N##7(); \
    virtual void unused##N##8(); \
    virtual void unused##N##9();

    VIRTUAL_SLOTS(0)
    VIRTUAL_SLOTS(1)
    VIRTUAL_SLOTS(2)
    VIRTUAL_SLOTS(3)
    VIRTUAL_SLOTS(4)
    VIRTUAL_SLOTS(5)
    VIRTUAL_SLOTS(6)
    VIRTUAL_SLOTS(7)
    VIRTUAL_SLOTS(8)
    VIRTUAL_SLOTS(9)
    VIRTUAL_SLOTS(10)

#undef VIRTUAL_SLOTS

    virtual void unused110();
    virtual void unused111();
    virtual void unused112();
    virtual void unused113();
    virtual void unused114();
    virtual void unused115();
    virtual void unused116();
    virtual void unused117();
    virtual void unused118();
    virtual void setMotion(int, int, int, float*);
};

struct Halberd : HalberdBase {
    char pad40[0x110];
    u8 step;
    char pad151[0xB];
    u8* event;
    char pad160[8];
    u8 type;
    char pad169[7];
    float motion[3];
    char sound[4];
};

extern "C" int playSE__14snd3DGeneratorF5SndIDiii(
    void*, int, int, int, int);

extern "C" void fn_57_10734(Halberd* self) {
    if (self->type == 2) {
        switch (self->step) {
        case 0:
            self->setMotion(0, 1, 1, self->motion);
            self->step = 1;
        case 1:
            if (*self->event == 0x12) {
                playSE__14snd3DGeneratorF5SndIDiii(
                    self->sound, 0x1BF5, 0, 0, -1);
                self->step = 2;
            }
            break;
        case 2:
            if (*self->event == 0x13) {
                self->setMotion(1, 0, 1, self->motion);
                playSE__14snd3DGeneratorF5SndIDiii(
                    self->sound, 0x1BF6, 0, 0, -1);
                self->step = 13;
            }
            break;
        case 13:
            if (*self->event == 0x14) {
                self->setMotion(2, 0, 1, self->motion);
                playSE__14snd3DGeneratorF5SndIDiii(
                    self->sound, 0x1BF7, 0, 0, -1);
                self->step = 14;
            }
            break;
        case 14:
            if (*self->event == 0x15) {
                self->step = 0;
            }
            break;
        }
    }
}
