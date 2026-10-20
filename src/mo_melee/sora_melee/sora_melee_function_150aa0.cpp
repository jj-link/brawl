#pragma force_active on
struct soModuleAccesser;

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser* accesser, unsigned long id, unsigned long param);

extern "C" float fn_27_150AA0(char* p) {
    return getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(*(soModuleAccesser**)(p + 0x2c), 0xc84, 0);
}
