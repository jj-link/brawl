#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void __dt__14snd3DGeneratorFv(void* self, int flags);
void fn_52_363C(void* self, int flags);
}

extern char lbl_52_data_2390[];

extern "C" char* fn_52_A408(char* self, int flags) {
    if (self) {
        void* p = *(void**)(self + 0x178);
        *(char**)(self + 0x3C) = lbl_52_data_2390;
        if (p) {
            __dl__FPv(p);
        }
        *(void**)(self + 0x178) = 0;
        __dt__14snd3DGeneratorFv(self + 0x17C, -1);
        fn_52_363C(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
