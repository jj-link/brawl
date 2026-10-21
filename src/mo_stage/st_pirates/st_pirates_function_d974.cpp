#pragma force_active on
extern "C" char lbl_52_data_2DA8[];
extern "C" void fn_52_363C(void* self, int flags);
extern "C" void __dt__14snd3DGeneratorFv(void* self, int flags);

extern "C" void* fn_52_D974(void* self, int flags) {
    if (self) {
        char* p = (char*)self;
        void* old = *(void**)(p + 0x1a4);
        *(char**)(p + 0x3c) = lbl_52_data_2DA8;
        if (old) {
            operator delete(old);
        }
        *(void**)(p + 0x1a4) = 0;
        __dt__14snd3DGeneratorFv(p + 0x1ac, -1);
        fn_52_363C(self, 0);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}
