#pragma force_active on
extern char lbl_73_data_3A68[];

extern "C" {
void __dt__14snd3DGeneratorFv(void* self, int flags);
void fn_73_2CC8(void*, int);

void* fn_73_6834(char* a, int b) {
    if (a) {
        __dt__14snd3DGeneratorFv(a + 0x2a8, -1);
        if (a) {
            void* p = *(void**)(a + 0x284);
            *(void**)(a + 0x3c) = lbl_73_data_3A68;
            if (p) {
                delete p;
            }
            void* q = *(void**)(a + 0x174);
            *(void**)(a + 0x284) = 0;
            if (q) {
                delete[] q;
            }
            *(void**)(a + 0x174) = 0;
            fn_73_2CC8(a, 0);
        }
        if (b > 0) {
            delete a;
        }
    }
    return a;
}
}
