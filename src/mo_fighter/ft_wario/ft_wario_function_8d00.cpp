#pragma force_active on
extern "C" {
extern char lbl_27_bss_8094[];
void fn_27_357DB0(void*, void*, int);
void fn_27_130808(void*, int);

void fn_110_8D00(void* object, int argument) {
    fn_27_357DB0(lbl_27_bss_8094, *(void**)((char*)object + 0x60), argument);
    fn_27_130808(object, argument);
}
}
