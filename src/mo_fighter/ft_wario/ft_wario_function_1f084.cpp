#pragma force_active on
extern "C" char lbl_27_bss_8094[];
extern "C" void fn_27_357DB0(void* a, void* b, void* c);
extern "C" void fn_27_130808(void* object, int param);

extern "C" void fn_110_1F084(void* object, int param) {
    fn_27_357DB0(lbl_27_bss_8094, *(void**)((char*)object + 0x60), (void*)param);
    fn_27_130808(object, param);
}
