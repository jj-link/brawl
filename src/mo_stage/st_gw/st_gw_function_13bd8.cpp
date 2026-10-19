#pragma force_active on
extern "C" void __dt__14snd3DGeneratorFv(void* self, int flags);
extern "C" void fn_63_2C40(void* self, int flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_63_13BD8(void* self, int flag) {
    if (self != 0) {
        __dt__14snd3DGeneratorFv((char*)self + 0x190, -1);
        fn_63_2C40(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
