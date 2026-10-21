#pragma force_active on
typedef unsigned int u32;

extern float lbl_805A4798;

extern "C" u32 fn_80324888(float* p) {
    return (u32)(p[3] < lbl_805A4798) |
           (((u32)(p[2] < lbl_805A4798) << 1) |
            (((u32)(p[0] < lbl_805A4798) << 3) |
             ((u32)(p[1] < lbl_805A4798) << 2)));
}
