#pragma force_active on
extern "C" void __dt__14snd3DGeneratorFv(void* self, int flags);
extern "C" void fn_52_363C(void* self, int flags);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_52_11D38(void* self, int flags) {
    if (self != 0) {
        __dt__14snd3DGeneratorFv((char*)self + 0x170, -1);
        fn_52_363C(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
