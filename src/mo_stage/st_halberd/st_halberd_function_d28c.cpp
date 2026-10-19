#pragma force_active on
extern "C" {
void __dt__14snd3DGeneratorFv(void* self, int flags);
void* fn_57_39EC(void* self, int del);
void __dl__FPv(void* p);
}

extern "C" void* fn_57_D28C(void* self, int flags) {
    if (self) {
        __dt__14snd3DGeneratorFv((char*)self + 0x16C, -1);
        fn_57_39EC(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
