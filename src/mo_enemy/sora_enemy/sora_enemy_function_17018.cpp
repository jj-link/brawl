#pragma force_active on
extern "C" float lbl_41_rodata_C38[];
extern "C" float getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* acc, unsigned int id, unsigned int index);

extern "C" float fn_41_17018(void* self) {
    float* base = lbl_41_rodata_C38;
    float f1 = *(float*)((char*)self + 0xbd0);
    if (f1 < base[1]) {
        return base[4];
    }
    if (f1 > base[8]) {
        return base[4];
    }
    float val = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(*(void**)((char*)self + 0x20), 0xbc5, 0);
    float f3 = *(float*)((char*)self + 0xbd0);
    if (f3 < base[16]) {
        f3 = base[1];
    }
    return val * ((base[8] - f3) / base[8]);
}
