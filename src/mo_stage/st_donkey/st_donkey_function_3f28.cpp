#pragma force_active on
extern "C" {
extern char lbl_50_data_19C0[];
void __dl__FPv(void* p);
void __dt__14snd3DGeneratorFv(void* self, int flags);
void* fn_50_2034(void* p, int flag);
}

extern "C" void* fn_50_3F28(char* p, int flag) {
    if (p) {
        *(char**)(p + 0x3C) = lbl_50_data_19C0;
        void* q = *(void**)(p + 0x17C);
        if (q) {
            __dl__FPv(q);
        }
        *(void**)(p + 0x17C) = 0;
        __dt__14snd3DGeneratorFv(p + 0x190, -1);
        fn_50_2034(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
