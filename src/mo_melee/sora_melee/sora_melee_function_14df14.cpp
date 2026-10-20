#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern char lbl_27_data_2C3A0[];

extern "C" {
u32 fn_27_14DF14(void *unused, s32 kind, s32 idx)
{
    return *(u32 *)(lbl_27_data_2C3A0 + kind * 0x38 + idx * 4);
}
}
