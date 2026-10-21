#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void __dt__14snd3DGeneratorFv(void* self, int flags);
extern "C" void* fn_61_2384(void* p, int del);
extern "C" char lbl_61_data_25A0[];

extern "C" void* fn_61_70E4(char* self, int flags) {
    if (self) {
        void* p = *(void**)(self + 0x170);
        *(void**)(self + 0x3c) = lbl_61_data_25A0;
        if (p) {
            __dl__FPv(p);
        }
        *(void**)(self + 0x170) = 0;
        __dt__14snd3DGeneratorFv(self + 0x174, -1);
        fn_61_2384(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
