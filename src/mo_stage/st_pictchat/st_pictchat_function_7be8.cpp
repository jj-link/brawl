#pragma force_active on
extern "C" {
void __dt__14snd3DGeneratorFv(void*, int);
void __dt__Q28StSeUtil5SeSeqFv(void*, int);
void __dl__FPv(void*);
void __dla__FPv(void*);
void* fn_73_2CC8(void*, int);
extern char lbl_73_data_3A68[];
}

extern "C" void* fn_73_7BE8(void* arg0, int arg1) {
    if (arg0) {
        __dt__14snd3DGeneratorFv((char*)arg0 + 0x318, -1);
        char* seq = (char*)arg0 + 0x294;
        if (seq) {
            __dt__Q28StSeUtil5SeSeqFv(seq, 0);
        }
        if (arg0) {
            void* p284 = *(void**)((char*)arg0 + 0x284);
            *(void**)((char*)arg0 + 0x3c) = lbl_73_data_3A68;
            if (p284)
                __dl__FPv(p284);
            void* p174 = *(void**)((char*)arg0 + 0x174);
            *(void**)((char*)arg0 + 0x284) = 0;
            if (p174)
                __dla__FPv(p174);
            *(void**)((char*)arg0 + 0x174) = 0;
            fn_73_2CC8(arg0, 0);
        }
        if (arg1 > 0)
            __dl__FPv(arg0);
    }
    return arg0;
}
