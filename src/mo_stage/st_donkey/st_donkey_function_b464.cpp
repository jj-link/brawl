#pragma force_active on
extern "C" void __dt__14snd3DGeneratorFv(void*, int);
extern "C" void fn_50_2034(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_50_B464(void* self, int flags) {
    if (self != 0) {
        __dt__14snd3DGeneratorFv((char*)self + 0x170, -1);

        if (self != 0) {
            fn_50_2034(self, 0);
        }

        if (flags > 0) {
            __dl__FPv(self);
        }
    }

    return self;
}
