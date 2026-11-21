#pragma force_active on

extern "C" {

extern const float lbl_805A3678;
extern const float lbl_805A367C;
extern const float lbl_805A3680;
extern const float lbl_805A3690;
extern const float lbl_805A3694;
extern const float lbl_805A3698;
extern void* lbl_80466D50[];

struct FnObj3440 {
    int unk0;
    unsigned char unk4;
    unsigned char unk5;
};

float fn_801D3440(FnObj3440* obj, float farg0) {
    float x;
    float v;
    float* tbl;
    int idx;

    if (farg0 > lbl_805A3678) {
        x = lbl_805A3678;
    } else if (farg0 < lbl_805A3690) {
        x = lbl_805A3690;
    } else {
        x = farg0;
    }
    tbl = (float*)lbl_80466D50[obj->unk0];
    farg0 = lbl_805A3678 + x;
    farg0 *= lbl_805A3680;
    idx = (int)(lbl_805A3680 + lbl_805A3694 * farg0);
    v = tbl[idx];
    if (obj->unk4 != 0) {
        v /= *(float*)((char*)tbl + 0x200);
    }
    if (obj->unk5 != 0) {
        if (v > lbl_805A3678) {
            return lbl_805A3678;
        }
        if (v < lbl_805A3698) {
            return lbl_805A3698;
        }
        return v;
    }
    if (v > lbl_805A367C) {
        return lbl_805A367C;
    }
    if (v < lbl_805A3698) {
        return lbl_805A3698;
    }
    return v;
}

}
