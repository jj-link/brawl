#pragma force_active on
extern "C" {
void __dt__14snd3DGeneratorFv(void* self, int flags);
void fn_8009EE60(void* self, int flags);
void fn_74_26B0(void* self, int flags);
void __dl__FPv(void* p);
}

extern "C" void* fn_74_3144(void* self, int flags) {
    if (self != 0) {
        __dt__14snd3DGeneratorFv((char*)self + 0x1f8, -1);
        fn_8009EE60((char*)self + 0x174, -1);
        fn_74_26B0(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
