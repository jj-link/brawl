#pragma force_active on

struct Entry {
    unsigned int pad;
    float f4;
    float f8;
    unsigned char rest[0x10];
};

extern "C" Entry lbl_8049E5A0[];

extern "C" int fn_80138ED8(int unused, int b, int a) {
    if (lbl_8049E5A0[b].f4 == lbl_8049E5A0[a].f4 &&
        lbl_8049E5A0[b].f8 == lbl_8049E5A0[a].f8) {
        return 1;
    }
    return 0;
}
