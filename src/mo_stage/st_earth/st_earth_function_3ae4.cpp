#pragma force_active on
extern "C" {
void fn_8009EE60(void*, int);
void __dt__14snd3DGeneratorFv(void*, int);
void fn_66_2C60(void*, int);
void __dl__FPv(void*);
void* fn_66_3AE4(void* self, int flags);
}

void* fn_66_3AE4(void* self, int flags) {
    if (self != 0) {
        fn_8009EE60((char*)self + 0x28c, -1);
        __dt__14snd3DGeneratorFv((char*)self + 0x280, -1);
        fn_66_2C60(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
