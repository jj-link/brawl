#pragma force_active on

extern "C" {
void __dt__14snd3DGeneratorFv(void*, int);
void __dt__Q28StSeUtil5SeSeqFv(void*, int);
void* fn_57_39EC(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_57_7740(void* self, int flags) {
    if (self) {
        __dt__14snd3DGeneratorFv((char*)self + 0x244, -1);
        char* seq = (char*)self + 0x1a4;
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
