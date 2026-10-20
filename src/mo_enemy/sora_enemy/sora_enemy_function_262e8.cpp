#pragma force_active on
extern char __RTTI__16emAreaModuleImpl[];
extern char __RTTI__12soAreaModule[];
extern float lbl_41_rodata_D60;
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);

extern "C" float fn_41_262E8(char* p, int idx) {
    if (idx <= -1 || idx >= 8) {
        return lbl_41_rodata_D60;
    }
    char* m = *(char**)(*(char**)(p + 0xd8) + 0x90);
    char* r = (char*)__dynamic_cast(m, 0, __RTTI__16emAreaModuleImpl, __RTTI__12soAreaModule, 1);
    return *(float*)(r + (idx << 2) + 0x5a8);
}
