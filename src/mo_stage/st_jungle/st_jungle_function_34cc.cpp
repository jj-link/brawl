#pragma force_active on
extern "C" {
void __dt__14snd3DGeneratorFv(void* self, int flags);
void fn_51_289C(void* self, int flag);
void __dl__FPv(void* ptr);
}

extern "C" void* fn_51_34CC(void* self, int flags) {
    if (self != 0) {
        __dt__14snd3DGeneratorFv((char*)self + 0x198, -1);
        fn_51_289C(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
