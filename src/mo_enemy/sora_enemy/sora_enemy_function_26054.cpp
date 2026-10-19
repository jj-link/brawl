#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char __RTTI__16emAreaModuleImpl[];
extern char __RTTI__12soAreaModule[];

typedef int s32;

extern "C" s32 fn_41_26054(void* p1, s32 idx) {
    if (idx <= -1 || idx >= 8) {
        return -1;
    }
    void* p = *(void**)((char*)*(void**)((char*)p1 + 0xD8) + 0x90);
    p = __dynamic_cast(p, 0, __RTTI__16emAreaModuleImpl, __RTTI__12soAreaModule, 1);
    return *(s32*)((char*)p + idx * 4 + 0x568);
}
