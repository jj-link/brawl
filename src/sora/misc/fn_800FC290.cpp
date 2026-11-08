#pragma force_active on

extern "C" {

extern void* g_IfWifiprMngr;
void fn_800FC840(void*);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void fn_800FC3E4(void*);
void __destroy_arr(void*, void (*)(void*), unsigned long, unsigned long);
void __dl__FPv(void*);

void fn_800FC290(void) {
    void* p = g_IfWifiprMngr;
    if (p != 0) {
        fn_800FC840(p);
        Destroy__Q34nw4r3g3d6G3dObjFv(*(void**)((char*)p + 0x14));
        *(void**)((char*)p + 0x14) = 0;
        __destroy_arr((char*)p + 0x54, fn_800FC3E4, 4, 5);
        __dl__FPv(p);
    }
    g_IfWifiprMngr = 0;
}

}
