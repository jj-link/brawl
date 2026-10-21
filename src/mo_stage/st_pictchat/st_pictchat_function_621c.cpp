#pragma force_active on
extern "C" {
void __dt__14snd3DGeneratorFv(void* self, int flags);
void __dl__FPv(void* p);
void __dla__FPv(void* p);
void* fn_73_2CC8(void* p, int n);
extern char lbl_73_data_3A68[];
}

extern "C" void* fn_73_621C(char* self, int n) {
    if (self != 0) {
        __dt__14snd3DGeneratorFv(self + 0x294, -1);
        if (self != 0) {
            *(void**)(self + 0x3c) = lbl_73_data_3A68;
            if (*(void**)(self + 0x284) != 0) {
                __dl__FPv(*(void**)(self + 0x284));
            }
            void* q = *(void**)(self + 0x174);
            *(void**)(self + 0x284) = 0;
            if (q != 0) {
                __dla__FPv(q);
            }
            *(void**)(self + 0x174) = 0;
            fn_73_2CC8(self, 0);
        }
        if (n > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
