#pragma force_active on
typedef unsigned char u8;

extern "C" {
extern const float lbl_52_rodata_1C;
}

struct Sub {
    char pad[0x90];
    float f90;
    float f94;
};

extern "C" int fn_52_3310(u8* self, int a, Sub* b, int* out) {
    if (self[0x608] == 0) {
        return 0;
    }
    Sub* s = *(Sub**)(self + 0x9c);
    if (s == 0) {
        return 0;
    }
    u8 mode = self[0x1e1];
    if (mode == 2) {
        if (lbl_52_rodata_1C - *(float*)(self + 0x1dc) > s->f90 - lbl_52_rodata_1C) {
            goto set1;
        }
    }
    if (mode != 1) {
        goto set0;
    }
    if (!(lbl_52_rodata_1C - *(float*)(self + 0x1dc) < (s->f94 - lbl_52_rodata_1C) - lbl_52_rodata_1C)) {
        goto set0;
    }
set1:
    *out = 1;
    goto end;
set0:
    *out = 0;
end:
    return 1;
}
