typedef unsigned int u32;

#pragma force_active on
u32 fn_803512B4(u32 *arg0) {
    u32 b = (*arg0 >> 11) & 3;
    return (-b | b) >> 31;
}
