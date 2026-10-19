#pragma force_active on
extern "C" {
void __dt__14snd3DGeneratorFv(void* self, int flags);
void fn_67_A084(void* p, int doFree);
void __dl__FPv(void* p);
}

extern "C" void* fn_67_A41C(char* self, int flags) {
    if (self != 0) {
        __dt__14snd3DGeneratorFv(self + 0x1CC, -1);
        fn_67_A084(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
