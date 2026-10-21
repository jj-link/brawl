#pragma force_active on
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);

extern "C" int fn_27_63438(void* self, float value) {
    float first = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0x7D3, 0);
    if (value < first)
        return 0;
    float second = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0x7D4, 0);
    if (value < second)
        return 1;
    float third = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0x7D5, 0);
    if (value < third)
        return 2;
    return 3;
}
