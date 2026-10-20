#pragma force_active on
extern "C" void fn_57_39EC(void*, int);
extern "C" void __dt__14snd3DGeneratorFv(void*, int);
extern "C" void __dt__Q28StSeUtil5SeSeqFv(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_57_1156C(char* self, int flags) {
    if (self) {
        __dt__14snd3DGeneratorFv(self + 0x1f0, -1);
        char* seq = self + 0x170;
        if (seq) {
            __dt__Q28StSeUtil5SeSeqFv(seq, 0);
        }
        fn_57_39EC(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
