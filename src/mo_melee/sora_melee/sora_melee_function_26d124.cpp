#pragma force_active on

extern "C" void __dla__FPv(void*);
extern "C" void* __nwa__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_27_26CE0C();
extern "C" void* __construct_new_array(
    void*, void (*)(), void*, unsigned long, int);

extern const float lbl_27_rodata_4388;
extern const float lbl_27_rodata_4398;

struct Vec2 {
    float x, y;

    Vec2(float a, float b) : x(a), y(b) {}
};

struct Effect {
    unsigned short state;
    short pad2;
    float frame;
    int handle;
    int id;
    unsigned long repeat;
    unsigned long end;
    short node;
    short generator;
    Vec2 offset;
    float scale;
};

struct grGimmick {
    char pad[0xAC];
    unsigned long count;
    Effect* effects;
};

extern "C" void createEffectWork__9grGimmickFi(grGimmick* self, int count) {
    if (self->effects) {
        if (self->effects)
            __dla__FPv((char*)self->effects - 16);
        self->effects = 0;
    }

    self->count = count;
    self->effects = (Effect*)__construct_new_array(
        __nwa__FUlQ25Heaps8HeapType(count * 40 + 16, 15),
        fn_27_26CE0C, 0, 40, count);

    for (unsigned long i = 0; i < self->count; i++) {
        Effect* e = &self->effects[i];
        e->state = 0;
        e->frame = lbl_27_rodata_4388;
        e->handle = -1;
        e->generator = 0;
        e->offset = Vec2(lbl_27_rodata_4388, lbl_27_rodata_4388);
        self->effects[i].repeat = 0;
        self->effects[i].id = 0;
        self->effects[i].scale = lbl_27_rodata_4398;
    }
}
