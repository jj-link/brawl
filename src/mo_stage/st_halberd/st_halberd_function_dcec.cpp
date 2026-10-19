#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void __dt__14snd3DGeneratorFv(void*, int);
void fn_57_39EC(void*, int);
}

extern "C" void* fn_57_DCEC(void* self, int flags) {
    if (self) {
        __dt__14snd3DGeneratorFv((char*)self + 0x1a8, -1);
        fn_57_39EC(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
