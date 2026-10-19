#pragma force_active on
extern "C" {
void __dt__14snd3DGeneratorFv(void* self, int flags);
void fn_66_2C60(void* self, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_66_114C0(void* self, int flags) {
    if (self) {
        __dt__14snd3DGeneratorFv((char*)self + 0x170, -1);
        fn_66_2C60(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
