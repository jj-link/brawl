#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void __dt__14snd3DGeneratorFv(void*, int);
void* fn_62_2CE8(void*, int);
extern char lbl_62_data_5650[];
}

extern "C" void* fn_62_F244(void* p, int flags) {
    if (p) {
        char* c = (char*)p;
        void* ptr = *(void**)(c + 0x174);
        *(void**)(c + 0x3c) = &lbl_62_data_5650;
        if (ptr)
            __dl__FPv(ptr);
        *(void**)(c + 0x174) = 0;
        __dt__14snd3DGeneratorFv(c + 0x188, -1);
        fn_62_2CE8(p, 0);
        if (flags > 0)
            __dl__FPv(p);
    }
    return p;
}
