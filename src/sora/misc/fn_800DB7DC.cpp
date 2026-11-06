#pragma force_active on

extern "C" {

extern void* g_IfMngr;
void fn_800DBD3C(void*);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void __dl__FPv(void*);

void fn_800DB7DC(void) {
    void* mgr = g_IfMngr;
    if (mgr != 0) {
        fn_800DBD3C(mgr);
        void* obj = *(void**)((char*)mgr + 0x18);
        if (obj != 0) {
            Destroy__Q34nw4r3g3d6G3dObjFv(obj);
            *(void**)((char*)mgr + 0x18) = 0;
        }
        __dl__FPv(mgr);
    }
    g_IfMngr = 0;
}

}