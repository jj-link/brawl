#pragma force_active on
extern "C" {
void __dt__14snd3DGeneratorFv(void*, int);
void __dl__FPv(void*);
void __dla__FPv(void*);
void fn_73_2CC8(void*, int);
extern char lbl_73_data_3A68[];

void* fn_73_7834(void* a, int b) {
    void* ret = a;
    if (a != 0) {
        __dt__14snd3DGeneratorFv((char*)a + 0x294, -1);
        if (a != 0) {
            void* p284 = *(void**)((char*)a + 0x284);
            *(void**)((char*)a + 0x3c) = lbl_73_data_3A68;
            if (p284 != 0)
                __dl__FPv(p284);
            void* p174 = *(void**)((char*)a + 0x174);
            *(void**)((char*)a + 0x284) = 0;
            if (p174 != 0)
                __dla__FPv(p174);
            *(void**)((char*)a + 0x174) = 0;
            fn_73_2CC8(a, 0);
        }
        if (b > 0)
            __dl__FPv(a);
    }
    return ret;
}
}
