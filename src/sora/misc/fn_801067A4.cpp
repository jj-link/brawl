#pragma force_active on
extern "C" {
extern void* g_IfAdvMngr;
void fn_80107040(void*);
void fn_80109774(void*, int);
void fn_80106D10(void*);
void __dl__FPv(void*);

void fn_801067A4() {
    void* p = g_IfAdvMngr;
    if (p) {
        fn_80107040(p);
        fn_80109774(*(void**)((char*)p + 0x74), 1);
        fn_80106D10(p);
        if ((unsigned long)p + 0x78)
            __dl__FPv(*(void**)((char*)p + 0x78));
        __dl__FPv(p);
    }
    g_IfAdvMngr = 0;
}
}