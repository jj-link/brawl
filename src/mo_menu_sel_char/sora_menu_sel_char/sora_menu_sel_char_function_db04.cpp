#pragma force_active on

extern "C" int fn_10_DA54(void*, int);
extern "C" void fn_800B68F0(void*, float*, char*, char*);
extern "C" char lbl_10_data_5B8[];
extern "C" char lbl_10_data_5C0[];
extern "C" const float lbl_10_rodata_468;

struct MenuStruct {
    unsigned char padding[0x13C];
    void* data[252];
};

extern "C" int fn_10_DB04(MenuStruct* self, float* out, int kind) {
    float v[4];
    int r = 0;
    int index = fn_10_DA54(self, kind);

    if (index < 0) {
        r = 0;
    } else {
        fn_800B68F0(self->data[index + 0xC], v,
                    lbl_10_data_5B8, lbl_10_data_5C0);
        r = 1;
    }

    if (r == 0) {
        return 0;
    }

    float x = v[1] + v[0];
    x *= lbl_10_rodata_468;
    out[0] = x;

    float y = v[3] + v[2];
    y *= lbl_10_rodata_468;
    out[1] = y;

    return 1;
}
