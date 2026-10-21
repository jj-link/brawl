#pragma force_active on

extern "C" {
struct Vec3f {
    float x, y, z;
};

void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_96_B488(void*);
void fn_96_14960(void*, const void*);
Vec3f* fn_96_BC54(Vec3f*, float, float, float);
void* memcpy(void*, const void*, unsigned long);

extern const char lbl_96_data_608[];
extern const char lbl_96_data_68D8[];
extern const float lbl_96_rodata_48;
extern const float lbl_96_rodata_4C;

void fn_96_15740(unsigned char* arg0) {
    Vec3f sp8;
    fn_96_BC54(&sp8, lbl_96_rodata_4C, lbl_96_rodata_48,
               lbl_96_rodata_4C);

    unsigned char* p = (unsigned char*)fn_96_B488(
        __dynamic_cast(*(void**)(arg0 + 8), 0x3c,
                       lbl_96_data_608, lbl_96_data_68D8, 1));

    fn_96_14960(p, &sp8);
    *(float*)(p + 12) = lbl_96_rodata_4C;

    for (int i = 0; i < 4; ++i) {
        int off = i << 4;
        memcpy(p + 0x50 + off, p, 0x10);
        memcpy(p + 0x10 + off, p, 0x10);
    }
}
}
