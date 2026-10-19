#pragma force_active on
extern "C" const float lbl_60_rodata_0[];

extern "C" int fn_60_6098(void* self, const float* v) {
    const float* tbl = lbl_60_rodata_0;
    if (v == 0) {
        return 0x14;
    }
    float x = v[0];
    float y = v[1];
    if (x < tbl[56]) {
        return 0x14;
    }
    if (x > tbl[57]) {
        return 0x14;
    }
    if (y < tbl[58]) {
        return 0x14;
    }
    if (y > tbl[59]) {
        return 0x14;
    }
    return 0x15;
}
