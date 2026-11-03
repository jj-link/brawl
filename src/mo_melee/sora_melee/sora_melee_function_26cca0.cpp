#pragma force_active on

extern "C" void __dla__FPv(void*);
extern "C" void* __nwa__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* __construct_new_array(void*, void (*)(), void*, unsigned long, int);
extern "C" void fn_27_26CE0C();
extern "C" void __ct__14snd3DGeneratorFv();
extern "C" void __dt__14snd3DGeneratorFv();
extern "C" void fn_803F0D4C(void*, void (*)());

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
    char pad[0x9C];
    unsigned long unk9C;
    void* unkA0;
    unsigned long unkA4;
    Effect* unkA8;
};

extern "C" void createSoundWork__9grGimmickFUlUl(grGimmick* self, unsigned long a, unsigned long b) {
    if (self->unkA0) {
        fn_803F0D4C(self->unkA0, __dt__14snd3DGeneratorFv);
        self->unkA0 = 0;
    }
    if (self->unkA8) {
        if (self->unkA8)
            __dla__FPv((char*)self->unkA8 - 16);
        self->unkA8 = 0;
    }

    self->unk9C = b;
    self->unkA0 = __construct_new_array(
        __nwa__FUlQ25Heaps8HeapType(b * 8 + 16, 15),
        __ct__14snd3DGeneratorFv, __dt__14snd3DGeneratorFv, 8, b);
    self->unkA4 = a;
    self->unkA8 = (Effect*)__construct_new_array(
        __nwa__FUlQ25Heaps8HeapType(a * 40 + 16, 15),
        fn_27_26CE0C, 0, 40, a);

    for (unsigned long i = 0; i < self->unkA4; i++) {
        Effect* e = &self->unkA8[i];
        e->state = 0;
        e->frame = lbl_27_rodata_4388;
        e->handle = -1;
        e->generator = 0;
        e->offset = Vec2(lbl_27_rodata_4388, lbl_27_rodata_4388);
        self->unkA8[i].repeat = 0;
        self->unkA8[i].id = -1;
        self->unkA8[i].scale = lbl_27_rodata_4398;
    }
}
