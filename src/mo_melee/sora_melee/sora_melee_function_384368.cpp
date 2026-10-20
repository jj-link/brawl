#pragma force_active on
extern "C" {
void fn_27_378F90(void*, int);
void fn_27_3790E4(void*, int);
void fn_27_125E20(void*, short);
void __dl__FPv(void*);

void* fn_27_384368(void* p, int del) {
    if (p) {
        if (p) {
            char* base = (char*)p;
            if (base + 0x194 != 0) {
                fn_27_378F90(base + 0x6928, -1);
                fn_27_3790E4(base + 0x194, 0);
            }
            fn_27_125E20(p, 0);
        }
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
