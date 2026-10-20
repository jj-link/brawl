#pragma force_active on
extern "C" {
void __dt__14snd3DGeneratorFv(void* self, int flags);
void __dt__Q28StSeUtil5SeSeqFv(void* self, int flags);
void fn_57_39EC(void* self, int del);
void __dl__FPv(void* p);
}

extern "C" void* fn_57_3ED4(void* self, int del) {
    if (self) {
        __dt__14snd3DGeneratorFv((char*)self + 0x3e0, -1);
        if ((char*)self + 0x19c) {
            __dt__Q28StSeUtil5SeSeqFv((char*)self + 0x19c, 0);
        }
        fn_57_39EC(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
