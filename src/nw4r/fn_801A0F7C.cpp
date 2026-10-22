#pragma force_active on

extern "C" {
    extern unsigned char lbl_804A5514[0x2A2C];
    extern void fn_8019ECA0(void*, void*, void*, void*, void*, void*, void*);

    void fn_801A0F7C(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5) {
        fn_8019ECA0(lbl_804A5514, arg0, arg1, arg2, arg3, arg4, arg5);
    }
}
