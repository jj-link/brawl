#pragma force_active on
extern "C" {
void __dt__14snd3DGeneratorFv(void*, int);
void __dt__Q28StSeUtil5SeSeqFv(void*, int);
void* fn_57_39EC(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_57_5894(void* self, int flags) {
    if (self != 0) {
        __dt__14snd3DGeneratorFv((char*)self + 0x224, -1);
        void* seq = (char*)self + 0x18C;
        if (seq != 0) {
            __dt__Q28StSeUtil5SeSeqFv(seq, 0);
        }
        fn_57_39EC(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
