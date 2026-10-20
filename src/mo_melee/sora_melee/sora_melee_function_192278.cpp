#pragma force_active on
extern unsigned char lbl_27_bss_7B0C[];

extern "C" void* fn_27_30FA2C(
    void*, unsigned long, unsigned long, void*, unsigned long);
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, void*, unsigned long);

extern "C" float fn_27_192278(void* self, unsigned long arg) {
    void* accesser = fn_27_30FA2C(lbl_27_bss_7B0C, 1, arg, self, 0);
    return getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        self, accesser, 0);
}
