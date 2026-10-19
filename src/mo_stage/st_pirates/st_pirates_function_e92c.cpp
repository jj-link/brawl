#pragma force_active on
extern "C" {
void __dt__14snd3DGeneratorFv(void* self, int flags);
void fn_52_363C(void* self, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_52_E92C(char* self, int flags) {
    if (self) {
        __dt__14snd3DGeneratorFv(self + 0x188, -1);
        fn_52_363C(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
