#pragma force_active on
struct LucasB994Callback {
    virtual void slot00() = 0;
    virtual void slot01() = 0;
    virtual void slot02() = 0;
    virtual void slot03() = 0;
    virtual void slot04() = 0;
    virtual void slot05() = 0;
    virtual void slot06() = 0;
    virtual void slot07() = 0;
    virtual void slot08() = 0;
    virtual void slot09() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void dispatch(int, int, int) = 0;
};

struct LucasB994Leaf {
    unsigned char padding[0x28];
    LucasB994Callback* callback;
};

struct LucasB994Intermediate {
    unsigned char padding[0xD8];
    LucasB994Leaf* leaf;
};

struct LucasB994Object {
    unsigned char padding0[0x60];
    LucasB994Intermediate* intermediate;
    unsigned char padding1[0x48C60];
    unsigned char state0;
    unsigned char state1;
};

extern "C" int fn_27_135DE8(void*);

extern "C" int fn_114_B994(LucasB994Object* self) {
    if (self->state0 == 1) {
        return 1;
    }
    if (self->state1 == 1) {
        self->intermediate->leaf->callback->dispatch(0, 0, 2);
    }
    return fn_27_135DE8(self);
}
