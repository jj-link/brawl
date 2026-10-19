#pragma force_active on
extern "C" {
extern char lbl_27_bss_8094[];
void fn_27_13D34C(void*, void*, int);
void fn_27_358BF8(void*, void*, void*, int);

void fn_110_1F5E4(void* object, void* arg1, int arg2) {
    fn_27_13D34C(object, arg1, arg2);
    fn_27_358BF8(lbl_27_bss_8094, *(void**)((char*)object + 0x60), arg1, arg2);
}
}
