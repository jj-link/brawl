#pragma force_active on
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void fn_27_1392D4(void*, float, float, int, int, int);

extern const char lbl_27_data_69C0[];
extern const char lbl_27_data_248[];

extern "C" void fn_27_151B7C(void*, void* accesser, const float* values) {
    float scale = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xD85, 0);
    void* object = __dynamic_cast(
        *(void**)((char*)accesser + 8), 0x3C,
        lbl_27_data_69C0, lbl_27_data_248, 1);
    fn_27_1392D4(object, scale * values[1], values[1], 1, 0, 0);
}
