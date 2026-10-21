#pragma force_active on
typedef unsigned int u32;

u32 fn_80281294(void *arg0) {
    u32 temp_r3;

    temp_r3 = *(u32 *)((char *)arg0 + 0x18);
    return ((u32)(-temp_r3 | temp_r3) >> 7U) & 0x01000000;
}
