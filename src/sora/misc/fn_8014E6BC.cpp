#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

extern "C" {
u32 fn_8014E070(void);

u16 fn_8014E6BC(void) {
    u32 temp_r3;

    temp_r3 = fn_8014E070();
    if (temp_r3 >= 0x32000U) {
        return 0U;
    }
    return (u16)((0x32000U - temp_r3) / 10240U);
}
}
