#pragma force_active on
extern "C" void __dt__14snd3DGeneratorFv(void*, int);
extern "C" void __dt__Q28StSeUtil5SeSeqFv(void*, int);
extern "C" void* fn_57_39EC(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_57_6AA8(void* self, int flag) {
    if (self) {
        __dt__14snd3DGeneratorFv((char*)self + 0x2e4, -1);
        if ((char*)self + 0x16c) {
            __dt__Q28StSeUtil5SeSeqFv((char*)self + 0x16c, 0);
        }
        fn_57_39EC(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
