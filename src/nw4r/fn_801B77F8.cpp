#pragma force_active on
extern "C" {
extern signed char lbl_805A0560;
extern char lbl_804C1B8C[];
extern char lbl_804C1B80[];
void fn_801B72E0(void*);
void fn_801B785C(void*, int);
void __register_global_object(void* obj, void (*dtor)(void*), void* ctx);
}

extern "C" char* fn_801B77F8(void) {
    if (lbl_805A0560 == 0) {
        fn_801B72E0(&lbl_804C1B8C);
        __register_global_object(&lbl_804C1B8C, (void (*)(void*))fn_801B785C, &lbl_804C1B80);
        lbl_805A0560 = 1;
    }
    return lbl_804C1B8C;
}
