#pragma force_active on
typedef unsigned int u32;
typedef unsigned long long u64;

extern "C" void fn_801E1D80(u64, u32);

extern "C" void fn_800506C0(u32 arg0, u32 arg1) {
    fn_801E1D80((u64)arg1 * (*(u32*)0x800000F8 >> 2), arg0);
}
