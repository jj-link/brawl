#pragma force_active on
struct Resolver {
    virtual void unused0() = 0;
    virtual void unused1() = 0;
    virtual unsigned int resolve(unsigned int, unsigned int) = 0;
};

struct Context {
    unsigned char pad[0x38];
    unsigned int field38;
    void* field3C;
    unsigned int field40;
    Resolver* field44;
    unsigned char pad48[8];
    float field50;
    unsigned int field54;
};

extern "C" int fn_27_58120(void*, unsigned int, unsigned int,
                          unsigned int, unsigned int);
extern "C" void fn_800778CC(void*, int, float);

extern void* g_sndSystem;
extern const float lbl_27_rodata_728;

extern "C" int fn_27_56AC8(Context* self, unsigned int arg,
                         unsigned int mode, unsigned int value) {
    unsigned int id = self->field44->resolve(arg, self->field40);
    if (id == 0xFFFFFFFF)
        return -1;

    int result = fn_27_58120(self->field3C, value, id,
                            self->field38, self->field54);

    if (lbl_27_rodata_728 != self->field50 && mode == 1 && result >= 0)
        fn_800778CC(g_sndSystem, result, self->field50);

    return result;
}
