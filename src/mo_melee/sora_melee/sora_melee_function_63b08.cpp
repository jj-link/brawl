#pragma force_active on
struct soModuleAccesser;

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);
extern "C" int fn_27_68140(float, float, float, float, float);

extern "C" int fn_27_63B08(soModuleAccesser* module, float a, float b) {
    float second;
    float first;

    first = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        module, 0x7E2, 0);
    second = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        module, 0x7E4, 0);
    float third = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        module, 0x7E3, 0);

    return fn_27_68140(a, third, second, b, first);
}
