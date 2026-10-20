#pragma force_active on
typedef unsigned int u32;

extern "C" u32 fn_27_30B8B0(u32* self, u32 unused, u32 idx) {
    return *(u32*)((char*)self + 0x34 + ((idx - self[6]) << 2));
}
