#pragma force_active on
extern "C" {
void fn_27_13CC24(void*);
void fn_27_358A3C(void*, void*, void*);
extern char lbl_27_bss_8094[];
}

extern "C" void fn_110_9014(void* object, void* argument) {
    fn_27_13CC24(object);
    fn_27_358A3C(lbl_27_bss_8094, *(void**)((char*)object + 0x60), argument);
}
