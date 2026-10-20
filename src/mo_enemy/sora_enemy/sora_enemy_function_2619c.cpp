#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char __RTTI__16emAreaModuleImpl[];
extern char __RTTI__12soAreaModule[];
extern float lbl_41_rodata_D60;

extern "C" float fn_41_2619C(void* p1, int idx) {
    if (idx <= -1 || idx >= 8)
        return lbl_41_rodata_D60;
    char* p = (char*)__dynamic_cast(
        *(void**)(*(char**)((char*)p1 + 0xD8) + 0x90),
        0, __RTTI__16emAreaModuleImpl, __RTTI__12soAreaModule, 1);
    return *(float*)(p + idx * 4 + 0x588);
}
