#pragma force_active on
extern char lbl_73_data_3A68[];

extern "C" {
void __dt__14snd3DGeneratorFv(void*, int);
void __dl__FPv(void*);
void __dla__FPv(void*);
void fn_73_2CC8(void*, int);

void* fn_73_6ED0(char* a, int b) {
    if (a) {
        __dt__14snd3DGeneratorFv(a + 0x2a8, -1);
        if (a) {
            void* p = *(void**)(a + 0x284);
            *(void**)(a + 0x3c) = lbl_73_data_3A68;
            if (p) __dl__FPv(p);
            void* q = *(void**)(a + 0x174);
            *(void**)(a + 0x284) = 0;
            if (q) __dla__FPv(q);
            *(void**)(a + 0x174) = 0;
            fn_73_2CC8(a, 0);
        }
        if (b > 0) __dl__FPv(a);
    }
    return a;
}
}
