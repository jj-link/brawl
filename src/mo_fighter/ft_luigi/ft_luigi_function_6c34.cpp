#pragma force_active on
extern "C" void fn_27_D2FF0(void*, int, int);
extern "C" void fn_27_61454(void*, void*, void*, void*, void*, void*);
extern unsigned char lbl_27_bss_4694[];
extern unsigned char lbl_27_bss_46AC[];

extern "C" void* fn_99_6C34(void* object, void* arg1, void* arg2) {
    fn_27_D2FF0(object, 1, 0);
    fn_27_61454(static_cast<unsigned char*>(object) + 0xac, arg1, object, lbl_27_bss_4694, lbl_27_bss_46AC, arg2);
    return object;
}
