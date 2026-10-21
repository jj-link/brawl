#pragma force_active on
typedef unsigned char u8;

extern "C" const u8 lbl_804556D8[];

extern "C" int fn_800AF904(int idx) {
    const u8* p = lbl_804556D8 + (idx << 4);
    return p[1];
}
