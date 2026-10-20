#pragma force_active on
extern const float lbl_88_rodata_F8[4];

struct Vec3 {
    float x, y, z;
};

struct Base {
    char pad00[0x3c];
};

struct Object : Base {
    virtual void padV0();
    virtual void padV1();
    virtual void padV2();
    virtual void padV3();
    virtual void padV4();
    virtual void padV5();
    virtual void padV6();
    virtual void padV7();
    virtual void padV8();
    virtual void padV9();
    virtual void padV10();
    virtual void padV11();
    virtual void padV12();
    virtual void padV13();
    virtual void padV14();
    virtual void padV15();
    virtual void padV16();
    virtual void padV17();
    virtual void padV18();
    virtual void padV19();
    virtual void padV20();
    virtual void padV21();
    virtual void padV22();
    virtual void padV23();
    virtual void padV24();
    virtual void padV25();
    virtual void padV26();
    virtual void padV27();
    virtual void padV28();
    virtual void padV29();
    virtual void padV30();
    virtual void padV31();
    virtual void padV32();
    virtual void padV33();
    virtual void padV34();
    virtual void padV35();
    virtual void padV36();
    virtual void padV37();
    virtual void padV38();
    virtual void padV39();
    virtual void padV40();
    virtual void padV41();
    virtual void padV42();
    virtual void padV43();
    virtual void padV44();
    virtual void padV45();
    virtual void padV46();
    virtual void padV47();
    virtual void set(Vec3*, int, int);
    virtual void gapV0();
    virtual void gapV1();
    virtual void gapV2();
    virtual void gapV3();
    virtual void gapV4();
    virtual void gapV5();
    virtual void gapV6();
    virtual void gapV7();
    virtual void gapV8();
    virtual void gapV9();
    virtual void gapV10();
    virtual void gapV11();
    virtual void gapV12();
    virtual void gapV13();
    virtual void gapV14();
    virtual void gapV15();
    virtual void gapV16();
    virtual void gapV17();
    virtual void gapV18();
    virtual void gapV19();
    virtual void gapV20();
    virtual void gapV21();
    virtual void reset();

    char pad40[0x6c - 0x40];
    unsigned char flags;
    char pad6D[0x150 - 0x6d];
    unsigned char state;
    char pad151[3];
    float timer;
    char pad158[0x170 - 0x158];
    int active1;
    int active2;
    char pad178[0x184 - 0x178];
    Vec3 positions[6];
    int ids[6];
};

extern "C" void fn_88_502C(Object* self, float delta) {
    if (self->active1 != 0 && self->active2 != 0) {
        self->timer -= delta;
        if (self->timer < lbl_88_rodata_F8[0])
            self->timer = lbl_88_rodata_F8[0];

        switch (self->state) {
        case 2:
            break;
        case 0:
            self->reset();
            self->flags &= ~2;
            self->set(&self->positions[0], 0, self->ids[0]);
            self->set(&self->positions[1], 0, self->ids[1]);
            self->set(&self->positions[2], 0, self->ids[2]);
            self->set(&self->positions[3], 0, self->ids[3]);
            self->set(&self->positions[4], 0, self->ids[4]);
            self->set(&self->positions[5], 0, self->ids[5]);
            self->state = 1;
        case 1:
            self->state = 2;
            break;
        }
    }
}
