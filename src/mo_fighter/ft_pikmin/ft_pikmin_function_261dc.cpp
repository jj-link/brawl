#pragma force_active on

extern "C" {
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void* mod, unsigned long id, unsigned long index);

void fn_27_60CDC(
    void* self, float f1, float f2, float f3,
    void* arg1, void* arg2,
    float f4, float f5, float f6, float f7, float f8);
}

extern "C" void fn_113_261DC(
    int unused, void* self,
    float f1, float f2, float f3,
    void* arg1, void* arg2)
{
    float a, b, c, d, e;

    d = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xfc4, 0);
    c = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xfc3, 0);
    b = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xfc2, 0);
    a = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xfc1, 0);
    e = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xfc0, 0);

    fn_27_60CDC(self, f1, f2, f3, arg1, arg2, e, a, b, c, d);
}
