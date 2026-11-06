#pragma force_active on
extern "C" const float lbl_47_rodata_0[];

extern "C" int fn_47_12C4(unsigned char* self, const float* v) {
    const float* tbl = lbl_47_rodata_0;
    if (v == 0) {
        return 0x15;
    }
    float x = v[0];
    float y = v[1];
    if (x < tbl[10]) {
        return 0x15;
    }
    if (x > tbl[11]) {
        return 0x15;
    }
    if (y < tbl[12]) {
        return 0x15;
    }
    if (y > tbl[13]) {
        return 0x15;
    }
    if (x <= tbl[0]) {
        if (y >= tbl[14]) {
            if ((unsigned char)(self[0x24c] + 0xFE) <= 1U) {
                return 0x15;
            }
        } else {
            if ((unsigned char)(self[0x24d] + 0xFE) <= 1U) {
                return 0x15;
            }
        }
    } else {
        if (y >= tbl[14]) {
            if ((unsigned char)(self[0x24e] + 0xFE) <= 1U) {
                return 0x15;
            }
        } else {
            if ((unsigned char)(self[0x24f] + 0xFE) <= 1U) {
                return 0x15;
            }
        }
    }
    return 0x14;
}
