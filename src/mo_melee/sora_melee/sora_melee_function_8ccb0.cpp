#pragma force_active on
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);

extern "C" float fn_27_8CCB0(void* self, unsigned long arg) {
    void* acc = *(void**)((char*)self + 0x60);
    return getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, arg, 0);
}
