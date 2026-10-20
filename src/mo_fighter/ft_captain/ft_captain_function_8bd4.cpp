#pragma force_active on
extern "C" {
void fn_100_D274(void*, void*);
void fn_27_13138C(void*, int, int, void*, void*);
extern unsigned char lbl_100_bss_194[];
}

extern "C" void fn_100_8BD4(void* arg0, int arg1, int arg2, void* arg3, void* arg4) {
    if (arg2 == 0x113 && arg1 == 0x0E) {
        fn_100_D274(lbl_100_bss_194, arg4);
    }

    fn_27_13138C(arg0, arg1, arg2, arg3, arg4);
}
