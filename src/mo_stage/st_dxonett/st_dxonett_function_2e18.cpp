#pragma force_active on
extern "C" {
void __dt__14snd3DGeneratorFv(void* self, int flags);
void fn_78_17D0(void* self, int arg);
void __dl__FPv(void* p);
}

extern "C" void* fn_78_2E18(void* self, int flag) {
    if (self != 0) {
        __dt__14snd3DGeneratorFv((char*)self + 0x17C, -1);
        fn_78_17D0(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
