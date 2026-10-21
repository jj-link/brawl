#pragma force_active on

typedef unsigned int u32;
typedef int s32;

extern "C" int sprintf(char*, const char*, ...);
extern const u32 lbl_90_data_2A64[5];
extern const char* lbl_90_data_28C8[5];

extern "C" s32 fn_90_6C18(s32 a, char* buf, u32 idx, u32 val) {
    if (buf == 0 || (u32)idx >= 5 || val >= lbl_90_data_2A64[idx]) {
        return 0;
    }
    s32 inc = (s32)idx != 4 ? (s32)val + 1 : (s32)val / 256 + 1;
    sprintf(buf, lbl_90_data_28C8[idx], inc);
    return 1;
}
