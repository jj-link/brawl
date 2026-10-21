#pragma force_active on
extern "C" {
void __dt__14snd3DGeneratorFv(void*, int);
void __dl__FPv(void*);
void __dla__FPv(void*);
void* fn_73_2CC8(void*, int);
extern char lbl_73_data_3A68[];
}

extern "C" void* fn_73_5D9C(void* p, int flags) {
    if (p) {
        __dt__14snd3DGeneratorFv((char*)p + 0x29c, -1);
        if (p) {
            void* q = *(void**)((char*)p + 0x284);
            *(void**)((char*)p + 0x3c) = lbl_73_data_3A68;
            if (q)
                __dl__FPv(q);
            q = *(void**)((char*)p + 0x174);
            *(void**)((char*)p + 0x284) = 0;
            if (q)
                __dla__FPv(q);
            *(void**)((char*)p + 0x174) = 0;
            fn_73_2CC8(p, 0);
        }
        if (flags > 0)
            __dl__FPv(p);
    }
    return p;
}
