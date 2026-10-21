#pragma force_active on
extern "C" float getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* acc, unsigned long id, unsigned long index);

extern "C" int fn_41_FD44(void* self, float f) {
    if (f < getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(*(void**)((char*)self + 0x3c), 0xbd8, 0)) {
        return 0;
    }
    if (f < getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(*(void**)((char*)self + 0x3c), 0xbd9, 0)) {
        return 1;
    }
    if (f < getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(*(void**)((char*)self + 0x3c), 0xbda, 0)) {
        return 2;
    }
    return 3;
}
