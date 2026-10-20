#pragma force_active on
extern "C" {
void __dt__14snd3DGeneratorFv(void*, int);
void __dt__Q28StSeUtil5SeSeqFv(void*, int);
void* fn_70_20FC(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_70_6108(void* self, int flags) {
    if (self != 0) {
        __dt__14snd3DGeneratorFv((char*)self + 0x1C4, -1);
        void* seq = (char*)self + 0x174;
        if (seq != 0) {
            __dt__Q28StSeUtil5SeSeqFv(seq, 0);
        }
        fn_70_20FC(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
