#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_41_1AE10(s32);

extern "C" s32 fn_41_1AE30(s32 p1) {
    if ((u32)fn_41_1AE10(p1) == 1) {
        return -1;
    }
    extern s32 lbl_41_data_2A38[];
    return lbl_41_data_2A38[p1];
}
