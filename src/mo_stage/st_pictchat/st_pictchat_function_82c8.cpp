#pragma force_active on
extern "C" {
extern char lbl_73_data_3A68[];
void fn_73_2CC8(void* p, int n);
void __dt__14snd3DGeneratorFv(void* self, int flags);
void __dl__FPv(void* p);
void __dla__FPv(void* p);
}

extern "C" void* fn_73_82C8(void* a, int flags) {
    char* p = (char*)a;
    if (p != 0) {
        __dt__14snd3DGeneratorFv(p + 0x294, -1);
        if (p != 0) {
            void* obj = *(void**)(p + 0x284);
            *(void**)(p + 0x3c) = lbl_73_data_3A68;
            if (obj != 0) {
                __dl__FPv(obj);
            }
            *(void**)(p + 0x284) = 0;
            void* arr = *(void**)(p + 0x174);
            if (arr != 0) {
                __dla__FPv(arr);
            }
            *(void**)(p + 0x174) = 0;
            fn_73_2CC8(p, 0);
        }
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return a;
}
