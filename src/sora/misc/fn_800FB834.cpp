#pragma force_active on

extern "C" void __dt__6gfTaskFv(void*, int);
extern "C" void __dl__FPv(void*);
extern "C" void fn_8005E3C8(void*, const unsigned char*, float);
extern "C" void* g_efScreen;
extern "C" char lbl_8045C278[];
extern "C" const float lbl_805A26D0;

struct Task {
    char pad[0x3C];
    void* vtable;
    char pad40[4];
    unsigned char effect;
};

extern "C" void* fn_800FB834(Task* self, int flags) {
    unsigned char effect;

    if (self != 0) {
        unsigned char b = self->effect;
        self->vtable = lbl_8045C278;
        float f = lbl_805A26D0;
        effect = b;
        fn_8005E3C8(g_efScreen, &effect, f);

        if (self != 0) {
            __dt__6gfTaskFv(self, 0);
        }

        if (flags > 0) {
            __dl__FPv(self);
        }
    }

    return self;
}
