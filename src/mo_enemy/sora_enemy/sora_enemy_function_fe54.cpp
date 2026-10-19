#pragma force_active on
extern "C" unsigned int fn_41_FDDC(void*);
extern "C" int getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned int, unsigned int);

extern "C" int fn_41_FE54(void* self, int id, int* out) {
    if (id == 0x169)
        goto done;

    if (fn_41_FDDC(self) != 1u)
        goto done;

    *out = getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(
        *(void**)((char*)self + 0x3C), 0x59DB, 0);
    return 1;

done:
    return 0;
}
